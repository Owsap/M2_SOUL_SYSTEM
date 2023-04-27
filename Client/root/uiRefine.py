""" 1. """
# Search
		dlgQuestion = uiCommon.QuestionDialog2()
		dlgQuestion.SetText2(localeInfo.REFINE_WARNING2)

# Add above
		if app.ENABLE_SOUL_SYSTEM:
			if 8 == self.type or 9 == self.type:
				self.Accept()
				return
