# 재귀호출 제한 늘린다 파이썬 재귀호출 기본이 1000
import sys

#노드정보담기 위한 클래스
class Node:
    def __init__(self, id, x, y):
        self.id = id
        self.x = x
        self.y = y
        self.left = None
        self.right = None
        
    def __lt__(self, other): # < 비교연산자를 통해 비교 기본적으로 오름차순
        if(self.y == other.y):
            return self.x < other.x
        
        return self.y > other.y
    
# 이진트리 형태로 구성    
def addNode(parent, child):
    if child.x < parent.x:
        if parent.left is None:
            parent.left = child
        else:
            addNode(parent.left, child)
    else:
        if parent.right is None:
            parent.right = child
        else:
            addNode(parent.right, child)
            
# 전위순회            
def preorder(ans, node):
    if node is None:
        return
    ans.append(node.id)
    # 재귀호출 전위순회는 왼쪽 노드부터 방문
    preorder(ans, node.left)
    preorder(ans, node.right)

# 후위순회
def postorder(ans, node):
    if node is None:
        return
    postorder(ans, node.left)
    postorder(ans, node.right)
    ans.append(node.id)
    
def solution(nodeinfo):
    sys.setrecursionlimit(1500)
    size = len(nodeinfo)
    nodelist = []
    for i in range(size):
        nodelist.append(Node((i+1), nodeinfo[i][0], nodeinfo[i][1]))
    
    nodelist.sort()
    root = nodelist[0] # 루트
    for i in range(1, size):
        addNode(root, nodelist[i])
    
    #전위순회, 후위순회
    answer = [[],[]]
    #answer 첫번째, 두번째에 기록, 시작은 root
    preorder(answer[0], root)
    postorder(answer[1], root)
    
    
    
    return answer