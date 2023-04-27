/// 1.
// Search
			if (IS_NO_CLEAR_ON_DEATH_AFFECT(pkAff->dwType) || IS_NO_SAVE_AFFECT(pkAff->dwType))
			{
				++it;
				continue;
			}

// Add below
#if defined(__SOUL_SYSTEM__)
			if (pkAff->dwType == AFFECT_SOUL)
			{
				++it;
				continue;
			}
#endif

/// 2.
// Search
		if (pElements->bApplyOn >= POINT_MAX_NUM)

// Add above
#if defined(__SOUL_SYSTEM__)
		if (pElements->dwType == AFFECT_SOUL)
		{
			if (pElements->bApplyOn != AFF_SOUL_MIX)
			{
				const auto& item = FindItemByID(pElements->lApplyValue);
				if (item == nullptr)
					continue;

				item->Lock(true);
			}
		}
#endif

/// 3.
// Search
	if (bAdd)
		PointChange(pkAff->wApplyOn, pkAff->lApplyValue);
	else
		PointChange(pkAff->wApplyOn, -pkAff->lApplyValue);

// Add above
#if defined(__SOUL_SYSTEM__)
	if (pkAff->dwType == AFFECT_SOUL)
		return;
#endif

/// 4.
// Search
bool CHARACTER::IsAffectFlag(DWORD dwAff) const

// Add above
#if defined(__SOUL_SYSTEM__)
void CHARACTER::RemoveAffect(DWORD dwType, BYTE bApplyType)
{
	const CAffect* affect = nullptr;
	for (const auto& it : m_list_pkAffect)
	{
		affect = it;

		if (affect->dwType == dwType)
			if (affect->bApplyOn == bApplyType || affect->bApplyOn == APPLY_NONE)
				break;

		affect = nullptr;
	}

	if (affect != nullptr)
		RemoveAffect(const_cast<CAffect*>(affect));
}
#endif
