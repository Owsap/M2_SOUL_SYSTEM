""" 1. """
# Search
			## �ڵ����� (HP: #72723 ~ #72726, SP: #72727 ~ #72730) Ư��ó�� - �������ε��� ���Կ� Ȱ��ȭ/��Ȱ��ȭ ǥ�ø� ���� �۾��� - [hyo]
			if constInfo.IS_AUTO_POTION(itemVnum):
				# metinSocket - [0] : Ȱ��ȭ ����, [1] : ����� ��, [2] : �ִ� �뷮
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
