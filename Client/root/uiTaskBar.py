""" 1. """
# Search
					## �ڵ����� (#72723, #72724) Ư��ó�� - �������ε��� ���Կ� Ȱ��ȭ/��Ȱ��ȭ ǥ�ø� ���� �۾��� - [hyo]
					if constInfo.IS_AUTO_POTION(itemIndex):
						# metinSocket - [0] : Ȱ��ȭ ����, [1] : ����� ��, [2] : �ִ� �뷮
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
