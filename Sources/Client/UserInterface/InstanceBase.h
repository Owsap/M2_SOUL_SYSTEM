/// 1.
// Search
		AFFECT_WAR_FLAG3,

// Add below
#if defined(ENABLE_SOUL_SYSTEM)
		AFFECT_SOUL_RED,
		AFFECT_SOUL_BLUE,
		AFFECT_SOUL_MIX,
#endif

/// 2.
	// HORSE
	void __AttachHorseSaddle();
	void __DetachHorseSaddle();

// Add below
#if defined(ENABLE_SOUL_SYSTEM)
	void __SetSoulAffect(UINT eAffect, bool isVisible);
#endif
