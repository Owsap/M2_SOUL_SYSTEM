/// 1.
// Search @ CItem::CItem
	m_dwMaskVnum(0), m_dwSIGVnum(0)

// Add below
#if defined(__SOUL_SYSTEM__)
	, m_pkSoulTimerUseEvent(nullptr)
#endif

/// 2.
// Search
	m_pkAccessorySocketExpireEvent = NULL;

// Add below
#if defined(__SOUL_SYSTEM__)
	m_pkSoulTimerUseEvent = nullptr;
#endif

/// 3.
// Search
	event_cancel(&m_pkAccessorySocketExpireEvent);

// Add below
#if defined(__SOUL_SYSTEM__)
	event_cancel(&m_pkSoulTimerUseEvent);
#endif

/// 4.
// Search
bool CItem::OnAfterCreatedItem()
{

// Add below
#if defined(__SOUL_SYSTEM__)
	if (GetType() == ITEM_SOUL && GetLimitValue(1) != 0)
		StartSoulTimerUseEvent();
#endif

/// 5.
// Add to the bottom of the file
#if defined(__SOUL_SYSTEM__)
EVENTFUNC(soul_timer_use_event)
{
	const item_vid_event_info* info = reinterpret_cast<const item_vid_event_info*>(event->info);
	if (info == nullptr)
		return 0;

	LPITEM item = ITEM_MANAGER::instance().FindByVID(info->item_vid);
	if (item == nullptr)
		return 0;

	auto data = item->GetSocket(2);
	if (data == 0)
		data = item->GetValue(2);

	auto keep_time = data / 10000;
	auto max_time = item->GetLimitValue(1);
	auto min_time = 60;
	auto remain_count = data % 10000;

	if (keep_time % min_time == 0 && keep_time > 0 && item->GetSocket(1) != TRUE)
		if (const auto& ch = item->GetOwner())
			ch->ChatPacket(CHAT_TYPE_INFO, LC_TEXT("[Soul System] Use %s to receive the effect."), item->GetName());

	if (keep_time >= max_time)
		return 0;

	auto new_data = ((keep_time + 1) * 10000) + remain_count;
	item->SetSocket(2, new_data, false /* log */);

	return PASSES_PER_SEC(test_server ? 1 : 60);
}

void CItem::StartSoulTimerUseEvent()
{
	if (m_pkSoulTimerUseEvent)
		return;

	item_vid_event_info* info = AllocEventInfo<item_vid_event_info>();
	info->item_vid = GetVID();
	m_pkSoulTimerUseEvent = event_create(soul_timer_use_event, info, PASSES_PER_SEC(test_server ? 1 : 60));
}

void CItem::ResetSoulTimerUseEvent()
{
	if (m_pkSoulTimerUseEvent)
		event_cancel(&m_pkSoulTimerUseEvent);

	StartSoulTimerUseEvent();
}
#endif
