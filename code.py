import random
import time
import threading
import pygame
import os, sys, threading
from pygame.locals import *
if sys.platform in ["win32","win64"]: os.environ["SDL_VIDEO_CENTERED"]="1"
pygame.init()
size = (800,600)
surface = pygame.display.set_mode(size)	
pygame.display.set_caption("GUITAR HERO TEST DE REACCION")
#roja verde naranja azul

def lineas():
	red=(255, 0, 0)
	green=(0, 255, 0)
	blue=(0, 0, 255)
	black=(0,0,0)
	orange = (255,137,0)
	white=(255,255,255)
	pygame.draw.circle(surface,white,(100,520), 60,4)
	pygame.draw.circle(surface,white,(300,520), 60,4)
	pygame.draw.circle(surface,white,(500,520), 60,4)
	pygame.draw.circle(surface,white,(700,520), 60,4)
	pygame.draw.lines(surface,white,False,[(200,0),(200,600)],2)
	pygame.draw.lines(surface,white,False,[(400,0),(400,600)],2)
	pygame.draw.lines(surface,white,False,[(600,0),(600,600)],2)

def circulo(puntos):
	speed = 20
	posy = 0
	black=(0,0,0)
	multiplos = [0,60, 120, 180, 240, 300, 360, 420, 480, 540, 600, 660, 720, 780]
	for x in puntos:
		position = puntos.index(x)
		posx = x["posicion"]
		color = x["color"]
		posy = x["posy"] 
		posy = (posy + speed)
		#x["posy"] = posy
		if posy in multiplos:
			pygame.draw.circle(surface,color,(posx,x["posy"]), 56,0)
			lineas()
			x["posy"] = posy
			print " posicion en el array " + str(x["posy"])
		else:
			x["posy"] = posy
		if posy > 520:
			del puntos[position]
		clock = pygame.time.Clock()
		fps = 120
		draw = 0	
		clock.tick(fps)	
		for event in pygame.event.get():
			if event.type == pygame.QUIT:	
				pygame.quit()
				quit()		
puntos = []

while True:
	red=(255, 0, 0)
	green=(0, 255, 0)
	blue=(0, 0, 255)
	black=(0,0,0)

	orange = (255,137,0)
	list1 = [{"posicion":100,"color":red,"posy":0},{"posicion":300,"color":green,"posy":0},{"posicion":500,"color":orange,"posy":0},{"posicion":700,"color":blue,"posy":0}]  
	pos = random.choice(list1)
	puntos.append(pos)
	circulo(puntos)
	black=(0,0,0)
	pygame.display.update()
	surface.fill(black)
	for event in pygame.event.get():
		if event.type == pygame.QUIT: 
			pygame.quit()
			quit()
