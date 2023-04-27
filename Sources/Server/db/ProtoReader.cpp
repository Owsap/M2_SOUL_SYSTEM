/// 1.
// Search @ int get_Item_Type_Value
	string arType[] = {

// Extend with
#if defined(__SOUL_SYSTEM__)
		"ITEM_SOUL",
#endif

/// 2.
// Search
	static string* arSubType[] = {

// Add above
#if defined(__SOUL_SYSTEM__)
	static string arSub34[] = {
		"SOUL_RED",
		"SOUL_BLUE"
	};
#endif

/// 3.
// Search
	static string* arSubType[] = {

// Extend with
#if defined(__SOUL_SYSTEM__)
		arSub34,
#endif

/// 4.
// Search
	static int arNumberOfSubtype[33] = {

// Extend with
#if defined(__SOUL_SYSTEM__)
		sizeof(arSub34) / sizeof(arSub34[0]),
#endif

// Search
	static int arNumberOfSubtype[33] = {

// Replace with
	static int arNumberOfSubtype[34] = {
