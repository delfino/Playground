from xml.dom.minidom import parse

dom = parse("game.xml")

for node in dom.getElementsByTagName('unit'):
    print node.toxml()
