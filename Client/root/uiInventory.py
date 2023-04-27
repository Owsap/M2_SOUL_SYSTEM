""" 1. """
# Search
			## 자동물약 (HP: #72723 ~ #72726, SP: #72727 ~ #72730) 특수처리 - 아이템인데도 슬롯에 활성화/비활성화 표시를 위한 작업임 - [hyo]
			if constInfo.IS_AUTO_POTION(itemVnum):
				# metinSocket - [0] : 활성화 여부, [1] : 사용한 양, [2] : 최대 용량
				metinSocket = [player.GetItemMetinSocket(slotNumber, j) for j in xrange(player.METIN_SOCKET_MAX_NUM)]
				tempSlotNum = slotNumber
				if tempSlotNum >= player.INVENTORY_PAGE_SIZE:
					tempSlotNum -= (self.inventoryPageIndex * player.INVENTORY_PAGE_SIZE)

				isActivated = 0 != metinSocket[0]

				if isActivated:
					self.wndItem.ActivateSlot(tempSlotNum)
				else:
					self.wndItem.DeactivateSlot(tempSlotNum)

# Add below
			if app.ENABLE_SOUL_SYSTEM:
				if item.IsSoulItem(itemVnum):
					metinSocket = [player.GetItemMetinSocket(slotNumber, j) for j in xrange(player.METIN_SOCKET_MAX_NUM)]
					tempSlotNum = slotNumber
					if tempSlotNum >= player.INVENTORY_PAGE_SIZE:
						tempSlotNum -= (self.inventoryPageIndex * player.INVENTORY_PAGE_SIZE)

					if 0 != metinSocket[1]:
						self.wndItem.ActivateSlot(tempSlotNum)
					else:
						self.wndItem.DeactivateSlot(tempSlotNum)
