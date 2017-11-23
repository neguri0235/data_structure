'''
Created on 2017. 11. 24.

@author: neguri
'''
import unittest

class Permutation():
    def __init__(self):
        pass
    
    def checkPermutation(self, str1, str2):
        if len(str1) != len(str2):
            return False;
        
        str1 = ''.join(sorted(str1))
        str2 = ''.join(sorted(str2))
        if(str1 == str2):
            return True
        else:
            return False    


class Test(unittest.TestCase):
    def testName(self):
        p = Permutation()
        self.assertTrue(p.checkPermutation("abc", "cba"))
        self.assertTrue(p.checkPermutation("abcde", "bcaed"))
        self.assertFalse(p.checkPermutation("abcd","abde"))
        self.assertFalse(p.checkPermutation("abc", "ab"))
        pass


if __name__ == "__main__":
    #import sys;sys.argv = ['', 'Test.testName']
    unittest.main()
