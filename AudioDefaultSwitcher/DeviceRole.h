﻿#pragma once
namespace AudioEndPoint {
	enum DeviceRole
	{
		rConsole = 0,
	    rMultimedia = (rConsole + 1),
		rCommunications = (rMultimedia + 1),
		rAll = (rCommunications + 1)
	};
}