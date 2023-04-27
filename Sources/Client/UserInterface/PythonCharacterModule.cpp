/// 1.
// Add to the bottom of the file above }
#ifdef ENABLE_SOUL_SYSTEM
	PyModule_AddIntConstant(poModule, "AFFECT_SOUL_RED", CInstanceBase::AFFECT_SOUL_RED);
	PyModule_AddIntConstant(poModule, "AFFECT_SOUL_BLUE", CInstanceBase::AFFECT_SOUL_BLUE);
	PyModule_AddIntConstant(poModule, "AFFECT_SOUL_MIX", CInstanceBase::AFFECT_SOUL_MIX);
#endif
