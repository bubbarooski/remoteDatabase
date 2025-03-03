'''
from flask import Flask

app = Flask(__name__)

@app.route('/')
def home():
    return '<h1>Flask REST API</h1>'

app.run(debug=True)
'''

import os
from ctypes import *

# .so file creation
if os.path.exists("../server/compiledLibraryFiles/database.so"):
    os.remove("../server/compiledLibraryFiles/database.so")
    os.system("cc -fPIC -shared -o ../server/compiledLibraryFiles/database.so ../server/database/database.c")
else:
    os.system("cc -fPIC -shared -o ../server/compiledLibraryFiles/database.so ../server/database/database.c")

databaseFile = "../server/compiledLibraryFiles/database.so"
database = CDLL(databaseFile)

database.databaseSetup()
database.databaseSearchWrapper.argtypes = [c_char_p]
database.databaseSearchWrapper.restype = None

while True:
    player = input("Enter player name: ")
    player = player.encode("utf-8")
    database.databaseSearchWrapper(player)


