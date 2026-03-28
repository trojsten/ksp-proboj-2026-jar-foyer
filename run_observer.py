#!/bin/env python
import http.server
import socketserver

PORT = 8000
DIRECTORY = "observer"  # change to the folder you want to serve

class Handler(http.server.SimpleHTTPRequestHandler):
    def __init__(self, *args, **kwargs):
        super().__init__(*args, directory=DIRECTORY, **kwargs)

    def log_message(self, format, *args):
        pass

    def log_request(self, code='-', size='-'):
        pass

with socketserver.TCPServer(("", PORT), Handler) as httpd:
    print(f"Serving {DIRECTORY} at http://localhost:{PORT}")
    httpd.serve_forever()
    
