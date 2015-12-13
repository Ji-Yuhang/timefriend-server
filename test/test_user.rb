require 'socket'
require 'json'
socket = TcpSocket.new('localhost',5200)

login = {}
login[:controller] = "user"
login[:action] = "login"
login[:account] = "jiyuhang"
login[:password] = "jiyuhang110"
socket.write login.to_json + "\n"
re = socket.read
print re
