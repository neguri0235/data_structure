#created on 2017. 11. 27.

@author: neguri
'''
import unittest

class URLify:
    def __init__(self):
        self.len = 0
        pass
    
    def conv(self, _str,n = 0):
        self.len = n
        c = []
        for i in range(self.len):
            if _str[i] != ' ':
                c.append(_str[i])
            else:
                c.append('%')
                c.append('2')
                c.append('0')
        r = ''.join(c)
        return r


class Test(unittest.TestCase):

    def testName(self):
        u = URLify()
        print(u.conv("Mr John Smith    ", 13))
        self.assertEqual("Mr%20John%20Smith",u.conv("Mr John Smith    ", 13),"String not Equal")
        pass


if __name__ == "__main__":
    #import sys;sys.argv = ['', 'Test.testName']
    unittest.main()
