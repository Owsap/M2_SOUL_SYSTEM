""" 1. """
# Search
					## 자동물약 (#72723, #72724) 특수처리 - 아이템인데도 슬롯에 활성화/비활성화 표시를 위한 작업임 - [hyo]
					if constInfo.IS_AUTO_POTION(itemIndex):
						# metinSocket - [0] : 활성화 여부, [1] : 사용한 양, [2] : 최대 용량
						metinSocket = [player.GetItemMetinSocket(window, Position, j) for j in xrange(player.METIN_SOCKET_MAX_NUM)]

						if 0 != int(metinSocket[0]):
							slot.ActivateSlot(slotNumber)
						else:
							slot.DeactivateSlot(slotNumber)

# Add below
					if app.ENABLE_SOUL_SYSTEM:
						if item.IsSoulItem(itemIndex):
							metinSocket = [player.GetItemMetinSocket(window, Position, j) for j in xrange(player.METIN_SOCKET_MAX_NUM)]

							if 0 != int(metinSocket[1]):
								slot.ActivateSlot(slotNumber)
							else:
								slot.DeactivateSlot(slotNumber)
