/// 1.
// Search
	PyModule_AddIntConstant(poModule, "CAMERA_STOP", CPythonApplication::CAMERA_STOP);

// Add below
#if defined(ENABLE_SOUL_SYSTEM)
	PyModule_AddIntConstant(poModule, "ENABLE_SOUL_SYSTEM", 1);
#else
	PyModule_AddIntConstant(poModule, "ENABLE_SOUL_SYSTEM", 0);
#endif
