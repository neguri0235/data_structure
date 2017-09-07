import unittest


class Queue():
    def __init__(self):
        self.data = []

    def enqueue(self,n):
        self.data.insert(0,n)

    def dequeue(self):
        return self.data.pop(0)

    def peek(self):
        return self.data[0]

    def empty(self):
        if len(self.data) == 0:
            return True
        else:
            return False

class QueueTest(unittest.TestCase):
    def Test(self): 
        q = Queue()
        self.assertTrue(q.empty())
        q.enqueue(1)
        q.enqueue(2)
        q.enqueue(3)
        q.enqueue(4)
        q.enqueue(5)
        q.enqueue(6)
        self.assertEqual(q.dequeue(),1)
        self.assertEqual(q.peek(),2)
        self.assertEqual(q.dequeue(),2)
        self.assertEqual(q.dequeue(),3)


