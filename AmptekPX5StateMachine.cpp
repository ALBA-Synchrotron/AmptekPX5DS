/*----- PROTECTED REGION ID(AmptekPX5StateMachine.cpp) ENABLED START -----*/
static const char *RcsId = "$Id:  $";
//=============================================================================
//
// file :        AmptekPX5StateMachine.cpp
//
// description : C++ source for the �name� and its alowed
//               methods for commands and attributes
//
// project :     AmptekPX5.
//
// $Author:  $
//
// $Revision:  $
// $Date:  $
//
// SVN only:
// $HeadURL:  $
//
// CVS only:
// $Source:  $
// $Log:  $
//
//=============================================================================
//                This file is generated by POGO
//        (Program Obviously used to Generate tango Object)
//=============================================================================



#include <AmptekPX5.h>
#include <AmptekPX5Class.h>

/*----- PROTECTED REGION END -----*/	//	AmptekPX5::AmptekPX5StateMachine.cpp

//================================================================
//  States  |  Description
//================================================================
//  MOVING  |  
//  ALARM   |  


namespace AmptekPX5_ns
{
//=================================================
//		Attributes Allowed Methods
//=================================================

//--------------------------------------------------------
/**
 *	Method      : AmptekPX5::is_AcquisitionTime_allowed()
 *	Description : Execution allowed for AcquisitionTime attribute
 */
//--------------------------------------------------------
bool AmptekPX5::is_AcquisitionTime_allowed(TANGO_UNUSED(Tango::AttReqType type))
{
	//	Check access type.
	if ( type!=Tango::READ_REQ )
	{
		//	Compare device state with not allowed states for WRITE 
		if (get_state()==Tango::MOVING)
		{
		/*----- PROTECTED REGION ID(AmptekPX5::AcquisitionTimeStateAllowed_WRITE) ENABLED START -----*/

	/*----- PROTECTED REGION END -----*/	//	AmptekPX5::AcquisitionTimeStateAllowed_WRITE
			return false;
		}
		return true;
	}
	else

	//	Not any excluded states for AcquisitionTime attribute in read access.
	/*----- PROTECTED REGION ID(AmptekPX5::AcquisitionTimeStateAllowed_READ) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	AmptekPX5::AcquisitionTimeStateAllowed_READ
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : AmptekPX5::is_AuxOut1_allowed()
 *	Description : Execution allowed for AuxOut1 attribute
 */
//--------------------------------------------------------
bool AmptekPX5::is_AuxOut1_allowed(TANGO_UNUSED(Tango::AttReqType type))
{
	//	Not any excluded states for AuxOut1 attribute in Write access.
	/*----- PROTECTED REGION ID(AmptekPX5::AuxOut1StateAllowed_WRITE) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	AmptekPX5::AuxOut1StateAllowed_WRITE

	//	Not any excluded states for AuxOut1 attribute in read access.
	/*----- PROTECTED REGION ID(AmptekPX5::AuxOut1StateAllowed_READ) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	AmptekPX5::AuxOut1StateAllowed_READ
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : AmptekPX5::is_Clock_allowed()
 *	Description : Execution allowed for Clock attribute
 */
//--------------------------------------------------------
bool AmptekPX5::is_Clock_allowed(TANGO_UNUSED(Tango::AttReqType type))
{
	//	Check access type.
	if ( type!=Tango::READ_REQ )
	{
		//	Compare device state with not allowed states for WRITE 
		if (get_state()==Tango::MOVING)
		{
		/*----- PROTECTED REGION ID(AmptekPX5::ClockStateAllowed_WRITE) ENABLED START -----*/

	/*----- PROTECTED REGION END -----*/	//	AmptekPX5::ClockStateAllowed_WRITE
			return false;
		}
		return true;
	}
	else

	//	Not any excluded states for Clock attribute in read access.
	/*----- PROTECTED REGION ID(AmptekPX5::ClockStateAllowed_READ) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	AmptekPX5::ClockStateAllowed_READ
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : AmptekPX5::is_CoarseGain_allowed()
 *	Description : Execution allowed for CoarseGain attribute
 */
//--------------------------------------------------------
bool AmptekPX5::is_CoarseGain_allowed(TANGO_UNUSED(Tango::AttReqType type))
{
	//	Check access type.
	if ( type!=Tango::READ_REQ )
	{
		//	Compare device state with not allowed states for WRITE 
		if (get_state()==Tango::MOVING)
		{
		/*----- PROTECTED REGION ID(AmptekPX5::CoarseGainStateAllowed_WRITE) ENABLED START -----*/

	/*----- PROTECTED REGION END -----*/	//	AmptekPX5::CoarseGainStateAllowed_WRITE
			return false;
		}
		return true;
	}
	else

	//	Not any excluded states for CoarseGain attribute in read access.
	/*----- PROTECTED REGION ID(AmptekPX5::CoarseGainStateAllowed_READ) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	AmptekPX5::CoarseGainStateAllowed_READ
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : AmptekPX5::is_Con1_allowed()
 *	Description : Execution allowed for Con1 attribute
 */
//--------------------------------------------------------
bool AmptekPX5::is_Con1_allowed(TANGO_UNUSED(Tango::AttReqType type))
{
	//	Not any excluded states for Con1 attribute in Write access.
	/*----- PROTECTED REGION ID(AmptekPX5::Con1StateAllowed_WRITE) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	AmptekPX5::Con1StateAllowed_WRITE

	//	Not any excluded states for Con1 attribute in read access.
	/*----- PROTECTED REGION ID(AmptekPX5::Con1StateAllowed_READ) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	AmptekPX5::Con1StateAllowed_READ
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : AmptekPX5::is_DeadTime_allowed()
 *	Description : Execution allowed for DeadTime attribute
 */
//--------------------------------------------------------
bool AmptekPX5::is_DeadTime_allowed(TANGO_UNUSED(Tango::AttReqType type))
{

	//	Not any excluded states for DeadTime attribute in read access.
	/*----- PROTECTED REGION ID(AmptekPX5::DeadTimeStateAllowed_READ) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	AmptekPX5::DeadTimeStateAllowed_READ
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : AmptekPX5::is_FastCount_allowed()
 *	Description : Execution allowed for FastCount attribute
 */
//--------------------------------------------------------
bool AmptekPX5::is_FastCount_allowed(TANGO_UNUSED(Tango::AttReqType type))
{

	//	Not any excluded states for FastCount attribute in read access.
	/*----- PROTECTED REGION ID(AmptekPX5::FastCountStateAllowed_READ) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	AmptekPX5::FastCountStateAllowed_READ
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : AmptekPX5::is_FineGain_allowed()
 *	Description : Execution allowed for FineGain attribute
 */
//--------------------------------------------------------
bool AmptekPX5::is_FineGain_allowed(TANGO_UNUSED(Tango::AttReqType type))
{
	//	Check access type.
	if ( type!=Tango::READ_REQ )
	{
		//	Compare device state with not allowed states for WRITE 
		if (get_state()==Tango::MOVING)
		{
		/*----- PROTECTED REGION ID(AmptekPX5::FineGainStateAllowed_WRITE) ENABLED START -----*/

	/*----- PROTECTED REGION END -----*/	//	AmptekPX5::FineGainStateAllowed_WRITE
			return false;
		}
		return true;
	}
	else

	//	Not any excluded states for FineGain attribute in read access.
	/*----- PROTECTED REGION ID(AmptekPX5::FineGainStateAllowed_READ) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	AmptekPX5::FineGainStateAllowed_READ
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : AmptekPX5::is_FlatTopWidth_allowed()
 *	Description : Execution allowed for FlatTopWidth attribute
 */
//--------------------------------------------------------
bool AmptekPX5::is_FlatTopWidth_allowed(TANGO_UNUSED(Tango::AttReqType type))
{
	//	Check access type.
	if ( type!=Tango::READ_REQ )
	{
		//	Compare device state with not allowed states for WRITE 
		if (get_state()==Tango::MOVING)
		{
		/*----- PROTECTED REGION ID(AmptekPX5::FlatTopWidthStateAllowed_WRITE) ENABLED START -----*/

	/*----- PROTECTED REGION END -----*/	//	AmptekPX5::FlatTopWidthStateAllowed_WRITE
			return false;
		}
		return true;
	}
	else

	//	Not any excluded states for FlatTopWidth attribute in read access.
	/*----- PROTECTED REGION ID(AmptekPX5::FlatTopWidthStateAllowed_READ) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	AmptekPX5::FlatTopWidthStateAllowed_READ
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : AmptekPX5::is_MCAC_allowed()
 *	Description : Execution allowed for MCAC attribute
 */
//--------------------------------------------------------
bool AmptekPX5::is_MCAC_allowed(TANGO_UNUSED(Tango::AttReqType type))
{
	//	Check access type.
	if ( type!=Tango::READ_REQ )
	{
		//	Compare device state with not allowed states for WRITE 
		if (get_state()==Tango::MOVING)
		{
		/*----- PROTECTED REGION ID(AmptekPX5::MCACStateAllowed_WRITE) ENABLED START -----*/

	/*----- PROTECTED REGION END -----*/	//	AmptekPX5::MCACStateAllowed_WRITE
			return false;
		}
		return true;
	}
	else

	//	Not any excluded states for MCAC attribute in read access.
	/*----- PROTECTED REGION ID(AmptekPX5::MCACStateAllowed_READ) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	AmptekPX5::MCACStateAllowed_READ
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : AmptekPX5::is_PeakingTime_allowed()
 *	Description : Execution allowed for PeakingTime attribute
 */
//--------------------------------------------------------
bool AmptekPX5::is_PeakingTime_allowed(TANGO_UNUSED(Tango::AttReqType type))
{
	//	Check access type.
	if ( type!=Tango::READ_REQ )
	{
		//	Compare device state with not allowed states for WRITE 
		if (get_state()==Tango::MOVING)
		{
		/*----- PROTECTED REGION ID(AmptekPX5::PeakingTimeStateAllowed_WRITE) ENABLED START -----*/

	/*----- PROTECTED REGION END -----*/	//	AmptekPX5::PeakingTimeStateAllowed_WRITE
			return false;
		}
		return true;
	}
	else

	//	Not any excluded states for PeakingTime attribute in read access.
	/*----- PROTECTED REGION ID(AmptekPX5::PeakingTimeStateAllowed_READ) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	AmptekPX5::PeakingTimeStateAllowed_READ
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : AmptekPX5::is_PileupReject_allowed()
 *	Description : Execution allowed for PileupReject attribute
 */
//--------------------------------------------------------
bool AmptekPX5::is_PileupReject_allowed(TANGO_UNUSED(Tango::AttReqType type))
{
	//	Check access type.
	if ( type!=Tango::READ_REQ )
	{
		//	Compare device state with not allowed states for WRITE 
		if (get_state()==Tango::MOVING)
		{
		/*----- PROTECTED REGION ID(AmptekPX5::PileupRejectStateAllowed_WRITE) ENABLED START -----*/

	/*----- PROTECTED REGION END -----*/	//	AmptekPX5::PileupRejectStateAllowed_WRITE
			return false;
		}
		return true;
	}
	else

	//	Not any excluded states for PileupReject attribute in read access.
	/*----- PROTECTED REGION ID(AmptekPX5::PileupRejectStateAllowed_READ) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	AmptekPX5::PileupRejectStateAllowed_READ
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : AmptekPX5::is_SCA1HT_allowed()
 *	Description : Execution allowed for SCA1HT attribute
 */
//--------------------------------------------------------
bool AmptekPX5::is_SCA1HT_allowed(TANGO_UNUSED(Tango::AttReqType type))
{
	//	Not any excluded states for SCA1HT attribute in Write access.
	/*----- PROTECTED REGION ID(AmptekPX5::SCA1HTStateAllowed_WRITE) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	AmptekPX5::SCA1HTStateAllowed_WRITE

	//	Not any excluded states for SCA1HT attribute in read access.
	/*----- PROTECTED REGION ID(AmptekPX5::SCA1HTStateAllowed_READ) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	AmptekPX5::SCA1HTStateAllowed_READ
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : AmptekPX5::is_SCA1LT_allowed()
 *	Description : Execution allowed for SCA1LT attribute
 */
//--------------------------------------------------------
bool AmptekPX5::is_SCA1LT_allowed(TANGO_UNUSED(Tango::AttReqType type))
{
	//	Not any excluded states for SCA1LT attribute in Write access.
	/*----- PROTECTED REGION ID(AmptekPX5::SCA1LTStateAllowed_WRITE) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	AmptekPX5::SCA1LTStateAllowed_WRITE

	//	Not any excluded states for SCA1LT attribute in read access.
	/*----- PROTECTED REGION ID(AmptekPX5::SCA1LTStateAllowed_READ) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	AmptekPX5::SCA1LTStateAllowed_READ
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : AmptekPX5::is_SCA2HT_allowed()
 *	Description : Execution allowed for SCA2HT attribute
 */
//--------------------------------------------------------
bool AmptekPX5::is_SCA2HT_allowed(TANGO_UNUSED(Tango::AttReqType type))
{
	//	Not any excluded states for SCA2HT attribute in Write access.
	/*----- PROTECTED REGION ID(AmptekPX5::SCA2HTStateAllowed_WRITE) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	AmptekPX5::SCA2HTStateAllowed_WRITE

	//	Not any excluded states for SCA2HT attribute in read access.
	/*----- PROTECTED REGION ID(AmptekPX5::SCA2HTStateAllowed_READ) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	AmptekPX5::SCA2HTStateAllowed_READ
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : AmptekPX5::is_SCA2LT_allowed()
 *	Description : Execution allowed for SCA2LT attribute
 */
//--------------------------------------------------------
bool AmptekPX5::is_SCA2LT_allowed(TANGO_UNUSED(Tango::AttReqType type))
{
	//	Not any excluded states for SCA2LT attribute in Write access.
	/*----- PROTECTED REGION ID(AmptekPX5::SCA2LTStateAllowed_WRITE) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	AmptekPX5::SCA2LTStateAllowed_WRITE

	//	Not any excluded states for SCA2LT attribute in read access.
	/*----- PROTECTED REGION ID(AmptekPX5::SCA2LTStateAllowed_READ) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	AmptekPX5::SCA2LTStateAllowed_READ
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : AmptekPX5::is_SCA3HT_allowed()
 *	Description : Execution allowed for SCA3HT attribute
 */
//--------------------------------------------------------
bool AmptekPX5::is_SCA3HT_allowed(TANGO_UNUSED(Tango::AttReqType type))
{
	//	Not any excluded states for SCA3HT attribute in Write access.
	/*----- PROTECTED REGION ID(AmptekPX5::SCA3HTStateAllowed_WRITE) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	AmptekPX5::SCA3HTStateAllowed_WRITE

	//	Not any excluded states for SCA3HT attribute in read access.
	/*----- PROTECTED REGION ID(AmptekPX5::SCA3HTStateAllowed_READ) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	AmptekPX5::SCA3HTStateAllowed_READ
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : AmptekPX5::is_SCA3LT_allowed()
 *	Description : Execution allowed for SCA3LT attribute
 */
//--------------------------------------------------------
bool AmptekPX5::is_SCA3LT_allowed(TANGO_UNUSED(Tango::AttReqType type))
{
	//	Not any excluded states for SCA3LT attribute in Write access.
	/*----- PROTECTED REGION ID(AmptekPX5::SCA3LTStateAllowed_WRITE) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	AmptekPX5::SCA3LTStateAllowed_WRITE

	//	Not any excluded states for SCA3LT attribute in read access.
	/*----- PROTECTED REGION ID(AmptekPX5::SCA3LTStateAllowed_READ) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	AmptekPX5::SCA3LTStateAllowed_READ
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : AmptekPX5::is_SCA4HT_allowed()
 *	Description : Execution allowed for SCA4HT attribute
 */
//--------------------------------------------------------
bool AmptekPX5::is_SCA4HT_allowed(TANGO_UNUSED(Tango::AttReqType type))
{
	//	Not any excluded states for SCA4HT attribute in Write access.
	/*----- PROTECTED REGION ID(AmptekPX5::SCA4HTStateAllowed_WRITE) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	AmptekPX5::SCA4HTStateAllowed_WRITE

	//	Not any excluded states for SCA4HT attribute in read access.
	/*----- PROTECTED REGION ID(AmptekPX5::SCA4HTStateAllowed_READ) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	AmptekPX5::SCA4HTStateAllowed_READ
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : AmptekPX5::is_SCA4LT_allowed()
 *	Description : Execution allowed for SCA4LT attribute
 */
//--------------------------------------------------------
bool AmptekPX5::is_SCA4LT_allowed(TANGO_UNUSED(Tango::AttReqType type))
{
	//	Not any excluded states for SCA4LT attribute in Write access.
	/*----- PROTECTED REGION ID(AmptekPX5::SCA4LTStateAllowed_WRITE) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	AmptekPX5::SCA4LTStateAllowed_WRITE

	//	Not any excluded states for SCA4LT attribute in read access.
	/*----- PROTECTED REGION ID(AmptekPX5::SCA4LTStateAllowed_READ) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	AmptekPX5::SCA4LTStateAllowed_READ
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : AmptekPX5::is_SCA5HT_allowed()
 *	Description : Execution allowed for SCA5HT attribute
 */
//--------------------------------------------------------
bool AmptekPX5::is_SCA5HT_allowed(TANGO_UNUSED(Tango::AttReqType type))
{
	//	Not any excluded states for SCA5HT attribute in Write access.
	/*----- PROTECTED REGION ID(AmptekPX5::SCA5HTStateAllowed_WRITE) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	AmptekPX5::SCA5HTStateAllowed_WRITE

	//	Not any excluded states for SCA5HT attribute in read access.
	/*----- PROTECTED REGION ID(AmptekPX5::SCA5HTStateAllowed_READ) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	AmptekPX5::SCA5HTStateAllowed_READ
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : AmptekPX5::is_SCA5LT_allowed()
 *	Description : Execution allowed for SCA5LT attribute
 */
//--------------------------------------------------------
bool AmptekPX5::is_SCA5LT_allowed(TANGO_UNUSED(Tango::AttReqType type))
{
	//	Not any excluded states for SCA5LT attribute in Write access.
	/*----- PROTECTED REGION ID(AmptekPX5::SCA5LTStateAllowed_WRITE) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	AmptekPX5::SCA5LTStateAllowed_WRITE

	//	Not any excluded states for SCA5LT attribute in read access.
	/*----- PROTECTED REGION ID(AmptekPX5::SCA5LTStateAllowed_READ) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	AmptekPX5::SCA5LTStateAllowed_READ
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : AmptekPX5::is_SCA6HT_allowed()
 *	Description : Execution allowed for SCA6HT attribute
 */
//--------------------------------------------------------
bool AmptekPX5::is_SCA6HT_allowed(TANGO_UNUSED(Tango::AttReqType type))
{
	//	Not any excluded states for SCA6HT attribute in Write access.
	/*----- PROTECTED REGION ID(AmptekPX5::SCA6HTStateAllowed_WRITE) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	AmptekPX5::SCA6HTStateAllowed_WRITE

	//	Not any excluded states for SCA6HT attribute in read access.
	/*----- PROTECTED REGION ID(AmptekPX5::SCA6HTStateAllowed_READ) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	AmptekPX5::SCA6HTStateAllowed_READ
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : AmptekPX5::is_SCA6LT_allowed()
 *	Description : Execution allowed for SCA6LT attribute
 */
//--------------------------------------------------------
bool AmptekPX5::is_SCA6LT_allowed(TANGO_UNUSED(Tango::AttReqType type))
{
	//	Not any excluded states for SCA6LT attribute in Write access.
	/*----- PROTECTED REGION ID(AmptekPX5::SCA6LTStateAllowed_WRITE) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	AmptekPX5::SCA6LTStateAllowed_WRITE

	//	Not any excluded states for SCA6LT attribute in read access.
	/*----- PROTECTED REGION ID(AmptekPX5::SCA6LTStateAllowed_READ) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	AmptekPX5::SCA6LTStateAllowed_READ
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : AmptekPX5::is_SCA7HT_allowed()
 *	Description : Execution allowed for SCA7HT attribute
 */
//--------------------------------------------------------
bool AmptekPX5::is_SCA7HT_allowed(TANGO_UNUSED(Tango::AttReqType type))
{
	//	Not any excluded states for SCA7HT attribute in Write access.
	/*----- PROTECTED REGION ID(AmptekPX5::SCA7HTStateAllowed_WRITE) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	AmptekPX5::SCA7HTStateAllowed_WRITE

	//	Not any excluded states for SCA7HT attribute in read access.
	/*----- PROTECTED REGION ID(AmptekPX5::SCA7HTStateAllowed_READ) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	AmptekPX5::SCA7HTStateAllowed_READ
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : AmptekPX5::is_SCA7LT_allowed()
 *	Description : Execution allowed for SCA7LT attribute
 */
//--------------------------------------------------------
bool AmptekPX5::is_SCA7LT_allowed(TANGO_UNUSED(Tango::AttReqType type))
{
	//	Not any excluded states for SCA7LT attribute in Write access.
	/*----- PROTECTED REGION ID(AmptekPX5::SCA7LTStateAllowed_WRITE) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	AmptekPX5::SCA7LTStateAllowed_WRITE

	//	Not any excluded states for SCA7LT attribute in read access.
	/*----- PROTECTED REGION ID(AmptekPX5::SCA7LTStateAllowed_READ) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	AmptekPX5::SCA7LTStateAllowed_READ
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : AmptekPX5::is_SCA8HT_allowed()
 *	Description : Execution allowed for SCA8HT attribute
 */
//--------------------------------------------------------
bool AmptekPX5::is_SCA8HT_allowed(TANGO_UNUSED(Tango::AttReqType type))
{
	//	Not any excluded states for SCA8HT attribute in Write access.
	/*----- PROTECTED REGION ID(AmptekPX5::SCA8HTStateAllowed_WRITE) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	AmptekPX5::SCA8HTStateAllowed_WRITE

	//	Not any excluded states for SCA8HT attribute in read access.
	/*----- PROTECTED REGION ID(AmptekPX5::SCA8HTStateAllowed_READ) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	AmptekPX5::SCA8HTStateAllowed_READ
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : AmptekPX5::is_SCA8LT_allowed()
 *	Description : Execution allowed for SCA8LT attribute
 */
//--------------------------------------------------------
bool AmptekPX5::is_SCA8LT_allowed(TANGO_UNUSED(Tango::AttReqType type))
{
	//	Not any excluded states for SCA8LT attribute in Write access.
	/*----- PROTECTED REGION ID(AmptekPX5::SCA8LTStateAllowed_WRITE) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	AmptekPX5::SCA8LTStateAllowed_WRITE

	//	Not any excluded states for SCA8LT attribute in read access.
	/*----- PROTECTED REGION ID(AmptekPX5::SCA8LTStateAllowed_READ) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	AmptekPX5::SCA8LTStateAllowed_READ
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : AmptekPX5::is_SlowCount_allowed()
 *	Description : Execution allowed for SlowCount attribute
 */
//--------------------------------------------------------
bool AmptekPX5::is_SlowCount_allowed(TANGO_UNUSED(Tango::AttReqType type))
{

	//	Not any excluded states for SlowCount attribute in read access.
	/*----- PROTECTED REGION ID(AmptekPX5::SlowCountStateAllowed_READ) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	AmptekPX5::SlowCountStateAllowed_READ
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : AmptekPX5::is_TotalGain_allowed()
 *	Description : Execution allowed for TotalGain attribute
 */
//--------------------------------------------------------
bool AmptekPX5::is_TotalGain_allowed(TANGO_UNUSED(Tango::AttReqType type))
{

	//	Not any excluded states for TotalGain attribute in read access.
	/*----- PROTECTED REGION ID(AmptekPX5::TotalGainStateAllowed_READ) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	AmptekPX5::TotalGainStateAllowed_READ
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : AmptekPX5::is_Spectrum_allowed()
 *	Description : Execution allowed for Spectrum attribute
 */
//--------------------------------------------------------
bool AmptekPX5::is_Spectrum_allowed(TANGO_UNUSED(Tango::AttReqType type))
{

	//	Not any excluded states for Spectrum attribute in read access.
	/*----- PROTECTED REGION ID(AmptekPX5::SpectrumStateAllowed_READ) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	AmptekPX5::SpectrumStateAllowed_READ
	return true;
}

//=================================================
//		Commands Allowed Methods
//=================================================

//--------------------------------------------------------
/**
 *	Method      : AmptekPX5::is_SetTextConfiguration_allowed()
 *	Description : Execution allowed for SetTextConfiguration attribute
 */
//--------------------------------------------------------
bool AmptekPX5::is_SetTextConfiguration_allowed(TANGO_UNUSED(const CORBA::Any &any))
{
	//	Not any excluded states for SetTextConfiguration command.
	/*----- PROTECTED REGION ID(AmptekPX5::SetTextConfigurationStateAllowed) ENABLED START -----*/

	/*----- PROTECTED REGION END -----*/	//	AmptekPX5::SetTextConfigurationStateAllowed
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : AmptekPX5::is_GetTextConfiguration_allowed()
 *	Description : Execution allowed for GetTextConfiguration attribute
 */
//--------------------------------------------------------
bool AmptekPX5::is_GetTextConfiguration_allowed(TANGO_UNUSED(const CORBA::Any &any))
{
	//	Not any excluded states for GetTextConfiguration command.
	/*----- PROTECTED REGION ID(AmptekPX5::GetTextConfigurationStateAllowed) ENABLED START -----*/

	/*----- PROTECTED REGION END -----*/	//	AmptekPX5::GetTextConfigurationStateAllowed
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : AmptekPX5::is_Echo_allowed()
 *	Description : Execution allowed for Echo attribute
 */
//--------------------------------------------------------
bool AmptekPX5::is_Echo_allowed(TANGO_UNUSED(const CORBA::Any &any))
{
	//	Not any excluded states for Echo command.
	/*----- PROTECTED REGION ID(AmptekPX5::EchoStateAllowed) ENABLED START -----*/

	/*----- PROTECTED REGION END -----*/	//	AmptekPX5::EchoStateAllowed
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : AmptekPX5::is_Enable_allowed()
 *	Description : Execution allowed for Enable attribute
 */
//--------------------------------------------------------
bool AmptekPX5::is_Enable_allowed(TANGO_UNUSED(const CORBA::Any &any))
{
	//	Not any excluded states for Enable command.
	/*----- PROTECTED REGION ID(AmptekPX5::EnableStateAllowed) ENABLED START -----*/

	/*----- PROTECTED REGION END -----*/	//	AmptekPX5::EnableStateAllowed
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : AmptekPX5::is_Disable_allowed()
 *	Description : Execution allowed for Disable attribute
 */
//--------------------------------------------------------
bool AmptekPX5::is_Disable_allowed(TANGO_UNUSED(const CORBA::Any &any))
{
	//	Not any excluded states for Disable command.
	/*----- PROTECTED REGION ID(AmptekPX5::DisableStateAllowed) ENABLED START -----*/

	/*----- PROTECTED REGION END -----*/	//	AmptekPX5::DisableStateAllowed
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : AmptekPX5::is_ClearSpectrum_allowed()
 *	Description : Execution allowed for ClearSpectrum attribute
 */
//--------------------------------------------------------
bool AmptekPX5::is_ClearSpectrum_allowed(TANGO_UNUSED(const CORBA::Any &any))
{
	//	Not any excluded states for ClearSpectrum command.
	/*----- PROTECTED REGION ID(AmptekPX5::ClearSpectrumStateAllowed) ENABLED START -----*/

	/*----- PROTECTED REGION END -----*/	//	AmptekPX5::ClearSpectrumStateAllowed
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : AmptekPX5::is_LatchGetClearSCA_allowed()
 *	Description : Execution allowed for LatchGetClearSCA attribute
 */
//--------------------------------------------------------
bool AmptekPX5::is_LatchGetClearSCA_allowed(TANGO_UNUSED(const CORBA::Any &any))
{
	//	Not any excluded states for LatchGetClearSCA command.
	/*----- PROTECTED REGION ID(AmptekPX5::LatchGetClearSCAStateAllowed) ENABLED START -----*/

	/*----- PROTECTED REGION END -----*/	//	AmptekPX5::LatchGetClearSCAStateAllowed
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : AmptekPX5::is_ClearInputBuffer_allowed()
 *	Description : Execution allowed for ClearInputBuffer attribute
 */
//--------------------------------------------------------
bool AmptekPX5::is_ClearInputBuffer_allowed(TANGO_UNUSED(const CORBA::Any &any))
{
	//	Not any excluded states for ClearInputBuffer command.
	/*----- PROTECTED REGION ID(AmptekPX5::ClearInputBufferStateAllowed) ENABLED START -----*/

	/*----- PROTECTED REGION END -----*/	//	AmptekPX5::ClearInputBufferStateAllowed
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : AmptekPX5::is_AutoTune_allowed()
 *	Description : Execution allowed for AutoTune attribute
 */
//--------------------------------------------------------
bool AmptekPX5::is_AutoTune_allowed(TANGO_UNUSED(const CORBA::Any &any))
{
	//	Compare device state with not allowed states.
	if (get_state()==Tango::MOVING)
	{
	/*----- PROTECTED REGION ID(AmptekPX5::AutoTuneStateAllowed) ENABLED START -----*/

	/*----- PROTECTED REGION END -----*/	//	AmptekPX5::AutoTuneStateAllowed
		return false;
	}
	return true;
}

}	//	End of namespace
