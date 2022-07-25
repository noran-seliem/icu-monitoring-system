# ICU-Realtime-monitoring-system
the system is monitoring the data of multiple patients in same room every patient has two sensors connected 
to him on an `arduino` and a led near him, the arduino is sending its data to the `ESP` through bluetooth module 
the data printed on serial is parsed as jason and the esp then send it to the `flask server` which stores it in a `firebase` 
data set, on the app side it reads the data from the data set and monitor it as a graph using `Flutter`.

```we need to add images of arduino and esp serial, flutter app, flutter code