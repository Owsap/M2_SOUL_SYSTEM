/// 1.
// Search
public:
	void SetSIGVnum(DWORD dwSIG)

// Add above
#if defined(__SOUL_SYSTEM__)
public:
	void StartSoulTimerUseEvent();
	void ResetSoulTimerUseEvent();
private:
	LPEVENT m_pkSoulTimerUseEvent;
#endif
