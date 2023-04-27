""" 1. """
# Search
	def AddItemData(...

# Add above
	if app.ENABLE_SOUL_SYSTEM:
		def __SoulItemToolTip(self, itemVnum, metinSlot, flags):
			self.itemVnum = itemVnum
			item.SelectItem(itemVnum)
			itemType = item.GetItemType()
			itemSubType = item.GetItemSubType()

			(limit_Type, limit_Value) = item.GetLimit(1)
			max_time = limit_Value

			if 0 != flags:
				metinSlot[2] = item.GetValue(2)

			data = metinSlot[2]
			keep_time = data / 10000
			remain_count = data % 10000

			## value3,4,5
			value_index = 2 + keep_time / 60
			if value_index < 3:
				value_index = 3
			if value_index > 5:
				value_index = 5
			damage_value = float(item.GetValue(value_index) / 10.0)

			self.ClearToolTip()
			## board size
			soul_desc = ""
			if item.RED_SOUL == itemSubType:
				soul_desc = localeInfo.SOUL_ITEM_TOOLTIP_RED1 % (keep_time, max_time)
				soul_desc += localeInfo.SOUL_ITEM_TOOLTIP_RED2 % (damage_value)
			elif item.BLUE_SOUL == itemSubType:
				soul_desc = localeInfo.SOUL_ITEM_TOOLTIP_BLUE1 % (keep_time, max_time)
				soul_desc += localeInfo.SOUL_ITEM_TOOLTIP_BLUE2 % (damage_value)

			self.__AdjustMaxWidth(0, soul_desc)

			## 아이템 이름
			self.__SetNormalItemTitle()

			## desc
			board_width = self.__AdjustDescMaxWidth(soul_desc)
			if keep_time < 60:
				desc_color = 0xfff15f5f # RGB(241,95,95)
			else:
				desc_color = 0xff86e57f # RGB(134,229,127)

			self.AppendDescription(soul_desc, 26, desc_color)

			## PVP,변신,마운트 미적용
			self.AppendDescription(localeInfo.SOUL_ITEM_TOOLTIP_COMMON, 26, 0xfff15f5f) # RGB(241,95,95)
			self.AppendSpace(10)

			## 효과 적용/미적용
			if metinSlot[1] and keep_time >= 60 and remain_count > 0:
				self.AppendTextLine(localeInfo.SOUL_ITEM_TOOLTIP_APPLY, 0xff86e57f ) # RGB(134,229,127)
			else:
				self.AppendTextLine(localeInfo.SOUL_ITEM_TOOLTIP_UNAPPLIED, 0xfff15f5f ) # RGB(241,95,95)
			self.AppendSpace(5)

			## 남은 횟수 
			self.AppendTextLine(localeInfo.SOUL_ITEM_TOOLTIP_REMAIN_COUNT % remain_count)
			self.AppendSpace(5)

			## 남은 시간
			if 0 == flags:
				for i in xrange(item.LIMIT_MAX_NUM):
					(limitType, limitValue) = item.GetLimit(i)
					if item.LIMIT_REAL_TIME == limitType:
						self.AppendSoulItemLastTime(metinSlot[0])
			else:
				(limitType, limitValue) = item.GetLimit(0)
				self.AppendSoulItemLastTime(limitValue + app.GetGlobalTimeStamp())

			self.ShowToolTip()

		def AppendSoulItemLastTime(self, endTime):
			leftSec = max(0, endTime - app.GetGlobalTimeStamp())
			if leftSec > 0:
				self.AppendSpace(5)
				self.AppendTextLine(localeInfo.SOUL_ITEM_TOOLTIP_REMOVE_TIME + " : " + localeInfo.SecondToDHM(leftSec), self.NORMAL_COLOR)

""" 2. """
# Search
		itemDesc = item.GetItemDescription()

# Add above
		if app.ENABLE_SOUL_SYSTEM:
			if item.ITEM_TYPE_SOUL == itemType:
				self.__SoulItemToolTip(itemVnum, metinSlot, flags)
				return
