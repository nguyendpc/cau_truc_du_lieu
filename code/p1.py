# -*- coding: utf-8 -*-
"""
Created on Mon Nov  9 16:28:38 2020

@author: dpcng
"""


class Node:
    def __init__(self,value):
        self.value = value
        self.next = None
        
class DanhSachLK:
    def __init__(self):
        self.nutdau = None
        
    def inDanhSach(self):
        tam = self.nutdau
        while tam != None:
            print(tam.value)
            tam = tam.next
            
        
if __name__ == "__main__":
    danhsach = DanhSachLK()
    nuttam = None
    while True:
        print("nhap danh sach")
        vals = input()
        if vals == "0":
            break
        nutmoi = Node(vals)
        if danhsach.nutdau == None:
            danhsach.nutdau = nutmoi
        else:
            nuttam.next = nutmoi
        nuttam = nutmoi
    danhsach.inDanhSach()