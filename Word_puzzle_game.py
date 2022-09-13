'''                                 Word Puzzle Game
Problem Statement: You have to write a Word Puzzle Game in which the user has to form
the correct word out of a given set of characters. In the game the user has to solve this
puzzle for 5 words, one at a time. Problem words are stored in a list and appear to the user
in random sequence. Give the user score +1 for each correct answer and give -1 for each
wrong answer. At last print the final score. You can store any number of words in the list, but
in each round of the game only 5 words are shown to the user.
'''

import random
import os
A=['OAERELANP','REGEN','RAEHTF','TERELT','FSTIR','LTSA','OCPMUETR','XBO','LCCKO','NFA','TAC','BBLAOCAKRD','ELPHAENT','BKOO','YKE','SHCOLO','CEOLLGE','ENNEEGIR','CRCKIET','IDNAI','OODR']
D={0:'aeroplane',1:'green',2:'father',3:'letter',4:'first',5:'last',6:'computer',7:'box',8:'clock',9:'fan',10:'cat',11:'blackboard',12:'elephant',13:'book',14:'key',15:'school',16:'college',17:'engineer',18:'cricket',19:'india',20:'door'}
while 1:
    os.system('cls')
    print("Enter Choise number \n0.Exit \n1.Play")
    match int(input("==>")):
        case 1:
            temp,i,point=[],5,0
            while i:
                print("Arrange the letters to form a valid word:")
                while 1:
                    num=random.randint(0,20)
                    if(num not in temp):
                        break
                temp.append(num)
                print(A[num])
                if(input().lower()==D[num]):
                    print("\nCorrect\n")
                    point+=1
                else:
                    print("\nWrong\n")
                    point-=1
                i-=1
            print("\nNet Score is",point)
            if(point>=4):
                print("\t!!!...CONGRATULATION...!!!")
        case _:
            exit()
    input()