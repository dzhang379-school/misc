import sys
import Queue
# Dict mapping names to stations
stations = {}

class Station:
    def __init__(self, children):
        # list of station NAMES
        self.children = children
    def get_children(self):
        return self.children
    def add_child(self, child):
        self.children.append(child)


n = int(raw_input())
lines = []
for i in range(n+1):
    lines.append(raw_input().strip())

#print lines
#print lines[:-1]
#print lines[-1]

for line in lines[:-1]:
    station_list = line.split(' ')
    children = station_list[1:]
    station = Station(children)
    stations[station_list[0]] = station

endpoints = lines[-1].split(' ')
start = endpoints[0]
end = endpoints[1]

def search(start, end, visited):
    if start == end:
        return start
    else:
        visited.append(start)
        vertex = stations[start]
        for child in vertex.get_children():
            if child not in visited:
                return start + " " + search(child, end, visited) 
    return ""        

for key, val in stations.iteritems():
  print key
  print val.get_children()
print search(start, end, [start])
