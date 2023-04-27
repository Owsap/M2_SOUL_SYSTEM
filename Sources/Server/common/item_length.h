/// 1.
// Search
enum EItemTypes

// Extend with
#if defined(__SOUL_SYSTEM__)
	ITEM_SOUL,
#endif

/// 2.
// Search
enum EItemFlag

// Add above
#if defined(__SOUL_SYSTEM__)
enum ESoulSubType
{
	RED_SOUL,
	BLUE_SOUL
};
#endif

/// 2.
// Search
enum ERefineType

// Extend with
#if defined(__SOUL_SYSTEM__)
	REFINE_TYPE_SOUL_AWAKE,
	REFINE_TYPE_SOUL_EVOLVE,
#endif

/// 3.
// Add to the bottom of the file above #endif
#if defined(__SOUL_SYSTEM__)
enum ESoulGradeType
{
	SOUL_GRADE_BASIC,
	SOUL_GRADE_GLEAMING,
	SOUL_GRADE_LUSTROUS,
	SOUL_GRADE_PRISMATIC,
	SOUL_GRADE_ILUMINED,
	SOUL_GRADE_MAX,
};
#endif
