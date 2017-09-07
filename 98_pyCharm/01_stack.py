import unittest

class Stack():
    def __init__(self,n):
        self.lists = []
        self.max_size = n

    def push(self,n):
        self.lists.append(n)

    def pop(self):
        return self.lists.pop()

    def peek(self):
        return self.lists[len(self.lists)-1]

    def isEmpty(self):
        if len(self.lists)==0:
            return True
        else:
            return False





class StackTest(unittest.TestCase):
    def test(self):
        st = Stack(10)
        self.assertTrue(st.isEmpty())
        st.push(1)
        st.push(2)
        st.push(3)
        st.push(4)
        st.push(5)
        self.assertEqual(st.peek(),5)
        self.assertEqual(st.pop(),5)
        self.assertEqual(st.pop(),4)
        self.assertEqual(st.pop(),3)
        self.assertEqual(st.pop(),2)


