/// 1.
// Search
	BDRAGON_SCROLL = 6,

// Add below
#if defined(__SOUL_SYSTEM__)
	SOUL_AWAKE_SCROLL = 8,
	SOUL_EVOLVE_SCROLL = 9,
#endif

/// 2.
// Search
bool CHARACTER::DoRefineWithScroll(LPITEM item)

// Add above
#if defined(__SOUL_SYSTEM__)
bool CHARACTER::DoRefineSoul(LPITEM item)
{
	if (!CanHandleItem(true))
	{
		ClearRefineMode();
		return false;
	}

	ClearRefineMode();

	const TRefineTable* prt = CRefineManager::instance().GetRefineRecipe(item->GetRefineSet());
	if (!prt)
		return false;

	if (m_iRefineAdditionalCell < 0)
		return false;

	LPITEM item_scroll = GetInventoryItem(m_iRefineAdditionalCell);
	if (item_scroll == nullptr)
		return false;

	if (!(item_scroll->GetType() == ITEM_USE && item_scroll->GetSubType() == USE_TUNING))
		return false;

	if (item_scroll->GetVnum() == item->GetVnum())
		return false;

	DWORD result_vnum = item->GetRefinedVnum();
	if (result_vnum == 0)
	{
		ChatPacket(CHAT_TYPE_INFO, LC_TEXT("´õ ÀÌ»ó °³·®ÇÒ ¼ö ¾ø½À´Ï´Ù."));
		return false;
	}

	TItemTable* proto = ITEM_MANAGER::instance().GetTable(item->GetRefinedVnum());
	if (!proto)
	{
		sys_err("DoRefineSoul NOT GET ITEM PROTO %d", item->GetRefinedVnum());
		ChatPacket(CHAT_TYPE_INFO, LC_TEXT("ÀÌ ¾ÆÀÌÅÛÀº °³·®ÇÒ ¼ö ¾ø½À´Ï´Ù."));
		return false;
	}

	int prob = number(1, 100);
	int success_prob = prt->prob;

	switch (item_scroll->GetValue(0))
	{
		case SOUL_AWAKE_SCROLL:
			success_prob = 100;
			break;

		case SOUL_EVOLVE_SCROLL:
			success_prob = soul_refine_prob[MINMAX(0, item->GetValue(1), SOUL_GRADE_MAX)];
			break;
	}

	item_scroll->SetCount(item_scroll->GetCount() - 1);

	if (prob <= success_prob)
	{
		LPITEM new_item = ITEM_MANAGER::instance().CreateItem(result_vnum, 1, 0, false);
		if (new_item)
		{
			WORD wCell = item->GetCell();

			LogManager::instance().ItemLog(this, new_item, "SOUL REFINE FAIL", new_item->GetName());
			ChatPacket(CHAT_TYPE_COMMAND, "RefineSoulSuceeded");

			ITEM_MANAGER::instance().RemoveItem(item, "REMOVE (SOUL REFINE FAIL)");

			new_item->AddToCharacter(this, TItemPos(INVENTORY, wCell));
			ITEM_MANAGER::instance().FlushDelayedSave(new_item);
		}
		else
		{
			sys_err("cannot create item %u", result_vnum);
			ChatPacket(CHAT_TYPE_COMMAND, "RefineSoulFailed");
		}
	}
	else
	{
		ChatPacket(CHAT_TYPE_COMMAND, "RefineSoulFailed");
	}

	return true;
}
#endif

/// 3.
// Search
	CRefineManager& rm = CRefineManager::instance();
	const TRefineTable* prt = rm.GetRefineRecipe(item->GetRefineSet());

// Add above
#if defined(__SOUL_SYSTEM__)
	if (item->GetType() == ITEM_SOUL)
	{
		if (bType == REFINE_TYPE_SOUL_AWAKE || bType == REFINE_TYPE_SOUL_EVOLVE)
		{
			p.cost = 0;
			p.prob = bType == REFINE_TYPE_SOUL_AWAKE ? 100 : soul_refine_prob[MINMAX(0, item->GetValue(1), SOUL_GRADE_MAX)];
			p.material_count = 0;
			std::memset(p.materials, 0, sizeof(p.materials));

			GetDesc()->Packet(&p, sizeof(TPacketGCRefineInformation));

			SetRefineMode(iAdditionalCell);
			return true;
		}
	}
#endif

