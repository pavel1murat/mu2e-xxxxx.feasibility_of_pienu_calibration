//-----------------------------------------------------------------------------
// track ID: D0
//-----------------------------------------------------------------------------
plot_data_t* plot_figure_0277(int Figure, int Print) {
    
  const char* bpip2b0s51  = "pipenu.bpip2b0s51r0100";        // STT
  const char* bpip2b0s54  = "pipenu.bpip2b0s54r0100";        // degrader
  const char* bmup2b0s54  = "pipenu.bmup2b0s54r0100";        // DIF

  const char* ana_job     = "murat_pipenu_ana.0000";
  const char* ana_module  = "PipenuAna";
  const char* hist_name   = "tid_0/d0_1";

  plot_data_t* pdata = new plot_data_t(3);
  plot_data_t& p     = *pdata;
//-----------------------------------------------------------------------------
// 100000: the number of generated pi+ --> e+ nu events in each sample
//------------------------------------------------------------------------------
  p.hd[0]              = hist_data_t(catalog,"pipenu",bpip2b0s51,ana_job,ana_module,hist_name);

  p.hd[0].fRebin       = 10;
  p.hd[0].fLabel       = "pion stops in the ST";
  p.hd[0].fMarkerColor = kRed+1;
  p.hd[0].fMarkerStyle = 20;
  //  p.hd[0].fLumiSF      = gPipenu->GetChannel("bpip2b0s51r0100")->NormSF();

  p.hd[1]              = hist_data_t(catalog,"pipenu",bpip2b0s54,ana_job,ana_module,hist_name);
  p.hd[1].fRebin       = 10;
  p.hd[1].fLabel       = "degrader";
  p.hd[1].fLineColor   = kBlue;
  p.hd[1].fMarkerColor = kBlue;
  p.hd[1].fMarkerStyle = 21;
  p.hd[1].fMarkerSize  = 1.0;
  p.hd[1].fScale       = 2;
    
  p.hd[2]              = hist_data_t(catalog,"pipenu",bmup2b0s54,ana_job,ana_module,hist_name);
  p.hd[2].fRebin       = 10;
  p.hd[2].fLabel       = "DIF";
  p.hd[2].fLineColor   = kGreen+2;
  p.hd[2].fMarkerColor = kGreen+2;
  p.hd[2].fMarkerStyle = 22;
  p.hd[2].fMarkerSize  = 1.0;
  p.hd[2].fScale       = 2;
    
  // p.fXMin              = 55.;
  // p.fXMax              = 80.;
  // p.fYMin              = 0;
  // p.fYMax              = 8e-12;
  p.fCanvasName        = Form("Figure_%04i",Figure);
  p.fName              = Form("figure_%05i",Figure);

  p.fXAxisTitle        = "track d0, mm";
  p.fLabel             = "#pi^{+} #rightarrow e #nu , 2 mm Ti degrader, events with tracks passing ID cuts";
  p.fYLogScale         = 0;

  p.fStatBoxYMax       = 0.90;
  p.fStatBoxYMin       = 0.75;

  p.fLegendXMin  = 0.35; p.fLegendXMax  = 0.65; p.fLegendYMin  = 0.75; p.fLegendYMax  = 0.85; 
    

  plot_hist_1d(&p,-1);

  p.fCanvas->Modified();
  p.fCanvas->Update();

  TArrow* arr = new TArrow(-100,1000,-100,150,0.015);
  arr->SetLineWidth(2);
  arr->Draw();

  TArrow* arr2 = new TArrow(100,1000,100,150,0.015);
  arr2->SetLineWidth(2);
  arr2->Draw();

  printf(" plot.C p.fOutputFn = %s\n",p.fOutputFn.Data());
    
  if (Print == 1) p.print() ;

  return pdata;
}
