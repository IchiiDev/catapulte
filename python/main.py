#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
- Lecture de la température ambiante
- Lecture de la consigne
- Commande du chauffage
"""



# Les bibliothèques
#-------------------------
# il faut installer le module pyserial mais importer serial (sous ubuntu).
import time
import serial
# import PySimpleGUI as sg
import PySimpleGUIWeb as sg

# Définir le port série
#ser = serial.Serial('/dev/tty.usbserial', 9600)
#ser = serial.Serial('/dev/ttyACM0', 9600)
ser = serial.Serial('/dev/ttyACM0', 9600)


# Affichage des valeurs dans la console
def shoot():
    ser.write(b"on" + b"\n")
    time.sleep(0.1)
    ser.flushInput()
    ser.write(b"off" + b"\n")

sg.theme('DarkAmber')   # Add a touch of color
# All the stuff inside your window.
layout = [  [sg.Text('Appuyez sur le bouton pour tirer sur la catapulte')],
            [sg.Button('Lancer')] ]

# Create the Window
window = sg.Window('Catapulte', layout)
# Event Loop to process "events" and get the "values" of the inputs

loop = True
while loop == True:
    event = window.read()
    print(event)
    if event[0] == None: # if user closes window or clicks cancel
        loop = False
    if event[0] == "Lancer": shoot()

window.close()