/// 4.
// Search
		else if (pkItem->GetValue(0) == BDRAGON_SCROLL)
		{
			if (pkTarget->GetRefineSet() != 702) return false;
			RefineInformation(pkTarget->GetCell(), REFINE_TYPE_BDRAGON, pkItem->GetCell());
		}

// Add below
#if defined(__SOUL_SYSTEM__)
		else if (pkItem->GetValue(0) == SOUL_AWAKE_SCROLL)
		{
			if (pkTarget->GetValue(0) >= SOUL_GRADE_ILUMINED) return false;
			RefineInformation(pkTarget->GetCell(), REFINE_TYPE_SOUL_AWAKE, pkItem->GetCell());
		}
		else if (pkItem->GetValue(0) == SOUL_EVOLVE_SCROLL)
		{
			if (pkTarget->GetValue(0) >= SOUL_GRADE_ILUMINED) return false;
			RefineInformation(pkTarget->GetCell(), REFINE_TYPE_SOUL_EVOLVE, pkItem->GetCell());
		}
#endif

/// 5.
// Search @ case USE_TUNING:
					if (item2->GetVnum() >= 28330 && item2->GetVnum() <= 28343) // ¿µ¼®+3
					{
						ChatPacket(CHAT_TYPE_INFO, LC_TEXT("+3 ¿µ¼®Àº ÀÌ ¾ÆÀÌÅÛÀ¸·Î °³·®ÇÒ ¼ö ¾ø½À´Ï´Ù"));
						return false;
					}

// Add above
#if defined(__SOUL_SYSTEM__)
					if (item->GetValue(0) == SOUL_AWAKE_SCROLL || item->GetValue(0) == SOUL_EVOLVE_SCROLL)
					{
						if (item2->GetValue(0) >= SOUL_GRADE_ILUMINED)
						{
							ChatPacket(CHAT_TYPE_INFO, LC_TEXT("[Soul System] %s is already at the highest level."), item2->GetName());
							return false;
						}
					}
#endif

/// 6.
// Search
		case ITEM_NONE:
			sys_err("Item type NONE %s", item->GetName());
			break;

// Add above
#if defined(__SOUL_SYSTEM__)
		case ITEM_SOUL:
		{
			struct SoulData
			{
				WORD point_type;
				DWORD affect_flag;
			};
			std::unordered_map<BYTE, SoulData> soul_map
			{
				{ RED_SOUL, { AFF_SOUL_RED, AFF_SOUL_RED }, },
				{ BLUE_SOUL, { AFF_SOUL_BLUE, AFF_SOUL_BLUE }, },
			};

			const auto& it = soul_map.find(item->GetSubType());
			if (it == soul_map.end())
			{
				sys_err("ITEM_SOUL: Unknown SubType");
				return false;
			}

			const auto& soul = it->second;

			CAffect* affect = nullptr;
			for (auto const& it : GetAffectContainer())
			{
				if (it != nullptr && it->dwType == AFFECT_SOUL)
				{
					if (it->bApplyOn == soul.point_type)
						if (item->GetSocket(1) != TRUE)
							return false;

					affect = it;
					continue;
				}
			}

			if (item->GetSocket(1) != TRUE)
			{
				AddAffect(AFFECT_SOUL, soul.point_type, item->GetID(), affect ? AFF_NONE : soul.affect_flag, item->GetSocket(0), 0, false /* override */);

				if (affect)
				{
					std::vector<CAffect> tmp_affects;
					std::vector<CAffect*> to_remove;
					for (const auto& [k, v] : soul_map)
					{
						CAffect* affect = FindAffect(AFFECT_SOUL, v.point_type);
						if (affect)
						{
							tmp_affects.emplace_back(*affect);
							to_remove.emplace_back(affect);
						}
					}

					if (!to_remove.empty())
					{
						for (const auto& it : to_remove)
							RemoveAffect(it);
					}

					if (!tmp_affects.empty())
					{
						for (const auto& it : tmp_affects)
							AddAffect(it.dwType, it.bApplyOn, it.lApplyValue, AFF_NONE, it.lDuration, 0, false /* override */);
					}

					AddAffect(AFFECT_SOUL, AFF_SOUL_MIX, 0, AFF_SOUL_MIX, item->GetSocket(0), 0, false /* override */);
				}

				item->SetSocket(1, TRUE);
				item->Lock(true);
			}
			else
			{
				RemoveAffect(AFFECT_SOUL, soul.point_type);
				RemoveAffect(AFFECT_SOUL, AFF_SOUL_MIX); // AFF_SOUL_MIX

				std::vector<CAffect> tmp_affects;
				std::vector<CAffect*> to_remove;
				for (const auto& affect : GetAffectContainer())
				{
					if (affect != nullptr && affect->dwType == AFFECT_SOUL)
					{
						tmp_affects.emplace_back(*affect);
						to_remove.emplace_back(affect);
					}
				}

				for (const auto& affect : to_remove)
					RemoveAffect(affect);

				if (!tmp_affects.empty())
				{
					for (const auto& affect : tmp_affects)
					{
						auto it = std::find_if(soul_map.begin(), soul_map.end(), [&](const auto& kv_pair) {
							return kv_pair.second.point_type == affect.bApplyOn;
							});
				
						if (it != soul_map.end())
							AddAffect(affect.dwType, affect.bApplyOn, affect.lApplyValue, it->second.affect_flag, affect.lDuration, 0, false/*override*/);
					}
				}

				item->SetSocket(1, FALSE);
				item->Lock(false);
			}
		}
		break;
