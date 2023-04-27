/// 1.
// Search
	bool RemoveAffect(DWORD dwType);

// Add below
#if defined(__SOUL_SYSTEM__)
	void RemoveAffect(DWORD dwType, BYTE bApplyType);
#endif

/// 2.
// Search
};

ESex GET_SEX(LPCHARACTER ch);

// Add above
#if defined(__SOUL_SYSTEM__)
public:
	void SoulItemProcess(ESoulSubType eSubType);
	void SoulRecoveryItemProcess();

	int GetSoulDamage(ESoulSubType eSubType) const;
	bool DoRefineSoul(LPITEM item);
#endif
