/// 1.
// Search @ enum EItemType
		ITEM_TYPE_MAX_NUM,

// Add above
#ifdef ENABLE_SOUL_SYSTEM
		ITEM_TYPE_SOUL,
#endif

/// 2.
// Search
	enum ELimitTypes

// Add above
#ifdef ENABLE_SOUL_SYSTEM
	enum ESoulSubType
	{
		RED_SOUL,
		BLUE_SOUL,
	};
#endif
