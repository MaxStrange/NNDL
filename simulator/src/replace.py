from os import listdir
from os.path import isfile, join
paths = [p for p in listdir(".") if isfile(join(".", p))]
for path in paths:
    lines = []
    try:
        print("Working on: " + str(path))
        with open(path, 'r') as f:
            lines = [line.replace("Synapse", "Synapse")\
                    for line in f]
        with open(path, 'w') as f:
            for line in lines:
                f.write(line)
    except UnicodeDecodeError:
        print("Failed on file: " + str(path))



