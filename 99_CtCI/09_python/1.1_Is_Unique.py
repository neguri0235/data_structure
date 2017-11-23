reated on 2017. 11. 24.

@author: neguri
'''
import unittest

class Unique():
    def __init__(self):
        self._list = [0]*26
    
    def IsUnique(self, str):
        for i in range(len(str)):
            c = ord(str[i]) - ord('a')
            if(self._list[c] == 0):
                self._list[c] = 1
            else:
                return False
        return True

class Test(unittest.TestCase):

    def testName(self):
        u = Unique()
        self.assertTrue(u.IsUnique("abc"))
        self.assertFalse(u.IsUnique("abca"))        
        self.assertFalse(u.IsUnique("abcdefgahijk"))
        pass


if __name__ == "__main__":
    #import sys;sys.argv = ['', 'Test.testName']
    unittest.main()
