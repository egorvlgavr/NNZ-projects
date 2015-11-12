using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.ServiceProcess;
using System.Threading.Tasks;
using System.Timers;
using System.Diagnostics;
using System.ComponentModel;

namespace SimpleWindowsService
{
    public class SimpleService : ServiceBase
    {
        private Timer _aTimer;
        private System.Diagnostics.EventLog _eventLog;

        public SimpleService()
        {
            const string eventLogSource = "Simple service";
            const string logName = "SimpleServiceLog";
            InitializeComponent();
            if (!System.Diagnostics.EventLog.SourceExists(eventLogSource))
            {
                System.Diagnostics.EventLog.CreateEventSource(eventLogSource, logName);
            }
            // Logs
            _eventLog.Source = eventLogSource;
            _eventLog.Log = logName;
            // Timer
            _aTimer = new Timer();
            _aTimer.AutoReset = true;
            _aTimer.Elapsed += _atimer_Elapsed;
        }

                /// <summary>
        /// Called when start service.
        /// </summary>
        /// <param name="args">Console arguments</param>
        protected override void OnStart(string[] args)
        {
            // Set interval
            _aTimer.Interval = 20000;
            _aTimer.Enabled = true;
            _eventLog.WriteEntry("Service start", EventLogEntryType.Information);
        }

        /// <summary>
        /// Called when stop service. Stop timer.
        /// </summary>
        protected override void OnStop()
        {
            _eventLog.WriteEntry("Service stop", EventLogEntryType.Information);
            _aTimer.Enabled = false;
        }


        private void _atimer_Elapsed(object sender, ElapsedEventArgs e)
        {
            _eventLog.WriteEntry("Elapsed event handled", EventLogEntryType.Information);
        }

        #region Component Designer generated code

        /// <summary> 
        /// Required method for Designer support - do not modify 
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this._eventLog = new System.Diagnostics.EventLog();
            ((System.ComponentModel.ISupportInitialize)(this._eventLog)).BeginInit();
            // 
            // SimpleService
            // 
            this.ServiceName = "SimpleService";
            ((System.ComponentModel.ISupportInitialize)(this._eventLog)).EndInit();

        }

        #endregion
        
        /// <summary> 
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }
    }
}
