#!/usr/bin/env python

from flask import Flask, render_template, request
import keras
import json
app = Flask(__name__)
model = keras.models.load_model('./lstm_test.h5')

@app.route('/')
def homepage():
  # get params
  # requests.args.get('param_key')
  print(type(model))

  return render_template('index.html')

if __name__ == "__main__":
  app.run(debug=True, host='localhost')