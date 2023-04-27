/// 1.
// Search @ PyObject* playerCanRefine
	if (pTargetItemData->HasNextGrade())
		return Py_BuildValue("i", REFINE_OK);
	else
		return Py_BuildValue("i", REFINE_NOT_NEXT_GRADE_ITEM);

	return Py_BuildValue("i", REFINE_CANT);

// Add above
#if defined(ENABLE_SOUL_SYSTEM)
	if ((pScrollItemData->GetValue(0) == 8 || pScrollItemData->GetValue(0) == 9) && (CItemData::ITEM_TYPE_SOUL != iTargetType))
		return Py_BuildValue("i", REFINE_CANT);

	if ((pScrollItemData->GetValue(0) != 8 && pScrollItemData->GetValue(0) != 9) && (CItemData::ITEM_TYPE_SOUL == iTargetType))
		return Py_BuildValue("i", REFINE_CANT);
#endif
