import unittest


def bsort(a):
	print(a)
	for i in range(len(a)):
		for j in range(i+1,len(a)):
			if a[i] > a[j]:
				a[i],a[j] = a[j],a[i]
	return a


data = [3,2,5,1,7,4,9,0,6,3,6]
print(bsort(data))