#endif

/// 7.
// Add to the bottom of the file
#if defined(__SOUL_SYSTEM__)
void CHARACTER::SoulItemProcess(ESoulSubType eSubType)
{
	LPITEM item = nullptr;
	for (const auto& it : GetAffectContainer())
	{
		if (it == nullptr || it->dwType != AFFECT_SOUL)
			continue;

		switch (eSubType)
		{
			case ESoulSubType::RED_SOUL:
			{
				if (it->bApplyOn == AFF_SOUL_RED)
					item = FindItemByID(it->lApplyValue);
			}
			break;

			case ESoulSubType::BLUE_SOUL:
			{
				if (it->bApplyOn == AFF_SOUL_BLUE)
					item = FindItemByID(it->lApplyValue);
			}
			break;
		}
	}

	if (item == nullptr)
		return;

	if (!item->isLocked() || item->GetSocket(1) != TRUE)
		return;

	auto data = item->GetSocket(2);
	auto keep_time = data / 10000;
	//auto max_time = item->GetLimitValue(1);
	auto min_time = 60;

	// Minimum use time.
	if (keep_time < min_time)
		return;

	/*
	* Since the `remain_count` is added after the `keep_time`
	* we can decrease `data` directly because the count
	* stays at the end of `data`.
	*/
	if (test_server)
		data -= 5;
	else
		--data; /* remain_count */;

	/*
	* If the remaining count is equal or below to zero
	* then set the socket data to 0 and start the soul
	* timer event.
	*/
	auto remain_count = data % 10000;
	if (remain_count <= 0)
	{
		item->SetSocket(2, 0);
		item->ResetSoulTimerUseEvent();
		return;
	}

	// Update the item with the new data (decreased count)
	item->SetSocket(2, data, false /* log */);
}

int CHARACTER::GetSoulDamage(ESoulSubType eSubType) const
{
	LPITEM item = nullptr;
	for (const auto& it : GetAffectContainer())
	{
		if (it == nullptr || it->dwType != AFFECT_SOUL)
			continue;

		switch (eSubType)
		{
			case ESoulSubType::RED_SOUL:
			{
				if (it->bApplyOn == AFF_SOUL_RED)
					item = FindItemByID(it->lApplyValue);
			}
			break;

			case ESoulSubType::BLUE_SOUL:
			{
				if (it->bApplyOn == AFF_SOUL_BLUE)
					item = FindItemByID(it->lApplyValue);
			}
			break;
		}
	}

	if (item == nullptr)
		return 0;

	if (item->GetSocket(1) != TRUE)
		return 0;

	auto value = 0;
	auto data = item->GetSocket(2);
	auto keep_time = data / 10000;

	auto max_time = item->GetLimitValue(1);
	auto min_time = 60;

	// Minimum use time.
	if (keep_time < min_time)
		return 0;

	if (keep_time >= max_time)
		return item->GetValue(5);

	// Damage values in value field (3, 4, 5)
	auto value_field = 3 + std::floor(keep_time / (max_time - min_time));
	if (value_field < ITEM_VALUES_MAX_NUM)
		value = item->GetValue(value_field);

	return value;
}
#endif
