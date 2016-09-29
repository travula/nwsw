/*
 * Note: this file originally auto-generated by mib2c using
 *  : mib2c.iterate.conf 19302 2010-08-13 12:19:42Z dts12 $
 */
#ifndef IPCOUNTERS_H
#define IPCOUNTERS_H

/* function declarations */
void init_ipCounters(void);
void initialize_table_ipCountersTable(void);

/* column number definitions for table ipCountersTable */
       #define COLUMN_PWAV_IPSYSTEMSTATSIPVERSION		1
       #define COLUMN_PWAV_IPSYSTEMSTATSINRECEIVES		2
       #define COLUMN_PWAV_IPSYSTEMSTATSINOCTETS		3
       #define COLUMN_PWAV_IPSYSTEMSTATSINHDRERRORS		4
       #define COLUMN_PWAV_IPSYSTEMSTATSINNOROUTES		5
       #define COLUMN_PWAV_IPSYSTEMSTATSINADDRERRORS		6
       #define COLUMN_PWAV_IPSYSTEMSTATSINUNKNOWNPROTOS		7
       #define COLUMN_PWAV_IPSYSTEMSTATSINTRUNCATEDPKTS		8
       #define COLUMN_PWAV_IPSYSTEMSTATSINFORWDATAGRAMS		9
       #define COLUMN_PWAV_IPSYSTEMSTATSREASMREQDS		10
       #define COLUMN_PWAV_IPSYSTEMSTATSREASMOKS		11
       #define COLUMN_PWAV_IPSYSTEMSTATSREASMFAILS		12
       #define COLUMN_PWAV_IPSYSTEMSTATSINDISCARDS		13
       #define COLUMN_PWAV_IPSYSTEMSTATSINDELIVERS		14
       #define COLUMN_PWAV_IPSYSTEMSTATSOUTREQUESTS		15
       #define COLUMN_PWAV_IPSYSTEMSTATSOUTNOROUTES		16
       #define COLUMN_PWAV_IPSYSTEMSTATSOUTFORWDATAGRAMS		17
       #define COLUMN_PWAV_IPSYSTEMSTATSOUTDISCARDS		18
       #define COLUMN_PWAV_IPSYSTEMSTATSOUTFRAGREQDS		19
       #define COLUMN_PWAV_IPSYSTEMSTATSOUTFRAGOKS		20
       #define COLUMN_PWAV_IPSYSTEMSTATSOUTFRAGFAILS		21
       #define COLUMN_PWAV_IPSYSTEMSTATSOUTFRAGCREATES		22
       #define COLUMN_PWAV_IPSYSTEMSTATSOUTTRANSMITS		23
       #define COLUMN_PWAV_IPSYSTEMSTATSOUTOCTETS		24
       #define COLUMN_PWAV_IPSYSTEMSTATSINMCASTPKTS		25
       #define COLUMN_PWAV_IPSYSTEMSTATSINMCASTOCTETS		26
       #define COLUMN_PWAV_IPSYSTEMSTATSOUTMCASTPKTS		27
       #define COLUMN_PWAV_IPSYSTEMSTATSOUTMCASTOCTETS		28
       #define COLUMN_PWAV_IPSYSTEMSTATSINBCASTPKTS		29
       #define COLUMN_PWAV_IPSYSTEMSTATSOUTBCASTPKTS		30
       #define COLUMN_PWAV_IPSYSTEMSTATSDISCONTINUITYTIME		31
       #define COLUMN_PWAV_IPSYSTEMSTATSREFRESHRATE		32
	   #define COLUMN_PWAV_IP_COUNTERS_LASTCOLLECTEDAT	33

#define IP_COUNTERS_MAX_COL COLUMN_PWAV_IP_COUNTERS_LASTCOLLECTEDAT

#define IP_COUNTERS_LCOLLECT_BUF_LEN_MAX 18

    /* Typical data structure for a row entry */
typedef struct ipCountersTable_entry {
    /* Index values */
    unsigned int ipSystemStatsIPVersion;

    /* Column values */
    unsigned int ipSystemStatsInReceives;
    unsigned int ipSystemStatsInOctets;
    unsigned int ipSystemStatsInHdrErrors;
    unsigned int ipSystemStatsInNoRoutes;
    unsigned int ipSystemStatsInAddrErrors;
    unsigned int ipSystemStatsInUnknownProtos;
    unsigned int ipSystemStatsInTruncatedPkts;
    unsigned int ipSystemStatsInForwDatagrams;
    unsigned int ipSystemStatsReasmReqds;
    unsigned int ipSystemStatsReasmOKs;
    unsigned int ipSystemStatsReasmFails;
    unsigned int ipSystemStatsInDiscards;
    unsigned int ipSystemStatsInDelivers;
    unsigned int ipSystemStatsOutRequests;
    unsigned int ipSystemStatsOutNoRoutes;
    unsigned int ipSystemStatsOutForwDatagrams;
    unsigned int ipSystemStatsOutDiscards;
    unsigned int ipSystemStatsOutFragReqds;
    unsigned int ipSystemStatsOutFragOKs;
    unsigned int ipSystemStatsOutFragFails;
    unsigned int ipSystemStatsOutFragCreates;
    unsigned int ipSystemStatsOutTransmits;
    unsigned int ipSystemStatsOutOctets;
    unsigned int ipSystemStatsInMcastPkts;
    unsigned int ipSystemStatsInMcastOctets;
    unsigned int ipSystemStatsOutMcastPkts;
    unsigned int ipSystemStatsOutMcastOctets;
    unsigned int ipSystemStatsInBcastPkts;
    unsigned int ipSystemStatsOutBcastPkts;
    unsigned int ipSystemStatsDiscontinuityTime;
    unsigned int ipSystemStatsRefreshRate;
    char lastCollectedAt[IP_COUNTERS_LCOLLECT_BUF_LEN_MAX];
    size_t lastCollectedAt_len;

    /* Illustrate using a simple linked list */
    int   valid;
    struct ipCountersTable_entry *next;
}ipCountersTableEntry;

#endif /* IPCOUNTERS_H */