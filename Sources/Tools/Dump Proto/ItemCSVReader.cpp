/// 1.
// Search @ int get_Item_Type_Value
	string arType[] = {

// Extend with
		"ITEM_SOUL",

/// 2.
// Search
	static string* arSubType[] = {

// Add above
	string arSub33[] = {
		"SOUL_RED",
		"SOUL_BLUE"
	};

/// 3.
// Search
	static string* arSubType[] = {

// Extend with
		arSub33,

/// 4.
// Search
	static int arNumberOfSubtype[] = {

// Extend with
		sizeof(arSub33) / sizeof(arSub33[0]),
