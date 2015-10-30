'''
Selection sort
'''

def selection_sort(list):
    for i in range(0, len(list)):
        minimum_number_index = i
        for j in range(i+1, len(list)):
            if list[i] < list[minimum_number_index]:
                minimum_number_index = i

        temp = list[i]
        list[i] = list[minimum_number_index]
        list[minimum_number_index] = temp

if __name__ == '__main__':
	test_list = [1, 4, 3, 6, 8, 0, 3]
	selection_sort(test_list)
	print(test_list)
