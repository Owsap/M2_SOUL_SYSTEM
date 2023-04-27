/// 1.
// Search
void initItem()

// Add above
#if defined(ENABLE_SOUL_SYSTEM)
PyObject* itemIsSoulItem(PyObject* poSelf, PyObject* poArgs)
{
	int iItemIndex;
	if (!PyTuple_GetInteger(poArgs, 0, &iItemIndex))
		return Py_BadArgument();

	CItemData* pItemData;
	if (!CItemManager::Instance().GetItemDataPointer(iItemIndex, &pItemData))
		return Py_BuildValue("b", false);

	if (pItemData->GetType() == CItemData::ITEM_TYPE_SOUL)
		return Py_BuildValue("b", true);

	return Py_BuildValue("b", false);
}
#endif

/// 2.
// Search
		{ NULL, NULL, NULL },

// Add above
#if defined(ENABLE_SOUL_SYSTEM)
		{ "IsSoulItem", itemIsSoulItem, METH_VARARGS },
#endif

/// 3.
// Add to the bottom of the file above }
#if defined(ENABLE_SOUL_SYSTEM)
	PyModule_AddIntConstant(poModule, "ITEM_TYPE_SOUL", CItemData::ITEM_TYPE_SOUL);

	PyModule_AddIntConstant(poModule, "RED_SOUL", CItemData::RED_SOUL);
	PyModule_AddIntConstant(poModule, "BLUE_SOUL", CItemData::BLUE_SOUL);
#endif
