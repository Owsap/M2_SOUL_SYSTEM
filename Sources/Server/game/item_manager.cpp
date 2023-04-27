/// 1.
// Search
	if (id == 0) // »õ·Î ¸¸µå´Â ¾ÆÀÌÅÛÀÏ ¶§¸¸ Ã³¸®
	{
		// »õ·ÎÃß°¡µÇ´Â ¾àÃÊµéÀÏ°æ¿ì ¼º´ÉÀ» ´Ù¸£°ÔÃ³¸®
		if (ITEM_BLEND == item->GetType())
		{
			if (Blend_Item_find(item->GetVnum()))
			{
				Blend_Item_set_value(item);
				return item;
			}
		}

// Add above
#if defined(__SOUL_SYSTEM__)
	if (item->GetType() == ITEM_SOUL)
		item->StartSoulTimerUseEvent();
#endif

/// 2.
// Search
void ITEM_MANAGER::CopyAllAttrTo(LPITEM pkOldItem, LPITEM pkNewItem)
{

// Add below
#if defined(__SOUL_SYSTEM__)
	if (pkOldItem == nullptr || pkNewItem == nullptr)
		return;

	if (pkOldItem->GetType() == ITEM_SOUL)
		return;
#endif
