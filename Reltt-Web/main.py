from flask import Flask
app = Flask(__name__)

@app.route('/')
def hello_world():
    return render_template('hello.html', name=name)

app.run(host="127.0.0.1",port=5555,debug=True)