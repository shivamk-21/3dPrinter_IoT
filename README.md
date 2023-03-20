# Malfunction Detection of 3D Printer
> using Vibrational Sensor

### 1. Introductiion

* The current world demands for Rapid Prototyping and Deployment.
* Conventional Manufacturing is not fast enough and require tasks like manufacturing, assembly and finishing.
* 3D Printing eliminates these tasks.
* But, 3D Printing is prone to various errors thus its monitoring is essential
* By Recording vibrations produced in the printer and then using Machine Learning Models we can predict if error is produced or not.

### 2. Concept Diagram

<p align='center'><img width=500 src=https://user-images.githubusercontent.com/98400026/226247967-fff653ab-cec4-460d-801c-d56606602615.png></p>

### 3. Circuit Connections

<p align='center'><img width=500 height=350 src="https://user-images.githubusercontent.com/98400026/226248101-51880551-90df-4d83-a748-af04359b4166.png"></p>

### 4. Working Principle 

* The Accelerometer of the above node is attached to the 3D Printer's bed.
* The Accelerometer captures the reading of the acceleration in X, Y and Z planes and then sends them to cloud every 15 seconds.
* Readings in both error-free conditions and in case of error were collected in the cloud.
* The collected data was used to train a model to predict the error and error-free readings.
* The WebApp Interface can be used to fetch data from the cloud and then apply the trained model to detect if any error has occured or was occured.
* RealTime updation of readings in cloud can be used to detect errors in RealTime.

### 5. Dataset Collection

* The node was attached to a 3D Printer and data was collected in the cloud.
* Sufficient data was collected in normal working condition.
* Few errors in printing was created and data was collected for that condition.
* Later the data was downloaded from the cloud and was mannualy labeled to be error or error-free.
* The split of error and error-free readings in total data was :<br>
![image](https://user-images.githubusercontent.com/98400026/226250199-a8da9bbd-f23d-4b0c-ba63-2fd39a5daa10.png)

### 6. Results

<p align=center>
<img width="500" height=350 src=https://user-images.githubusercontent.com/98400026/226248932-34d89f85-872f-4ed2-b601-fea0d3f31617.png>
<img width="500" height=350 src=https://user-images.githubusercontent.com/98400026/226248971-af2639c7-d625-484e-9d18-c1f39a735b1e.png>
<img width="500" height=350 src=https://user-images.githubusercontent.com/98400026/226249482-badcf487-e28f-488e-9051-20ec5b4958fe.png>
<img width="500" height=350 src=https://user-images.githubusercontent.com/98400026/226249032-6162ab52-03bc-473f-b317-87e2097857da.png>
</p>

### 7. Future Scope
* Making the Interface more Informational
* Use of more sensors to detect things like flow of filament
