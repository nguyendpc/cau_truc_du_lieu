# -*- coding: utf-8 -*-
"""
Created on Mon Nov  9 16:59:08 2020

@author: dpcng
"""


class Node:
    def __init__(self,value):
        self.value = value
        self.next = None
       
def inDanhSach(nutdau):
        tam = nutdau
        while tam != None:
            print(tam.value)
            tam = tam.next
    
if __name__ == "__main__":
    nutdau = None
    nuttam = None
    while True:
        print("nhap danh sach")
        vals = input()
        if vals == "0":
            break
        nutmoi = Node(vals)
        if nutdau == None:
            nutdau = nutmoi
        else:
            nuttam.next = nutmoi
        nuttam = nutmoi
    inDanhSach(nutdau)