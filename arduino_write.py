import serial
import time
import aiohttp
import asyncio
from enturclient import EnturPublicTransportData
from datetime import datetime, timezone, timedelta
import pytz
import pdb
from entur import get_minutes_to_arrival

ser1 = serial.Serial('COM3', 9600)

while True:
    loop = asyncio.get_event_loop()
    minutes_to_arrival = loop.run_until_complete(get_minutes_to_arrival())
    if minutes_to_arrival < 10:
        minutes_to_arrival = str(minutes_to_arrival)

    time.sleep(2)
    ser1.write(minutes_to_arrival.encode())
    time.sleep(50)


