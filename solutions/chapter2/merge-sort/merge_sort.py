'''
Merge sort
'''

def merge_sort(list):
	if len(list) <= 1:
		return list

	def merge(left, right):
		merged = [ ]
		while left and right:
			merged.append(left.pop(0) if left[0] <= right[0] else right.pop(0))
		while left:
			merged.append(left.pop(0))
		while right:
			merged.append(right.pop(0))

		return merged

	middle = int(len(list) / 2)
	left = merge_sort(list[:middle])
	right = merge_sort(list[middle:])
	return merge(left, right)
