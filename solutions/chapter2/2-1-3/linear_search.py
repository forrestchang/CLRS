'''
Linear search
'''

def linear_serch(key, list):
	for i in range(0, len(list)):
		if key == list[i]:
			return i
		else:
			return -1
