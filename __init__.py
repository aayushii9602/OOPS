from distutils.log import debug
from pip import main
from flask import Flask

app = Flask(__name__)

@app.route("/")
def hello_world():
    return 'hello world'

if __name__=="__main__":
    app.run(debug=True)