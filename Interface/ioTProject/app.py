from flask import Flask, render_template
import datetime,json,joblib, pandas as pd,urllib.request as urllib2,numpy as np
import warnings
warnings.filterwarnings("ignore")
app = Flask(__name__, template_folder='templates')

def receive_data():
    conn = urllib2.urlopen("https://api.thingspeak.com/channels/1746090/feeds.json?api_key=R4AWQ5XBZY9DD09I&results=1")
    response = conn.read()
    data=json.loads(response)
    conn.close()
    return data['feeds'][0]['field2'],data['feeds'][0]['field3'],data['feeds'][0]['field4'],data['feeds'][0]['created_at']
def send_data(b):
    conn = urllib2.urlopen("https://api.thingspeak.com/update?api_key=QHDJ6BWKMC7M0JHQ&field1="+str(int(b)))
    conn.read()
    conn.close()
def recieve_error():
    conn = urllib2.urlopen("https://api.thingspeak.com/channels/1795159/feeds.json?api_key=AZBK5KZV7OPGN4ZD&results=1")
    response = conn.read()
    data=json.loads(response)
    conn.close()
    return data['feeds'][0]['created_at']
@app.route('/')
def index():
    x,y,z,t=receive_data()
    input_data=tuple([x,y,z])
    input_data_as_numpy_array = np.asarray(input_data)
    input_data_reshaped = input_data_as_numpy_array.reshape(1,3)
    df=pd.DataFrame(input_data_reshaped, )
    m_jlib = joblib.load('static//Trained_Model.joblib')
    prediction = m_jlib.predict(df)
    last=datetime.datetime.strptime(recieve_error(),"%Y-%m-%dT%H:%M:%SZ")
    if prediction==True:
      prediction="Error Detected"
      if (datetime.datetime.now()-datetime.datetime.strptime(t,"%Y-%m-%dT%H:%M:%SZ")).seconds<=15:
        send_data(True)
    else:
      prediction="Working Fine"
    return render_template('home.html',x=x,y=y,z=z,error=prediction,now=datetime.datetime.strptime(t,"%Y-%m-%dT%H:%M:%SZ"),last=last)


    





    
