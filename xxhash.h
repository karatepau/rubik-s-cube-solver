









<!doctype html>
<html>
  <head>
    
  
      <meta charset="UTF-8">
       <link rel="stylesheet" type="text/css"
            href="/static/bootstrap/bootstrap.min.css" />
      <link rel="stylesheet" type="text/css"
            href="/static/css/debian.css" />
      <link rel="stylesheet" type="text/css"
            href="/static/css/base.css" />
      <link rel="shortcut icon"
            href="/static/favicon.ico" />
      
      <title>File: xxhash.h
| Debian Sources
</title>
    

  <link rel="stylesheet"
        href="/static/javascript-lib/highlight/styles/googlecode.css">
  <script src="/static/javascript-lib/highlight/highlight.min.js"></script>

  <script src="/static/javascript/debsources.js"></script>
  <link rel="stylesheet" type="text/css"
        href="/static/css/source_file.css" />


  </head>
  <body>
    <header id="header">
      <div id="upperheader">
        <div id="logo">
          <a href="https://www.debian.org" title="Debian Home"><img src="/static/img/debian-50.png" alt="Debian"></a>
        </div> <!-- end logo -->
        <p class="section"><a href="/">DEBSOURCES</a></p>
        <div id="searchbox">
            
    
  
  <form action="/search/" name="searchform"
        method="post" style="display: inline;">
      <input id="query-1" name="query" placeholder="package name" required type="text" value="">
    
    
    <input type="submit" value="Search package" />
  </form>
            <form name="codesearch" method="get"
            action="https://codesearch.debian.net/search">
              <input name="q" value="package:xxhash "
              type="text" />
              <input type="submit" value="Search code" />
            </form>
        </div>   <!-- end sitetools -->
      </div> <!-- end upperheader -->

      <nav id="navbar">
        <p class="hidecss"><a href="#content">Skip Quicknav</a></p>
        
  <ul>
    <li><a href="/">Home</a></li>
    <li><a href="/advancedsearch/">Search</a></li>
    <li><a href="/doc/">Documentation</a></li>
    <li><a href="/stats/">Stats</a></li>
    <li><a href="/doc/about/">About</a></li>
  </ul>

      </nav> <!-- end navbar -->

      <p id="breadcrumbs"><a href="/">sources</a> / <a href="/src/xxhash">xxhash</a> / <a href="/src/xxhash/0.8.3-2">0.8.3-2</a> / xxhash.h</p>
    </header> <!-- end header -->

    
      <div id="content">
        


<h2>File: xxhash.h</h2>



<script type="text/javascript">
    function toggle(id)
    {
    var elem = document.getElementById(id);
    if(elem.style.display == "none")
      elem.style.display = "block";
    else
      elem.style.display = "none";
    }
  </script>


<div id="pkginfobox" class="pkginfobox_fixed">

  
  <span onclick="toggle('infobox_content')">package info
    <small>(click to toggle)</small></span>
  
  <div id="infobox_content">
    
    <em>xxhash 0.8.3-2</em>
    
    <ul>
    <!--
    
      <li><a href="/copyright/license/xxhash/0.8.3-2/">view license information</a></li>
    
    -->
      <li>links:
  <a href="https://tracker.debian.org/pkg/xxhash"><abbr title="Debian Package Tracking
                 System">PTS</abbr></a>,
  <a href="https://salsa.debian.org/debian/xxhash"><abbr title="Version Control System">VCS</abbr></a>
  </li>
      <li>area: main</li>
      <li>in suites: forky, sid, trixie</li>
      
        <li>size: 5,632 kB</li>
      

      

      
        <li><abbr title="source lines of code">sloc</abbr>:
    
            
              ansic: 55,509; 
            
              makefile: 675; 
            
              sh: 74; 
            
              cpp: 23
            
    
        </li>
      
    </ul>
  </div>
</div>


<table id="file_metadata">
  <tr>
    <td>
    file content (7238 lines)
    | stat: -rw-r--r-- 268,319 bytes
    </td>
    <td style="text-align: right;">
    <a id="link_parent_folder" href="/src/xxhash/0.8.3-2">parent folder</a>
    | <a id="link_download" href="/data/main/x/xxhash/0.8.3-2/xxhash.h">download</a>
    
    | <a id="link_duplicates" href="/sha256/?checksum=17973c0dc49d9854ca26caa191f0e12f7a424b68858d9a78de3860d959d85e4b&amp;page=1">
	  duplicates (22)</a>
    
    </td>
  </tr>
</table>
<table id="codetable">
  <tr>
    <td>
      <pre id="sourceslinenumbers"><a id="L1" href="#L1">1</a><br /><a id="L2" href="#L2">2</a><br /><a id="L3" href="#L3">3</a><br /><a id="L4" href="#L4">4</a><br /><a id="L5" href="#L5">5</a><br /><a id="L6" href="#L6">6</a><br /><a id="L7" href="#L7">7</a><br /><a id="L8" href="#L8">8</a><br /><a id="L9" href="#L9">9</a><br /><a id="L10" href="#L10">10</a><br /><a id="L11" href="#L11">11</a><br /><a id="L12" href="#L12">12</a><br /><a id="L13" href="#L13">13</a><br /><a id="L14" href="#L14">14</a><br /><a id="L15" href="#L15">15</a><br /><a id="L16" href="#L16">16</a><br /><a id="L17" href="#L17">17</a><br /><a id="L18" href="#L18">18</a><br /><a id="L19" href="#L19">19</a><br /><a id="L20" href="#L20">20</a><br /><a id="L21" href="#L21">21</a><br /><a id="L22" href="#L22">22</a><br /><a id="L23" href="#L23">23</a><br /><a id="L24" href="#L24">24</a><br /><a id="L25" href="#L25">25</a><br /><a id="L26" href="#L26">26</a><br /><a id="L27" href="#L27">27</a><br /><a id="L28" href="#L28">28</a><br /><a id="L29" href="#L29">29</a><br /><a id="L30" href="#L30">30</a><br /><a id="L31" href="#L31">31</a><br /><a id="L32" href="#L32">32</a><br /><a id="L33" href="#L33">33</a><br /><a id="L34" href="#L34">34</a><br /><a id="L35" href="#L35">35</a><br /><a id="L36" href="#L36">36</a><br /><a id="L37" href="#L37">37</a><br /><a id="L38" href="#L38">38</a><br /><a id="L39" href="#L39">39</a><br /><a id="L40" href="#L40">40</a><br /><a id="L41" href="#L41">41</a><br /><a id="L42" href="#L42">42</a><br /><a id="L43" href="#L43">43</a><br /><a id="L44" href="#L44">44</a><br /><a id="L45" href="#L45">45</a><br /><a id="L46" href="#L46">46</a><br /><a id="L47" href="#L47">47</a><br /><a id="L48" href="#L48">48</a><br /><a id="L49" href="#L49">49</a><br /><a id="L50" href="#L50">50</a><br /><a id="L51" href="#L51">51</a><br /><a id="L52" href="#L52">52</a><br /><a id="L53" href="#L53">53</a><br /><a id="L54" href="#L54">54</a><br /><a id="L55" href="#L55">55</a><br /><a id="L56" href="#L56">56</a><br /><a id="L57" href="#L57">57</a><br /><a id="L58" href="#L58">58</a><br /><a id="L59" href="#L59">59</a><br /><a id="L60" href="#L60">60</a><br /><a id="L61" href="#L61">61</a><br /><a id="L62" href="#L62">62</a><br /><a id="L63" href="#L63">63</a><br /><a id="L64" href="#L64">64</a><br /><a id="L65" href="#L65">65</a><br /><a id="L66" href="#L66">66</a><br /><a id="L67" href="#L67">67</a><br /><a id="L68" href="#L68">68</a><br /><a id="L69" href="#L69">69</a><br /><a id="L70" href="#L70">70</a><br /><a id="L71" href="#L71">71</a><br /><a id="L72" href="#L72">72</a><br /><a id="L73" href="#L73">73</a><br /><a id="L74" href="#L74">74</a><br /><a id="L75" href="#L75">75</a><br /><a id="L76" href="#L76">76</a><br /><a id="L77" href="#L77">77</a><br /><a id="L78" href="#L78">78</a><br /><a id="L79" href="#L79">79</a><br /><a id="L80" href="#L80">80</a><br /><a id="L81" href="#L81">81</a><br /><a id="L82" href="#L82">82</a><br /><a id="L83" href="#L83">83</a><br /><a id="L84" href="#L84">84</a><br /><a id="L85" href="#L85">85</a><br /><a id="L86" href="#L86">86</a><br /><a id="L87" href="#L87">87</a><br /><a id="L88" href="#L88">88</a><br /><a id="L89" href="#L89">89</a><br /><a id="L90" href="#L90">90</a><br /><a id="L91" href="#L91">91</a><br /><a id="L92" href="#L92">92</a><br /><a id="L93" href="#L93">93</a><br /><a id="L94" href="#L94">94</a><br /><a id="L95" href="#L95">95</a><br /><a id="L96" href="#L96">96</a><br /><a id="L97" href="#L97">97</a><br /><a id="L98" href="#L98">98</a><br /><a id="L99" href="#L99">99</a><br /><a id="L100" href="#L100">100</a><br /><a id="L101" href="#L101">101</a><br /><a id="L102" href="#L102">102</a><br /><a id="L103" href="#L103">103</a><br /><a id="L104" href="#L104">104</a><br /><a id="L105" href="#L105">105</a><br /><a id="L106" href="#L106">106</a><br /><a id="L107" href="#L107">107</a><br /><a id="L108" href="#L108">108</a><br /><a id="L109" href="#L109">109</a><br /><a id="L110" href="#L110">110</a><br /><a id="L111" href="#L111">111</a><br /><a id="L112" href="#L112">112</a><br /><a id="L113" href="#L113">113</a><br /><a id="L114" href="#L114">114</a><br /><a id="L115" href="#L115">115</a><br /><a id="L116" href="#L116">116</a><br /><a id="L117" href="#L117">117</a><br /><a id="L118" href="#L118">118</a><br /><a id="L119" href="#L119">119</a><br /><a id="L120" href="#L120">120</a><br /><a id="L121" href="#L121">121</a><br /><a id="L122" href="#L122">122</a><br /><a id="L123" href="#L123">123</a><br /><a id="L124" href="#L124">124</a><br /><a id="L125" href="#L125">125</a><br /><a id="L126" href="#L126">126</a><br /><a id="L127" href="#L127">127</a><br /><a id="L128" href="#L128">128</a><br /><a id="L129" href="#L129">129</a><br /><a id="L130" href="#L130">130</a><br /><a id="L131" href="#L131">131</a><br /><a id="L132" href="#L132">132</a><br /><a id="L133" href="#L133">133</a><br /><a id="L134" href="#L134">134</a><br /><a id="L135" href="#L135">135</a><br /><a id="L136" href="#L136">136</a><br /><a id="L137" href="#L137">137</a><br /><a id="L138" href="#L138">138</a><br /><a id="L139" href="#L139">139</a><br /><a id="L140" href="#L140">140</a><br /><a id="L141" href="#L141">141</a><br /><a id="L142" href="#L142">142</a><br /><a id="L143" href="#L143">143</a><br /><a id="L144" href="#L144">144</a><br /><a id="L145" href="#L145">145</a><br /><a id="L146" href="#L146">146</a><br /><a id="L147" href="#L147">147</a><br /><a id="L148" href="#L148">148</a><br /><a id="L149" href="#L149">149</a><br /><a id="L150" href="#L150">150</a><br /><a id="L151" href="#L151">151</a><br /><a id="L152" href="#L152">152</a><br /><a id="L153" href="#L153">153</a><br /><a id="L154" href="#L154">154</a><br /><a id="L155" href="#L155">155</a><br /><a id="L156" href="#L156">156</a><br /><a id="L157" href="#L157">157</a><br /><a id="L158" href="#L158">158</a><br /><a id="L159" href="#L159">159</a><br /><a id="L160" href="#L160">160</a><br /><a id="L161" href="#L161">161</a><br /><a id="L162" href="#L162">162</a><br /><a id="L163" href="#L163">163</a><br /><a id="L164" href="#L164">164</a><br /><a id="L165" href="#L165">165</a><br /><a id="L166" href="#L166">166</a><br /><a id="L167" href="#L167">167</a><br /><a id="L168" href="#L168">168</a><br /><a id="L169" href="#L169">169</a><br /><a id="L170" href="#L170">170</a><br /><a id="L171" href="#L171">171</a><br /><a id="L172" href="#L172">172</a><br /><a id="L173" href="#L173">173</a><br /><a id="L174" href="#L174">174</a><br /><a id="L175" href="#L175">175</a><br /><a id="L176" href="#L176">176</a><br /><a id="L177" href="#L177">177</a><br /><a id="L178" href="#L178">178</a><br /><a id="L179" href="#L179">179</a><br /><a id="L180" href="#L180">180</a><br /><a id="L181" href="#L181">181</a><br /><a id="L182" href="#L182">182</a><br /><a id="L183" href="#L183">183</a><br /><a id="L184" href="#L184">184</a><br /><a id="L185" href="#L185">185</a><br /><a id="L186" href="#L186">186</a><br /><a id="L187" href="#L187">187</a><br /><a id="L188" href="#L188">188</a><br /><a id="L189" href="#L189">189</a><br /><a id="L190" href="#L190">190</a><br /><a id="L191" href="#L191">191</a><br /><a id="L192" href="#L192">192</a><br /><a id="L193" href="#L193">193</a><br /><a id="L194" href="#L194">194</a><br /><a id="L195" href="#L195">195</a><br /><a id="L196" href="#L196">196</a><br /><a id="L197" href="#L197">197</a><br /><a id="L198" href="#L198">198</a><br /><a id="L199" href="#L199">199</a><br /><a id="L200" href="#L200">200</a><br /><a id="L201" href="#L201">201</a><br /><a id="L202" href="#L202">202</a><br /><a id="L203" href="#L203">203</a><br /><a id="L204" href="#L204">204</a><br /><a id="L205" href="#L205">205</a><br /><a id="L206" href="#L206">206</a><br /><a id="L207" href="#L207">207</a><br /><a id="L208" href="#L208">208</a><br /><a id="L209" href="#L209">209</a><br /><a id="L210" href="#L210">210</a><br /><a id="L211" href="#L211">211</a><br /><a id="L212" href="#L212">212</a><br /><a id="L213" href="#L213">213</a><br /><a id="L214" href="#L214">214</a><br /><a id="L215" href="#L215">215</a><br /><a id="L216" href="#L216">216</a><br /><a id="L217" href="#L217">217</a><br /><a id="L218" href="#L218">218</a><br /><a id="L219" href="#L219">219</a><br /><a id="L220" href="#L220">220</a><br /><a id="L221" href="#L221">221</a><br /><a id="L222" href="#L222">222</a><br /><a id="L223" href="#L223">223</a><br /><a id="L224" href="#L224">224</a><br /><a id="L225" href="#L225">225</a><br /><a id="L226" href="#L226">226</a><br /><a id="L227" href="#L227">227</a><br /><a id="L228" href="#L228">228</a><br /><a id="L229" href="#L229">229</a><br /><a id="L230" href="#L230">230</a><br /><a id="L231" href="#L231">231</a><br /><a id="L232" href="#L232">232</a><br /><a id="L233" href="#L233">233</a><br /><a id="L234" href="#L234">234</a><br /><a id="L235" href="#L235">235</a><br /><a id="L236" href="#L236">236</a><br /><a id="L237" href="#L237">237</a><br /><a id="L238" href="#L238">238</a><br /><a id="L239" href="#L239">239</a><br /><a id="L240" href="#L240">240</a><br /><a id="L241" href="#L241">241</a><br /><a id="L242" href="#L242">242</a><br /><a id="L243" href="#L243">243</a><br /><a id="L244" href="#L244">244</a><br /><a id="L245" href="#L245">245</a><br /><a id="L246" href="#L246">246</a><br /><a id="L247" href="#L247">247</a><br /><a id="L248" href="#L248">248</a><br /><a id="L249" href="#L249">249</a><br /><a id="L250" href="#L250">250</a><br /><a id="L251" href="#L251">251</a><br /><a id="L252" href="#L252">252</a><br /><a id="L253" href="#L253">253</a><br /><a id="L254" href="#L254">254</a><br /><a id="L255" href="#L255">255</a><br /><a id="L256" href="#L256">256</a><br /><a id="L257" href="#L257">257</a><br /><a id="L258" href="#L258">258</a><br /><a id="L259" href="#L259">259</a><br /><a id="L260" href="#L260">260</a><br /><a id="L261" href="#L261">261</a><br /><a id="L262" href="#L262">262</a><br /><a id="L263" href="#L263">263</a><br /><a id="L264" href="#L264">264</a><br /><a id="L265" href="#L265">265</a><br /><a id="L266" href="#L266">266</a><br /><a id="L267" href="#L267">267</a><br /><a id="L268" href="#L268">268</a><br /><a id="L269" href="#L269">269</a><br /><a id="L270" href="#L270">270</a><br /><a id="L271" href="#L271">271</a><br /><a id="L272" href="#L272">272</a><br /><a id="L273" href="#L273">273</a><br /><a id="L274" href="#L274">274</a><br /><a id="L275" href="#L275">275</a><br /><a id="L276" href="#L276">276</a><br /><a id="L277" href="#L277">277</a><br /><a id="L278" href="#L278">278</a><br /><a id="L279" href="#L279">279</a><br /><a id="L280" href="#L280">280</a><br /><a id="L281" href="#L281">281</a><br /><a id="L282" href="#L282">282</a><br /><a id="L283" href="#L283">283</a><br /><a id="L284" href="#L284">284</a><br /><a id="L285" href="#L285">285</a><br /><a id="L286" href="#L286">286</a><br /><a id="L287" href="#L287">287</a><br /><a id="L288" href="#L288">288</a><br /><a id="L289" href="#L289">289</a><br /><a id="L290" href="#L290">290</a><br /><a id="L291" href="#L291">291</a><br /><a id="L292" href="#L292">292</a><br /><a id="L293" href="#L293">293</a><br /><a id="L294" href="#L294">294</a><br /><a id="L295" href="#L295">295</a><br /><a id="L296" href="#L296">296</a><br /><a id="L297" href="#L297">297</a><br /><a id="L298" href="#L298">298</a><br /><a id="L299" href="#L299">299</a><br /><a id="L300" href="#L300">300</a><br /><a id="L301" href="#L301">301</a><br /><a id="L302" href="#L302">302</a><br /><a id="L303" href="#L303">303</a><br /><a id="L304" href="#L304">304</a><br /><a id="L305" href="#L305">305</a><br /><a id="L306" href="#L306">306</a><br /><a id="L307" href="#L307">307</a><br /><a id="L308" href="#L308">308</a><br /><a id="L309" href="#L309">309</a><br /><a id="L310" href="#L310">310</a><br /><a id="L311" href="#L311">311</a><br /><a id="L312" href="#L312">312</a><br /><a id="L313" href="#L313">313</a><br /><a id="L314" href="#L314">314</a><br /><a id="L315" href="#L315">315</a><br /><a id="L316" href="#L316">316</a><br /><a id="L317" href="#L317">317</a><br /><a id="L318" href="#L318">318</a><br /><a id="L319" href="#L319">319</a><br /><a id="L320" href="#L320">320</a><br /><a id="L321" href="#L321">321</a><br /><a id="L322" href="#L322">322</a><br /><a id="L323" href="#L323">323</a><br /><a id="L324" href="#L324">324</a><br /><a id="L325" href="#L325">325</a><br /><a id="L326" href="#L326">326</a><br /><a id="L327" href="#L327">327</a><br /><a id="L328" href="#L328">328</a><br /><a id="L329" href="#L329">329</a><br /><a id="L330" href="#L330">330</a><br /><a id="L331" href="#L331">331</a><br /><a id="L332" href="#L332">332</a><br /><a id="L333" href="#L333">333</a><br /><a id="L334" href="#L334">334</a><br /><a id="L335" href="#L335">335</a><br /><a id="L336" href="#L336">336</a><br /><a id="L337" href="#L337">337</a><br /><a id="L338" href="#L338">338</a><br /><a id="L339" href="#L339">339</a><br /><a id="L340" href="#L340">340</a><br /><a id="L341" href="#L341">341</a><br /><a id="L342" href="#L342">342</a><br /><a id="L343" href="#L343">343</a><br /><a id="L344" href="#L344">344</a><br /><a id="L345" href="#L345">345</a><br /><a id="L346" href="#L346">346</a><br /><a id="L347" href="#L347">347</a><br /><a id="L348" href="#L348">348</a><br /><a id="L349" href="#L349">349</a><br /><a id="L350" href="#L350">350</a><br /><a id="L351" href="#L351">351</a><br /><a id="L352" href="#L352">352</a><br /><a id="L353" href="#L353">353</a><br /><a id="L354" href="#L354">354</a><br /><a id="L355" href="#L355">355</a><br /><a id="L356" href="#L356">356</a><br /><a id="L357" href="#L357">357</a><br /><a id="L358" href="#L358">358</a><br /><a id="L359" href="#L359">359</a><br /><a id="L360" href="#L360">360</a><br /><a id="L361" href="#L361">361</a><br /><a id="L362" href="#L362">362</a><br /><a id="L363" href="#L363">363</a><br /><a id="L364" href="#L364">364</a><br /><a id="L365" href="#L365">365</a><br /><a id="L366" href="#L366">366</a><br /><a id="L367" href="#L367">367</a><br /><a id="L368" href="#L368">368</a><br /><a id="L369" href="#L369">369</a><br /><a id="L370" href="#L370">370</a><br /><a id="L371" href="#L371">371</a><br /><a id="L372" href="#L372">372</a><br /><a id="L373" href="#L373">373</a><br /><a id="L374" href="#L374">374</a><br /><a id="L375" href="#L375">375</a><br /><a id="L376" href="#L376">376</a><br /><a id="L377" href="#L377">377</a><br /><a id="L378" href="#L378">378</a><br /><a id="L379" href="#L379">379</a><br /><a id="L380" href="#L380">380</a><br /><a id="L381" href="#L381">381</a><br /><a id="L382" href="#L382">382</a><br /><a id="L383" href="#L383">383</a><br /><a id="L384" href="#L384">384</a><br /><a id="L385" href="#L385">385</a><br /><a id="L386" href="#L386">386</a><br /><a id="L387" href="#L387">387</a><br /><a id="L388" href="#L388">388</a><br /><a id="L389" href="#L389">389</a><br /><a id="L390" href="#L390">390</a><br /><a id="L391" href="#L391">391</a><br /><a id="L392" href="#L392">392</a><br /><a id="L393" href="#L393">393</a><br /><a id="L394" href="#L394">394</a><br /><a id="L395" href="#L395">395</a><br /><a id="L396" href="#L396">396</a><br /><a id="L397" href="#L397">397</a><br /><a id="L398" href="#L398">398</a><br /><a id="L399" href="#L399">399</a><br /><a id="L400" href="#L400">400</a><br /><a id="L401" href="#L401">401</a><br /><a id="L402" href="#L402">402</a><br /><a id="L403" href="#L403">403</a><br /><a id="L404" href="#L404">404</a><br /><a id="L405" href="#L405">405</a><br /><a id="L406" href="#L406">406</a><br /><a id="L407" href="#L407">407</a><br /><a id="L408" href="#L408">408</a><br /><a id="L409" href="#L409">409</a><br /><a id="L410" href="#L410">410</a><br /><a id="L411" href="#L411">411</a><br /><a id="L412" href="#L412">412</a><br /><a id="L413" href="#L413">413</a><br /><a id="L414" href="#L414">414</a><br /><a id="L415" href="#L415">415</a><br /><a id="L416" href="#L416">416</a><br /><a id="L417" href="#L417">417</a><br /><a id="L418" href="#L418">418</a><br /><a id="L419" href="#L419">419</a><br /><a id="L420" href="#L420">420</a><br /><a id="L421" href="#L421">421</a><br /><a id="L422" href="#L422">422</a><br /><a id="L423" href="#L423">423</a><br /><a id="L424" href="#L424">424</a><br /><a id="L425" href="#L425">425</a><br /><a id="L426" href="#L426">426</a><br /><a id="L427" href="#L427">427</a><br /><a id="L428" href="#L428">428</a><br /><a id="L429" href="#L429">429</a><br /><a id="L430" href="#L430">430</a><br /><a id="L431" href="#L431">431</a><br /><a id="L432" href="#L432">432</a><br /><a id="L433" href="#L433">433</a><br /><a id="L434" href="#L434">434</a><br /><a id="L435" href="#L435">435</a><br /><a id="L436" href="#L436">436</a><br /><a id="L437" href="#L437">437</a><br /><a id="L438" href="#L438">438</a><br /><a id="L439" href="#L439">439</a><br /><a id="L440" href="#L440">440</a><br /><a id="L441" href="#L441">441</a><br /><a id="L442" href="#L442">442</a><br /><a id="L443" href="#L443">443</a><br /><a id="L444" href="#L444">444</a><br /><a id="L445" href="#L445">445</a><br /><a id="L446" href="#L446">446</a><br /><a id="L447" href="#L447">447</a><br /><a id="L448" href="#L448">448</a><br /><a id="L449" href="#L449">449</a><br /><a id="L450" href="#L450">450</a><br /><a id="L451" href="#L451">451</a><br /><a id="L452" href="#L452">452</a><br /><a id="L453" href="#L453">453</a><br /><a id="L454" href="#L454">454</a><br /><a id="L455" href="#L455">455</a><br /><a id="L456" href="#L456">456</a><br /><a id="L457" href="#L457">457</a><br /><a id="L458" href="#L458">458</a><br /><a id="L459" href="#L459">459</a><br /><a id="L460" href="#L460">460</a><br /><a id="L461" href="#L461">461</a><br /><a id="L462" href="#L462">462</a><br /><a id="L463" href="#L463">463</a><br /><a id="L464" href="#L464">464</a><br /><a id="L465" href="#L465">465</a><br /><a id="L466" href="#L466">466</a><br /><a id="L467" href="#L467">467</a><br /><a id="L468" href="#L468">468</a><br /><a id="L469" href="#L469">469</a><br /><a id="L470" href="#L470">470</a><br /><a id="L471" href="#L471">471</a><br /><a id="L472" href="#L472">472</a><br /><a id="L473" href="#L473">473</a><br /><a id="L474" href="#L474">474</a><br /><a id="L475" href="#L475">475</a><br /><a id="L476" href="#L476">476</a><br /><a id="L477" href="#L477">477</a><br /><a id="L478" href="#L478">478</a><br /><a id="L479" href="#L479">479</a><br /><a id="L480" href="#L480">480</a><br /><a id="L481" href="#L481">481</a><br /><a id="L482" href="#L482">482</a><br /><a id="L483" href="#L483">483</a><br /><a id="L484" href="#L484">484</a><br /><a id="L485" href="#L485">485</a><br /><a id="L486" href="#L486">486</a><br /><a id="L487" href="#L487">487</a><br /><a id="L488" href="#L488">488</a><br /><a id="L489" href="#L489">489</a><br /><a id="L490" href="#L490">490</a><br /><a id="L491" href="#L491">491</a><br /><a id="L492" href="#L492">492</a><br /><a id="L493" href="#L493">493</a><br /><a id="L494" href="#L494">494</a><br /><a id="L495" href="#L495">495</a><br /><a id="L496" href="#L496">496</a><br /><a id="L497" href="#L497">497</a><br /><a id="L498" href="#L498">498</a><br /><a id="L499" href="#L499">499</a><br /><a id="L500" href="#L500">500</a><br /><a id="L501" href="#L501">501</a><br /><a id="L502" href="#L502">502</a><br /><a id="L503" href="#L503">503</a><br /><a id="L504" href="#L504">504</a><br /><a id="L505" href="#L505">505</a><br /><a id="L506" href="#L506">506</a><br /><a id="L507" href="#L507">507</a><br /><a id="L508" href="#L508">508</a><br /><a id="L509" href="#L509">509</a><br /><a id="L510" href="#L510">510</a><br /><a id="L511" href="#L511">511</a><br /><a id="L512" href="#L512">512</a><br /><a id="L513" href="#L513">513</a><br /><a id="L514" href="#L514">514</a><br /><a id="L515" href="#L515">515</a><br /><a id="L516" href="#L516">516</a><br /><a id="L517" href="#L517">517</a><br /><a id="L518" href="#L518">518</a><br /><a id="L519" href="#L519">519</a><br /><a id="L520" href="#L520">520</a><br /><a id="L521" href="#L521">521</a><br /><a id="L522" href="#L522">522</a><br /><a id="L523" href="#L523">523</a><br /><a id="L524" href="#L524">524</a><br /><a id="L525" href="#L525">525</a><br /><a id="L526" href="#L526">526</a><br /><a id="L527" href="#L527">527</a><br /><a id="L528" href="#L528">528</a><br /><a id="L529" href="#L529">529</a><br /><a id="L530" href="#L530">530</a><br /><a id="L531" href="#L531">531</a><br /><a id="L532" href="#L532">532</a><br /><a id="L533" href="#L533">533</a><br /><a id="L534" href="#L534">534</a><br /><a id="L535" href="#L535">535</a><br /><a id="L536" href="#L536">536</a><br /><a id="L537" href="#L537">537</a><br /><a id="L538" href="#L538">538</a><br /><a id="L539" href="#L539">539</a><br /><a id="L540" href="#L540">540</a><br /><a id="L541" href="#L541">541</a><br /><a id="L542" href="#L542">542</a><br /><a id="L543" href="#L543">543</a><br /><a id="L544" href="#L544">544</a><br /><a id="L545" href="#L545">545</a><br /><a id="L546" href="#L546">546</a><br /><a id="L547" href="#L547">547</a><br /><a id="L548" href="#L548">548</a><br /><a id="L549" href="#L549">549</a><br /><a id="L550" href="#L550">550</a><br /><a id="L551" href="#L551">551</a><br /><a id="L552" href="#L552">552</a><br /><a id="L553" href="#L553">553</a><br /><a id="L554" href="#L554">554</a><br /><a id="L555" href="#L555">555</a><br /><a id="L556" href="#L556">556</a><br /><a id="L557" href="#L557">557</a><br /><a id="L558" href="#L558">558</a><br /><a id="L559" href="#L559">559</a><br /><a id="L560" href="#L560">560</a><br /><a id="L561" href="#L561">561</a><br /><a id="L562" href="#L562">562</a><br /><a id="L563" href="#L563">563</a><br /><a id="L564" href="#L564">564</a><br /><a id="L565" href="#L565">565</a><br /><a id="L566" href="#L566">566</a><br /><a id="L567" href="#L567">567</a><br /><a id="L568" href="#L568">568</a><br /><a id="L569" href="#L569">569</a><br /><a id="L570" href="#L570">570</a><br /><a id="L571" href="#L571">571</a><br /><a id="L572" href="#L572">572</a><br /><a id="L573" href="#L573">573</a><br /><a id="L574" href="#L574">574</a><br /><a id="L575" href="#L575">575</a><br /><a id="L576" href="#L576">576</a><br /><a id="L577" href="#L577">577</a><br /><a id="L578" href="#L578">578</a><br /><a id="L579" href="#L579">579</a><br /><a id="L580" href="#L580">580</a><br /><a id="L581" href="#L581">581</a><br /><a id="L582" href="#L582">582</a><br /><a id="L583" href="#L583">583</a><br /><a id="L584" href="#L584">584</a><br /><a id="L585" href="#L585">585</a><br /><a id="L586" href="#L586">586</a><br /><a id="L587" href="#L587">587</a><br /><a id="L588" href="#L588">588</a><br /><a id="L589" href="#L589">589</a><br /><a id="L590" href="#L590">590</a><br /><a id="L591" href="#L591">591</a><br /><a id="L592" href="#L592">592</a><br /><a id="L593" href="#L593">593</a><br /><a id="L594" href="#L594">594</a><br /><a id="L595" href="#L595">595</a><br /><a id="L596" href="#L596">596</a><br /><a id="L597" href="#L597">597</a><br /><a id="L598" href="#L598">598</a><br /><a id="L599" href="#L599">599</a><br /><a id="L600" href="#L600">600</a><br /><a id="L601" href="#L601">601</a><br /><a id="L602" href="#L602">602</a><br /><a id="L603" href="#L603">603</a><br /><a id="L604" href="#L604">604</a><br /><a id="L605" href="#L605">605</a><br /><a id="L606" href="#L606">606</a><br /><a id="L607" href="#L607">607</a><br /><a id="L608" href="#L608">608</a><br /><a id="L609" href="#L609">609</a><br /><a id="L610" href="#L610">610</a><br /><a id="L611" href="#L611">611</a><br /><a id="L612" href="#L612">612</a><br /><a id="L613" href="#L613">613</a><br /><a id="L614" href="#L614">614</a><br /><a id="L615" href="#L615">615</a><br /><a id="L616" href="#L616">616</a><br /><a id="L617" href="#L617">617</a><br /><a id="L618" href="#L618">618</a><br /><a id="L619" href="#L619">619</a><br /><a id="L620" href="#L620">620</a><br /><a id="L621" href="#L621">621</a><br /><a id="L622" href="#L622">622</a><br /><a id="L623" href="#L623">623</a><br /><a id="L624" href="#L624">624</a><br /><a id="L625" href="#L625">625</a><br /><a id="L626" href="#L626">626</a><br /><a id="L627" href="#L627">627</a><br /><a id="L628" href="#L628">628</a><br /><a id="L629" href="#L629">629</a><br /><a id="L630" href="#L630">630</a><br /><a id="L631" href="#L631">631</a><br /><a id="L632" href="#L632">632</a><br /><a id="L633" href="#L633">633</a><br /><a id="L634" href="#L634">634</a><br /><a id="L635" href="#L635">635</a><br /><a id="L636" href="#L636">636</a><br /><a id="L637" href="#L637">637</a><br /><a id="L638" href="#L638">638</a><br /><a id="L639" href="#L639">639</a><br /><a id="L640" href="#L640">640</a><br /><a id="L641" href="#L641">641</a><br /><a id="L642" href="#L642">642</a><br /><a id="L643" href="#L643">643</a><br /><a id="L644" href="#L644">644</a><br /><a id="L645" href="#L645">645</a><br /><a id="L646" href="#L646">646</a><br /><a id="L647" href="#L647">647</a><br /><a id="L648" href="#L648">648</a><br /><a id="L649" href="#L649">649</a><br /><a id="L650" href="#L650">650</a><br /><a id="L651" href="#L651">651</a><br /><a id="L652" href="#L652">652</a><br /><a id="L653" href="#L653">653</a><br /><a id="L654" href="#L654">654</a><br /><a id="L655" href="#L655">655</a><br /><a id="L656" href="#L656">656</a><br /><a id="L657" href="#L657">657</a><br /><a id="L658" href="#L658">658</a><br /><a id="L659" href="#L659">659</a><br /><a id="L660" href="#L660">660</a><br /><a id="L661" href="#L661">661</a><br /><a id="L662" href="#L662">662</a><br /><a id="L663" href="#L663">663</a><br /><a id="L664" href="#L664">664</a><br /><a id="L665" href="#L665">665</a><br /><a id="L666" href="#L666">666</a><br /><a id="L667" href="#L667">667</a><br /><a id="L668" href="#L668">668</a><br /><a id="L669" href="#L669">669</a><br /><a id="L670" href="#L670">670</a><br /><a id="L671" href="#L671">671</a><br /><a id="L672" href="#L672">672</a><br /><a id="L673" href="#L673">673</a><br /><a id="L674" href="#L674">674</a><br /><a id="L675" href="#L675">675</a><br /><a id="L676" href="#L676">676</a><br /><a id="L677" href="#L677">677</a><br /><a id="L678" href="#L678">678</a><br /><a id="L679" href="#L679">679</a><br /><a id="L680" href="#L680">680</a><br /><a id="L681" href="#L681">681</a><br /><a id="L682" href="#L682">682</a><br /><a id="L683" href="#L683">683</a><br /><a id="L684" href="#L684">684</a><br /><a id="L685" href="#L685">685</a><br /><a id="L686" href="#L686">686</a><br /><a id="L687" href="#L687">687</a><br /><a id="L688" href="#L688">688</a><br /><a id="L689" href="#L689">689</a><br /><a id="L690" href="#L690">690</a><br /><a id="L691" href="#L691">691</a><br /><a id="L692" href="#L692">692</a><br /><a id="L693" href="#L693">693</a><br /><a id="L694" href="#L694">694</a><br /><a id="L695" href="#L695">695</a><br /><a id="L696" href="#L696">696</a><br /><a id="L697" href="#L697">697</a><br /><a id="L698" href="#L698">698</a><br /><a id="L699" href="#L699">699</a><br /><a id="L700" href="#L700">700</a><br /><a id="L701" href="#L701">701</a><br /><a id="L702" href="#L702">702</a><br /><a id="L703" href="#L703">703</a><br /><a id="L704" href="#L704">704</a><br /><a id="L705" href="#L705">705</a><br /><a id="L706" href="#L706">706</a><br /><a id="L707" href="#L707">707</a><br /><a id="L708" href="#L708">708</a><br /><a id="L709" href="#L709">709</a><br /><a id="L710" href="#L710">710</a><br /><a id="L711" href="#L711">711</a><br /><a id="L712" href="#L712">712</a><br /><a id="L713" href="#L713">713</a><br /><a id="L714" href="#L714">714</a><br /><a id="L715" href="#L715">715</a><br /><a id="L716" href="#L716">716</a><br /><a id="L717" href="#L717">717</a><br /><a id="L718" href="#L718">718</a><br /><a id="L719" href="#L719">719</a><br /><a id="L720" href="#L720">720</a><br /><a id="L721" href="#L721">721</a><br /><a id="L722" href="#L722">722</a><br /><a id="L723" href="#L723">723</a><br /><a id="L724" href="#L724">724</a><br /><a id="L725" href="#L725">725</a><br /><a id="L726" href="#L726">726</a><br /><a id="L727" href="#L727">727</a><br /><a id="L728" href="#L728">728</a><br /><a id="L729" href="#L729">729</a><br /><a id="L730" href="#L730">730</a><br /><a id="L731" href="#L731">731</a><br /><a id="L732" href="#L732">732</a><br /><a id="L733" href="#L733">733</a><br /><a id="L734" href="#L734">734</a><br /><a id="L735" href="#L735">735</a><br /><a id="L736" href="#L736">736</a><br /><a id="L737" href="#L737">737</a><br /><a id="L738" href="#L738">738</a><br /><a id="L739" href="#L739">739</a><br /><a id="L740" href="#L740">740</a><br /><a id="L741" href="#L741">741</a><br /><a id="L742" href="#L742">742</a><br /><a id="L743" href="#L743">743</a><br /><a id="L744" href="#L744">744</a><br /><a id="L745" href="#L745">745</a><br /><a id="L746" href="#L746">746</a><br /><a id="L747" href="#L747">747</a><br /><a id="L748" href="#L748">748</a><br /><a id="L749" href="#L749">749</a><br /><a id="L750" href="#L750">750</a><br /><a id="L751" href="#L751">751</a><br /><a id="L752" href="#L752">752</a><br /><a id="L753" href="#L753">753</a><br /><a id="L754" href="#L754">754</a><br /><a id="L755" href="#L755">755</a><br /><a id="L756" href="#L756">756</a><br /><a id="L757" href="#L757">757</a><br /><a id="L758" href="#L758">758</a><br /><a id="L759" href="#L759">759</a><br /><a id="L760" href="#L760">760</a><br /><a id="L761" href="#L761">761</a><br /><a id="L762" href="#L762">762</a><br /><a id="L763" href="#L763">763</a><br /><a id="L764" href="#L764">764</a><br /><a id="L765" href="#L765">765</a><br /><a id="L766" href="#L766">766</a><br /><a id="L767" href="#L767">767</a><br /><a id="L768" href="#L768">768</a><br /><a id="L769" href="#L769">769</a><br /><a id="L770" href="#L770">770</a><br /><a id="L771" href="#L771">771</a><br /><a id="L772" href="#L772">772</a><br /><a id="L773" href="#L773">773</a><br /><a id="L774" href="#L774">774</a><br /><a id="L775" href="#L775">775</a><br /><a id="L776" href="#L776">776</a><br /><a id="L777" href="#L777">777</a><br /><a id="L778" href="#L778">778</a><br /><a id="L779" href="#L779">779</a><br /><a id="L780" href="#L780">780</a><br /><a id="L781" href="#L781">781</a><br /><a id="L782" href="#L782">782</a><br /><a id="L783" href="#L783">783</a><br /><a id="L784" href="#L784">784</a><br /><a id="L785" href="#L785">785</a><br /><a id="L786" href="#L786">786</a><br /><a id="L787" href="#L787">787</a><br /><a id="L788" href="#L788">788</a><br /><a id="L789" href="#L789">789</a><br /><a id="L790" href="#L790">790</a><br /><a id="L791" href="#L791">791</a><br /><a id="L792" href="#L792">792</a><br /><a id="L793" href="#L793">793</a><br /><a id="L794" href="#L794">794</a><br /><a id="L795" href="#L795">795</a><br /><a id="L796" href="#L796">796</a><br /><a id="L797" href="#L797">797</a><br /><a id="L798" href="#L798">798</a><br /><a id="L799" href="#L799">799</a><br /><a id="L800" href="#L800">800</a><br /><a id="L801" href="#L801">801</a><br /><a id="L802" href="#L802">802</a><br /><a id="L803" href="#L803">803</a><br /><a id="L804" href="#L804">804</a><br /><a id="L805" href="#L805">805</a><br /><a id="L806" href="#L806">806</a><br /><a id="L807" href="#L807">807</a><br /><a id="L808" href="#L808">808</a><br /><a id="L809" href="#L809">809</a><br /><a id="L810" href="#L810">810</a><br /><a id="L811" href="#L811">811</a><br /><a id="L812" href="#L812">812</a><br /><a id="L813" href="#L813">813</a><br /><a id="L814" href="#L814">814</a><br /><a id="L815" href="#L815">815</a><br /><a id="L816" href="#L816">816</a><br /><a id="L817" href="#L817">817</a><br /><a id="L818" href="#L818">818</a><br /><a id="L819" href="#L819">819</a><br /><a id="L820" href="#L820">820</a><br /><a id="L821" href="#L821">821</a><br /><a id="L822" href="#L822">822</a><br /><a id="L823" href="#L823">823</a><br /><a id="L824" href="#L824">824</a><br /><a id="L825" href="#L825">825</a><br /><a id="L826" href="#L826">826</a><br /><a id="L827" href="#L827">827</a><br /><a id="L828" href="#L828">828</a><br /><a id="L829" href="#L829">829</a><br /><a id="L830" href="#L830">830</a><br /><a id="L831" href="#L831">831</a><br /><a id="L832" href="#L832">832</a><br /><a id="L833" href="#L833">833</a><br /><a id="L834" href="#L834">834</a><br /><a id="L835" href="#L835">835</a><br /><a id="L836" href="#L836">836</a><br /><a id="L837" href="#L837">837</a><br /><a id="L838" href="#L838">838</a><br /><a id="L839" href="#L839">839</a><br /><a id="L840" href="#L840">840</a><br /><a id="L841" href="#L841">841</a><br /><a id="L842" href="#L842">842</a><br /><a id="L843" href="#L843">843</a><br /><a id="L844" href="#L844">844</a><br /><a id="L845" href="#L845">845</a><br /><a id="L846" href="#L846">846</a><br /><a id="L847" href="#L847">847</a><br /><a id="L848" href="#L848">848</a><br /><a id="L849" href="#L849">849</a><br /><a id="L850" href="#L850">850</a><br /><a id="L851" href="#L851">851</a><br /><a id="L852" href="#L852">852</a><br /><a id="L853" href="#L853">853</a><br /><a id="L854" href="#L854">854</a><br /><a id="L855" href="#L855">855</a><br /><a id="L856" href="#L856">856</a><br /><a id="L857" href="#L857">857</a><br /><a id="L858" href="#L858">858</a><br /><a id="L859" href="#L859">859</a><br /><a id="L860" href="#L860">860</a><br /><a id="L861" href="#L861">861</a><br /><a id="L862" href="#L862">862</a><br /><a id="L863" href="#L863">863</a><br /><a id="L864" href="#L864">864</a><br /><a id="L865" href="#L865">865</a><br /><a id="L866" href="#L866">866</a><br /><a id="L867" href="#L867">867</a><br /><a id="L868" href="#L868">868</a><br /><a id="L869" href="#L869">869</a><br /><a id="L870" href="#L870">870</a><br /><a id="L871" href="#L871">871</a><br /><a id="L872" href="#L872">872</a><br /><a id="L873" href="#L873">873</a><br /><a id="L874" href="#L874">874</a><br /><a id="L875" href="#L875">875</a><br /><a id="L876" href="#L876">876</a><br /><a id="L877" href="#L877">877</a><br /><a id="L878" href="#L878">878</a><br /><a id="L879" href="#L879">879</a><br /><a id="L880" href="#L880">880</a><br /><a id="L881" href="#L881">881</a><br /><a id="L882" href="#L882">882</a><br /><a id="L883" href="#L883">883</a><br /><a id="L884" href="#L884">884</a><br /><a id="L885" href="#L885">885</a><br /><a id="L886" href="#L886">886</a><br /><a id="L887" href="#L887">887</a><br /><a id="L888" href="#L888">888</a><br /><a id="L889" href="#L889">889</a><br /><a id="L890" href="#L890">890</a><br /><a id="L891" href="#L891">891</a><br /><a id="L892" href="#L892">892</a><br /><a id="L893" href="#L893">893</a><br /><a id="L894" href="#L894">894</a><br /><a id="L895" href="#L895">895</a><br /><a id="L896" href="#L896">896</a><br /><a id="L897" href="#L897">897</a><br /><a id="L898" href="#L898">898</a><br /><a id="L899" href="#L899">899</a><br /><a id="L900" href="#L900">900</a><br /><a id="L901" href="#L901">901</a><br /><a id="L902" href="#L902">902</a><br /><a id="L903" href="#L903">903</a><br /><a id="L904" href="#L904">904</a><br /><a id="L905" href="#L905">905</a><br /><a id="L906" href="#L906">906</a><br /><a id="L907" href="#L907">907</a><br /><a id="L908" href="#L908">908</a><br /><a id="L909" href="#L909">909</a><br /><a id="L910" href="#L910">910</a><br /><a id="L911" href="#L911">911</a><br /><a id="L912" href="#L912">912</a><br /><a id="L913" href="#L913">913</a><br /><a id="L914" href="#L914">914</a><br /><a id="L915" href="#L915">915</a><br /><a id="L916" href="#L916">916</a><br /><a id="L917" href="#L917">917</a><br /><a id="L918" href="#L918">918</a><br /><a id="L919" href="#L919">919</a><br /><a id="L920" href="#L920">920</a><br /><a id="L921" href="#L921">921</a><br /><a id="L922" href="#L922">922</a><br /><a id="L923" href="#L923">923</a><br /><a id="L924" href="#L924">924</a><br /><a id="L925" href="#L925">925</a><br /><a id="L926" href="#L926">926</a><br /><a id="L927" href="#L927">927</a><br /><a id="L928" href="#L928">928</a><br /><a id="L929" href="#L929">929</a><br /><a id="L930" href="#L930">930</a><br /><a id="L931" href="#L931">931</a><br /><a id="L932" href="#L932">932</a><br /><a id="L933" href="#L933">933</a><br /><a id="L934" href="#L934">934</a><br /><a id="L935" href="#L935">935</a><br /><a id="L936" href="#L936">936</a><br /><a id="L937" href="#L937">937</a><br /><a id="L938" href="#L938">938</a><br /><a id="L939" href="#L939">939</a><br /><a id="L940" href="#L940">940</a><br /><a id="L941" href="#L941">941</a><br /><a id="L942" href="#L942">942</a><br /><a id="L943" href="#L943">943</a><br /><a id="L944" href="#L944">944</a><br /><a id="L945" href="#L945">945</a><br /><a id="L946" href="#L946">946</a><br /><a id="L947" href="#L947">947</a><br /><a id="L948" href="#L948">948</a><br /><a id="L949" href="#L949">949</a><br /><a id="L950" href="#L950">950</a><br /><a id="L951" href="#L951">951</a><br /><a id="L952" href="#L952">952</a><br /><a id="L953" href="#L953">953</a><br /><a id="L954" href="#L954">954</a><br /><a id="L955" href="#L955">955</a><br /><a id="L956" href="#L956">956</a><br /><a id="L957" href="#L957">957</a><br /><a id="L958" href="#L958">958</a><br /><a id="L959" href="#L959">959</a><br /><a id="L960" href="#L960">960</a><br /><a id="L961" href="#L961">961</a><br /><a id="L962" href="#L962">962</a><br /><a id="L963" href="#L963">963</a><br /><a id="L964" href="#L964">964</a><br /><a id="L965" href="#L965">965</a><br /><a id="L966" href="#L966">966</a><br /><a id="L967" href="#L967">967</a><br /><a id="L968" href="#L968">968</a><br /><a id="L969" href="#L969">969</a><br /><a id="L970" href="#L970">970</a><br /><a id="L971" href="#L971">971</a><br /><a id="L972" href="#L972">972</a><br /><a id="L973" href="#L973">973</a><br /><a id="L974" href="#L974">974</a><br /><a id="L975" href="#L975">975</a><br /><a id="L976" href="#L976">976</a><br /><a id="L977" href="#L977">977</a><br /><a id="L978" href="#L978">978</a><br /><a id="L979" href="#L979">979</a><br /><a id="L980" href="#L980">980</a><br /><a id="L981" href="#L981">981</a><br /><a id="L982" href="#L982">982</a><br /><a id="L983" href="#L983">983</a><br /><a id="L984" href="#L984">984</a><br /><a id="L985" href="#L985">985</a><br /><a id="L986" href="#L986">986</a><br /><a id="L987" href="#L987">987</a><br /><a id="L988" href="#L988">988</a><br /><a id="L989" href="#L989">989</a><br /><a id="L990" href="#L990">990</a><br /><a id="L991" href="#L991">991</a><br /><a id="L992" href="#L992">992</a><br /><a id="L993" href="#L993">993</a><br /><a id="L994" href="#L994">994</a><br /><a id="L995" href="#L995">995</a><br /><a id="L996" href="#L996">996</a><br /><a id="L997" href="#L997">997</a><br /><a id="L998" href="#L998">998</a><br /><a id="L999" href="#L999">999</a><br /><a id="L1000" href="#L1000">1000</a><br /><a id="L1001" href="#L1001">1001</a><br /><a id="L1002" href="#L1002">1002</a><br /><a id="L1003" href="#L1003">1003</a><br /><a id="L1004" href="#L1004">1004</a><br /><a id="L1005" href="#L1005">1005</a><br /><a id="L1006" href="#L1006">1006</a><br /><a id="L1007" href="#L1007">1007</a><br /><a id="L1008" href="#L1008">1008</a><br /><a id="L1009" href="#L1009">1009</a><br /><a id="L1010" href="#L1010">1010</a><br /><a id="L1011" href="#L1011">1011</a><br /><a id="L1012" href="#L1012">1012</a><br /><a id="L1013" href="#L1013">1013</a><br /><a id="L1014" href="#L1014">1014</a><br /><a id="L1015" href="#L1015">1015</a><br /><a id="L1016" href="#L1016">1016</a><br /><a id="L1017" href="#L1017">1017</a><br /><a id="L1018" href="#L1018">1018</a><br /><a id="L1019" href="#L1019">1019</a><br /><a id="L1020" href="#L1020">1020</a><br /><a id="L1021" href="#L1021">1021</a><br /><a id="L1022" href="#L1022">1022</a><br /><a id="L1023" href="#L1023">1023</a><br /><a id="L1024" href="#L1024">1024</a><br /><a id="L1025" href="#L1025">1025</a><br /><a id="L1026" href="#L1026">1026</a><br /><a id="L1027" href="#L1027">1027</a><br /><a id="L1028" href="#L1028">1028</a><br /><a id="L1029" href="#L1029">1029</a><br /><a id="L1030" href="#L1030">1030</a><br /><a id="L1031" href="#L1031">1031</a><br /><a id="L1032" href="#L1032">1032</a><br /><a id="L1033" href="#L1033">1033</a><br /><a id="L1034" href="#L1034">1034</a><br /><a id="L1035" href="#L1035">1035</a><br /><a id="L1036" href="#L1036">1036</a><br /><a id="L1037" href="#L1037">1037</a><br /><a id="L1038" href="#L1038">1038</a><br /><a id="L1039" href="#L1039">1039</a><br /><a id="L1040" href="#L1040">1040</a><br /><a id="L1041" href="#L1041">1041</a><br /><a id="L1042" href="#L1042">1042</a><br /><a id="L1043" href="#L1043">1043</a><br /><a id="L1044" href="#L1044">1044</a><br /><a id="L1045" href="#L1045">1045</a><br /><a id="L1046" href="#L1046">1046</a><br /><a id="L1047" href="#L1047">1047</a><br /><a id="L1048" href="#L1048">1048</a><br /><a id="L1049" href="#L1049">1049</a><br /><a id="L1050" href="#L1050">1050</a><br /><a id="L1051" href="#L1051">1051</a><br /><a id="L1052" href="#L1052">1052</a><br /><a id="L1053" href="#L1053">1053</a><br /><a id="L1054" href="#L1054">1054</a><br /><a id="L1055" href="#L1055">1055</a><br /><a id="L1056" href="#L1056">1056</a><br /><a id="L1057" href="#L1057">1057</a><br /><a id="L1058" href="#L1058">1058</a><br /><a id="L1059" href="#L1059">1059</a><br /><a id="L1060" href="#L1060">1060</a><br /><a id="L1061" href="#L1061">1061</a><br /><a id="L1062" href="#L1062">1062</a><br /><a id="L1063" href="#L1063">1063</a><br /><a id="L1064" href="#L1064">1064</a><br /><a id="L1065" href="#L1065">1065</a><br /><a id="L1066" href="#L1066">1066</a><br /><a id="L1067" href="#L1067">1067</a><br /><a id="L1068" href="#L1068">1068</a><br /><a id="L1069" href="#L1069">1069</a><br /><a id="L1070" href="#L1070">1070</a><br /><a id="L1071" href="#L1071">1071</a><br /><a id="L1072" href="#L1072">1072</a><br /><a id="L1073" href="#L1073">1073</a><br /><a id="L1074" href="#L1074">1074</a><br /><a id="L1075" href="#L1075">1075</a><br /><a id="L1076" href="#L1076">1076</a><br /><a id="L1077" href="#L1077">1077</a><br /><a id="L1078" href="#L1078">1078</a><br /><a id="L1079" href="#L1079">1079</a><br /><a id="L1080" href="#L1080">1080</a><br /><a id="L1081" href="#L1081">1081</a><br /><a id="L1082" href="#L1082">1082</a><br /><a id="L1083" href="#L1083">1083</a><br /><a id="L1084" href="#L1084">1084</a><br /><a id="L1085" href="#L1085">1085</a><br /><a id="L1086" href="#L1086">1086</a><br /><a id="L1087" href="#L1087">1087</a><br /><a id="L1088" href="#L1088">1088</a><br /><a id="L1089" href="#L1089">1089</a><br /><a id="L1090" href="#L1090">1090</a><br /><a id="L1091" href="#L1091">1091</a><br /><a id="L1092" href="#L1092">1092</a><br /><a id="L1093" href="#L1093">1093</a><br /><a id="L1094" href="#L1094">1094</a><br /><a id="L1095" href="#L1095">1095</a><br /><a id="L1096" href="#L1096">1096</a><br /><a id="L1097" href="#L1097">1097</a><br /><a id="L1098" href="#L1098">1098</a><br /><a id="L1099" href="#L1099">1099</a><br /><a id="L1100" href="#L1100">1100</a><br /><a id="L1101" href="#L1101">1101</a><br /><a id="L1102" href="#L1102">1102</a><br /><a id="L1103" href="#L1103">1103</a><br /><a id="L1104" href="#L1104">1104</a><br /><a id="L1105" href="#L1105">1105</a><br /><a id="L1106" href="#L1106">1106</a><br /><a id="L1107" href="#L1107">1107</a><br /><a id="L1108" href="#L1108">1108</a><br /><a id="L1109" href="#L1109">1109</a><br /><a id="L1110" href="#L1110">1110</a><br /><a id="L1111" href="#L1111">1111</a><br /><a id="L1112" href="#L1112">1112</a><br /><a id="L1113" href="#L1113">1113</a><br /><a id="L1114" href="#L1114">1114</a><br /><a id="L1115" href="#L1115">1115</a><br /><a id="L1116" href="#L1116">1116</a><br /><a id="L1117" href="#L1117">1117</a><br /><a id="L1118" href="#L1118">1118</a><br /><a id="L1119" href="#L1119">1119</a><br /><a id="L1120" href="#L1120">1120</a><br /><a id="L1121" href="#L1121">1121</a><br /><a id="L1122" href="#L1122">1122</a><br /><a id="L1123" href="#L1123">1123</a><br /><a id="L1124" href="#L1124">1124</a><br /><a id="L1125" href="#L1125">1125</a><br /><a id="L1126" href="#L1126">1126</a><br /><a id="L1127" href="#L1127">1127</a><br /><a id="L1128" href="#L1128">1128</a><br /><a id="L1129" href="#L1129">1129</a><br /><a id="L1130" href="#L1130">1130</a><br /><a id="L1131" href="#L1131">1131</a><br /><a id="L1132" href="#L1132">1132</a><br /><a id="L1133" href="#L1133">1133</a><br /><a id="L1134" href="#L1134">1134</a><br /><a id="L1135" href="#L1135">1135</a><br /><a id="L1136" href="#L1136">1136</a><br /><a id="L1137" href="#L1137">1137</a><br /><a id="L1138" href="#L1138">1138</a><br /><a id="L1139" href="#L1139">1139</a><br /><a id="L1140" href="#L1140">1140</a><br /><a id="L1141" href="#L1141">1141</a><br /><a id="L1142" href="#L1142">1142</a><br /><a id="L1143" href="#L1143">1143</a><br /><a id="L1144" href="#L1144">1144</a><br /><a id="L1145" href="#L1145">1145</a><br /><a id="L1146" href="#L1146">1146</a><br /><a id="L1147" href="#L1147">1147</a><br /><a id="L1148" href="#L1148">1148</a><br /><a id="L1149" href="#L1149">1149</a><br /><a id="L1150" href="#L1150">1150</a><br /><a id="L1151" href="#L1151">1151</a><br /><a id="L1152" href="#L1152">1152</a><br /><a id="L1153" href="#L1153">1153</a><br /><a id="L1154" href="#L1154">1154</a><br /><a id="L1155" href="#L1155">1155</a><br /><a id="L1156" href="#L1156">1156</a><br /><a id="L1157" href="#L1157">1157</a><br /><a id="L1158" href="#L1158">1158</a><br /><a id="L1159" href="#L1159">1159</a><br /><a id="L1160" href="#L1160">1160</a><br /><a id="L1161" href="#L1161">1161</a><br /><a id="L1162" href="#L1162">1162</a><br /><a id="L1163" href="#L1163">1163</a><br /><a id="L1164" href="#L1164">1164</a><br /><a id="L1165" href="#L1165">1165</a><br /><a id="L1166" href="#L1166">1166</a><br /><a id="L1167" href="#L1167">1167</a><br /><a id="L1168" href="#L1168">1168</a><br /><a id="L1169" href="#L1169">1169</a><br /><a id="L1170" href="#L1170">1170</a><br /><a id="L1171" href="#L1171">1171</a><br /><a id="L1172" href="#L1172">1172</a><br /><a id="L1173" href="#L1173">1173</a><br /><a id="L1174" href="#L1174">1174</a><br /><a id="L1175" href="#L1175">1175</a><br /><a id="L1176" href="#L1176">1176</a><br /><a id="L1177" href="#L1177">1177</a><br /><a id="L1178" href="#L1178">1178</a><br /><a id="L1179" href="#L1179">1179</a><br /><a id="L1180" href="#L1180">1180</a><br /><a id="L1181" href="#L1181">1181</a><br /><a id="L1182" href="#L1182">1182</a><br /><a id="L1183" href="#L1183">1183</a><br /><a id="L1184" href="#L1184">1184</a><br /><a id="L1185" href="#L1185">1185</a><br /><a id="L1186" href="#L1186">1186</a><br /><a id="L1187" href="#L1187">1187</a><br /><a id="L1188" href="#L1188">1188</a><br /><a id="L1189" href="#L1189">1189</a><br /><a id="L1190" href="#L1190">1190</a><br /><a id="L1191" href="#L1191">1191</a><br /><a id="L1192" href="#L1192">1192</a><br /><a id="L1193" href="#L1193">1193</a><br /><a id="L1194" href="#L1194">1194</a><br /><a id="L1195" href="#L1195">1195</a><br /><a id="L1196" href="#L1196">1196</a><br /><a id="L1197" href="#L1197">1197</a><br /><a id="L1198" href="#L1198">1198</a><br /><a id="L1199" href="#L1199">1199</a><br /><a id="L1200" href="#L1200">1200</a><br /><a id="L1201" href="#L1201">1201</a><br /><a id="L1202" href="#L1202">1202</a><br /><a id="L1203" href="#L1203">1203</a><br /><a id="L1204" href="#L1204">1204</a><br /><a id="L1205" href="#L1205">1205</a><br /><a id="L1206" href="#L1206">1206</a><br /><a id="L1207" href="#L1207">1207</a><br /><a id="L1208" href="#L1208">1208</a><br /><a id="L1209" href="#L1209">1209</a><br /><a id="L1210" href="#L1210">1210</a><br /><a id="L1211" href="#L1211">1211</a><br /><a id="L1212" href="#L1212">1212</a><br /><a id="L1213" href="#L1213">1213</a><br /><a id="L1214" href="#L1214">1214</a><br /><a id="L1215" href="#L1215">1215</a><br /><a id="L1216" href="#L1216">1216</a><br /><a id="L1217" href="#L1217">1217</a><br /><a id="L1218" href="#L1218">1218</a><br /><a id="L1219" href="#L1219">1219</a><br /><a id="L1220" href="#L1220">1220</a><br /><a id="L1221" href="#L1221">1221</a><br /><a id="L1222" href="#L1222">1222</a><br /><a id="L1223" href="#L1223">1223</a><br /><a id="L1224" href="#L1224">1224</a><br /><a id="L1225" href="#L1225">1225</a><br /><a id="L1226" href="#L1226">1226</a><br /><a id="L1227" href="#L1227">1227</a><br /><a id="L1228" href="#L1228">1228</a><br /><a id="L1229" href="#L1229">1229</a><br /><a id="L1230" href="#L1230">1230</a><br /><a id="L1231" href="#L1231">1231</a><br /><a id="L1232" href="#L1232">1232</a><br /><a id="L1233" href="#L1233">1233</a><br /><a id="L1234" href="#L1234">1234</a><br /><a id="L1235" href="#L1235">1235</a><br /><a id="L1236" href="#L1236">1236</a><br /><a id="L1237" href="#L1237">1237</a><br /><a id="L1238" href="#L1238">1238</a><br /><a id="L1239" href="#L1239">1239</a><br /><a id="L1240" href="#L1240">1240</a><br /><a id="L1241" href="#L1241">1241</a><br /><a id="L1242" href="#L1242">1242</a><br /><a id="L1243" href="#L1243">1243</a><br /><a id="L1244" href="#L1244">1244</a><br /><a id="L1245" href="#L1245">1245</a><br /><a id="L1246" href="#L1246">1246</a><br /><a id="L1247" href="#L1247">1247</a><br /><a id="L1248" href="#L1248">1248</a><br /><a id="L1249" href="#L1249">1249</a><br /><a id="L1250" href="#L1250">1250</a><br /><a id="L1251" href="#L1251">1251</a><br /><a id="L1252" href="#L1252">1252</a><br /><a id="L1253" href="#L1253">1253</a><br /><a id="L1254" href="#L1254">1254</a><br /><a id="L1255" href="#L1255">1255</a><br /><a id="L1256" href="#L1256">1256</a><br /><a id="L1257" href="#L1257">1257</a><br /><a id="L1258" href="#L1258">1258</a><br /><a id="L1259" href="#L1259">1259</a><br /><a id="L1260" href="#L1260">1260</a><br /><a id="L1261" href="#L1261">1261</a><br /><a id="L1262" href="#L1262">1262</a><br /><a id="L1263" href="#L1263">1263</a><br /><a id="L1264" href="#L1264">1264</a><br /><a id="L1265" href="#L1265">1265</a><br /><a id="L1266" href="#L1266">1266</a><br /><a id="L1267" href="#L1267">1267</a><br /><a id="L1268" href="#L1268">1268</a><br /><a id="L1269" href="#L1269">1269</a><br /><a id="L1270" href="#L1270">1270</a><br /><a id="L1271" href="#L1271">1271</a><br /><a id="L1272" href="#L1272">1272</a><br /><a id="L1273" href="#L1273">1273</a><br /><a id="L1274" href="#L1274">1274</a><br /><a id="L1275" href="#L1275">1275</a><br /><a id="L1276" href="#L1276">1276</a><br /><a id="L1277" href="#L1277">1277</a><br /><a id="L1278" href="#L1278">1278</a><br /><a id="L1279" href="#L1279">1279</a><br /><a id="L1280" href="#L1280">1280</a><br /><a id="L1281" href="#L1281">1281</a><br /><a id="L1282" href="#L1282">1282</a><br /><a id="L1283" href="#L1283">1283</a><br /><a id="L1284" href="#L1284">1284</a><br /><a id="L1285" href="#L1285">1285</a><br /><a id="L1286" href="#L1286">1286</a><br /><a id="L1287" href="#L1287">1287</a><br /><a id="L1288" href="#L1288">1288</a><br /><a id="L1289" href="#L1289">1289</a><br /><a id="L1290" href="#L1290">1290</a><br /><a id="L1291" href="#L1291">1291</a><br /><a id="L1292" href="#L1292">1292</a><br /><a id="L1293" href="#L1293">1293</a><br /><a id="L1294" href="#L1294">1294</a><br /><a id="L1295" href="#L1295">1295</a><br /><a id="L1296" href="#L1296">1296</a><br /><a id="L1297" href="#L1297">1297</a><br /><a id="L1298" href="#L1298">1298</a><br /><a id="L1299" href="#L1299">1299</a><br /><a id="L1300" href="#L1300">1300</a><br /><a id="L1301" href="#L1301">1301</a><br /><a id="L1302" href="#L1302">1302</a><br /><a id="L1303" href="#L1303">1303</a><br /><a id="L1304" href="#L1304">1304</a><br /><a id="L1305" href="#L1305">1305</a><br /><a id="L1306" href="#L1306">1306</a><br /><a id="L1307" href="#L1307">1307</a><br /><a id="L1308" href="#L1308">1308</a><br /><a id="L1309" href="#L1309">1309</a><br /><a id="L1310" href="#L1310">1310</a><br /><a id="L1311" href="#L1311">1311</a><br /><a id="L1312" href="#L1312">1312</a><br /><a id="L1313" href="#L1313">1313</a><br /><a id="L1314" href="#L1314">1314</a><br /><a id="L1315" href="#L1315">1315</a><br /><a id="L1316" href="#L1316">1316</a><br /><a id="L1317" href="#L1317">1317</a><br /><a id="L1318" href="#L1318">1318</a><br /><a id="L1319" href="#L1319">1319</a><br /><a id="L1320" href="#L1320">1320</a><br /><a id="L1321" href="#L1321">1321</a><br /><a id="L1322" href="#L1322">1322</a><br /><a id="L1323" href="#L1323">1323</a><br /><a id="L1324" href="#L1324">1324</a><br /><a id="L1325" href="#L1325">1325</a><br /><a id="L1326" href="#L1326">1326</a><br /><a id="L1327" href="#L1327">1327</a><br /><a id="L1328" href="#L1328">1328</a><br /><a id="L1329" href="#L1329">1329</a><br /><a id="L1330" href="#L1330">1330</a><br /><a id="L1331" href="#L1331">1331</a><br /><a id="L1332" href="#L1332">1332</a><br /><a id="L1333" href="#L1333">1333</a><br /><a id="L1334" href="#L1334">1334</a><br /><a id="L1335" href="#L1335">1335</a><br /><a id="L1336" href="#L1336">1336</a><br /><a id="L1337" href="#L1337">1337</a><br /><a id="L1338" href="#L1338">1338</a><br /><a id="L1339" href="#L1339">1339</a><br /><a id="L1340" href="#L1340">1340</a><br /><a id="L1341" href="#L1341">1341</a><br /><a id="L1342" href="#L1342">1342</a><br /><a id="L1343" href="#L1343">1343</a><br /><a id="L1344" href="#L1344">1344</a><br /><a id="L1345" href="#L1345">1345</a><br /><a id="L1346" href="#L1346">1346</a><br /><a id="L1347" href="#L1347">1347</a><br /><a id="L1348" href="#L1348">1348</a><br /><a id="L1349" href="#L1349">1349</a><br /><a id="L1350" href="#L1350">1350</a><br /><a id="L1351" href="#L1351">1351</a><br /><a id="L1352" href="#L1352">1352</a><br /><a id="L1353" href="#L1353">1353</a><br /><a id="L1354" href="#L1354">1354</a><br /><a id="L1355" href="#L1355">1355</a><br /><a id="L1356" href="#L1356">1356</a><br /><a id="L1357" href="#L1357">1357</a><br /><a id="L1358" href="#L1358">1358</a><br /><a id="L1359" href="#L1359">1359</a><br /><a id="L1360" href="#L1360">1360</a><br /><a id="L1361" href="#L1361">1361</a><br /><a id="L1362" href="#L1362">1362</a><br /><a id="L1363" href="#L1363">1363</a><br /><a id="L1364" href="#L1364">1364</a><br /><a id="L1365" href="#L1365">1365</a><br /><a id="L1366" href="#L1366">1366</a><br /><a id="L1367" href="#L1367">1367</a><br /><a id="L1368" href="#L1368">1368</a><br /><a id="L1369" href="#L1369">1369</a><br /><a id="L1370" href="#L1370">1370</a><br /><a id="L1371" href="#L1371">1371</a><br /><a id="L1372" href="#L1372">1372</a><br /><a id="L1373" href="#L1373">1373</a><br /><a id="L1374" href="#L1374">1374</a><br /><a id="L1375" href="#L1375">1375</a><br /><a id="L1376" href="#L1376">1376</a><br /><a id="L1377" href="#L1377">1377</a><br /><a id="L1378" href="#L1378">1378</a><br /><a id="L1379" href="#L1379">1379</a><br /><a id="L1380" href="#L1380">1380</a><br /><a id="L1381" href="#L1381">1381</a><br /><a id="L1382" href="#L1382">1382</a><br /><a id="L1383" href="#L1383">1383</a><br /><a id="L1384" href="#L1384">1384</a><br /><a id="L1385" href="#L1385">1385</a><br /><a id="L1386" href="#L1386">1386</a><br /><a id="L1387" href="#L1387">1387</a><br /><a id="L1388" href="#L1388">1388</a><br /><a id="L1389" href="#L1389">1389</a><br /><a id="L1390" href="#L1390">1390</a><br /><a id="L1391" href="#L1391">1391</a><br /><a id="L1392" href="#L1392">1392</a><br /><a id="L1393" href="#L1393">1393</a><br /><a id="L1394" href="#L1394">1394</a><br /><a id="L1395" href="#L1395">1395</a><br /><a id="L1396" href="#L1396">1396</a><br /><a id="L1397" href="#L1397">1397</a><br /><a id="L1398" href="#L1398">1398</a><br /><a id="L1399" href="#L1399">1399</a><br /><a id="L1400" href="#L1400">1400</a><br /><a id="L1401" href="#L1401">1401</a><br /><a id="L1402" href="#L1402">1402</a><br /><a id="L1403" href="#L1403">1403</a><br /><a id="L1404" href="#L1404">1404</a><br /><a id="L1405" href="#L1405">1405</a><br /><a id="L1406" href="#L1406">1406</a><br /><a id="L1407" href="#L1407">1407</a><br /><a id="L1408" href="#L1408">1408</a><br /><a id="L1409" href="#L1409">1409</a><br /><a id="L1410" href="#L1410">1410</a><br /><a id="L1411" href="#L1411">1411</a><br /><a id="L1412" href="#L1412">1412</a><br /><a id="L1413" href="#L1413">1413</a><br /><a id="L1414" href="#L1414">1414</a><br /><a id="L1415" href="#L1415">1415</a><br /><a id="L1416" href="#L1416">1416</a><br /><a id="L1417" href="#L1417">1417</a><br /><a id="L1418" href="#L1418">1418</a><br /><a id="L1419" href="#L1419">1419</a><br /><a id="L1420" href="#L1420">1420</a><br /><a id="L1421" href="#L1421">1421</a><br /><a id="L1422" href="#L1422">1422</a><br /><a id="L1423" href="#L1423">1423</a><br /><a id="L1424" href="#L1424">1424</a><br /><a id="L1425" href="#L1425">1425</a><br /><a id="L1426" href="#L1426">1426</a><br /><a id="L1427" href="#L1427">1427</a><br /><a id="L1428" href="#L1428">1428</a><br /><a id="L1429" href="#L1429">1429</a><br /><a id="L1430" href="#L1430">1430</a><br /><a id="L1431" href="#L1431">1431</a><br /><a id="L1432" href="#L1432">1432</a><br /><a id="L1433" href="#L1433">1433</a><br /><a id="L1434" href="#L1434">1434</a><br /><a id="L1435" href="#L1435">1435</a><br /><a id="L1436" href="#L1436">1436</a><br /><a id="L1437" href="#L1437">1437</a><br /><a id="L1438" href="#L1438">1438</a><br /><a id="L1439" href="#L1439">1439</a><br /><a id="L1440" href="#L1440">1440</a><br /><a id="L1441" href="#L1441">1441</a><br /><a id="L1442" href="#L1442">1442</a><br /><a id="L1443" href="#L1443">1443</a><br /><a id="L1444" href="#L1444">1444</a><br /><a id="L1445" href="#L1445">1445</a><br /><a id="L1446" href="#L1446">1446</a><br /><a id="L1447" href="#L1447">1447</a><br /><a id="L1448" href="#L1448">1448</a><br /><a id="L1449" href="#L1449">1449</a><br /><a id="L1450" href="#L1450">1450</a><br /><a id="L1451" href="#L1451">1451</a><br /><a id="L1452" href="#L1452">1452</a><br /><a id="L1453" href="#L1453">1453</a><br /><a id="L1454" href="#L1454">1454</a><br /><a id="L1455" href="#L1455">1455</a><br /><a id="L1456" href="#L1456">1456</a><br /><a id="L1457" href="#L1457">1457</a><br /><a id="L1458" href="#L1458">1458</a><br /><a id="L1459" href="#L1459">1459</a><br /><a id="L1460" href="#L1460">1460</a><br /><a id="L1461" href="#L1461">1461</a><br /><a id="L1462" href="#L1462">1462</a><br /><a id="L1463" href="#L1463">1463</a><br /><a id="L1464" href="#L1464">1464</a><br /><a id="L1465" href="#L1465">1465</a><br /><a id="L1466" href="#L1466">1466</a><br /><a id="L1467" href="#L1467">1467</a><br /><a id="L1468" href="#L1468">1468</a><br /><a id="L1469" href="#L1469">1469</a><br /><a id="L1470" href="#L1470">1470</a><br /><a id="L1471" href="#L1471">1471</a><br /><a id="L1472" href="#L1472">1472</a><br /><a id="L1473" href="#L1473">1473</a><br /><a id="L1474" href="#L1474">1474</a><br /><a id="L1475" href="#L1475">1475</a><br /><a id="L1476" href="#L1476">1476</a><br /><a id="L1477" href="#L1477">1477</a><br /><a id="L1478" href="#L1478">1478</a><br /><a id="L1479" href="#L1479">1479</a><br /><a id="L1480" href="#L1480">1480</a><br /><a id="L1481" href="#L1481">1481</a><br /><a id="L1482" href="#L1482">1482</a><br /><a id="L1483" href="#L1483">1483</a><br /><a id="L1484" href="#L1484">1484</a><br /><a id="L1485" href="#L1485">1485</a><br /><a id="L1486" href="#L1486">1486</a><br /><a id="L1487" href="#L1487">1487</a><br /><a id="L1488" href="#L1488">1488</a><br /><a id="L1489" href="#L1489">1489</a><br /><a id="L1490" href="#L1490">1490</a><br /><a id="L1491" href="#L1491">1491</a><br /><a id="L1492" href="#L1492">1492</a><br /><a id="L1493" href="#L1493">1493</a><br /><a id="L1494" href="#L1494">1494</a><br /><a id="L1495" href="#L1495">1495</a><br /><a id="L1496" href="#L1496">1496</a><br /><a id="L1497" href="#L1497">1497</a><br /><a id="L1498" href="#L1498">1498</a><br /><a id="L1499" href="#L1499">1499</a><br /><a id="L1500" href="#L1500">1500</a><br /><a id="L1501" href="#L1501">1501</a><br /><a id="L1502" href="#L1502">1502</a><br /><a id="L1503" href="#L1503">1503</a><br /><a id="L1504" href="#L1504">1504</a><br /><a id="L1505" href="#L1505">1505</a><br /><a id="L1506" href="#L1506">1506</a><br /><a id="L1507" href="#L1507">1507</a><br /><a id="L1508" href="#L1508">1508</a><br /><a id="L1509" href="#L1509">1509</a><br /><a id="L1510" href="#L1510">1510</a><br /><a id="L1511" href="#L1511">1511</a><br /><a id="L1512" href="#L1512">1512</a><br /><a id="L1513" href="#L1513">1513</a><br /><a id="L1514" href="#L1514">1514</a><br /><a id="L1515" href="#L1515">1515</a><br /><a id="L1516" href="#L1516">1516</a><br /><a id="L1517" href="#L1517">1517</a><br /><a id="L1518" href="#L1518">1518</a><br /><a id="L1519" href="#L1519">1519</a><br /><a id="L1520" href="#L1520">1520</a><br /><a id="L1521" href="#L1521">1521</a><br /><a id="L1522" href="#L1522">1522</a><br /><a id="L1523" href="#L1523">1523</a><br /><a id="L1524" href="#L1524">1524</a><br /><a id="L1525" href="#L1525">1525</a><br /><a id="L1526" href="#L1526">1526</a><br /><a id="L1527" href="#L1527">1527</a><br /><a id="L1528" href="#L1528">1528</a><br /><a id="L1529" href="#L1529">1529</a><br /><a id="L1530" href="#L1530">1530</a><br /><a id="L1531" href="#L1531">1531</a><br /><a id="L1532" href="#L1532">1532</a><br /><a id="L1533" href="#L1533">1533</a><br /><a id="L1534" href="#L1534">1534</a><br /><a id="L1535" href="#L1535">1535</a><br /><a id="L1536" href="#L1536">1536</a><br /><a id="L1537" href="#L1537">1537</a><br /><a id="L1538" href="#L1538">1538</a><br /><a id="L1539" href="#L1539">1539</a><br /><a id="L1540" href="#L1540">1540</a><br /><a id="L1541" href="#L1541">1541</a><br /><a id="L1542" href="#L1542">1542</a><br /><a id="L1543" href="#L1543">1543</a><br /><a id="L1544" href="#L1544">1544</a><br /><a id="L1545" href="#L1545">1545</a><br /><a id="L1546" href="#L1546">1546</a><br /><a id="L1547" href="#L1547">1547</a><br /><a id="L1548" href="#L1548">1548</a><br /><a id="L1549" href="#L1549">1549</a><br /><a id="L1550" href="#L1550">1550</a><br /><a id="L1551" href="#L1551">1551</a><br /><a id="L1552" href="#L1552">1552</a><br /><a id="L1553" href="#L1553">1553</a><br /><a id="L1554" href="#L1554">1554</a><br /><a id="L1555" href="#L1555">1555</a><br /><a id="L1556" href="#L1556">1556</a><br /><a id="L1557" href="#L1557">1557</a><br /><a id="L1558" href="#L1558">1558</a><br /><a id="L1559" href="#L1559">1559</a><br /><a id="L1560" href="#L1560">1560</a><br /><a id="L1561" href="#L1561">1561</a><br /><a id="L1562" href="#L1562">1562</a><br /><a id="L1563" href="#L1563">1563</a><br /><a id="L1564" href="#L1564">1564</a><br /><a id="L1565" href="#L1565">1565</a><br /><a id="L1566" href="#L1566">1566</a><br /><a id="L1567" href="#L1567">1567</a><br /><a id="L1568" href="#L1568">1568</a><br /><a id="L1569" href="#L1569">1569</a><br /><a id="L1570" href="#L1570">1570</a><br /><a id="L1571" href="#L1571">1571</a><br /><a id="L1572" href="#L1572">1572</a><br /><a id="L1573" href="#L1573">1573</a><br /><a id="L1574" href="#L1574">1574</a><br /><a id="L1575" href="#L1575">1575</a><br /><a id="L1576" href="#L1576">1576</a><br /><a id="L1577" href="#L1577">1577</a><br /><a id="L1578" href="#L1578">1578</a><br /><a id="L1579" href="#L1579">1579</a><br /><a id="L1580" href="#L1580">1580</a><br /><a id="L1581" href="#L1581">1581</a><br /><a id="L1582" href="#L1582">1582</a><br /><a id="L1583" href="#L1583">1583</a><br /><a id="L1584" href="#L1584">1584</a><br /><a id="L1585" href="#L1585">1585</a><br /><a id="L1586" href="#L1586">1586</a><br /><a id="L1587" href="#L1587">1587</a><br /><a id="L1588" href="#L1588">1588</a><br /><a id="L1589" href="#L1589">1589</a><br /><a id="L1590" href="#L1590">1590</a><br /><a id="L1591" href="#L1591">1591</a><br /><a id="L1592" href="#L1592">1592</a><br /><a id="L1593" href="#L1593">1593</a><br /><a id="L1594" href="#L1594">1594</a><br /><a id="L1595" href="#L1595">1595</a><br /><a id="L1596" href="#L1596">1596</a><br /><a id="L1597" href="#L1597">1597</a><br /><a id="L1598" href="#L1598">1598</a><br /><a id="L1599" href="#L1599">1599</a><br /><a id="L1600" href="#L1600">1600</a><br /><a id="L1601" href="#L1601">1601</a><br /><a id="L1602" href="#L1602">1602</a><br /><a id="L1603" href="#L1603">1603</a><br /><a id="L1604" href="#L1604">1604</a><br /><a id="L1605" href="#L1605">1605</a><br /><a id="L1606" href="#L1606">1606</a><br /><a id="L1607" href="#L1607">1607</a><br /><a id="L1608" href="#L1608">1608</a><br /><a id="L1609" href="#L1609">1609</a><br /><a id="L1610" href="#L1610">1610</a><br /><a id="L1611" href="#L1611">1611</a><br /><a id="L1612" href="#L1612">1612</a><br /><a id="L1613" href="#L1613">1613</a><br /><a id="L1614" href="#L1614">1614</a><br /><a id="L1615" href="#L1615">1615</a><br /><a id="L1616" href="#L1616">1616</a><br /><a id="L1617" href="#L1617">1617</a><br /><a id="L1618" href="#L1618">1618</a><br /><a id="L1619" href="#L1619">1619</a><br /><a id="L1620" href="#L1620">1620</a><br /><a id="L1621" href="#L1621">1621</a><br /><a id="L1622" href="#L1622">1622</a><br /><a id="L1623" href="#L1623">1623</a><br /><a id="L1624" href="#L1624">1624</a><br /><a id="L1625" href="#L1625">1625</a><br /><a id="L1626" href="#L1626">1626</a><br /><a id="L1627" href="#L1627">1627</a><br /><a id="L1628" href="#L1628">1628</a><br /><a id="L1629" href="#L1629">1629</a><br /><a id="L1630" href="#L1630">1630</a><br /><a id="L1631" href="#L1631">1631</a><br /><a id="L1632" href="#L1632">1632</a><br /><a id="L1633" href="#L1633">1633</a><br /><a id="L1634" href="#L1634">1634</a><br /><a id="L1635" href="#L1635">1635</a><br /><a id="L1636" href="#L1636">1636</a><br /><a id="L1637" href="#L1637">1637</a><br /><a id="L1638" href="#L1638">1638</a><br /><a id="L1639" href="#L1639">1639</a><br /><a id="L1640" href="#L1640">1640</a><br /><a id="L1641" href="#L1641">1641</a><br /><a id="L1642" href="#L1642">1642</a><br /><a id="L1643" href="#L1643">1643</a><br /><a id="L1644" href="#L1644">1644</a><br /><a id="L1645" href="#L1645">1645</a><br /><a id="L1646" href="#L1646">1646</a><br /><a id="L1647" href="#L1647">1647</a><br /><a id="L1648" href="#L1648">1648</a><br /><a id="L1649" href="#L1649">1649</a><br /><a id="L1650" href="#L1650">1650</a><br /><a id="L1651" href="#L1651">1651</a><br /><a id="L1652" href="#L1652">1652</a><br /><a id="L1653" href="#L1653">1653</a><br /><a id="L1654" href="#L1654">1654</a><br /><a id="L1655" href="#L1655">1655</a><br /><a id="L1656" href="#L1656">1656</a><br /><a id="L1657" href="#L1657">1657</a><br /><a id="L1658" href="#L1658">1658</a><br /><a id="L1659" href="#L1659">1659</a><br /><a id="L1660" href="#L1660">1660</a><br /><a id="L1661" href="#L1661">1661</a><br /><a id="L1662" href="#L1662">1662</a><br /><a id="L1663" href="#L1663">1663</a><br /><a id="L1664" href="#L1664">1664</a><br /><a id="L1665" href="#L1665">1665</a><br /><a id="L1666" href="#L1666">1666</a><br /><a id="L1667" href="#L1667">1667</a><br /><a id="L1668" href="#L1668">1668</a><br /><a id="L1669" href="#L1669">1669</a><br /><a id="L1670" href="#L1670">1670</a><br /><a id="L1671" href="#L1671">1671</a><br /><a id="L1672" href="#L1672">1672</a><br /><a id="L1673" href="#L1673">1673</a><br /><a id="L1674" href="#L1674">1674</a><br /><a id="L1675" href="#L1675">1675</a><br /><a id="L1676" href="#L1676">1676</a><br /><a id="L1677" href="#L1677">1677</a><br /><a id="L1678" href="#L1678">1678</a><br /><a id="L1679" href="#L1679">1679</a><br /><a id="L1680" href="#L1680">1680</a><br /><a id="L1681" href="#L1681">1681</a><br /><a id="L1682" href="#L1682">1682</a><br /><a id="L1683" href="#L1683">1683</a><br /><a id="L1684" href="#L1684">1684</a><br /><a id="L1685" href="#L1685">1685</a><br /><a id="L1686" href="#L1686">1686</a><br /><a id="L1687" href="#L1687">1687</a><br /><a id="L1688" href="#L1688">1688</a><br /><a id="L1689" href="#L1689">1689</a><br /><a id="L1690" href="#L1690">1690</a><br /><a id="L1691" href="#L1691">1691</a><br /><a id="L1692" href="#L1692">1692</a><br /><a id="L1693" href="#L1693">1693</a><br /><a id="L1694" href="#L1694">1694</a><br /><a id="L1695" href="#L1695">1695</a><br /><a id="L1696" href="#L1696">1696</a><br /><a id="L1697" href="#L1697">1697</a><br /><a id="L1698" href="#L1698">1698</a><br /><a id="L1699" href="#L1699">1699</a><br /><a id="L1700" href="#L1700">1700</a><br /><a id="L1701" href="#L1701">1701</a><br /><a id="L1702" href="#L1702">1702</a><br /><a id="L1703" href="#L1703">1703</a><br /><a id="L1704" href="#L1704">1704</a><br /><a id="L1705" href="#L1705">1705</a><br /><a id="L1706" href="#L1706">1706</a><br /><a id="L1707" href="#L1707">1707</a><br /><a id="L1708" href="#L1708">1708</a><br /><a id="L1709" href="#L1709">1709</a><br /><a id="L1710" href="#L1710">1710</a><br /><a id="L1711" href="#L1711">1711</a><br /><a id="L1712" href="#L1712">1712</a><br /><a id="L1713" href="#L1713">1713</a><br /><a id="L1714" href="#L1714">1714</a><br /><a id="L1715" href="#L1715">1715</a><br /><a id="L1716" href="#L1716">1716</a><br /><a id="L1717" href="#L1717">1717</a><br /><a id="L1718" href="#L1718">1718</a><br /><a id="L1719" href="#L1719">1719</a><br /><a id="L1720" href="#L1720">1720</a><br /><a id="L1721" href="#L1721">1721</a><br /><a id="L1722" href="#L1722">1722</a><br /><a id="L1723" href="#L1723">1723</a><br /><a id="L1724" href="#L1724">1724</a><br /><a id="L1725" href="#L1725">1725</a><br /><a id="L1726" href="#L1726">1726</a><br /><a id="L1727" href="#L1727">1727</a><br /><a id="L1728" href="#L1728">1728</a><br /><a id="L1729" href="#L1729">1729</a><br /><a id="L1730" href="#L1730">1730</a><br /><a id="L1731" href="#L1731">1731</a><br /><a id="L1732" href="#L1732">1732</a><br /><a id="L1733" href="#L1733">1733</a><br /><a id="L1734" href="#L1734">1734</a><br /><a id="L1735" href="#L1735">1735</a><br /><a id="L1736" href="#L1736">1736</a><br /><a id="L1737" href="#L1737">1737</a><br /><a id="L1738" href="#L1738">1738</a><br /><a id="L1739" href="#L1739">1739</a><br /><a id="L1740" href="#L1740">1740</a><br /><a id="L1741" href="#L1741">1741</a><br /><a id="L1742" href="#L1742">1742</a><br /><a id="L1743" href="#L1743">1743</a><br /><a id="L1744" href="#L1744">1744</a><br /><a id="L1745" href="#L1745">1745</a><br /><a id="L1746" href="#L1746">1746</a><br /><a id="L1747" href="#L1747">1747</a><br /><a id="L1748" href="#L1748">1748</a><br /><a id="L1749" href="#L1749">1749</a><br /><a id="L1750" href="#L1750">1750</a><br /><a id="L1751" href="#L1751">1751</a><br /><a id="L1752" href="#L1752">1752</a><br /><a id="L1753" href="#L1753">1753</a><br /><a id="L1754" href="#L1754">1754</a><br /><a id="L1755" href="#L1755">1755</a><br /><a id="L1756" href="#L1756">1756</a><br /><a id="L1757" href="#L1757">1757</a><br /><a id="L1758" href="#L1758">1758</a><br /><a id="L1759" href="#L1759">1759</a><br /><a id="L1760" href="#L1760">1760</a><br /><a id="L1761" href="#L1761">1761</a><br /><a id="L1762" href="#L1762">1762</a><br /><a id="L1763" href="#L1763">1763</a><br /><a id="L1764" href="#L1764">1764</a><br /><a id="L1765" href="#L1765">1765</a><br /><a id="L1766" href="#L1766">1766</a><br /><a id="L1767" href="#L1767">1767</a><br /><a id="L1768" href="#L1768">1768</a><br /><a id="L1769" href="#L1769">1769</a><br /><a id="L1770" href="#L1770">1770</a><br /><a id="L1771" href="#L1771">1771</a><br /><a id="L1772" href="#L1772">1772</a><br /><a id="L1773" href="#L1773">1773</a><br /><a id="L1774" href="#L1774">1774</a><br /><a id="L1775" href="#L1775">1775</a><br /><a id="L1776" href="#L1776">1776</a><br /><a id="L1777" href="#L1777">1777</a><br /><a id="L1778" href="#L1778">1778</a><br /><a id="L1779" href="#L1779">1779</a><br /><a id="L1780" href="#L1780">1780</a><br /><a id="L1781" href="#L1781">1781</a><br /><a id="L1782" href="#L1782">1782</a><br /><a id="L1783" href="#L1783">1783</a><br /><a id="L1784" href="#L1784">1784</a><br /><a id="L1785" href="#L1785">1785</a><br /><a id="L1786" href="#L1786">1786</a><br /><a id="L1787" href="#L1787">1787</a><br /><a id="L1788" href="#L1788">1788</a><br /><a id="L1789" href="#L1789">1789</a><br /><a id="L1790" href="#L1790">1790</a><br /><a id="L1791" href="#L1791">1791</a><br /><a id="L1792" href="#L1792">1792</a><br /><a id="L1793" href="#L1793">1793</a><br /><a id="L1794" href="#L1794">1794</a><br /><a id="L1795" href="#L1795">1795</a><br /><a id="L1796" href="#L1796">1796</a><br /><a id="L1797" href="#L1797">1797</a><br /><a id="L1798" href="#L1798">1798</a><br /><a id="L1799" href="#L1799">1799</a><br /><a id="L1800" href="#L1800">1800</a><br /><a id="L1801" href="#L1801">1801</a><br /><a id="L1802" href="#L1802">1802</a><br /><a id="L1803" href="#L1803">1803</a><br /><a id="L1804" href="#L1804">1804</a><br /><a id="L1805" href="#L1805">1805</a><br /><a id="L1806" href="#L1806">1806</a><br /><a id="L1807" href="#L1807">1807</a><br /><a id="L1808" href="#L1808">1808</a><br /><a id="L1809" href="#L1809">1809</a><br /><a id="L1810" href="#L1810">1810</a><br /><a id="L1811" href="#L1811">1811</a><br /><a id="L1812" href="#L1812">1812</a><br /><a id="L1813" href="#L1813">1813</a><br /><a id="L1814" href="#L1814">1814</a><br /><a id="L1815" href="#L1815">1815</a><br /><a id="L1816" href="#L1816">1816</a><br /><a id="L1817" href="#L1817">1817</a><br /><a id="L1818" href="#L1818">1818</a><br /><a id="L1819" href="#L1819">1819</a><br /><a id="L1820" href="#L1820">1820</a><br /><a id="L1821" href="#L1821">1821</a><br /><a id="L1822" href="#L1822">1822</a><br /><a id="L1823" href="#L1823">1823</a><br /><a id="L1824" href="#L1824">1824</a><br /><a id="L1825" href="#L1825">1825</a><br /><a id="L1826" href="#L1826">1826</a><br /><a id="L1827" href="#L1827">1827</a><br /><a id="L1828" href="#L1828">1828</a><br /><a id="L1829" href="#L1829">1829</a><br /><a id="L1830" href="#L1830">1830</a><br /><a id="L1831" href="#L1831">1831</a><br /><a id="L1832" href="#L1832">1832</a><br /><a id="L1833" href="#L1833">1833</a><br /><a id="L1834" href="#L1834">1834</a><br /><a id="L1835" href="#L1835">1835</a><br /><a id="L1836" href="#L1836">1836</a><br /><a id="L1837" href="#L1837">1837</a><br /><a id="L1838" href="#L1838">1838</a><br /><a id="L1839" href="#L1839">1839</a><br /><a id="L1840" href="#L1840">1840</a><br /><a id="L1841" href="#L1841">1841</a><br /><a id="L1842" href="#L1842">1842</a><br /><a id="L1843" href="#L1843">1843</a><br /><a id="L1844" href="#L1844">1844</a><br /><a id="L1845" href="#L1845">1845</a><br /><a id="L1846" href="#L1846">1846</a><br /><a id="L1847" href="#L1847">1847</a><br /><a id="L1848" href="#L1848">1848</a><br /><a id="L1849" href="#L1849">1849</a><br /><a id="L1850" href="#L1850">1850</a><br /><a id="L1851" href="#L1851">1851</a><br /><a id="L1852" href="#L1852">1852</a><br /><a id="L1853" href="#L1853">1853</a><br /><a id="L1854" href="#L1854">1854</a><br /><a id="L1855" href="#L1855">1855</a><br /><a id="L1856" href="#L1856">1856</a><br /><a id="L1857" href="#L1857">1857</a><br /><a id="L1858" href="#L1858">1858</a><br /><a id="L1859" href="#L1859">1859</a><br /><a id="L1860" href="#L1860">1860</a><br /><a id="L1861" href="#L1861">1861</a><br /><a id="L1862" href="#L1862">1862</a><br /><a id="L1863" href="#L1863">1863</a><br /><a id="L1864" href="#L1864">1864</a><br /><a id="L1865" href="#L1865">1865</a><br /><a id="L1866" href="#L1866">1866</a><br /><a id="L1867" href="#L1867">1867</a><br /><a id="L1868" href="#L1868">1868</a><br /><a id="L1869" href="#L1869">1869</a><br /><a id="L1870" href="#L1870">1870</a><br /><a id="L1871" href="#L1871">1871</a><br /><a id="L1872" href="#L1872">1872</a><br /><a id="L1873" href="#L1873">1873</a><br /><a id="L1874" href="#L1874">1874</a><br /><a id="L1875" href="#L1875">1875</a><br /><a id="L1876" href="#L1876">1876</a><br /><a id="L1877" href="#L1877">1877</a><br /><a id="L1878" href="#L1878">1878</a><br /><a id="L1879" href="#L1879">1879</a><br /><a id="L1880" href="#L1880">1880</a><br /><a id="L1881" href="#L1881">1881</a><br /><a id="L1882" href="#L1882">1882</a><br /><a id="L1883" href="#L1883">1883</a><br /><a id="L1884" href="#L1884">1884</a><br /><a id="L1885" href="#L1885">1885</a><br /><a id="L1886" href="#L1886">1886</a><br /><a id="L1887" href="#L1887">1887</a><br /><a id="L1888" href="#L1888">1888</a><br /><a id="L1889" href="#L1889">1889</a><br /><a id="L1890" href="#L1890">1890</a><br /><a id="L1891" href="#L1891">1891</a><br /><a id="L1892" href="#L1892">1892</a><br /><a id="L1893" href="#L1893">1893</a><br /><a id="L1894" href="#L1894">1894</a><br /><a id="L1895" href="#L1895">1895</a><br /><a id="L1896" href="#L1896">1896</a><br /><a id="L1897" href="#L1897">1897</a><br /><a id="L1898" href="#L1898">1898</a><br /><a id="L1899" href="#L1899">1899</a><br /><a id="L1900" href="#L1900">1900</a><br /><a id="L1901" href="#L1901">1901</a><br /><a id="L1902" href="#L1902">1902</a><br /><a id="L1903" href="#L1903">1903</a><br /><a id="L1904" href="#L1904">1904</a><br /><a id="L1905" href="#L1905">1905</a><br /><a id="L1906" href="#L1906">1906</a><br /><a id="L1907" href="#L1907">1907</a><br /><a id="L1908" href="#L1908">1908</a><br /><a id="L1909" href="#L1909">1909</a><br /><a id="L1910" href="#L1910">1910</a><br /><a id="L1911" href="#L1911">1911</a><br /><a id="L1912" href="#L1912">1912</a><br /><a id="L1913" href="#L1913">1913</a><br /><a id="L1914" href="#L1914">1914</a><br /><a id="L1915" href="#L1915">1915</a><br /><a id="L1916" href="#L1916">1916</a><br /><a id="L1917" href="#L1917">1917</a><br /><a id="L1918" href="#L1918">1918</a><br /><a id="L1919" href="#L1919">1919</a><br /><a id="L1920" href="#L1920">1920</a><br /><a id="L1921" href="#L1921">1921</a><br /><a id="L1922" href="#L1922">1922</a><br /><a id="L1923" href="#L1923">1923</a><br /><a id="L1924" href="#L1924">1924</a><br /><a id="L1925" href="#L1925">1925</a><br /><a id="L1926" href="#L1926">1926</a><br /><a id="L1927" href="#L1927">1927</a><br /><a id="L1928" href="#L1928">1928</a><br /><a id="L1929" href="#L1929">1929</a><br /><a id="L1930" href="#L1930">1930</a><br /><a id="L1931" href="#L1931">1931</a><br /><a id="L1932" href="#L1932">1932</a><br /><a id="L1933" href="#L1933">1933</a><br /><a id="L1934" href="#L1934">1934</a><br /><a id="L1935" href="#L1935">1935</a><br /><a id="L1936" href="#L1936">1936</a><br /><a id="L1937" href="#L1937">1937</a><br /><a id="L1938" href="#L1938">1938</a><br /><a id="L1939" href="#L1939">1939</a><br /><a id="L1940" href="#L1940">1940</a><br /><a id="L1941" href="#L1941">1941</a><br /><a id="L1942" href="#L1942">1942</a><br /><a id="L1943" href="#L1943">1943</a><br /><a id="L1944" href="#L1944">1944</a><br /><a id="L1945" href="#L1945">1945</a><br /><a id="L1946" href="#L1946">1946</a><br /><a id="L1947" href="#L1947">1947</a><br /><a id="L1948" href="#L1948">1948</a><br /><a id="L1949" href="#L1949">1949</a><br /><a id="L1950" href="#L1950">1950</a><br /><a id="L1951" href="#L1951">1951</a><br /><a id="L1952" href="#L1952">1952</a><br /><a id="L1953" href="#L1953">1953</a><br /><a id="L1954" href="#L1954">1954</a><br /><a id="L1955" href="#L1955">1955</a><br /><a id="L1956" href="#L1956">1956</a><br /><a id="L1957" href="#L1957">1957</a><br /><a id="L1958" href="#L1958">1958</a><br /><a id="L1959" href="#L1959">1959</a><br /><a id="L1960" href="#L1960">1960</a><br /><a id="L1961" href="#L1961">1961</a><br /><a id="L1962" href="#L1962">1962</a><br /><a id="L1963" href="#L1963">1963</a><br /><a id="L1964" href="#L1964">1964</a><br /><a id="L1965" href="#L1965">1965</a><br /><a id="L1966" href="#L1966">1966</a><br /><a id="L1967" href="#L1967">1967</a><br /><a id="L1968" href="#L1968">1968</a><br /><a id="L1969" href="#L1969">1969</a><br /><a id="L1970" href="#L1970">1970</a><br /><a id="L1971" href="#L1971">1971</a><br /><a id="L1972" href="#L1972">1972</a><br /><a id="L1973" href="#L1973">1973</a><br /><a id="L1974" href="#L1974">1974</a><br /><a id="L1975" href="#L1975">1975</a><br /><a id="L1976" href="#L1976">1976</a><br /><a id="L1977" href="#L1977">1977</a><br /><a id="L1978" href="#L1978">1978</a><br /><a id="L1979" href="#L1979">1979</a><br /><a id="L1980" href="#L1980">1980</a><br /><a id="L1981" href="#L1981">1981</a><br /><a id="L1982" href="#L1982">1982</a><br /><a id="L1983" href="#L1983">1983</a><br /><a id="L1984" href="#L1984">1984</a><br /><a id="L1985" href="#L1985">1985</a><br /><a id="L1986" href="#L1986">1986</a><br /><a id="L1987" href="#L1987">1987</a><br /><a id="L1988" href="#L1988">1988</a><br /><a id="L1989" href="#L1989">1989</a><br /><a id="L1990" href="#L1990">1990</a><br /><a id="L1991" href="#L1991">1991</a><br /><a id="L1992" href="#L1992">1992</a><br /><a id="L1993" href="#L1993">1993</a><br /><a id="L1994" href="#L1994">1994</a><br /><a id="L1995" href="#L1995">1995</a><br /><a id="L1996" href="#L1996">1996</a><br /><a id="L1997" href="#L1997">1997</a><br /><a id="L1998" href="#L1998">1998</a><br /><a id="L1999" href="#L1999">1999</a><br /><a id="L2000" href="#L2000">2000</a><br /><a id="L2001" href="#L2001">2001</a><br /><a id="L2002" href="#L2002">2002</a><br /><a id="L2003" href="#L2003">2003</a><br /><a id="L2004" href="#L2004">2004</a><br /><a id="L2005" href="#L2005">2005</a><br /><a id="L2006" href="#L2006">2006</a><br /><a id="L2007" href="#L2007">2007</a><br /><a id="L2008" href="#L2008">2008</a><br /><a id="L2009" href="#L2009">2009</a><br /><a id="L2010" href="#L2010">2010</a><br /><a id="L2011" href="#L2011">2011</a><br /><a id="L2012" href="#L2012">2012</a><br /><a id="L2013" href="#L2013">2013</a><br /><a id="L2014" href="#L2014">2014</a><br /><a id="L2015" href="#L2015">2015</a><br /><a id="L2016" href="#L2016">2016</a><br /><a id="L2017" href="#L2017">2017</a><br /><a id="L2018" href="#L2018">2018</a><br /><a id="L2019" href="#L2019">2019</a><br /><a id="L2020" href="#L2020">2020</a><br /><a id="L2021" href="#L2021">2021</a><br /><a id="L2022" href="#L2022">2022</a><br /><a id="L2023" href="#L2023">2023</a><br /><a id="L2024" href="#L2024">2024</a><br /><a id="L2025" href="#L2025">2025</a><br /><a id="L2026" href="#L2026">2026</a><br /><a id="L2027" href="#L2027">2027</a><br /><a id="L2028" href="#L2028">2028</a><br /><a id="L2029" href="#L2029">2029</a><br /><a id="L2030" href="#L2030">2030</a><br /><a id="L2031" href="#L2031">2031</a><br /><a id="L2032" href="#L2032">2032</a><br /><a id="L2033" href="#L2033">2033</a><br /><a id="L2034" href="#L2034">2034</a><br /><a id="L2035" href="#L2035">2035</a><br /><a id="L2036" href="#L2036">2036</a><br /><a id="L2037" href="#L2037">2037</a><br /><a id="L2038" href="#L2038">2038</a><br /><a id="L2039" href="#L2039">2039</a><br /><a id="L2040" href="#L2040">2040</a><br /><a id="L2041" href="#L2041">2041</a><br /><a id="L2042" href="#L2042">2042</a><br /><a id="L2043" href="#L2043">2043</a><br /><a id="L2044" href="#L2044">2044</a><br /><a id="L2045" href="#L2045">2045</a><br /><a id="L2046" href="#L2046">2046</a><br /><a id="L2047" href="#L2047">2047</a><br /><a id="L2048" href="#L2048">2048</a><br /><a id="L2049" href="#L2049">2049</a><br /><a id="L2050" href="#L2050">2050</a><br /><a id="L2051" href="#L2051">2051</a><br /><a id="L2052" href="#L2052">2052</a><br /><a id="L2053" href="#L2053">2053</a><br /><a id="L2054" href="#L2054">2054</a><br /><a id="L2055" href="#L2055">2055</a><br /><a id="L2056" href="#L2056">2056</a><br /><a id="L2057" href="#L2057">2057</a><br /><a id="L2058" href="#L2058">2058</a><br /><a id="L2059" href="#L2059">2059</a><br /><a id="L2060" href="#L2060">2060</a><br /><a id="L2061" href="#L2061">2061</a><br /><a id="L2062" href="#L2062">2062</a><br /><a id="L2063" href="#L2063">2063</a><br /><a id="L2064" href="#L2064">2064</a><br /><a id="L2065" href="#L2065">2065</a><br /><a id="L2066" href="#L2066">2066</a><br /><a id="L2067" href="#L2067">2067</a><br /><a id="L2068" href="#L2068">2068</a><br /><a id="L2069" href="#L2069">2069</a><br /><a id="L2070" href="#L2070">2070</a><br /><a id="L2071" href="#L2071">2071</a><br /><a id="L2072" href="#L2072">2072</a><br /><a id="L2073" href="#L2073">2073</a><br /><a id="L2074" href="#L2074">2074</a><br /><a id="L2075" href="#L2075">2075</a><br /><a id="L2076" href="#L2076">2076</a><br /><a id="L2077" href="#L2077">2077</a><br /><a id="L2078" href="#L2078">2078</a><br /><a id="L2079" href="#L2079">2079</a><br /><a id="L2080" href="#L2080">2080</a><br /><a id="L2081" href="#L2081">2081</a><br /><a id="L2082" href="#L2082">2082</a><br /><a id="L2083" href="#L2083">2083</a><br /><a id="L2084" href="#L2084">2084</a><br /><a id="L2085" href="#L2085">2085</a><br /><a id="L2086" href="#L2086">2086</a><br /><a id="L2087" href="#L2087">2087</a><br /><a id="L2088" href="#L2088">2088</a><br /><a id="L2089" href="#L2089">2089</a><br /><a id="L2090" href="#L2090">2090</a><br /><a id="L2091" href="#L2091">2091</a><br /><a id="L2092" href="#L2092">2092</a><br /><a id="L2093" href="#L2093">2093</a><br /><a id="L2094" href="#L2094">2094</a><br /><a id="L2095" href="#L2095">2095</a><br /><a id="L2096" href="#L2096">2096</a><br /><a id="L2097" href="#L2097">2097</a><br /><a id="L2098" href="#L2098">2098</a><br /><a id="L2099" href="#L2099">2099</a><br /><a id="L2100" href="#L2100">2100</a><br /><a id="L2101" href="#L2101">2101</a><br /><a id="L2102" href="#L2102">2102</a><br /><a id="L2103" href="#L2103">2103</a><br /><a id="L2104" href="#L2104">2104</a><br /><a id="L2105" href="#L2105">2105</a><br /><a id="L2106" href="#L2106">2106</a><br /><a id="L2107" href="#L2107">2107</a><br /><a id="L2108" href="#L2108">2108</a><br /><a id="L2109" href="#L2109">2109</a><br /><a id="L2110" href="#L2110">2110</a><br /><a id="L2111" href="#L2111">2111</a><br /><a id="L2112" href="#L2112">2112</a><br /><a id="L2113" href="#L2113">2113</a><br /><a id="L2114" href="#L2114">2114</a><br /><a id="L2115" href="#L2115">2115</a><br /><a id="L2116" href="#L2116">2116</a><br /><a id="L2117" href="#L2117">2117</a><br /><a id="L2118" href="#L2118">2118</a><br /><a id="L2119" href="#L2119">2119</a><br /><a id="L2120" href="#L2120">2120</a><br /><a id="L2121" href="#L2121">2121</a><br /><a id="L2122" href="#L2122">2122</a><br /><a id="L2123" href="#L2123">2123</a><br /><a id="L2124" href="#L2124">2124</a><br /><a id="L2125" href="#L2125">2125</a><br /><a id="L2126" href="#L2126">2126</a><br /><a id="L2127" href="#L2127">2127</a><br /><a id="L2128" href="#L2128">2128</a><br /><a id="L2129" href="#L2129">2129</a><br /><a id="L2130" href="#L2130">2130</a><br /><a id="L2131" href="#L2131">2131</a><br /><a id="L2132" href="#L2132">2132</a><br /><a id="L2133" href="#L2133">2133</a><br /><a id="L2134" href="#L2134">2134</a><br /><a id="L2135" href="#L2135">2135</a><br /><a id="L2136" href="#L2136">2136</a><br /><a id="L2137" href="#L2137">2137</a><br /><a id="L2138" href="#L2138">2138</a><br /><a id="L2139" href="#L2139">2139</a><br /><a id="L2140" href="#L2140">2140</a><br /><a id="L2141" href="#L2141">2141</a><br /><a id="L2142" href="#L2142">2142</a><br /><a id="L2143" href="#L2143">2143</a><br /><a id="L2144" href="#L2144">2144</a><br /><a id="L2145" href="#L2145">2145</a><br /><a id="L2146" href="#L2146">2146</a><br /><a id="L2147" href="#L2147">2147</a><br /><a id="L2148" href="#L2148">2148</a><br /><a id="L2149" href="#L2149">2149</a><br /><a id="L2150" href="#L2150">2150</a><br /><a id="L2151" href="#L2151">2151</a><br /><a id="L2152" href="#L2152">2152</a><br /><a id="L2153" href="#L2153">2153</a><br /><a id="L2154" href="#L2154">2154</a><br /><a id="L2155" href="#L2155">2155</a><br /><a id="L2156" href="#L2156">2156</a><br /><a id="L2157" href="#L2157">2157</a><br /><a id="L2158" href="#L2158">2158</a><br /><a id="L2159" href="#L2159">2159</a><br /><a id="L2160" href="#L2160">2160</a><br /><a id="L2161" href="#L2161">2161</a><br /><a id="L2162" href="#L2162">2162</a><br /><a id="L2163" href="#L2163">2163</a><br /><a id="L2164" href="#L2164">2164</a><br /><a id="L2165" href="#L2165">2165</a><br /><a id="L2166" href="#L2166">2166</a><br /><a id="L2167" href="#L2167">2167</a><br /><a id="L2168" href="#L2168">2168</a><br /><a id="L2169" href="#L2169">2169</a><br /><a id="L2170" href="#L2170">2170</a><br /><a id="L2171" href="#L2171">2171</a><br /><a id="L2172" href="#L2172">2172</a><br /><a id="L2173" href="#L2173">2173</a><br /><a id="L2174" href="#L2174">2174</a><br /><a id="L2175" href="#L2175">2175</a><br /><a id="L2176" href="#L2176">2176</a><br /><a id="L2177" href="#L2177">2177</a><br /><a id="L2178" href="#L2178">2178</a><br /><a id="L2179" href="#L2179">2179</a><br /><a id="L2180" href="#L2180">2180</a><br /><a id="L2181" href="#L2181">2181</a><br /><a id="L2182" href="#L2182">2182</a><br /><a id="L2183" href="#L2183">2183</a><br /><a id="L2184" href="#L2184">2184</a><br /><a id="L2185" href="#L2185">2185</a><br /><a id="L2186" href="#L2186">2186</a><br /><a id="L2187" href="#L2187">2187</a><br /><a id="L2188" href="#L2188">2188</a><br /><a id="L2189" href="#L2189">2189</a><br /><a id="L2190" href="#L2190">2190</a><br /><a id="L2191" href="#L2191">2191</a><br /><a id="L2192" href="#L2192">2192</a><br /><a id="L2193" href="#L2193">2193</a><br /><a id="L2194" href="#L2194">2194</a><br /><a id="L2195" href="#L2195">2195</a><br /><a id="L2196" href="#L2196">2196</a><br /><a id="L2197" href="#L2197">2197</a><br /><a id="L2198" href="#L2198">2198</a><br /><a id="L2199" href="#L2199">2199</a><br /><a id="L2200" href="#L2200">2200</a><br /><a id="L2201" href="#L2201">2201</a><br /><a id="L2202" href="#L2202">2202</a><br /><a id="L2203" href="#L2203">2203</a><br /><a id="L2204" href="#L2204">2204</a><br /><a id="L2205" href="#L2205">2205</a><br /><a id="L2206" href="#L2206">2206</a><br /><a id="L2207" href="#L2207">2207</a><br /><a id="L2208" href="#L2208">2208</a><br /><a id="L2209" href="#L2209">2209</a><br /><a id="L2210" href="#L2210">2210</a><br /><a id="L2211" href="#L2211">2211</a><br /><a id="L2212" href="#L2212">2212</a><br /><a id="L2213" href="#L2213">2213</a><br /><a id="L2214" href="#L2214">2214</a><br /><a id="L2215" href="#L2215">2215</a><br /><a id="L2216" href="#L2216">2216</a><br /><a id="L2217" href="#L2217">2217</a><br /><a id="L2218" href="#L2218">2218</a><br /><a id="L2219" href="#L2219">2219</a><br /><a id="L2220" href="#L2220">2220</a><br /><a id="L2221" href="#L2221">2221</a><br /><a id="L2222" href="#L2222">2222</a><br /><a id="L2223" href="#L2223">2223</a><br /><a id="L2224" href="#L2224">2224</a><br /><a id="L2225" href="#L2225">2225</a><br /><a id="L2226" href="#L2226">2226</a><br /><a id="L2227" href="#L2227">2227</a><br /><a id="L2228" href="#L2228">2228</a><br /><a id="L2229" href="#L2229">2229</a><br /><a id="L2230" href="#L2230">2230</a><br /><a id="L2231" href="#L2231">2231</a><br /><a id="L2232" href="#L2232">2232</a><br /><a id="L2233" href="#L2233">2233</a><br /><a id="L2234" href="#L2234">2234</a><br /><a id="L2235" href="#L2235">2235</a><br /><a id="L2236" href="#L2236">2236</a><br /><a id="L2237" href="#L2237">2237</a><br /><a id="L2238" href="#L2238">2238</a><br /><a id="L2239" href="#L2239">2239</a><br /><a id="L2240" href="#L2240">2240</a><br /><a id="L2241" href="#L2241">2241</a><br /><a id="L2242" href="#L2242">2242</a><br /><a id="L2243" href="#L2243">2243</a><br /><a id="L2244" href="#L2244">2244</a><br /><a id="L2245" href="#L2245">2245</a><br /><a id="L2246" href="#L2246">2246</a><br /><a id="L2247" href="#L2247">2247</a><br /><a id="L2248" href="#L2248">2248</a><br /><a id="L2249" href="#L2249">2249</a><br /><a id="L2250" href="#L2250">2250</a><br /><a id="L2251" href="#L2251">2251</a><br /><a id="L2252" href="#L2252">2252</a><br /><a id="L2253" href="#L2253">2253</a><br /><a id="L2254" href="#L2254">2254</a><br /><a id="L2255" href="#L2255">2255</a><br /><a id="L2256" href="#L2256">2256</a><br /><a id="L2257" href="#L2257">2257</a><br /><a id="L2258" href="#L2258">2258</a><br /><a id="L2259" href="#L2259">2259</a><br /><a id="L2260" href="#L2260">2260</a><br /><a id="L2261" href="#L2261">2261</a><br /><a id="L2262" href="#L2262">2262</a><br /><a id="L2263" href="#L2263">2263</a><br /><a id="L2264" href="#L2264">2264</a><br /><a id="L2265" href="#L2265">2265</a><br /><a id="L2266" href="#L2266">2266</a><br /><a id="L2267" href="#L2267">2267</a><br /><a id="L2268" href="#L2268">2268</a><br /><a id="L2269" href="#L2269">2269</a><br /><a id="L2270" href="#L2270">2270</a><br /><a id="L2271" href="#L2271">2271</a><br /><a id="L2272" href="#L2272">2272</a><br /><a id="L2273" href="#L2273">2273</a><br /><a id="L2274" href="#L2274">2274</a><br /><a id="L2275" href="#L2275">2275</a><br /><a id="L2276" href="#L2276">2276</a><br /><a id="L2277" href="#L2277">2277</a><br /><a id="L2278" href="#L2278">2278</a><br /><a id="L2279" href="#L2279">2279</a><br /><a id="L2280" href="#L2280">2280</a><br /><a id="L2281" href="#L2281">2281</a><br /><a id="L2282" href="#L2282">2282</a><br /><a id="L2283" href="#L2283">2283</a><br /><a id="L2284" href="#L2284">2284</a><br /><a id="L2285" href="#L2285">2285</a><br /><a id="L2286" href="#L2286">2286</a><br /><a id="L2287" href="#L2287">2287</a><br /><a id="L2288" href="#L2288">2288</a><br /><a id="L2289" href="#L2289">2289</a><br /><a id="L2290" href="#L2290">2290</a><br /><a id="L2291" href="#L2291">2291</a><br /><a id="L2292" href="#L2292">2292</a><br /><a id="L2293" href="#L2293">2293</a><br /><a id="L2294" href="#L2294">2294</a><br /><a id="L2295" href="#L2295">2295</a><br /><a id="L2296" href="#L2296">2296</a><br /><a id="L2297" href="#L2297">2297</a><br /><a id="L2298" href="#L2298">2298</a><br /><a id="L2299" href="#L2299">2299</a><br /><a id="L2300" href="#L2300">2300</a><br /><a id="L2301" href="#L2301">2301</a><br /><a id="L2302" href="#L2302">2302</a><br /><a id="L2303" href="#L2303">2303</a><br /><a id="L2304" href="#L2304">2304</a><br /><a id="L2305" href="#L2305">2305</a><br /><a id="L2306" href="#L2306">2306</a><br /><a id="L2307" href="#L2307">2307</a><br /><a id="L2308" href="#L2308">2308</a><br /><a id="L2309" href="#L2309">2309</a><br /><a id="L2310" href="#L2310">2310</a><br /><a id="L2311" href="#L2311">2311</a><br /><a id="L2312" href="#L2312">2312</a><br /><a id="L2313" href="#L2313">2313</a><br /><a id="L2314" href="#L2314">2314</a><br /><a id="L2315" href="#L2315">2315</a><br /><a id="L2316" href="#L2316">2316</a><br /><a id="L2317" href="#L2317">2317</a><br /><a id="L2318" href="#L2318">2318</a><br /><a id="L2319" href="#L2319">2319</a><br /><a id="L2320" href="#L2320">2320</a><br /><a id="L2321" href="#L2321">2321</a><br /><a id="L2322" href="#L2322">2322</a><br /><a id="L2323" href="#L2323">2323</a><br /><a id="L2324" href="#L2324">2324</a><br /><a id="L2325" href="#L2325">2325</a><br /><a id="L2326" href="#L2326">2326</a><br /><a id="L2327" href="#L2327">2327</a><br /><a id="L2328" href="#L2328">2328</a><br /><a id="L2329" href="#L2329">2329</a><br /><a id="L2330" href="#L2330">2330</a><br /><a id="L2331" href="#L2331">2331</a><br /><a id="L2332" href="#L2332">2332</a><br /><a id="L2333" href="#L2333">2333</a><br /><a id="L2334" href="#L2334">2334</a><br /><a id="L2335" href="#L2335">2335</a><br /><a id="L2336" href="#L2336">2336</a><br /><a id="L2337" href="#L2337">2337</a><br /><a id="L2338" href="#L2338">2338</a><br /><a id="L2339" href="#L2339">2339</a><br /><a id="L2340" href="#L2340">2340</a><br /><a id="L2341" href="#L2341">2341</a><br /><a id="L2342" href="#L2342">2342</a><br /><a id="L2343" href="#L2343">2343</a><br /><a id="L2344" href="#L2344">2344</a><br /><a id="L2345" href="#L2345">2345</a><br /><a id="L2346" href="#L2346">2346</a><br /><a id="L2347" href="#L2347">2347</a><br /><a id="L2348" href="#L2348">2348</a><br /><a id="L2349" href="#L2349">2349</a><br /><a id="L2350" href="#L2350">2350</a><br /><a id="L2351" href="#L2351">2351</a><br /><a id="L2352" href="#L2352">2352</a><br /><a id="L2353" href="#L2353">2353</a><br /><a id="L2354" href="#L2354">2354</a><br /><a id="L2355" href="#L2355">2355</a><br /><a id="L2356" href="#L2356">2356</a><br /><a id="L2357" href="#L2357">2357</a><br /><a id="L2358" href="#L2358">2358</a><br /><a id="L2359" href="#L2359">2359</a><br /><a id="L2360" href="#L2360">2360</a><br /><a id="L2361" href="#L2361">2361</a><br /><a id="L2362" href="#L2362">2362</a><br /><a id="L2363" href="#L2363">2363</a><br /><a id="L2364" href="#L2364">2364</a><br /><a id="L2365" href="#L2365">2365</a><br /><a id="L2366" href="#L2366">2366</a><br /><a id="L2367" href="#L2367">2367</a><br /><a id="L2368" href="#L2368">2368</a><br /><a id="L2369" href="#L2369">2369</a><br /><a id="L2370" href="#L2370">2370</a><br /><a id="L2371" href="#L2371">2371</a><br /><a id="L2372" href="#L2372">2372</a><br /><a id="L2373" href="#L2373">2373</a><br /><a id="L2374" href="#L2374">2374</a><br /><a id="L2375" href="#L2375">2375</a><br /><a id="L2376" href="#L2376">2376</a><br /><a id="L2377" href="#L2377">2377</a><br /><a id="L2378" href="#L2378">2378</a><br /><a id="L2379" href="#L2379">2379</a><br /><a id="L2380" href="#L2380">2380</a><br /><a id="L2381" href="#L2381">2381</a><br /><a id="L2382" href="#L2382">2382</a><br /><a id="L2383" href="#L2383">2383</a><br /><a id="L2384" href="#L2384">2384</a><br /><a id="L2385" href="#L2385">2385</a><br /><a id="L2386" href="#L2386">2386</a><br /><a id="L2387" href="#L2387">2387</a><br /><a id="L2388" href="#L2388">2388</a><br /><a id="L2389" href="#L2389">2389</a><br /><a id="L2390" href="#L2390">2390</a><br /><a id="L2391" href="#L2391">2391</a><br /><a id="L2392" href="#L2392">2392</a><br /><a id="L2393" href="#L2393">2393</a><br /><a id="L2394" href="#L2394">2394</a><br /><a id="L2395" href="#L2395">2395</a><br /><a id="L2396" href="#L2396">2396</a><br /><a id="L2397" href="#L2397">2397</a><br /><a id="L2398" href="#L2398">2398</a><br /><a id="L2399" href="#L2399">2399</a><br /><a id="L2400" href="#L2400">2400</a><br /><a id="L2401" href="#L2401">2401</a><br /><a id="L2402" href="#L2402">2402</a><br /><a id="L2403" href="#L2403">2403</a><br /><a id="L2404" href="#L2404">2404</a><br /><a id="L2405" href="#L2405">2405</a><br /><a id="L2406" href="#L2406">2406</a><br /><a id="L2407" href="#L2407">2407</a><br /><a id="L2408" href="#L2408">2408</a><br /><a id="L2409" href="#L2409">2409</a><br /><a id="L2410" href="#L2410">2410</a><br /><a id="L2411" href="#L2411">2411</a><br /><a id="L2412" href="#L2412">2412</a><br /><a id="L2413" href="#L2413">2413</a><br /><a id="L2414" href="#L2414">2414</a><br /><a id="L2415" href="#L2415">2415</a><br /><a id="L2416" href="#L2416">2416</a><br /><a id="L2417" href="#L2417">2417</a><br /><a id="L2418" href="#L2418">2418</a><br /><a id="L2419" href="#L2419">2419</a><br /><a id="L2420" href="#L2420">2420</a><br /><a id="L2421" href="#L2421">2421</a><br /><a id="L2422" href="#L2422">2422</a><br /><a id="L2423" href="#L2423">2423</a><br /><a id="L2424" href="#L2424">2424</a><br /><a id="L2425" href="#L2425">2425</a><br /><a id="L2426" href="#L2426">2426</a><br /><a id="L2427" href="#L2427">2427</a><br /><a id="L2428" href="#L2428">2428</a><br /><a id="L2429" href="#L2429">2429</a><br /><a id="L2430" href="#L2430">2430</a><br /><a id="L2431" href="#L2431">2431</a><br /><a id="L2432" href="#L2432">2432</a><br /><a id="L2433" href="#L2433">2433</a><br /><a id="L2434" href="#L2434">2434</a><br /><a id="L2435" href="#L2435">2435</a><br /><a id="L2436" href="#L2436">2436</a><br /><a id="L2437" href="#L2437">2437</a><br /><a id="L2438" href="#L2438">2438</a><br /><a id="L2439" href="#L2439">2439</a><br /><a id="L2440" href="#L2440">2440</a><br /><a id="L2441" href="#L2441">2441</a><br /><a id="L2442" href="#L2442">2442</a><br /><a id="L2443" href="#L2443">2443</a><br /><a id="L2444" href="#L2444">2444</a><br /><a id="L2445" href="#L2445">2445</a><br /><a id="L2446" href="#L2446">2446</a><br /><a id="L2447" href="#L2447">2447</a><br /><a id="L2448" href="#L2448">2448</a><br /><a id="L2449" href="#L2449">2449</a><br /><a id="L2450" href="#L2450">2450</a><br /><a id="L2451" href="#L2451">2451</a><br /><a id="L2452" href="#L2452">2452</a><br /><a id="L2453" href="#L2453">2453</a><br /><a id="L2454" href="#L2454">2454</a><br /><a id="L2455" href="#L2455">2455</a><br /><a id="L2456" href="#L2456">2456</a><br /><a id="L2457" href="#L2457">2457</a><br /><a id="L2458" href="#L2458">2458</a><br /><a id="L2459" href="#L2459">2459</a><br /><a id="L2460" href="#L2460">2460</a><br /><a id="L2461" href="#L2461">2461</a><br /><a id="L2462" href="#L2462">2462</a><br /><a id="L2463" href="#L2463">2463</a><br /><a id="L2464" href="#L2464">2464</a><br /><a id="L2465" href="#L2465">2465</a><br /><a id="L2466" href="#L2466">2466</a><br /><a id="L2467" href="#L2467">2467</a><br /><a id="L2468" href="#L2468">2468</a><br /><a id="L2469" href="#L2469">2469</a><br /><a id="L2470" href="#L2470">2470</a><br /><a id="L2471" href="#L2471">2471</a><br /><a id="L2472" href="#L2472">2472</a><br /><a id="L2473" href="#L2473">2473</a><br /><a id="L2474" href="#L2474">2474</a><br /><a id="L2475" href="#L2475">2475</a><br /><a id="L2476" href="#L2476">2476</a><br /><a id="L2477" href="#L2477">2477</a><br /><a id="L2478" href="#L2478">2478</a><br /><a id="L2479" href="#L2479">2479</a><br /><a id="L2480" href="#L2480">2480</a><br /><a id="L2481" href="#L2481">2481</a><br /><a id="L2482" href="#L2482">2482</a><br /><a id="L2483" href="#L2483">2483</a><br /><a id="L2484" href="#L2484">2484</a><br /><a id="L2485" href="#L2485">2485</a><br /><a id="L2486" href="#L2486">2486</a><br /><a id="L2487" href="#L2487">2487</a><br /><a id="L2488" href="#L2488">2488</a><br /><a id="L2489" href="#L2489">2489</a><br /><a id="L2490" href="#L2490">2490</a><br /><a id="L2491" href="#L2491">2491</a><br /><a id="L2492" href="#L2492">2492</a><br /><a id="L2493" href="#L2493">2493</a><br /><a id="L2494" href="#L2494">2494</a><br /><a id="L2495" href="#L2495">2495</a><br /><a id="L2496" href="#L2496">2496</a><br /><a id="L2497" href="#L2497">2497</a><br /><a id="L2498" href="#L2498">2498</a><br /><a id="L2499" href="#L2499">2499</a><br /><a id="L2500" href="#L2500">2500</a><br /><a id="L2501" href="#L2501">2501</a><br /><a id="L2502" href="#L2502">2502</a><br /><a id="L2503" href="#L2503">2503</a><br /><a id="L2504" href="#L2504">2504</a><br /><a id="L2505" href="#L2505">2505</a><br /><a id="L2506" href="#L2506">2506</a><br /><a id="L2507" href="#L2507">2507</a><br /><a id="L2508" href="#L2508">2508</a><br /><a id="L2509" href="#L2509">2509</a><br /><a id="L2510" href="#L2510">2510</a><br /><a id="L2511" href="#L2511">2511</a><br /><a id="L2512" href="#L2512">2512</a><br /><a id="L2513" href="#L2513">2513</a><br /><a id="L2514" href="#L2514">2514</a><br /><a id="L2515" href="#L2515">2515</a><br /><a id="L2516" href="#L2516">2516</a><br /><a id="L2517" href="#L2517">2517</a><br /><a id="L2518" href="#L2518">2518</a><br /><a id="L2519" href="#L2519">2519</a><br /><a id="L2520" href="#L2520">2520</a><br /><a id="L2521" href="#L2521">2521</a><br /><a id="L2522" href="#L2522">2522</a><br /><a id="L2523" href="#L2523">2523</a><br /><a id="L2524" href="#L2524">2524</a><br /><a id="L2525" href="#L2525">2525</a><br /><a id="L2526" href="#L2526">2526</a><br /><a id="L2527" href="#L2527">2527</a><br /><a id="L2528" href="#L2528">2528</a><br /><a id="L2529" href="#L2529">2529</a><br /><a id="L2530" href="#L2530">2530</a><br /><a id="L2531" href="#L2531">2531</a><br /><a id="L2532" href="#L2532">2532</a><br /><a id="L2533" href="#L2533">2533</a><br /><a id="L2534" href="#L2534">2534</a><br /><a id="L2535" href="#L2535">2535</a><br /><a id="L2536" href="#L2536">2536</a><br /><a id="L2537" href="#L2537">2537</a><br /><a id="L2538" href="#L2538">2538</a><br /><a id="L2539" href="#L2539">2539</a><br /><a id="L2540" href="#L2540">2540</a><br /><a id="L2541" href="#L2541">2541</a><br /><a id="L2542" href="#L2542">2542</a><br /><a id="L2543" href="#L2543">2543</a><br /><a id="L2544" href="#L2544">2544</a><br /><a id="L2545" href="#L2545">2545</a><br /><a id="L2546" href="#L2546">2546</a><br /><a id="L2547" href="#L2547">2547</a><br /><a id="L2548" href="#L2548">2548</a><br /><a id="L2549" href="#L2549">2549</a><br /><a id="L2550" href="#L2550">2550</a><br /><a id="L2551" href="#L2551">2551</a><br /><a id="L2552" href="#L2552">2552</a><br /><a id="L2553" href="#L2553">2553</a><br /><a id="L2554" href="#L2554">2554</a><br /><a id="L2555" href="#L2555">2555</a><br /><a id="L2556" href="#L2556">2556</a><br /><a id="L2557" href="#L2557">2557</a><br /><a id="L2558" href="#L2558">2558</a><br /><a id="L2559" href="#L2559">2559</a><br /><a id="L2560" href="#L2560">2560</a><br /><a id="L2561" href="#L2561">2561</a><br /><a id="L2562" href="#L2562">2562</a><br /><a id="L2563" href="#L2563">2563</a><br /><a id="L2564" href="#L2564">2564</a><br /><a id="L2565" href="#L2565">2565</a><br /><a id="L2566" href="#L2566">2566</a><br /><a id="L2567" href="#L2567">2567</a><br /><a id="L2568" href="#L2568">2568</a><br /><a id="L2569" href="#L2569">2569</a><br /><a id="L2570" href="#L2570">2570</a><br /><a id="L2571" href="#L2571">2571</a><br /><a id="L2572" href="#L2572">2572</a><br /><a id="L2573" href="#L2573">2573</a><br /><a id="L2574" href="#L2574">2574</a><br /><a id="L2575" href="#L2575">2575</a><br /><a id="L2576" href="#L2576">2576</a><br /><a id="L2577" href="#L2577">2577</a><br /><a id="L2578" href="#L2578">2578</a><br /><a id="L2579" href="#L2579">2579</a><br /><a id="L2580" href="#L2580">2580</a><br /><a id="L2581" href="#L2581">2581</a><br /><a id="L2582" href="#L2582">2582</a><br /><a id="L2583" href="#L2583">2583</a><br /><a id="L2584" href="#L2584">2584</a><br /><a id="L2585" href="#L2585">2585</a><br /><a id="L2586" href="#L2586">2586</a><br /><a id="L2587" href="#L2587">2587</a><br /><a id="L2588" href="#L2588">2588</a><br /><a id="L2589" href="#L2589">2589</a><br /><a id="L2590" href="#L2590">2590</a><br /><a id="L2591" href="#L2591">2591</a><br /><a id="L2592" href="#L2592">2592</a><br /><a id="L2593" href="#L2593">2593</a><br /><a id="L2594" href="#L2594">2594</a><br /><a id="L2595" href="#L2595">2595</a><br /><a id="L2596" href="#L2596">2596</a><br /><a id="L2597" href="#L2597">2597</a><br /><a id="L2598" href="#L2598">2598</a><br /><a id="L2599" href="#L2599">2599</a><br /><a id="L2600" href="#L2600">2600</a><br /><a id="L2601" href="#L2601">2601</a><br /><a id="L2602" href="#L2602">2602</a><br /><a id="L2603" href="#L2603">2603</a><br /><a id="L2604" href="#L2604">2604</a><br /><a id="L2605" href="#L2605">2605</a><br /><a id="L2606" href="#L2606">2606</a><br /><a id="L2607" href="#L2607">2607</a><br /><a id="L2608" href="#L2608">2608</a><br /><a id="L2609" href="#L2609">2609</a><br /><a id="L2610" href="#L2610">2610</a><br /><a id="L2611" href="#L2611">2611</a><br /><a id="L2612" href="#L2612">2612</a><br /><a id="L2613" href="#L2613">2613</a><br /><a id="L2614" href="#L2614">2614</a><br /><a id="L2615" href="#L2615">2615</a><br /><a id="L2616" href="#L2616">2616</a><br /><a id="L2617" href="#L2617">2617</a><br /><a id="L2618" href="#L2618">2618</a><br /><a id="L2619" href="#L2619">2619</a><br /><a id="L2620" href="#L2620">2620</a><br /><a id="L2621" href="#L2621">2621</a><br /><a id="L2622" href="#L2622">2622</a><br /><a id="L2623" href="#L2623">2623</a><br /><a id="L2624" href="#L2624">2624</a><br /><a id="L2625" href="#L2625">2625</a><br /><a id="L2626" href="#L2626">2626</a><br /><a id="L2627" href="#L2627">2627</a><br /><a id="L2628" href="#L2628">2628</a><br /><a id="L2629" href="#L2629">2629</a><br /><a id="L2630" href="#L2630">2630</a><br /><a id="L2631" href="#L2631">2631</a><br /><a id="L2632" href="#L2632">2632</a><br /><a id="L2633" href="#L2633">2633</a><br /><a id="L2634" href="#L2634">2634</a><br /><a id="L2635" href="#L2635">2635</a><br /><a id="L2636" href="#L2636">2636</a><br /><a id="L2637" href="#L2637">2637</a><br /><a id="L2638" href="#L2638">2638</a><br /><a id="L2639" href="#L2639">2639</a><br /><a id="L2640" href="#L2640">2640</a><br /><a id="L2641" href="#L2641">2641</a><br /><a id="L2642" href="#L2642">2642</a><br /><a id="L2643" href="#L2643">2643</a><br /><a id="L2644" href="#L2644">2644</a><br /><a id="L2645" href="#L2645">2645</a><br /><a id="L2646" href="#L2646">2646</a><br /><a id="L2647" href="#L2647">2647</a><br /><a id="L2648" href="#L2648">2648</a><br /><a id="L2649" href="#L2649">2649</a><br /><a id="L2650" href="#L2650">2650</a><br /><a id="L2651" href="#L2651">2651</a><br /><a id="L2652" href="#L2652">2652</a><br /><a id="L2653" href="#L2653">2653</a><br /><a id="L2654" href="#L2654">2654</a><br /><a id="L2655" href="#L2655">2655</a><br /><a id="L2656" href="#L2656">2656</a><br /><a id="L2657" href="#L2657">2657</a><br /><a id="L2658" href="#L2658">2658</a><br /><a id="L2659" href="#L2659">2659</a><br /><a id="L2660" href="#L2660">2660</a><br /><a id="L2661" href="#L2661">2661</a><br /><a id="L2662" href="#L2662">2662</a><br /><a id="L2663" href="#L2663">2663</a><br /><a id="L2664" href="#L2664">2664</a><br /><a id="L2665" href="#L2665">2665</a><br /><a id="L2666" href="#L2666">2666</a><br /><a id="L2667" href="#L2667">2667</a><br /><a id="L2668" href="#L2668">2668</a><br /><a id="L2669" href="#L2669">2669</a><br /><a id="L2670" href="#L2670">2670</a><br /><a id="L2671" href="#L2671">2671</a><br /><a id="L2672" href="#L2672">2672</a><br /><a id="L2673" href="#L2673">2673</a><br /><a id="L2674" href="#L2674">2674</a><br /><a id="L2675" href="#L2675">2675</a><br /><a id="L2676" href="#L2676">2676</a><br /><a id="L2677" href="#L2677">2677</a><br /><a id="L2678" href="#L2678">2678</a><br /><a id="L2679" href="#L2679">2679</a><br /><a id="L2680" href="#L2680">2680</a><br /><a id="L2681" href="#L2681">2681</a><br /><a id="L2682" href="#L2682">2682</a><br /><a id="L2683" href="#L2683">2683</a><br /><a id="L2684" href="#L2684">2684</a><br /><a id="L2685" href="#L2685">2685</a><br /><a id="L2686" href="#L2686">2686</a><br /><a id="L2687" href="#L2687">2687</a><br /><a id="L2688" href="#L2688">2688</a><br /><a id="L2689" href="#L2689">2689</a><br /><a id="L2690" href="#L2690">2690</a><br /><a id="L2691" href="#L2691">2691</a><br /><a id="L2692" href="#L2692">2692</a><br /><a id="L2693" href="#L2693">2693</a><br /><a id="L2694" href="#L2694">2694</a><br /><a id="L2695" href="#L2695">2695</a><br /><a id="L2696" href="#L2696">2696</a><br /><a id="L2697" href="#L2697">2697</a><br /><a id="L2698" href="#L2698">2698</a><br /><a id="L2699" href="#L2699">2699</a><br /><a id="L2700" href="#L2700">2700</a><br /><a id="L2701" href="#L2701">2701</a><br /><a id="L2702" href="#L2702">2702</a><br /><a id="L2703" href="#L2703">2703</a><br /><a id="L2704" href="#L2704">2704</a><br /><a id="L2705" href="#L2705">2705</a><br /><a id="L2706" href="#L2706">2706</a><br /><a id="L2707" href="#L2707">2707</a><br /><a id="L2708" href="#L2708">2708</a><br /><a id="L2709" href="#L2709">2709</a><br /><a id="L2710" href="#L2710">2710</a><br /><a id="L2711" href="#L2711">2711</a><br /><a id="L2712" href="#L2712">2712</a><br /><a id="L2713" href="#L2713">2713</a><br /><a id="L2714" href="#L2714">2714</a><br /><a id="L2715" href="#L2715">2715</a><br /><a id="L2716" href="#L2716">2716</a><br /><a id="L2717" href="#L2717">2717</a><br /><a id="L2718" href="#L2718">2718</a><br /><a id="L2719" href="#L2719">2719</a><br /><a id="L2720" href="#L2720">2720</a><br /><a id="L2721" href="#L2721">2721</a><br /><a id="L2722" href="#L2722">2722</a><br /><a id="L2723" href="#L2723">2723</a><br /><a id="L2724" href="#L2724">2724</a><br /><a id="L2725" href="#L2725">2725</a><br /><a id="L2726" href="#L2726">2726</a><br /><a id="L2727" href="#L2727">2727</a><br /><a id="L2728" href="#L2728">2728</a><br /><a id="L2729" href="#L2729">2729</a><br /><a id="L2730" href="#L2730">2730</a><br /><a id="L2731" href="#L2731">2731</a><br /><a id="L2732" href="#L2732">2732</a><br /><a id="L2733" href="#L2733">2733</a><br /><a id="L2734" href="#L2734">2734</a><br /><a id="L2735" href="#L2735">2735</a><br /><a id="L2736" href="#L2736">2736</a><br /><a id="L2737" href="#L2737">2737</a><br /><a id="L2738" href="#L2738">2738</a><br /><a id="L2739" href="#L2739">2739</a><br /><a id="L2740" href="#L2740">2740</a><br /><a id="L2741" href="#L2741">2741</a><br /><a id="L2742" href="#L2742">2742</a><br /><a id="L2743" href="#L2743">2743</a><br /><a id="L2744" href="#L2744">2744</a><br /><a id="L2745" href="#L2745">2745</a><br /><a id="L2746" href="#L2746">2746</a><br /><a id="L2747" href="#L2747">2747</a><br /><a id="L2748" href="#L2748">2748</a><br /><a id="L2749" href="#L2749">2749</a><br /><a id="L2750" href="#L2750">2750</a><br /><a id="L2751" href="#L2751">2751</a><br /><a id="L2752" href="#L2752">2752</a><br /><a id="L2753" href="#L2753">2753</a><br /><a id="L2754" href="#L2754">2754</a><br /><a id="L2755" href="#L2755">2755</a><br /><a id="L2756" href="#L2756">2756</a><br /><a id="L2757" href="#L2757">2757</a><br /><a id="L2758" href="#L2758">2758</a><br /><a id="L2759" href="#L2759">2759</a><br /><a id="L2760" href="#L2760">2760</a><br /><a id="L2761" href="#L2761">2761</a><br /><a id="L2762" href="#L2762">2762</a><br /><a id="L2763" href="#L2763">2763</a><br /><a id="L2764" href="#L2764">2764</a><br /><a id="L2765" href="#L2765">2765</a><br /><a id="L2766" href="#L2766">2766</a><br /><a id="L2767" href="#L2767">2767</a><br /><a id="L2768" href="#L2768">2768</a><br /><a id="L2769" href="#L2769">2769</a><br /><a id="L2770" href="#L2770">2770</a><br /><a id="L2771" href="#L2771">2771</a><br /><a id="L2772" href="#L2772">2772</a><br /><a id="L2773" href="#L2773">2773</a><br /><a id="L2774" href="#L2774">2774</a><br /><a id="L2775" href="#L2775">2775</a><br /><a id="L2776" href="#L2776">2776</a><br /><a id="L2777" href="#L2777">2777</a><br /><a id="L2778" href="#L2778">2778</a><br /><a id="L2779" href="#L2779">2779</a><br /><a id="L2780" href="#L2780">2780</a><br /><a id="L2781" href="#L2781">2781</a><br /><a id="L2782" href="#L2782">2782</a><br /><a id="L2783" href="#L2783">2783</a><br /><a id="L2784" href="#L2784">2784</a><br /><a id="L2785" href="#L2785">2785</a><br /><a id="L2786" href="#L2786">2786</a><br /><a id="L2787" href="#L2787">2787</a><br /><a id="L2788" href="#L2788">2788</a><br /><a id="L2789" href="#L2789">2789</a><br /><a id="L2790" href="#L2790">2790</a><br /><a id="L2791" href="#L2791">2791</a><br /><a id="L2792" href="#L2792">2792</a><br /><a id="L2793" href="#L2793">2793</a><br /><a id="L2794" href="#L2794">2794</a><br /><a id="L2795" href="#L2795">2795</a><br /><a id="L2796" href="#L2796">2796</a><br /><a id="L2797" href="#L2797">2797</a><br /><a id="L2798" href="#L2798">2798</a><br /><a id="L2799" href="#L2799">2799</a><br /><a id="L2800" href="#L2800">2800</a><br /><a id="L2801" href="#L2801">2801</a><br /><a id="L2802" href="#L2802">2802</a><br /><a id="L2803" href="#L2803">2803</a><br /><a id="L2804" href="#L2804">2804</a><br /><a id="L2805" href="#L2805">2805</a><br /><a id="L2806" href="#L2806">2806</a><br /><a id="L2807" href="#L2807">2807</a><br /><a id="L2808" href="#L2808">2808</a><br /><a id="L2809" href="#L2809">2809</a><br /><a id="L2810" href="#L2810">2810</a><br /><a id="L2811" href="#L2811">2811</a><br /><a id="L2812" href="#L2812">2812</a><br /><a id="L2813" href="#L2813">2813</a><br /><a id="L2814" href="#L2814">2814</a><br /><a id="L2815" href="#L2815">2815</a><br /><a id="L2816" href="#L2816">2816</a><br /><a id="L2817" href="#L2817">2817</a><br /><a id="L2818" href="#L2818">2818</a><br /><a id="L2819" href="#L2819">2819</a><br /><a id="L2820" href="#L2820">2820</a><br /><a id="L2821" href="#L2821">2821</a><br /><a id="L2822" href="#L2822">2822</a><br /><a id="L2823" href="#L2823">2823</a><br /><a id="L2824" href="#L2824">2824</a><br /><a id="L2825" href="#L2825">2825</a><br /><a id="L2826" href="#L2826">2826</a><br /><a id="L2827" href="#L2827">2827</a><br /><a id="L2828" href="#L2828">2828</a><br /><a id="L2829" href="#L2829">2829</a><br /><a id="L2830" href="#L2830">2830</a><br /><a id="L2831" href="#L2831">2831</a><br /><a id="L2832" href="#L2832">2832</a><br /><a id="L2833" href="#L2833">2833</a><br /><a id="L2834" href="#L2834">2834</a><br /><a id="L2835" href="#L2835">2835</a><br /><a id="L2836" href="#L2836">2836</a><br /><a id="L2837" href="#L2837">2837</a><br /><a id="L2838" href="#L2838">2838</a><br /><a id="L2839" href="#L2839">2839</a><br /><a id="L2840" href="#L2840">2840</a><br /><a id="L2841" href="#L2841">2841</a><br /><a id="L2842" href="#L2842">2842</a><br /><a id="L2843" href="#L2843">2843</a><br /><a id="L2844" href="#L2844">2844</a><br /><a id="L2845" href="#L2845">2845</a><br /><a id="L2846" href="#L2846">2846</a><br /><a id="L2847" href="#L2847">2847</a><br /><a id="L2848" href="#L2848">2848</a><br /><a id="L2849" href="#L2849">2849</a><br /><a id="L2850" href="#L2850">2850</a><br /><a id="L2851" href="#L2851">2851</a><br /><a id="L2852" href="#L2852">2852</a><br /><a id="L2853" href="#L2853">2853</a><br /><a id="L2854" href="#L2854">2854</a><br /><a id="L2855" href="#L2855">2855</a><br /><a id="L2856" href="#L2856">2856</a><br /><a id="L2857" href="#L2857">2857</a><br /><a id="L2858" href="#L2858">2858</a><br /><a id="L2859" href="#L2859">2859</a><br /><a id="L2860" href="#L2860">2860</a><br /><a id="L2861" href="#L2861">2861</a><br /><a id="L2862" href="#L2862">2862</a><br /><a id="L2863" href="#L2863">2863</a><br /><a id="L2864" href="#L2864">2864</a><br /><a id="L2865" href="#L2865">2865</a><br /><a id="L2866" href="#L2866">2866</a><br /><a id="L2867" href="#L2867">2867</a><br /><a id="L2868" href="#L2868">2868</a><br /><a id="L2869" href="#L2869">2869</a><br /><a id="L2870" href="#L2870">2870</a><br /><a id="L2871" href="#L2871">2871</a><br /><a id="L2872" href="#L2872">2872</a><br /><a id="L2873" href="#L2873">2873</a><br /><a id="L2874" href="#L2874">2874</a><br /><a id="L2875" href="#L2875">2875</a><br /><a id="L2876" href="#L2876">2876</a><br /><a id="L2877" href="#L2877">2877</a><br /><a id="L2878" href="#L2878">2878</a><br /><a id="L2879" href="#L2879">2879</a><br /><a id="L2880" href="#L2880">2880</a><br /><a id="L2881" href="#L2881">2881</a><br /><a id="L2882" href="#L2882">2882</a><br /><a id="L2883" href="#L2883">2883</a><br /><a id="L2884" href="#L2884">2884</a><br /><a id="L2885" href="#L2885">2885</a><br /><a id="L2886" href="#L2886">2886</a><br /><a id="L2887" href="#L2887">2887</a><br /><a id="L2888" href="#L2888">2888</a><br /><a id="L2889" href="#L2889">2889</a><br /><a id="L2890" href="#L2890">2890</a><br /><a id="L2891" href="#L2891">2891</a><br /><a id="L2892" href="#L2892">2892</a><br /><a id="L2893" href="#L2893">2893</a><br /><a id="L2894" href="#L2894">2894</a><br /><a id="L2895" href="#L2895">2895</a><br /><a id="L2896" href="#L2896">2896</a><br /><a id="L2897" href="#L2897">2897</a><br /><a id="L2898" href="#L2898">2898</a><br /><a id="L2899" href="#L2899">2899</a><br /><a id="L2900" href="#L2900">2900</a><br /><a id="L2901" href="#L2901">2901</a><br /><a id="L2902" href="#L2902">2902</a><br /><a id="L2903" href="#L2903">2903</a><br /><a id="L2904" href="#L2904">2904</a><br /><a id="L2905" href="#L2905">2905</a><br /><a id="L2906" href="#L2906">2906</a><br /><a id="L2907" href="#L2907">2907</a><br /><a id="L2908" href="#L2908">2908</a><br /><a id="L2909" href="#L2909">2909</a><br /><a id="L2910" href="#L2910">2910</a><br /><a id="L2911" href="#L2911">2911</a><br /><a id="L2912" href="#L2912">2912</a><br /><a id="L2913" href="#L2913">2913</a><br /><a id="L2914" href="#L2914">2914</a><br /><a id="L2915" href="#L2915">2915</a><br /><a id="L2916" href="#L2916">2916</a><br /><a id="L2917" href="#L2917">2917</a><br /><a id="L2918" href="#L2918">2918</a><br /><a id="L2919" href="#L2919">2919</a><br /><a id="L2920" href="#L2920">2920</a><br /><a id="L2921" href="#L2921">2921</a><br /><a id="L2922" href="#L2922">2922</a><br /><a id="L2923" href="#L2923">2923</a><br /><a id="L2924" href="#L2924">2924</a><br /><a id="L2925" href="#L2925">2925</a><br /><a id="L2926" href="#L2926">2926</a><br /><a id="L2927" href="#L2927">2927</a><br /><a id="L2928" href="#L2928">2928</a><br /><a id="L2929" href="#L2929">2929</a><br /><a id="L2930" href="#L2930">2930</a><br /><a id="L2931" href="#L2931">2931</a><br /><a id="L2932" href="#L2932">2932</a><br /><a id="L2933" href="#L2933">2933</a><br /><a id="L2934" href="#L2934">2934</a><br /><a id="L2935" href="#L2935">2935</a><br /><a id="L2936" href="#L2936">2936</a><br /><a id="L2937" href="#L2937">2937</a><br /><a id="L2938" href="#L2938">2938</a><br /><a id="L2939" href="#L2939">2939</a><br /><a id="L2940" href="#L2940">2940</a><br /><a id="L2941" href="#L2941">2941</a><br /><a id="L2942" href="#L2942">2942</a><br /><a id="L2943" href="#L2943">2943</a><br /><a id="L2944" href="#L2944">2944</a><br /><a id="L2945" href="#L2945">2945</a><br /><a id="L2946" href="#L2946">2946</a><br /><a id="L2947" href="#L2947">2947</a><br /><a id="L2948" href="#L2948">2948</a><br /><a id="L2949" href="#L2949">2949</a><br /><a id="L2950" href="#L2950">2950</a><br /><a id="L2951" href="#L2951">2951</a><br /><a id="L2952" href="#L2952">2952</a><br /><a id="L2953" href="#L2953">2953</a><br /><a id="L2954" href="#L2954">2954</a><br /><a id="L2955" href="#L2955">2955</a><br /><a id="L2956" href="#L2956">2956</a><br /><a id="L2957" href="#L2957">2957</a><br /><a id="L2958" href="#L2958">2958</a><br /><a id="L2959" href="#L2959">2959</a><br /><a id="L2960" href="#L2960">2960</a><br /><a id="L2961" href="#L2961">2961</a><br /><a id="L2962" href="#L2962">2962</a><br /><a id="L2963" href="#L2963">2963</a><br /><a id="L2964" href="#L2964">2964</a><br /><a id="L2965" href="#L2965">2965</a><br /><a id="L2966" href="#L2966">2966</a><br /><a id="L2967" href="#L2967">2967</a><br /><a id="L2968" href="#L2968">2968</a><br /><a id="L2969" href="#L2969">2969</a><br /><a id="L2970" href="#L2970">2970</a><br /><a id="L2971" href="#L2971">2971</a><br /><a id="L2972" href="#L2972">2972</a><br /><a id="L2973" href="#L2973">2973</a><br /><a id="L2974" href="#L2974">2974</a><br /><a id="L2975" href="#L2975">2975</a><br /><a id="L2976" href="#L2976">2976</a><br /><a id="L2977" href="#L2977">2977</a><br /><a id="L2978" href="#L2978">2978</a><br /><a id="L2979" href="#L2979">2979</a><br /><a id="L2980" href="#L2980">2980</a><br /><a id="L2981" href="#L2981">2981</a><br /><a id="L2982" href="#L2982">2982</a><br /><a id="L2983" href="#L2983">2983</a><br /><a id="L2984" href="#L2984">2984</a><br /><a id="L2985" href="#L2985">2985</a><br /><a id="L2986" href="#L2986">2986</a><br /><a id="L2987" href="#L2987">2987</a><br /><a id="L2988" href="#L2988">2988</a><br /><a id="L2989" href="#L2989">2989</a><br /><a id="L2990" href="#L2990">2990</a><br /><a id="L2991" href="#L2991">2991</a><br /><a id="L2992" href="#L2992">2992</a><br /><a id="L2993" href="#L2993">2993</a><br /><a id="L2994" href="#L2994">2994</a><br /><a id="L2995" href="#L2995">2995</a><br /><a id="L2996" href="#L2996">2996</a><br /><a id="L2997" href="#L2997">2997</a><br /><a id="L2998" href="#L2998">2998</a><br /><a id="L2999" href="#L2999">2999</a><br /><a id="L3000" href="#L3000">3000</a><br /><a id="L3001" href="#L3001">3001</a><br /><a id="L3002" href="#L3002">3002</a><br /><a id="L3003" href="#L3003">3003</a><br /><a id="L3004" href="#L3004">3004</a><br /><a id="L3005" href="#L3005">3005</a><br /><a id="L3006" href="#L3006">3006</a><br /><a id="L3007" href="#L3007">3007</a><br /><a id="L3008" href="#L3008">3008</a><br /><a id="L3009" href="#L3009">3009</a><br /><a id="L3010" href="#L3010">3010</a><br /><a id="L3011" href="#L3011">3011</a><br /><a id="L3012" href="#L3012">3012</a><br /><a id="L3013" href="#L3013">3013</a><br /><a id="L3014" href="#L3014">3014</a><br /><a id="L3015" href="#L3015">3015</a><br /><a id="L3016" href="#L3016">3016</a><br /><a id="L3017" href="#L3017">3017</a><br /><a id="L3018" href="#L3018">3018</a><br /><a id="L3019" href="#L3019">3019</a><br /><a id="L3020" href="#L3020">3020</a><br /><a id="L3021" href="#L3021">3021</a><br /><a id="L3022" href="#L3022">3022</a><br /><a id="L3023" href="#L3023">3023</a><br /><a id="L3024" href="#L3024">3024</a><br /><a id="L3025" href="#L3025">3025</a><br /><a id="L3026" href="#L3026">3026</a><br /><a id="L3027" href="#L3027">3027</a><br /><a id="L3028" href="#L3028">3028</a><br /><a id="L3029" href="#L3029">3029</a><br /><a id="L3030" href="#L3030">3030</a><br /><a id="L3031" href="#L3031">3031</a><br /><a id="L3032" href="#L3032">3032</a><br /><a id="L3033" href="#L3033">3033</a><br /><a id="L3034" href="#L3034">3034</a><br /><a id="L3035" href="#L3035">3035</a><br /><a id="L3036" href="#L3036">3036</a><br /><a id="L3037" href="#L3037">3037</a><br /><a id="L3038" href="#L3038">3038</a><br /><a id="L3039" href="#L3039">3039</a><br /><a id="L3040" href="#L3040">3040</a><br /><a id="L3041" href="#L3041">3041</a><br /><a id="L3042" href="#L3042">3042</a><br /><a id="L3043" href="#L3043">3043</a><br /><a id="L3044" href="#L3044">3044</a><br /><a id="L3045" href="#L3045">3045</a><br /><a id="L3046" href="#L3046">3046</a><br /><a id="L3047" href="#L3047">3047</a><br /><a id="L3048" href="#L3048">3048</a><br /><a id="L3049" href="#L3049">3049</a><br /><a id="L3050" href="#L3050">3050</a><br /><a id="L3051" href="#L3051">3051</a><br /><a id="L3052" href="#L3052">3052</a><br /><a id="L3053" href="#L3053">3053</a><br /><a id="L3054" href="#L3054">3054</a><br /><a id="L3055" href="#L3055">3055</a><br /><a id="L3056" href="#L3056">3056</a><br /><a id="L3057" href="#L3057">3057</a><br /><a id="L3058" href="#L3058">3058</a><br /><a id="L3059" href="#L3059">3059</a><br /><a id="L3060" href="#L3060">3060</a><br /><a id="L3061" href="#L3061">3061</a><br /><a id="L3062" href="#L3062">3062</a><br /><a id="L3063" href="#L3063">3063</a><br /><a id="L3064" href="#L3064">3064</a><br /><a id="L3065" href="#L3065">3065</a><br /><a id="L3066" href="#L3066">3066</a><br /><a id="L3067" href="#L3067">3067</a><br /><a id="L3068" href="#L3068">3068</a><br /><a id="L3069" href="#L3069">3069</a><br /><a id="L3070" href="#L3070">3070</a><br /><a id="L3071" href="#L3071">3071</a><br /><a id="L3072" href="#L3072">3072</a><br /><a id="L3073" href="#L3073">3073</a><br /><a id="L3074" href="#L3074">3074</a><br /><a id="L3075" href="#L3075">3075</a><br /><a id="L3076" href="#L3076">3076</a><br /><a id="L3077" href="#L3077">3077</a><br /><a id="L3078" href="#L3078">3078</a><br /><a id="L3079" href="#L3079">3079</a><br /><a id="L3080" href="#L3080">3080</a><br /><a id="L3081" href="#L3081">3081</a><br /><a id="L3082" href="#L3082">3082</a><br /><a id="L3083" href="#L3083">3083</a><br /><a id="L3084" href="#L3084">3084</a><br /><a id="L3085" href="#L3085">3085</a><br /><a id="L3086" href="#L3086">3086</a><br /><a id="L3087" href="#L3087">3087</a><br /><a id="L3088" href="#L3088">3088</a><br /><a id="L3089" href="#L3089">3089</a><br /><a id="L3090" href="#L3090">3090</a><br /><a id="L3091" href="#L3091">3091</a><br /><a id="L3092" href="#L3092">3092</a><br /><a id="L3093" href="#L3093">3093</a><br /><a id="L3094" href="#L3094">3094</a><br /><a id="L3095" href="#L3095">3095</a><br /><a id="L3096" href="#L3096">3096</a><br /><a id="L3097" href="#L3097">3097</a><br /><a id="L3098" href="#L3098">3098</a><br /><a id="L3099" href="#L3099">3099</a><br /><a id="L3100" href="#L3100">3100</a><br /><a id="L3101" href="#L3101">3101</a><br /><a id="L3102" href="#L3102">3102</a><br /><a id="L3103" href="#L3103">3103</a><br /><a id="L3104" href="#L3104">3104</a><br /><a id="L3105" href="#L3105">3105</a><br /><a id="L3106" href="#L3106">3106</a><br /><a id="L3107" href="#L3107">3107</a><br /><a id="L3108" href="#L3108">3108</a><br /><a id="L3109" href="#L3109">3109</a><br /><a id="L3110" href="#L3110">3110</a><br /><a id="L3111" href="#L3111">3111</a><br /><a id="L3112" href="#L3112">3112</a><br /><a id="L3113" href="#L3113">3113</a><br /><a id="L3114" href="#L3114">3114</a><br /><a id="L3115" href="#L3115">3115</a><br /><a id="L3116" href="#L3116">3116</a><br /><a id="L3117" href="#L3117">3117</a><br /><a id="L3118" href="#L3118">3118</a><br /><a id="L3119" href="#L3119">3119</a><br /><a id="L3120" href="#L3120">3120</a><br /><a id="L3121" href="#L3121">3121</a><br /><a id="L3122" href="#L3122">3122</a><br /><a id="L3123" href="#L3123">3123</a><br /><a id="L3124" href="#L3124">3124</a><br /><a id="L3125" href="#L3125">3125</a><br /><a id="L3126" href="#L3126">3126</a><br /><a id="L3127" href="#L3127">3127</a><br /><a id="L3128" href="#L3128">3128</a><br /><a id="L3129" href="#L3129">3129</a><br /><a id="L3130" href="#L3130">3130</a><br /><a id="L3131" href="#L3131">3131</a><br /><a id="L3132" href="#L3132">3132</a><br /><a id="L3133" href="#L3133">3133</a><br /><a id="L3134" href="#L3134">3134</a><br /><a id="L3135" href="#L3135">3135</a><br /><a id="L3136" href="#L3136">3136</a><br /><a id="L3137" href="#L3137">3137</a><br /><a id="L3138" href="#L3138">3138</a><br /><a id="L3139" href="#L3139">3139</a><br /><a id="L3140" href="#L3140">3140</a><br /><a id="L3141" href="#L3141">3141</a><br /><a id="L3142" href="#L3142">3142</a><br /><a id="L3143" href="#L3143">3143</a><br /><a id="L3144" href="#L3144">3144</a><br /><a id="L3145" href="#L3145">3145</a><br /><a id="L3146" href="#L3146">3146</a><br /><a id="L3147" href="#L3147">3147</a><br /><a id="L3148" href="#L3148">3148</a><br /><a id="L3149" href="#L3149">3149</a><br /><a id="L3150" href="#L3150">3150</a><br /><a id="L3151" href="#L3151">3151</a><br /><a id="L3152" href="#L3152">3152</a><br /><a id="L3153" href="#L3153">3153</a><br /><a id="L3154" href="#L3154">3154</a><br /><a id="L3155" href="#L3155">3155</a><br /><a id="L3156" href="#L3156">3156</a><br /><a id="L3157" href="#L3157">3157</a><br /><a id="L3158" href="#L3158">3158</a><br /><a id="L3159" href="#L3159">3159</a><br /><a id="L3160" href="#L3160">3160</a><br /><a id="L3161" href="#L3161">3161</a><br /><a id="L3162" href="#L3162">3162</a><br /><a id="L3163" href="#L3163">3163</a><br /><a id="L3164" href="#L3164">3164</a><br /><a id="L3165" href="#L3165">3165</a><br /><a id="L3166" href="#L3166">3166</a><br /><a id="L3167" href="#L3167">3167</a><br /><a id="L3168" href="#L3168">3168</a><br /><a id="L3169" href="#L3169">3169</a><br /><a id="L3170" href="#L3170">3170</a><br /><a id="L3171" href="#L3171">3171</a><br /><a id="L3172" href="#L3172">3172</a><br /><a id="L3173" href="#L3173">3173</a><br /><a id="L3174" href="#L3174">3174</a><br /><a id="L3175" href="#L3175">3175</a><br /><a id="L3176" href="#L3176">3176</a><br /><a id="L3177" href="#L3177">3177</a><br /><a id="L3178" href="#L3178">3178</a><br /><a id="L3179" href="#L3179">3179</a><br /><a id="L3180" href="#L3180">3180</a><br /><a id="L3181" href="#L3181">3181</a><br /><a id="L3182" href="#L3182">3182</a><br /><a id="L3183" href="#L3183">3183</a><br /><a id="L3184" href="#L3184">3184</a><br /><a id="L3185" href="#L3185">3185</a><br /><a id="L3186" href="#L3186">3186</a><br /><a id="L3187" href="#L3187">3187</a><br /><a id="L3188" href="#L3188">3188</a><br /><a id="L3189" href="#L3189">3189</a><br /><a id="L3190" href="#L3190">3190</a><br /><a id="L3191" href="#L3191">3191</a><br /><a id="L3192" href="#L3192">3192</a><br /><a id="L3193" href="#L3193">3193</a><br /><a id="L3194" href="#L3194">3194</a><br /><a id="L3195" href="#L3195">3195</a><br /><a id="L3196" href="#L3196">3196</a><br /><a id="L3197" href="#L3197">3197</a><br /><a id="L3198" href="#L3198">3198</a><br /><a id="L3199" href="#L3199">3199</a><br /><a id="L3200" href="#L3200">3200</a><br /><a id="L3201" href="#L3201">3201</a><br /><a id="L3202" href="#L3202">3202</a><br /><a id="L3203" href="#L3203">3203</a><br /><a id="L3204" href="#L3204">3204</a><br /><a id="L3205" href="#L3205">3205</a><br /><a id="L3206" href="#L3206">3206</a><br /><a id="L3207" href="#L3207">3207</a><br /><a id="L3208" href="#L3208">3208</a><br /><a id="L3209" href="#L3209">3209</a><br /><a id="L3210" href="#L3210">3210</a><br /><a id="L3211" href="#L3211">3211</a><br /><a id="L3212" href="#L3212">3212</a><br /><a id="L3213" href="#L3213">3213</a><br /><a id="L3214" href="#L3214">3214</a><br /><a id="L3215" href="#L3215">3215</a><br /><a id="L3216" href="#L3216">3216</a><br /><a id="L3217" href="#L3217">3217</a><br /><a id="L3218" href="#L3218">3218</a><br /><a id="L3219" href="#L3219">3219</a><br /><a id="L3220" href="#L3220">3220</a><br /><a id="L3221" href="#L3221">3221</a><br /><a id="L3222" href="#L3222">3222</a><br /><a id="L3223" href="#L3223">3223</a><br /><a id="L3224" href="#L3224">3224</a><br /><a id="L3225" href="#L3225">3225</a><br /><a id="L3226" href="#L3226">3226</a><br /><a id="L3227" href="#L3227">3227</a><br /><a id="L3228" href="#L3228">3228</a><br /><a id="L3229" href="#L3229">3229</a><br /><a id="L3230" href="#L3230">3230</a><br /><a id="L3231" href="#L3231">3231</a><br /><a id="L3232" href="#L3232">3232</a><br /><a id="L3233" href="#L3233">3233</a><br /><a id="L3234" href="#L3234">3234</a><br /><a id="L3235" href="#L3235">3235</a><br /><a id="L3236" href="#L3236">3236</a><br /><a id="L3237" href="#L3237">3237</a><br /><a id="L3238" href="#L3238">3238</a><br /><a id="L3239" href="#L3239">3239</a><br /><a id="L3240" href="#L3240">3240</a><br /><a id="L3241" href="#L3241">3241</a><br /><a id="L3242" href="#L3242">3242</a><br /><a id="L3243" href="#L3243">3243</a><br /><a id="L3244" href="#L3244">3244</a><br /><a id="L3245" href="#L3245">3245</a><br /><a id="L3246" href="#L3246">3246</a><br /><a id="L3247" href="#L3247">3247</a><br /><a id="L3248" href="#L3248">3248</a><br /><a id="L3249" href="#L3249">3249</a><br /><a id="L3250" href="#L3250">3250</a><br /><a id="L3251" href="#L3251">3251</a><br /><a id="L3252" href="#L3252">3252</a><br /><a id="L3253" href="#L3253">3253</a><br /><a id="L3254" href="#L3254">3254</a><br /><a id="L3255" href="#L3255">3255</a><br /><a id="L3256" href="#L3256">3256</a><br /><a id="L3257" href="#L3257">3257</a><br /><a id="L3258" href="#L3258">3258</a><br /><a id="L3259" href="#L3259">3259</a><br /><a id="L3260" href="#L3260">3260</a><br /><a id="L3261" href="#L3261">3261</a><br /><a id="L3262" href="#L3262">3262</a><br /><a id="L3263" href="#L3263">3263</a><br /><a id="L3264" href="#L3264">3264</a><br /><a id="L3265" href="#L3265">3265</a><br /><a id="L3266" href="#L3266">3266</a><br /><a id="L3267" href="#L3267">3267</a><br /><a id="L3268" href="#L3268">3268</a><br /><a id="L3269" href="#L3269">3269</a><br /><a id="L3270" href="#L3270">3270</a><br /><a id="L3271" href="#L3271">3271</a><br /><a id="L3272" href="#L3272">3272</a><br /><a id="L3273" href="#L3273">3273</a><br /><a id="L3274" href="#L3274">3274</a><br /><a id="L3275" href="#L3275">3275</a><br /><a id="L3276" href="#L3276">3276</a><br /><a id="L3277" href="#L3277">3277</a><br /><a id="L3278" href="#L3278">3278</a><br /><a id="L3279" href="#L3279">3279</a><br /><a id="L3280" href="#L3280">3280</a><br /><a id="L3281" href="#L3281">3281</a><br /><a id="L3282" href="#L3282">3282</a><br /><a id="L3283" href="#L3283">3283</a><br /><a id="L3284" href="#L3284">3284</a><br /><a id="L3285" href="#L3285">3285</a><br /><a id="L3286" href="#L3286">3286</a><br /><a id="L3287" href="#L3287">3287</a><br /><a id="L3288" href="#L3288">3288</a><br /><a id="L3289" href="#L3289">3289</a><br /><a id="L3290" href="#L3290">3290</a><br /><a id="L3291" href="#L3291">3291</a><br /><a id="L3292" href="#L3292">3292</a><br /><a id="L3293" href="#L3293">3293</a><br /><a id="L3294" href="#L3294">3294</a><br /><a id="L3295" href="#L3295">3295</a><br /><a id="L3296" href="#L3296">3296</a><br /><a id="L3297" href="#L3297">3297</a><br /><a id="L3298" href="#L3298">3298</a><br /><a id="L3299" href="#L3299">3299</a><br /><a id="L3300" href="#L3300">3300</a><br /><a id="L3301" href="#L3301">3301</a><br /><a id="L3302" href="#L3302">3302</a><br /><a id="L3303" href="#L3303">3303</a><br /><a id="L3304" href="#L3304">3304</a><br /><a id="L3305" href="#L3305">3305</a><br /><a id="L3306" href="#L3306">3306</a><br /><a id="L3307" href="#L3307">3307</a><br /><a id="L3308" href="#L3308">3308</a><br /><a id="L3309" href="#L3309">3309</a><br /><a id="L3310" href="#L3310">3310</a><br /><a id="L3311" href="#L3311">3311</a><br /><a id="L3312" href="#L3312">3312</a><br /><a id="L3313" href="#L3313">3313</a><br /><a id="L3314" href="#L3314">3314</a><br /><a id="L3315" href="#L3315">3315</a><br /><a id="L3316" href="#L3316">3316</a><br /><a id="L3317" href="#L3317">3317</a><br /><a id="L3318" href="#L3318">3318</a><br /><a id="L3319" href="#L3319">3319</a><br /><a id="L3320" href="#L3320">3320</a><br /><a id="L3321" href="#L3321">3321</a><br /><a id="L3322" href="#L3322">3322</a><br /><a id="L3323" href="#L3323">3323</a><br /><a id="L3324" href="#L3324">3324</a><br /><a id="L3325" href="#L3325">3325</a><br /><a id="L3326" href="#L3326">3326</a><br /><a id="L3327" href="#L3327">3327</a><br /><a id="L3328" href="#L3328">3328</a><br /><a id="L3329" href="#L3329">3329</a><br /><a id="L3330" href="#L3330">3330</a><br /><a id="L3331" href="#L3331">3331</a><br /><a id="L3332" href="#L3332">3332</a><br /><a id="L3333" href="#L3333">3333</a><br /><a id="L3334" href="#L3334">3334</a><br /><a id="L3335" href="#L3335">3335</a><br /><a id="L3336" href="#L3336">3336</a><br /><a id="L3337" href="#L3337">3337</a><br /><a id="L3338" href="#L3338">3338</a><br /><a id="L3339" href="#L3339">3339</a><br /><a id="L3340" href="#L3340">3340</a><br /><a id="L3341" href="#L3341">3341</a><br /><a id="L3342" href="#L3342">3342</a><br /><a id="L3343" href="#L3343">3343</a><br /><a id="L3344" href="#L3344">3344</a><br /><a id="L3345" href="#L3345">3345</a><br /><a id="L3346" href="#L3346">3346</a><br /><a id="L3347" href="#L3347">3347</a><br /><a id="L3348" href="#L3348">3348</a><br /><a id="L3349" href="#L3349">3349</a><br /><a id="L3350" href="#L3350">3350</a><br /><a id="L3351" href="#L3351">3351</a><br /><a id="L3352" href="#L3352">3352</a><br /><a id="L3353" href="#L3353">3353</a><br /><a id="L3354" href="#L3354">3354</a><br /><a id="L3355" href="#L3355">3355</a><br /><a id="L3356" href="#L3356">3356</a><br /><a id="L3357" href="#L3357">3357</a><br /><a id="L3358" href="#L3358">3358</a><br /><a id="L3359" href="#L3359">3359</a><br /><a id="L3360" href="#L3360">3360</a><br /><a id="L3361" href="#L3361">3361</a><br /><a id="L3362" href="#L3362">3362</a><br /><a id="L3363" href="#L3363">3363</a><br /><a id="L3364" href="#L3364">3364</a><br /><a id="L3365" href="#L3365">3365</a><br /><a id="L3366" href="#L3366">3366</a><br /><a id="L3367" href="#L3367">3367</a><br /><a id="L3368" href="#L3368">3368</a><br /><a id="L3369" href="#L3369">3369</a><br /><a id="L3370" href="#L3370">3370</a><br /><a id="L3371" href="#L3371">3371</a><br /><a id="L3372" href="#L3372">3372</a><br /><a id="L3373" href="#L3373">3373</a><br /><a id="L3374" href="#L3374">3374</a><br /><a id="L3375" href="#L3375">3375</a><br /><a id="L3376" href="#L3376">3376</a><br /><a id="L3377" href="#L3377">3377</a><br /><a id="L3378" href="#L3378">3378</a><br /><a id="L3379" href="#L3379">3379</a><br /><a id="L3380" href="#L3380">3380</a><br /><a id="L3381" href="#L3381">3381</a><br /><a id="L3382" href="#L3382">3382</a><br /><a id="L3383" href="#L3383">3383</a><br /><a id="L3384" href="#L3384">3384</a><br /><a id="L3385" href="#L3385">3385</a><br /><a id="L3386" href="#L3386">3386</a><br /><a id="L3387" href="#L3387">3387</a><br /><a id="L3388" href="#L3388">3388</a><br /><a id="L3389" href="#L3389">3389</a><br /><a id="L3390" href="#L3390">3390</a><br /><a id="L3391" href="#L3391">3391</a><br /><a id="L3392" href="#L3392">3392</a><br /><a id="L3393" href="#L3393">3393</a><br /><a id="L3394" href="#L3394">3394</a><br /><a id="L3395" href="#L3395">3395</a><br /><a id="L3396" href="#L3396">3396</a><br /><a id="L3397" href="#L3397">3397</a><br /><a id="L3398" href="#L3398">3398</a><br /><a id="L3399" href="#L3399">3399</a><br /><a id="L3400" href="#L3400">3400</a><br /><a id="L3401" href="#L3401">3401</a><br /><a id="L3402" href="#L3402">3402</a><br /><a id="L3403" href="#L3403">3403</a><br /><a id="L3404" href="#L3404">3404</a><br /><a id="L3405" href="#L3405">3405</a><br /><a id="L3406" href="#L3406">3406</a><br /><a id="L3407" href="#L3407">3407</a><br /><a id="L3408" href="#L3408">3408</a><br /><a id="L3409" href="#L3409">3409</a><br /><a id="L3410" href="#L3410">3410</a><br /><a id="L3411" href="#L3411">3411</a><br /><a id="L3412" href="#L3412">3412</a><br /><a id="L3413" href="#L3413">3413</a><br /><a id="L3414" href="#L3414">3414</a><br /><a id="L3415" href="#L3415">3415</a><br /><a id="L3416" href="#L3416">3416</a><br /><a id="L3417" href="#L3417">3417</a><br /><a id="L3418" href="#L3418">3418</a><br /><a id="L3419" href="#L3419">3419</a><br /><a id="L3420" href="#L3420">3420</a><br /><a id="L3421" href="#L3421">3421</a><br /><a id="L3422" href="#L3422">3422</a><br /><a id="L3423" href="#L3423">3423</a><br /><a id="L3424" href="#L3424">3424</a><br /><a id="L3425" href="#L3425">3425</a><br /><a id="L3426" href="#L3426">3426</a><br /><a id="L3427" href="#L3427">3427</a><br /><a id="L3428" href="#L3428">3428</a><br /><a id="L3429" href="#L3429">3429</a><br /><a id="L3430" href="#L3430">3430</a><br /><a id="L3431" href="#L3431">3431</a><br /><a id="L3432" href="#L3432">3432</a><br /><a id="L3433" href="#L3433">3433</a><br /><a id="L3434" href="#L3434">3434</a><br /><a id="L3435" href="#L3435">3435</a><br /><a id="L3436" href="#L3436">3436</a><br /><a id="L3437" href="#L3437">3437</a><br /><a id="L3438" href="#L3438">3438</a><br /><a id="L3439" href="#L3439">3439</a><br /><a id="L3440" href="#L3440">3440</a><br /><a id="L3441" href="#L3441">3441</a><br /><a id="L3442" href="#L3442">3442</a><br /><a id="L3443" href="#L3443">3443</a><br /><a id="L3444" href="#L3444">3444</a><br /><a id="L3445" href="#L3445">3445</a><br /><a id="L3446" href="#L3446">3446</a><br /><a id="L3447" href="#L3447">3447</a><br /><a id="L3448" href="#L3448">3448</a><br /><a id="L3449" href="#L3449">3449</a><br /><a id="L3450" href="#L3450">3450</a><br /><a id="L3451" href="#L3451">3451</a><br /><a id="L3452" href="#L3452">3452</a><br /><a id="L3453" href="#L3453">3453</a><br /><a id="L3454" href="#L3454">3454</a><br /><a id="L3455" href="#L3455">3455</a><br /><a id="L3456" href="#L3456">3456</a><br /><a id="L3457" href="#L3457">3457</a><br /><a id="L3458" href="#L3458">3458</a><br /><a id="L3459" href="#L3459">3459</a><br /><a id="L3460" href="#L3460">3460</a><br /><a id="L3461" href="#L3461">3461</a><br /><a id="L3462" href="#L3462">3462</a><br /><a id="L3463" href="#L3463">3463</a><br /><a id="L3464" href="#L3464">3464</a><br /><a id="L3465" href="#L3465">3465</a><br /><a id="L3466" href="#L3466">3466</a><br /><a id="L3467" href="#L3467">3467</a><br /><a id="L3468" href="#L3468">3468</a><br /><a id="L3469" href="#L3469">3469</a><br /><a id="L3470" href="#L3470">3470</a><br /><a id="L3471" href="#L3471">3471</a><br /><a id="L3472" href="#L3472">3472</a><br /><a id="L3473" href="#L3473">3473</a><br /><a id="L3474" href="#L3474">3474</a><br /><a id="L3475" href="#L3475">3475</a><br /><a id="L3476" href="#L3476">3476</a><br /><a id="L3477" href="#L3477">3477</a><br /><a id="L3478" href="#L3478">3478</a><br /><a id="L3479" href="#L3479">3479</a><br /><a id="L3480" href="#L3480">3480</a><br /><a id="L3481" href="#L3481">3481</a><br /><a id="L3482" href="#L3482">3482</a><br /><a id="L3483" href="#L3483">3483</a><br /><a id="L3484" href="#L3484">3484</a><br /><a id="L3485" href="#L3485">3485</a><br /><a id="L3486" href="#L3486">3486</a><br /><a id="L3487" href="#L3487">3487</a><br /><a id="L3488" href="#L3488">3488</a><br /><a id="L3489" href="#L3489">3489</a><br /><a id="L3490" href="#L3490">3490</a><br /><a id="L3491" href="#L3491">3491</a><br /><a id="L3492" href="#L3492">3492</a><br /><a id="L3493" href="#L3493">3493</a><br /><a id="L3494" href="#L3494">3494</a><br /><a id="L3495" href="#L3495">3495</a><br /><a id="L3496" href="#L3496">3496</a><br /><a id="L3497" href="#L3497">3497</a><br /><a id="L3498" href="#L3498">3498</a><br /><a id="L3499" href="#L3499">3499</a><br /><a id="L3500" href="#L3500">3500</a><br /><a id="L3501" href="#L3501">3501</a><br /><a id="L3502" href="#L3502">3502</a><br /><a id="L3503" href="#L3503">3503</a><br /><a id="L3504" href="#L3504">3504</a><br /><a id="L3505" href="#L3505">3505</a><br /><a id="L3506" href="#L3506">3506</a><br /><a id="L3507" href="#L3507">3507</a><br /><a id="L3508" href="#L3508">3508</a><br /><a id="L3509" href="#L3509">3509</a><br /><a id="L3510" href="#L3510">3510</a><br /><a id="L3511" href="#L3511">3511</a><br /><a id="L3512" href="#L3512">3512</a><br /><a id="L3513" href="#L3513">3513</a><br /><a id="L3514" href="#L3514">3514</a><br /><a id="L3515" href="#L3515">3515</a><br /><a id="L3516" href="#L3516">3516</a><br /><a id="L3517" href="#L3517">3517</a><br /><a id="L3518" href="#L3518">3518</a><br /><a id="L3519" href="#L3519">3519</a><br /><a id="L3520" href="#L3520">3520</a><br /><a id="L3521" href="#L3521">3521</a><br /><a id="L3522" href="#L3522">3522</a><br /><a id="L3523" href="#L3523">3523</a><br /><a id="L3524" href="#L3524">3524</a><br /><a id="L3525" href="#L3525">3525</a><br /><a id="L3526" href="#L3526">3526</a><br /><a id="L3527" href="#L3527">3527</a><br /><a id="L3528" href="#L3528">3528</a><br /><a id="L3529" href="#L3529">3529</a><br /><a id="L3530" href="#L3530">3530</a><br /><a id="L3531" href="#L3531">3531</a><br /><a id="L3532" href="#L3532">3532</a><br /><a id="L3533" href="#L3533">3533</a><br /><a id="L3534" href="#L3534">3534</a><br /><a id="L3535" href="#L3535">3535</a><br /><a id="L3536" href="#L3536">3536</a><br /><a id="L3537" href="#L3537">3537</a><br /><a id="L3538" href="#L3538">3538</a><br /><a id="L3539" href="#L3539">3539</a><br /><a id="L3540" href="#L3540">3540</a><br /><a id="L3541" href="#L3541">3541</a><br /><a id="L3542" href="#L3542">3542</a><br /><a id="L3543" href="#L3543">3543</a><br /><a id="L3544" href="#L3544">3544</a><br /><a id="L3545" href="#L3545">3545</a><br /><a id="L3546" href="#L3546">3546</a><br /><a id="L3547" href="#L3547">3547</a><br /><a id="L3548" href="#L3548">3548</a><br /><a id="L3549" href="#L3549">3549</a><br /><a id="L3550" href="#L3550">3550</a><br /><a id="L3551" href="#L3551">3551</a><br /><a id="L3552" href="#L3552">3552</a><br /><a id="L3553" href="#L3553">3553</a><br /><a id="L3554" href="#L3554">3554</a><br /><a id="L3555" href="#L3555">3555</a><br /><a id="L3556" href="#L3556">3556</a><br /><a id="L3557" href="#L3557">3557</a><br /><a id="L3558" href="#L3558">3558</a><br /><a id="L3559" href="#L3559">3559</a><br /><a id="L3560" href="#L3560">3560</a><br /><a id="L3561" href="#L3561">3561</a><br /><a id="L3562" href="#L3562">3562</a><br /><a id="L3563" href="#L3563">3563</a><br /><a id="L3564" href="#L3564">3564</a><br /><a id="L3565" href="#L3565">3565</a><br /><a id="L3566" href="#L3566">3566</a><br /><a id="L3567" href="#L3567">3567</a><br /><a id="L3568" href="#L3568">3568</a><br /><a id="L3569" href="#L3569">3569</a><br /><a id="L3570" href="#L3570">3570</a><br /><a id="L3571" href="#L3571">3571</a><br /><a id="L3572" href="#L3572">3572</a><br /><a id="L3573" href="#L3573">3573</a><br /><a id="L3574" href="#L3574">3574</a><br /><a id="L3575" href="#L3575">3575</a><br /><a id="L3576" href="#L3576">3576</a><br /><a id="L3577" href="#L3577">3577</a><br /><a id="L3578" href="#L3578">3578</a><br /><a id="L3579" href="#L3579">3579</a><br /><a id="L3580" href="#L3580">3580</a><br /><a id="L3581" href="#L3581">3581</a><br /><a id="L3582" href="#L3582">3582</a><br /><a id="L3583" href="#L3583">3583</a><br /><a id="L3584" href="#L3584">3584</a><br /><a id="L3585" href="#L3585">3585</a><br /><a id="L3586" href="#L3586">3586</a><br /><a id="L3587" href="#L3587">3587</a><br /><a id="L3588" href="#L3588">3588</a><br /><a id="L3589" href="#L3589">3589</a><br /><a id="L3590" href="#L3590">3590</a><br /><a id="L3591" href="#L3591">3591</a><br /><a id="L3592" href="#L3592">3592</a><br /><a id="L3593" href="#L3593">3593</a><br /><a id="L3594" href="#L3594">3594</a><br /><a id="L3595" href="#L3595">3595</a><br /><a id="L3596" href="#L3596">3596</a><br /><a id="L3597" href="#L3597">3597</a><br /><a id="L3598" href="#L3598">3598</a><br /><a id="L3599" href="#L3599">3599</a><br /><a id="L3600" href="#L3600">3600</a><br /><a id="L3601" href="#L3601">3601</a><br /><a id="L3602" href="#L3602">3602</a><br /><a id="L3603" href="#L3603">3603</a><br /><a id="L3604" href="#L3604">3604</a><br /><a id="L3605" href="#L3605">3605</a><br /><a id="L3606" href="#L3606">3606</a><br /><a id="L3607" href="#L3607">3607</a><br /><a id="L3608" href="#L3608">3608</a><br /><a id="L3609" href="#L3609">3609</a><br /><a id="L3610" href="#L3610">3610</a><br /><a id="L3611" href="#L3611">3611</a><br /><a id="L3612" href="#L3612">3612</a><br /><a id="L3613" href="#L3613">3613</a><br /><a id="L3614" href="#L3614">3614</a><br /><a id="L3615" href="#L3615">3615</a><br /><a id="L3616" href="#L3616">3616</a><br /><a id="L3617" href="#L3617">3617</a><br /><a id="L3618" href="#L3618">3618</a><br /><a id="L3619" href="#L3619">3619</a><br /><a id="L3620" href="#L3620">3620</a><br /><a id="L3621" href="#L3621">3621</a><br /><a id="L3622" href="#L3622">3622</a><br /><a id="L3623" href="#L3623">3623</a><br /><a id="L3624" href="#L3624">3624</a><br /><a id="L3625" href="#L3625">3625</a><br /><a id="L3626" href="#L3626">3626</a><br /><a id="L3627" href="#L3627">3627</a><br /><a id="L3628" href="#L3628">3628</a><br /><a id="L3629" href="#L3629">3629</a><br /><a id="L3630" href="#L3630">3630</a><br /><a id="L3631" href="#L3631">3631</a><br /><a id="L3632" href="#L3632">3632</a><br /><a id="L3633" href="#L3633">3633</a><br /><a id="L3634" href="#L3634">3634</a><br /><a id="L3635" href="#L3635">3635</a><br /><a id="L3636" href="#L3636">3636</a><br /><a id="L3637" href="#L3637">3637</a><br /><a id="L3638" href="#L3638">3638</a><br /><a id="L3639" href="#L3639">3639</a><br /><a id="L3640" href="#L3640">3640</a><br /><a id="L3641" href="#L3641">3641</a><br /><a id="L3642" href="#L3642">3642</a><br /><a id="L3643" href="#L3643">3643</a><br /><a id="L3644" href="#L3644">3644</a><br /><a id="L3645" href="#L3645">3645</a><br /><a id="L3646" href="#L3646">3646</a><br /><a id="L3647" href="#L3647">3647</a><br /><a id="L3648" href="#L3648">3648</a><br /><a id="L3649" href="#L3649">3649</a><br /><a id="L3650" href="#L3650">3650</a><br /><a id="L3651" href="#L3651">3651</a><br /><a id="L3652" href="#L3652">3652</a><br /><a id="L3653" href="#L3653">3653</a><br /><a id="L3654" href="#L3654">3654</a><br /><a id="L3655" href="#L3655">3655</a><br /><a id="L3656" href="#L3656">3656</a><br /><a id="L3657" href="#L3657">3657</a><br /><a id="L3658" href="#L3658">3658</a><br /><a id="L3659" href="#L3659">3659</a><br /><a id="L3660" href="#L3660">3660</a><br /><a id="L3661" href="#L3661">3661</a><br /><a id="L3662" href="#L3662">3662</a><br /><a id="L3663" href="#L3663">3663</a><br /><a id="L3664" href="#L3664">3664</a><br /><a id="L3665" href="#L3665">3665</a><br /><a id="L3666" href="#L3666">3666</a><br /><a id="L3667" href="#L3667">3667</a><br /><a id="L3668" href="#L3668">3668</a><br /><a id="L3669" href="#L3669">3669</a><br /><a id="L3670" href="#L3670">3670</a><br /><a id="L3671" href="#L3671">3671</a><br /><a id="L3672" href="#L3672">3672</a><br /><a id="L3673" href="#L3673">3673</a><br /><a id="L3674" href="#L3674">3674</a><br /><a id="L3675" href="#L3675">3675</a><br /><a id="L3676" href="#L3676">3676</a><br /><a id="L3677" href="#L3677">3677</a><br /><a id="L3678" href="#L3678">3678</a><br /><a id="L3679" href="#L3679">3679</a><br /><a id="L3680" href="#L3680">3680</a><br /><a id="L3681" href="#L3681">3681</a><br /><a id="L3682" href="#L3682">3682</a><br /><a id="L3683" href="#L3683">3683</a><br /><a id="L3684" href="#L3684">3684</a><br /><a id="L3685" href="#L3685">3685</a><br /><a id="L3686" href="#L3686">3686</a><br /><a id="L3687" href="#L3687">3687</a><br /><a id="L3688" href="#L3688">3688</a><br /><a id="L3689" href="#L3689">3689</a><br /><a id="L3690" href="#L3690">3690</a><br /><a id="L3691" href="#L3691">3691</a><br /><a id="L3692" href="#L3692">3692</a><br /><a id="L3693" href="#L3693">3693</a><br /><a id="L3694" href="#L3694">3694</a><br /><a id="L3695" href="#L3695">3695</a><br /><a id="L3696" href="#L3696">3696</a><br /><a id="L3697" href="#L3697">3697</a><br /><a id="L3698" href="#L3698">3698</a><br /><a id="L3699" href="#L3699">3699</a><br /><a id="L3700" href="#L3700">3700</a><br /><a id="L3701" href="#L3701">3701</a><br /><a id="L3702" href="#L3702">3702</a><br /><a id="L3703" href="#L3703">3703</a><br /><a id="L3704" href="#L3704">3704</a><br /><a id="L3705" href="#L3705">3705</a><br /><a id="L3706" href="#L3706">3706</a><br /><a id="L3707" href="#L3707">3707</a><br /><a id="L3708" href="#L3708">3708</a><br /><a id="L3709" href="#L3709">3709</a><br /><a id="L3710" href="#L3710">3710</a><br /><a id="L3711" href="#L3711">3711</a><br /><a id="L3712" href="#L3712">3712</a><br /><a id="L3713" href="#L3713">3713</a><br /><a id="L3714" href="#L3714">3714</a><br /><a id="L3715" href="#L3715">3715</a><br /><a id="L3716" href="#L3716">3716</a><br /><a id="L3717" href="#L3717">3717</a><br /><a id="L3718" href="#L3718">3718</a><br /><a id="L3719" href="#L3719">3719</a><br /><a id="L3720" href="#L3720">3720</a><br /><a id="L3721" href="#L3721">3721</a><br /><a id="L3722" href="#L3722">3722</a><br /><a id="L3723" href="#L3723">3723</a><br /><a id="L3724" href="#L3724">3724</a><br /><a id="L3725" href="#L3725">3725</a><br /><a id="L3726" href="#L3726">3726</a><br /><a id="L3727" href="#L3727">3727</a><br /><a id="L3728" href="#L3728">3728</a><br /><a id="L3729" href="#L3729">3729</a><br /><a id="L3730" href="#L3730">3730</a><br /><a id="L3731" href="#L3731">3731</a><br /><a id="L3732" href="#L3732">3732</a><br /><a id="L3733" href="#L3733">3733</a><br /><a id="L3734" href="#L3734">3734</a><br /><a id="L3735" href="#L3735">3735</a><br /><a id="L3736" href="#L3736">3736</a><br /><a id="L3737" href="#L3737">3737</a><br /><a id="L3738" href="#L3738">3738</a><br /><a id="L3739" href="#L3739">3739</a><br /><a id="L3740" href="#L3740">3740</a><br /><a id="L3741" href="#L3741">3741</a><br /><a id="L3742" href="#L3742">3742</a><br /><a id="L3743" href="#L3743">3743</a><br /><a id="L3744" href="#L3744">3744</a><br /><a id="L3745" href="#L3745">3745</a><br /><a id="L3746" href="#L3746">3746</a><br /><a id="L3747" href="#L3747">3747</a><br /><a id="L3748" href="#L3748">3748</a><br /><a id="L3749" href="#L3749">3749</a><br /><a id="L3750" href="#L3750">3750</a><br /><a id="L3751" href="#L3751">3751</a><br /><a id="L3752" href="#L3752">3752</a><br /><a id="L3753" href="#L3753">3753</a><br /><a id="L3754" href="#L3754">3754</a><br /><a id="L3755" href="#L3755">3755</a><br /><a id="L3756" href="#L3756">3756</a><br /><a id="L3757" href="#L3757">3757</a><br /><a id="L3758" href="#L3758">3758</a><br /><a id="L3759" href="#L3759">3759</a><br /><a id="L3760" href="#L3760">3760</a><br /><a id="L3761" href="#L3761">3761</a><br /><a id="L3762" href="#L3762">3762</a><br /><a id="L3763" href="#L3763">3763</a><br /><a id="L3764" href="#L3764">3764</a><br /><a id="L3765" href="#L3765">3765</a><br /><a id="L3766" href="#L3766">3766</a><br /><a id="L3767" href="#L3767">3767</a><br /><a id="L3768" href="#L3768">3768</a><br /><a id="L3769" href="#L3769">3769</a><br /><a id="L3770" href="#L3770">3770</a><br /><a id="L3771" href="#L3771">3771</a><br /><a id="L3772" href="#L3772">3772</a><br /><a id="L3773" href="#L3773">3773</a><br /><a id="L3774" href="#L3774">3774</a><br /><a id="L3775" href="#L3775">3775</a><br /><a id="L3776" href="#L3776">3776</a><br /><a id="L3777" href="#L3777">3777</a><br /><a id="L3778" href="#L3778">3778</a><br /><a id="L3779" href="#L3779">3779</a><br /><a id="L3780" href="#L3780">3780</a><br /><a id="L3781" href="#L3781">3781</a><br /><a id="L3782" href="#L3782">3782</a><br /><a id="L3783" href="#L3783">3783</a><br /><a id="L3784" href="#L3784">3784</a><br /><a id="L3785" href="#L3785">3785</a><br /><a id="L3786" href="#L3786">3786</a><br /><a id="L3787" href="#L3787">3787</a><br /><a id="L3788" href="#L3788">3788</a><br /><a id="L3789" href="#L3789">3789</a><br /><a id="L3790" href="#L3790">3790</a><br /><a id="L3791" href="#L3791">3791</a><br /><a id="L3792" href="#L3792">3792</a><br /><a id="L3793" href="#L3793">3793</a><br /><a id="L3794" href="#L3794">3794</a><br /><a id="L3795" href="#L3795">3795</a><br /><a id="L3796" href="#L3796">3796</a><br /><a id="L3797" href="#L3797">3797</a><br /><a id="L3798" href="#L3798">3798</a><br /><a id="L3799" href="#L3799">3799</a><br /><a id="L3800" href="#L3800">3800</a><br /><a id="L3801" href="#L3801">3801</a><br /><a id="L3802" href="#L3802">3802</a><br /><a id="L3803" href="#L3803">3803</a><br /><a id="L3804" href="#L3804">3804</a><br /><a id="L3805" href="#L3805">3805</a><br /><a id="L3806" href="#L3806">3806</a><br /><a id="L3807" href="#L3807">3807</a><br /><a id="L3808" href="#L3808">3808</a><br /><a id="L3809" href="#L3809">3809</a><br /><a id="L3810" href="#L3810">3810</a><br /><a id="L3811" href="#L3811">3811</a><br /><a id="L3812" href="#L3812">3812</a><br /><a id="L3813" href="#L3813">3813</a><br /><a id="L3814" href="#L3814">3814</a><br /><a id="L3815" href="#L3815">3815</a><br /><a id="L3816" href="#L3816">3816</a><br /><a id="L3817" href="#L3817">3817</a><br /><a id="L3818" href="#L3818">3818</a><br /><a id="L3819" href="#L3819">3819</a><br /><a id="L3820" href="#L3820">3820</a><br /><a id="L3821" href="#L3821">3821</a><br /><a id="L3822" href="#L3822">3822</a><br /><a id="L3823" href="#L3823">3823</a><br /><a id="L3824" href="#L3824">3824</a><br /><a id="L3825" href="#L3825">3825</a><br /><a id="L3826" href="#L3826">3826</a><br /><a id="L3827" href="#L3827">3827</a><br /><a id="L3828" href="#L3828">3828</a><br /><a id="L3829" href="#L3829">3829</a><br /><a id="L3830" href="#L3830">3830</a><br /><a id="L3831" href="#L3831">3831</a><br /><a id="L3832" href="#L3832">3832</a><br /><a id="L3833" href="#L3833">3833</a><br /><a id="L3834" href="#L3834">3834</a><br /><a id="L3835" href="#L3835">3835</a><br /><a id="L3836" href="#L3836">3836</a><br /><a id="L3837" href="#L3837">3837</a><br /><a id="L3838" href="#L3838">3838</a><br /><a id="L3839" href="#L3839">3839</a><br /><a id="L3840" href="#L3840">3840</a><br /><a id="L3841" href="#L3841">3841</a><br /><a id="L3842" href="#L3842">3842</a><br /><a id="L3843" href="#L3843">3843</a><br /><a id="L3844" href="#L3844">3844</a><br /><a id="L3845" href="#L3845">3845</a><br /><a id="L3846" href="#L3846">3846</a><br /><a id="L3847" href="#L3847">3847</a><br /><a id="L3848" href="#L3848">3848</a><br /><a id="L3849" href="#L3849">3849</a><br /><a id="L3850" href="#L3850">3850</a><br /><a id="L3851" href="#L3851">3851</a><br /><a id="L3852" href="#L3852">3852</a><br /><a id="L3853" href="#L3853">3853</a><br /><a id="L3854" href="#L3854">3854</a><br /><a id="L3855" href="#L3855">3855</a><br /><a id="L3856" href="#L3856">3856</a><br /><a id="L3857" href="#L3857">3857</a><br /><a id="L3858" href="#L3858">3858</a><br /><a id="L3859" href="#L3859">3859</a><br /><a id="L3860" href="#L3860">3860</a><br /><a id="L3861" href="#L3861">3861</a><br /><a id="L3862" href="#L3862">3862</a><br /><a id="L3863" href="#L3863">3863</a><br /><a id="L3864" href="#L3864">3864</a><br /><a id="L3865" href="#L3865">3865</a><br /><a id="L3866" href="#L3866">3866</a><br /><a id="L3867" href="#L3867">3867</a><br /><a id="L3868" href="#L3868">3868</a><br /><a id="L3869" href="#L3869">3869</a><br /><a id="L3870" href="#L3870">3870</a><br /><a id="L3871" href="#L3871">3871</a><br /><a id="L3872" href="#L3872">3872</a><br /><a id="L3873" href="#L3873">3873</a><br /><a id="L3874" href="#L3874">3874</a><br /><a id="L3875" href="#L3875">3875</a><br /><a id="L3876" href="#L3876">3876</a><br /><a id="L3877" href="#L3877">3877</a><br /><a id="L3878" href="#L3878">3878</a><br /><a id="L3879" href="#L3879">3879</a><br /><a id="L3880" href="#L3880">3880</a><br /><a id="L3881" href="#L3881">3881</a><br /><a id="L3882" href="#L3882">3882</a><br /><a id="L3883" href="#L3883">3883</a><br /><a id="L3884" href="#L3884">3884</a><br /><a id="L3885" href="#L3885">3885</a><br /><a id="L3886" href="#L3886">3886</a><br /><a id="L3887" href="#L3887">3887</a><br /><a id="L3888" href="#L3888">3888</a><br /><a id="L3889" href="#L3889">3889</a><br /><a id="L3890" href="#L3890">3890</a><br /><a id="L3891" href="#L3891">3891</a><br /><a id="L3892" href="#L3892">3892</a><br /><a id="L3893" href="#L3893">3893</a><br /><a id="L3894" href="#L3894">3894</a><br /><a id="L3895" href="#L3895">3895</a><br /><a id="L3896" href="#L3896">3896</a><br /><a id="L3897" href="#L3897">3897</a><br /><a id="L3898" href="#L3898">3898</a><br /><a id="L3899" href="#L3899">3899</a><br /><a id="L3900" href="#L3900">3900</a><br /><a id="L3901" href="#L3901">3901</a><br /><a id="L3902" href="#L3902">3902</a><br /><a id="L3903" href="#L3903">3903</a><br /><a id="L3904" href="#L3904">3904</a><br /><a id="L3905" href="#L3905">3905</a><br /><a id="L3906" href="#L3906">3906</a><br /><a id="L3907" href="#L3907">3907</a><br /><a id="L3908" href="#L3908">3908</a><br /><a id="L3909" href="#L3909">3909</a><br /><a id="L3910" href="#L3910">3910</a><br /><a id="L3911" href="#L3911">3911</a><br /><a id="L3912" href="#L3912">3912</a><br /><a id="L3913" href="#L3913">3913</a><br /><a id="L3914" href="#L3914">3914</a><br /><a id="L3915" href="#L3915">3915</a><br /><a id="L3916" href="#L3916">3916</a><br /><a id="L3917" href="#L3917">3917</a><br /><a id="L3918" href="#L3918">3918</a><br /><a id="L3919" href="#L3919">3919</a><br /><a id="L3920" href="#L3920">3920</a><br /><a id="L3921" href="#L3921">3921</a><br /><a id="L3922" href="#L3922">3922</a><br /><a id="L3923" href="#L3923">3923</a><br /><a id="L3924" href="#L3924">3924</a><br /><a id="L3925" href="#L3925">3925</a><br /><a id="L3926" href="#L3926">3926</a><br /><a id="L3927" href="#L3927">3927</a><br /><a id="L3928" href="#L3928">3928</a><br /><a id="L3929" href="#L3929">3929</a><br /><a id="L3930" href="#L3930">3930</a><br /><a id="L3931" href="#L3931">3931</a><br /><a id="L3932" href="#L3932">3932</a><br /><a id="L3933" href="#L3933">3933</a><br /><a id="L3934" href="#L3934">3934</a><br /><a id="L3935" href="#L3935">3935</a><br /><a id="L3936" href="#L3936">3936</a><br /><a id="L3937" href="#L3937">3937</a><br /><a id="L3938" href="#L3938">3938</a><br /><a id="L3939" href="#L3939">3939</a><br /><a id="L3940" href="#L3940">3940</a><br /><a id="L3941" href="#L3941">3941</a><br /><a id="L3942" href="#L3942">3942</a><br /><a id="L3943" href="#L3943">3943</a><br /><a id="L3944" href="#L3944">3944</a><br /><a id="L3945" href="#L3945">3945</a><br /><a id="L3946" href="#L3946">3946</a><br /><a id="L3947" href="#L3947">3947</a><br /><a id="L3948" href="#L3948">3948</a><br /><a id="L3949" href="#L3949">3949</a><br /><a id="L3950" href="#L3950">3950</a><br /><a id="L3951" href="#L3951">3951</a><br /><a id="L3952" href="#L3952">3952</a><br /><a id="L3953" href="#L3953">3953</a><br /><a id="L3954" href="#L3954">3954</a><br /><a id="L3955" href="#L3955">3955</a><br /><a id="L3956" href="#L3956">3956</a><br /><a id="L3957" href="#L3957">3957</a><br /><a id="L3958" href="#L3958">3958</a><br /><a id="L3959" href="#L3959">3959</a><br /><a id="L3960" href="#L3960">3960</a><br /><a id="L3961" href="#L3961">3961</a><br /><a id="L3962" href="#L3962">3962</a><br /><a id="L3963" href="#L3963">3963</a><br /><a id="L3964" href="#L3964">3964</a><br /><a id="L3965" href="#L3965">3965</a><br /><a id="L3966" href="#L3966">3966</a><br /><a id="L3967" href="#L3967">3967</a><br /><a id="L3968" href="#L3968">3968</a><br /><a id="L3969" href="#L3969">3969</a><br /><a id="L3970" href="#L3970">3970</a><br /><a id="L3971" href="#L3971">3971</a><br /><a id="L3972" href="#L3972">3972</a><br /><a id="L3973" href="#L3973">3973</a><br /><a id="L3974" href="#L3974">3974</a><br /><a id="L3975" href="#L3975">3975</a><br /><a id="L3976" href="#L3976">3976</a><br /><a id="L3977" href="#L3977">3977</a><br /><a id="L3978" href="#L3978">3978</a><br /><a id="L3979" href="#L3979">3979</a><br /><a id="L3980" href="#L3980">3980</a><br /><a id="L3981" href="#L3981">3981</a><br /><a id="L3982" href="#L3982">3982</a><br /><a id="L3983" href="#L3983">3983</a><br /><a id="L3984" href="#L3984">3984</a><br /><a id="L3985" href="#L3985">3985</a><br /><a id="L3986" href="#L3986">3986</a><br /><a id="L3987" href="#L3987">3987</a><br /><a id="L3988" href="#L3988">3988</a><br /><a id="L3989" href="#L3989">3989</a><br /><a id="L3990" href="#L3990">3990</a><br /><a id="L3991" href="#L3991">3991</a><br /><a id="L3992" href="#L3992">3992</a><br /><a id="L3993" href="#L3993">3993</a><br /><a id="L3994" href="#L3994">3994</a><br /><a id="L3995" href="#L3995">3995</a><br /><a id="L3996" href="#L3996">3996</a><br /><a id="L3997" href="#L3997">3997</a><br /><a id="L3998" href="#L3998">3998</a><br /><a id="L3999" href="#L3999">3999</a><br /><a id="L4000" href="#L4000">4000</a><br /><a id="L4001" href="#L4001">4001</a><br /><a id="L4002" href="#L4002">4002</a><br /><a id="L4003" href="#L4003">4003</a><br /><a id="L4004" href="#L4004">4004</a><br /><a id="L4005" href="#L4005">4005</a><br /><a id="L4006" href="#L4006">4006</a><br /><a id="L4007" href="#L4007">4007</a><br /><a id="L4008" href="#L4008">4008</a><br /><a id="L4009" href="#L4009">4009</a><br /><a id="L4010" href="#L4010">4010</a><br /><a id="L4011" href="#L4011">4011</a><br /><a id="L4012" href="#L4012">4012</a><br /><a id="L4013" href="#L4013">4013</a><br /><a id="L4014" href="#L4014">4014</a><br /><a id="L4015" href="#L4015">4015</a><br /><a id="L4016" href="#L4016">4016</a><br /><a id="L4017" href="#L4017">4017</a><br /><a id="L4018" href="#L4018">4018</a><br /><a id="L4019" href="#L4019">4019</a><br /><a id="L4020" href="#L4020">4020</a><br /><a id="L4021" href="#L4021">4021</a><br /><a id="L4022" href="#L4022">4022</a><br /><a id="L4023" href="#L4023">4023</a><br /><a id="L4024" href="#L4024">4024</a><br /><a id="L4025" href="#L4025">4025</a><br /><a id="L4026" href="#L4026">4026</a><br /><a id="L4027" href="#L4027">4027</a><br /><a id="L4028" href="#L4028">4028</a><br /><a id="L4029" href="#L4029">4029</a><br /><a id="L4030" href="#L4030">4030</a><br /><a id="L4031" href="#L4031">4031</a><br /><a id="L4032" href="#L4032">4032</a><br /><a id="L4033" href="#L4033">4033</a><br /><a id="L4034" href="#L4034">4034</a><br /><a id="L4035" href="#L4035">4035</a><br /><a id="L4036" href="#L4036">4036</a><br /><a id="L4037" href="#L4037">4037</a><br /><a id="L4038" href="#L4038">4038</a><br /><a id="L4039" href="#L4039">4039</a><br /><a id="L4040" href="#L4040">4040</a><br /><a id="L4041" href="#L4041">4041</a><br /><a id="L4042" href="#L4042">4042</a><br /><a id="L4043" href="#L4043">4043</a><br /><a id="L4044" href="#L4044">4044</a><br /><a id="L4045" href="#L4045">4045</a><br /><a id="L4046" href="#L4046">4046</a><br /><a id="L4047" href="#L4047">4047</a><br /><a id="L4048" href="#L4048">4048</a><br /><a id="L4049" href="#L4049">4049</a><br /><a id="L4050" href="#L4050">4050</a><br /><a id="L4051" href="#L4051">4051</a><br /><a id="L4052" href="#L4052">4052</a><br /><a id="L4053" href="#L4053">4053</a><br /><a id="L4054" href="#L4054">4054</a><br /><a id="L4055" href="#L4055">4055</a><br /><a id="L4056" href="#L4056">4056</a><br /><a id="L4057" href="#L4057">4057</a><br /><a id="L4058" href="#L4058">4058</a><br /><a id="L4059" href="#L4059">4059</a><br /><a id="L4060" href="#L4060">4060</a><br /><a id="L4061" href="#L4061">4061</a><br /><a id="L4062" href="#L4062">4062</a><br /><a id="L4063" href="#L4063">4063</a><br /><a id="L4064" href="#L4064">4064</a><br /><a id="L4065" href="#L4065">4065</a><br /><a id="L4066" href="#L4066">4066</a><br /><a id="L4067" href="#L4067">4067</a><br /><a id="L4068" href="#L4068">4068</a><br /><a id="L4069" href="#L4069">4069</a><br /><a id="L4070" href="#L4070">4070</a><br /><a id="L4071" href="#L4071">4071</a><br /><a id="L4072" href="#L4072">4072</a><br /><a id="L4073" href="#L4073">4073</a><br /><a id="L4074" href="#L4074">4074</a><br /><a id="L4075" href="#L4075">4075</a><br /><a id="L4076" href="#L4076">4076</a><br /><a id="L4077" href="#L4077">4077</a><br /><a id="L4078" href="#L4078">4078</a><br /><a id="L4079" href="#L4079">4079</a><br /><a id="L4080" href="#L4080">4080</a><br /><a id="L4081" href="#L4081">4081</a><br /><a id="L4082" href="#L4082">4082</a><br /><a id="L4083" href="#L4083">4083</a><br /><a id="L4084" href="#L4084">4084</a><br /><a id="L4085" href="#L4085">4085</a><br /><a id="L4086" href="#L4086">4086</a><br /><a id="L4087" href="#L4087">4087</a><br /><a id="L4088" href="#L4088">4088</a><br /><a id="L4089" href="#L4089">4089</a><br /><a id="L4090" href="#L4090">4090</a><br /><a id="L4091" href="#L4091">4091</a><br /><a id="L4092" href="#L4092">4092</a><br /><a id="L4093" href="#L4093">4093</a><br /><a id="L4094" href="#L4094">4094</a><br /><a id="L4095" href="#L4095">4095</a><br /><a id="L4096" href="#L4096">4096</a><br /><a id="L4097" href="#L4097">4097</a><br /><a id="L4098" href="#L4098">4098</a><br /><a id="L4099" href="#L4099">4099</a><br /><a id="L4100" href="#L4100">4100</a><br /><a id="L4101" href="#L4101">4101</a><br /><a id="L4102" href="#L4102">4102</a><br /><a id="L4103" href="#L4103">4103</a><br /><a id="L4104" href="#L4104">4104</a><br /><a id="L4105" href="#L4105">4105</a><br /><a id="L4106" href="#L4106">4106</a><br /><a id="L4107" href="#L4107">4107</a><br /><a id="L4108" href="#L4108">4108</a><br /><a id="L4109" href="#L4109">4109</a><br /><a id="L4110" href="#L4110">4110</a><br /><a id="L4111" href="#L4111">4111</a><br /><a id="L4112" href="#L4112">4112</a><br /><a id="L4113" href="#L4113">4113</a><br /><a id="L4114" href="#L4114">4114</a><br /><a id="L4115" href="#L4115">4115</a><br /><a id="L4116" href="#L4116">4116</a><br /><a id="L4117" href="#L4117">4117</a><br /><a id="L4118" href="#L4118">4118</a><br /><a id="L4119" href="#L4119">4119</a><br /><a id="L4120" href="#L4120">4120</a><br /><a id="L4121" href="#L4121">4121</a><br /><a id="L4122" href="#L4122">4122</a><br /><a id="L4123" href="#L4123">4123</a><br /><a id="L4124" href="#L4124">4124</a><br /><a id="L4125" href="#L4125">4125</a><br /><a id="L4126" href="#L4126">4126</a><br /><a id="L4127" href="#L4127">4127</a><br /><a id="L4128" href="#L4128">4128</a><br /><a id="L4129" href="#L4129">4129</a><br /><a id="L4130" href="#L4130">4130</a><br /><a id="L4131" href="#L4131">4131</a><br /><a id="L4132" href="#L4132">4132</a><br /><a id="L4133" href="#L4133">4133</a><br /><a id="L4134" href="#L4134">4134</a><br /><a id="L4135" href="#L4135">4135</a><br /><a id="L4136" href="#L4136">4136</a><br /><a id="L4137" href="#L4137">4137</a><br /><a id="L4138" href="#L4138">4138</a><br /><a id="L4139" href="#L4139">4139</a><br /><a id="L4140" href="#L4140">4140</a><br /><a id="L4141" href="#L4141">4141</a><br /><a id="L4142" href="#L4142">4142</a><br /><a id="L4143" href="#L4143">4143</a><br /><a id="L4144" href="#L4144">4144</a><br /><a id="L4145" href="#L4145">4145</a><br /><a id="L4146" href="#L4146">4146</a><br /><a id="L4147" href="#L4147">4147</a><br /><a id="L4148" href="#L4148">4148</a><br /><a id="L4149" href="#L4149">4149</a><br /><a id="L4150" href="#L4150">4150</a><br /><a id="L4151" href="#L4151">4151</a><br /><a id="L4152" href="#L4152">4152</a><br /><a id="L4153" href="#L4153">4153</a><br /><a id="L4154" href="#L4154">4154</a><br /><a id="L4155" href="#L4155">4155</a><br /><a id="L4156" href="#L4156">4156</a><br /><a id="L4157" href="#L4157">4157</a><br /><a id="L4158" href="#L4158">4158</a><br /><a id="L4159" href="#L4159">4159</a><br /><a id="L4160" href="#L4160">4160</a><br /><a id="L4161" href="#L4161">4161</a><br /><a id="L4162" href="#L4162">4162</a><br /><a id="L4163" href="#L4163">4163</a><br /><a id="L4164" href="#L4164">4164</a><br /><a id="L4165" href="#L4165">4165</a><br /><a id="L4166" href="#L4166">4166</a><br /><a id="L4167" href="#L4167">4167</a><br /><a id="L4168" href="#L4168">4168</a><br /><a id="L4169" href="#L4169">4169</a><br /><a id="L4170" href="#L4170">4170</a><br /><a id="L4171" href="#L4171">4171</a><br /><a id="L4172" href="#L4172">4172</a><br /><a id="L4173" href="#L4173">4173</a><br /><a id="L4174" href="#L4174">4174</a><br /><a id="L4175" href="#L4175">4175</a><br /><a id="L4176" href="#L4176">4176</a><br /><a id="L4177" href="#L4177">4177</a><br /><a id="L4178" href="#L4178">4178</a><br /><a id="L4179" href="#L4179">4179</a><br /><a id="L4180" href="#L4180">4180</a><br /><a id="L4181" href="#L4181">4181</a><br /><a id="L4182" href="#L4182">4182</a><br /><a id="L4183" href="#L4183">4183</a><br /><a id="L4184" href="#L4184">4184</a><br /><a id="L4185" href="#L4185">4185</a><br /><a id="L4186" href="#L4186">4186</a><br /><a id="L4187" href="#L4187">4187</a><br /><a id="L4188" href="#L4188">4188</a><br /><a id="L4189" href="#L4189">4189</a><br /><a id="L4190" href="#L4190">4190</a><br /><a id="L4191" href="#L4191">4191</a><br /><a id="L4192" href="#L4192">4192</a><br /><a id="L4193" href="#L4193">4193</a><br /><a id="L4194" href="#L4194">4194</a><br /><a id="L4195" href="#L4195">4195</a><br /><a id="L4196" href="#L4196">4196</a><br /><a id="L4197" href="#L4197">4197</a><br /><a id="L4198" href="#L4198">4198</a><br /><a id="L4199" href="#L4199">4199</a><br /><a id="L4200" href="#L4200">4200</a><br /><a id="L4201" href="#L4201">4201</a><br /><a id="L4202" href="#L4202">4202</a><br /><a id="L4203" href="#L4203">4203</a><br /><a id="L4204" href="#L4204">4204</a><br /><a id="L4205" href="#L4205">4205</a><br /><a id="L4206" href="#L4206">4206</a><br /><a id="L4207" href="#L4207">4207</a><br /><a id="L4208" href="#L4208">4208</a><br /><a id="L4209" href="#L4209">4209</a><br /><a id="L4210" href="#L4210">4210</a><br /><a id="L4211" href="#L4211">4211</a><br /><a id="L4212" href="#L4212">4212</a><br /><a id="L4213" href="#L4213">4213</a><br /><a id="L4214" href="#L4214">4214</a><br /><a id="L4215" href="#L4215">4215</a><br /><a id="L4216" href="#L4216">4216</a><br /><a id="L4217" href="#L4217">4217</a><br /><a id="L4218" href="#L4218">4218</a><br /><a id="L4219" href="#L4219">4219</a><br /><a id="L4220" href="#L4220">4220</a><br /><a id="L4221" href="#L4221">4221</a><br /><a id="L4222" href="#L4222">4222</a><br /><a id="L4223" href="#L4223">4223</a><br /><a id="L4224" href="#L4224">4224</a><br /><a id="L4225" href="#L4225">4225</a><br /><a id="L4226" href="#L4226">4226</a><br /><a id="L4227" href="#L4227">4227</a><br /><a id="L4228" href="#L4228">4228</a><br /><a id="L4229" href="#L4229">4229</a><br /><a id="L4230" href="#L4230">4230</a><br /><a id="L4231" href="#L4231">4231</a><br /><a id="L4232" href="#L4232">4232</a><br /><a id="L4233" href="#L4233">4233</a><br /><a id="L4234" href="#L4234">4234</a><br /><a id="L4235" href="#L4235">4235</a><br /><a id="L4236" href="#L4236">4236</a><br /><a id="L4237" href="#L4237">4237</a><br /><a id="L4238" href="#L4238">4238</a><br /><a id="L4239" href="#L4239">4239</a><br /><a id="L4240" href="#L4240">4240</a><br /><a id="L4241" href="#L4241">4241</a><br /><a id="L4242" href="#L4242">4242</a><br /><a id="L4243" href="#L4243">4243</a><br /><a id="L4244" href="#L4244">4244</a><br /><a id="L4245" href="#L4245">4245</a><br /><a id="L4246" href="#L4246">4246</a><br /><a id="L4247" href="#L4247">4247</a><br /><a id="L4248" href="#L4248">4248</a><br /><a id="L4249" href="#L4249">4249</a><br /><a id="L4250" href="#L4250">4250</a><br /><a id="L4251" href="#L4251">4251</a><br /><a id="L4252" href="#L4252">4252</a><br /><a id="L4253" href="#L4253">4253</a><br /><a id="L4254" href="#L4254">4254</a><br /><a id="L4255" href="#L4255">4255</a><br /><a id="L4256" href="#L4256">4256</a><br /><a id="L4257" href="#L4257">4257</a><br /><a id="L4258" href="#L4258">4258</a><br /><a id="L4259" href="#L4259">4259</a><br /><a id="L4260" href="#L4260">4260</a><br /><a id="L4261" href="#L4261">4261</a><br /><a id="L4262" href="#L4262">4262</a><br /><a id="L4263" href="#L4263">4263</a><br /><a id="L4264" href="#L4264">4264</a><br /><a id="L4265" href="#L4265">4265</a><br /><a id="L4266" href="#L4266">4266</a><br /><a id="L4267" href="#L4267">4267</a><br /><a id="L4268" href="#L4268">4268</a><br /><a id="L4269" href="#L4269">4269</a><br /><a id="L4270" href="#L4270">4270</a><br /><a id="L4271" href="#L4271">4271</a><br /><a id="L4272" href="#L4272">4272</a><br /><a id="L4273" href="#L4273">4273</a><br /><a id="L4274" href="#L4274">4274</a><br /><a id="L4275" href="#L4275">4275</a><br /><a id="L4276" href="#L4276">4276</a><br /><a id="L4277" href="#L4277">4277</a><br /><a id="L4278" href="#L4278">4278</a><br /><a id="L4279" href="#L4279">4279</a><br /><a id="L4280" href="#L4280">4280</a><br /><a id="L4281" href="#L4281">4281</a><br /><a id="L4282" href="#L4282">4282</a><br /><a id="L4283" href="#L4283">4283</a><br /><a id="L4284" href="#L4284">4284</a><br /><a id="L4285" href="#L4285">4285</a><br /><a id="L4286" href="#L4286">4286</a><br /><a id="L4287" href="#L4287">4287</a><br /><a id="L4288" href="#L4288">4288</a><br /><a id="L4289" href="#L4289">4289</a><br /><a id="L4290" href="#L4290">4290</a><br /><a id="L4291" href="#L4291">4291</a><br /><a id="L4292" href="#L4292">4292</a><br /><a id="L4293" href="#L4293">4293</a><br /><a id="L4294" href="#L4294">4294</a><br /><a id="L4295" href="#L4295">4295</a><br /><a id="L4296" href="#L4296">4296</a><br /><a id="L4297" href="#L4297">4297</a><br /><a id="L4298" href="#L4298">4298</a><br /><a id="L4299" href="#L4299">4299</a><br /><a id="L4300" href="#L4300">4300</a><br /><a id="L4301" href="#L4301">4301</a><br /><a id="L4302" href="#L4302">4302</a><br /><a id="L4303" href="#L4303">4303</a><br /><a id="L4304" href="#L4304">4304</a><br /><a id="L4305" href="#L4305">4305</a><br /><a id="L4306" href="#L4306">4306</a><br /><a id="L4307" href="#L4307">4307</a><br /><a id="L4308" href="#L4308">4308</a><br /><a id="L4309" href="#L4309">4309</a><br /><a id="L4310" href="#L4310">4310</a><br /><a id="L4311" href="#L4311">4311</a><br /><a id="L4312" href="#L4312">4312</a><br /><a id="L4313" href="#L4313">4313</a><br /><a id="L4314" href="#L4314">4314</a><br /><a id="L4315" href="#L4315">4315</a><br /><a id="L4316" href="#L4316">4316</a><br /><a id="L4317" href="#L4317">4317</a><br /><a id="L4318" href="#L4318">4318</a><br /><a id="L4319" href="#L4319">4319</a><br /><a id="L4320" href="#L4320">4320</a><br /><a id="L4321" href="#L4321">4321</a><br /><a id="L4322" href="#L4322">4322</a><br /><a id="L4323" href="#L4323">4323</a><br /><a id="L4324" href="#L4324">4324</a><br /><a id="L4325" href="#L4325">4325</a><br /><a id="L4326" href="#L4326">4326</a><br /><a id="L4327" href="#L4327">4327</a><br /><a id="L4328" href="#L4328">4328</a><br /><a id="L4329" href="#L4329">4329</a><br /><a id="L4330" href="#L4330">4330</a><br /><a id="L4331" href="#L4331">4331</a><br /><a id="L4332" href="#L4332">4332</a><br /><a id="L4333" href="#L4333">4333</a><br /><a id="L4334" href="#L4334">4334</a><br /><a id="L4335" href="#L4335">4335</a><br /><a id="L4336" href="#L4336">4336</a><br /><a id="L4337" href="#L4337">4337</a><br /><a id="L4338" href="#L4338">4338</a><br /><a id="L4339" href="#L4339">4339</a><br /><a id="L4340" href="#L4340">4340</a><br /><a id="L4341" href="#L4341">4341</a><br /><a id="L4342" href="#L4342">4342</a><br /><a id="L4343" href="#L4343">4343</a><br /><a id="L4344" href="#L4344">4344</a><br /><a id="L4345" href="#L4345">4345</a><br /><a id="L4346" href="#L4346">4346</a><br /><a id="L4347" href="#L4347">4347</a><br /><a id="L4348" href="#L4348">4348</a><br /><a id="L4349" href="#L4349">4349</a><br /><a id="L4350" href="#L4350">4350</a><br /><a id="L4351" href="#L4351">4351</a><br /><a id="L4352" href="#L4352">4352</a><br /><a id="L4353" href="#L4353">4353</a><br /><a id="L4354" href="#L4354">4354</a><br /><a id="L4355" href="#L4355">4355</a><br /><a id="L4356" href="#L4356">4356</a><br /><a id="L4357" href="#L4357">4357</a><br /><a id="L4358" href="#L4358">4358</a><br /><a id="L4359" href="#L4359">4359</a><br /><a id="L4360" href="#L4360">4360</a><br /><a id="L4361" href="#L4361">4361</a><br /><a id="L4362" href="#L4362">4362</a><br /><a id="L4363" href="#L4363">4363</a><br /><a id="L4364" href="#L4364">4364</a><br /><a id="L4365" href="#L4365">4365</a><br /><a id="L4366" href="#L4366">4366</a><br /><a id="L4367" href="#L4367">4367</a><br /><a id="L4368" href="#L4368">4368</a><br /><a id="L4369" href="#L4369">4369</a><br /><a id="L4370" href="#L4370">4370</a><br /><a id="L4371" href="#L4371">4371</a><br /><a id="L4372" href="#L4372">4372</a><br /><a id="L4373" href="#L4373">4373</a><br /><a id="L4374" href="#L4374">4374</a><br /><a id="L4375" href="#L4375">4375</a><br /><a id="L4376" href="#L4376">4376</a><br /><a id="L4377" href="#L4377">4377</a><br /><a id="L4378" href="#L4378">4378</a><br /><a id="L4379" href="#L4379">4379</a><br /><a id="L4380" href="#L4380">4380</a><br /><a id="L4381" href="#L4381">4381</a><br /><a id="L4382" href="#L4382">4382</a><br /><a id="L4383" href="#L4383">4383</a><br /><a id="L4384" href="#L4384">4384</a><br /><a id="L4385" href="#L4385">4385</a><br /><a id="L4386" href="#L4386">4386</a><br /><a id="L4387" href="#L4387">4387</a><br /><a id="L4388" href="#L4388">4388</a><br /><a id="L4389" href="#L4389">4389</a><br /><a id="L4390" href="#L4390">4390</a><br /><a id="L4391" href="#L4391">4391</a><br /><a id="L4392" href="#L4392">4392</a><br /><a id="L4393" href="#L4393">4393</a><br /><a id="L4394" href="#L4394">4394</a><br /><a id="L4395" href="#L4395">4395</a><br /><a id="L4396" href="#L4396">4396</a><br /><a id="L4397" href="#L4397">4397</a><br /><a id="L4398" href="#L4398">4398</a><br /><a id="L4399" href="#L4399">4399</a><br /><a id="L4400" href="#L4400">4400</a><br /><a id="L4401" href="#L4401">4401</a><br /><a id="L4402" href="#L4402">4402</a><br /><a id="L4403" href="#L4403">4403</a><br /><a id="L4404" href="#L4404">4404</a><br /><a id="L4405" href="#L4405">4405</a><br /><a id="L4406" href="#L4406">4406</a><br /><a id="L4407" href="#L4407">4407</a><br /><a id="L4408" href="#L4408">4408</a><br /><a id="L4409" href="#L4409">4409</a><br /><a id="L4410" href="#L4410">4410</a><br /><a id="L4411" href="#L4411">4411</a><br /><a id="L4412" href="#L4412">4412</a><br /><a id="L4413" href="#L4413">4413</a><br /><a id="L4414" href="#L4414">4414</a><br /><a id="L4415" href="#L4415">4415</a><br /><a id="L4416" href="#L4416">4416</a><br /><a id="L4417" href="#L4417">4417</a><br /><a id="L4418" href="#L4418">4418</a><br /><a id="L4419" href="#L4419">4419</a><br /><a id="L4420" href="#L4420">4420</a><br /><a id="L4421" href="#L4421">4421</a><br /><a id="L4422" href="#L4422">4422</a><br /><a id="L4423" href="#L4423">4423</a><br /><a id="L4424" href="#L4424">4424</a><br /><a id="L4425" href="#L4425">4425</a><br /><a id="L4426" href="#L4426">4426</a><br /><a id="L4427" href="#L4427">4427</a><br /><a id="L4428" href="#L4428">4428</a><br /><a id="L4429" href="#L4429">4429</a><br /><a id="L4430" href="#L4430">4430</a><br /><a id="L4431" href="#L4431">4431</a><br /><a id="L4432" href="#L4432">4432</a><br /><a id="L4433" href="#L4433">4433</a><br /><a id="L4434" href="#L4434">4434</a><br /><a id="L4435" href="#L4435">4435</a><br /><a id="L4436" href="#L4436">4436</a><br /><a id="L4437" href="#L4437">4437</a><br /><a id="L4438" href="#L4438">4438</a><br /><a id="L4439" href="#L4439">4439</a><br /><a id="L4440" href="#L4440">4440</a><br /><a id="L4441" href="#L4441">4441</a><br /><a id="L4442" href="#L4442">4442</a><br /><a id="L4443" href="#L4443">4443</a><br /><a id="L4444" href="#L4444">4444</a><br /><a id="L4445" href="#L4445">4445</a><br /><a id="L4446" href="#L4446">4446</a><br /><a id="L4447" href="#L4447">4447</a><br /><a id="L4448" href="#L4448">4448</a><br /><a id="L4449" href="#L4449">4449</a><br /><a id="L4450" href="#L4450">4450</a><br /><a id="L4451" href="#L4451">4451</a><br /><a id="L4452" href="#L4452">4452</a><br /><a id="L4453" href="#L4453">4453</a><br /><a id="L4454" href="#L4454">4454</a><br /><a id="L4455" href="#L4455">4455</a><br /><a id="L4456" href="#L4456">4456</a><br /><a id="L4457" href="#L4457">4457</a><br /><a id="L4458" href="#L4458">4458</a><br /><a id="L4459" href="#L4459">4459</a><br /><a id="L4460" href="#L4460">4460</a><br /><a id="L4461" href="#L4461">4461</a><br /><a id="L4462" href="#L4462">4462</a><br /><a id="L4463" href="#L4463">4463</a><br /><a id="L4464" href="#L4464">4464</a><br /><a id="L4465" href="#L4465">4465</a><br /><a id="L4466" href="#L4466">4466</a><br /><a id="L4467" href="#L4467">4467</a><br /><a id="L4468" href="#L4468">4468</a><br /><a id="L4469" href="#L4469">4469</a><br /><a id="L4470" href="#L4470">4470</a><br /><a id="L4471" href="#L4471">4471</a><br /><a id="L4472" href="#L4472">4472</a><br /><a id="L4473" href="#L4473">4473</a><br /><a id="L4474" href="#L4474">4474</a><br /><a id="L4475" href="#L4475">4475</a><br /><a id="L4476" href="#L4476">4476</a><br /><a id="L4477" href="#L4477">4477</a><br /><a id="L4478" href="#L4478">4478</a><br /><a id="L4479" href="#L4479">4479</a><br /><a id="L4480" href="#L4480">4480</a><br /><a id="L4481" href="#L4481">4481</a><br /><a id="L4482" href="#L4482">4482</a><br /><a id="L4483" href="#L4483">4483</a><br /><a id="L4484" href="#L4484">4484</a><br /><a id="L4485" href="#L4485">4485</a><br /><a id="L4486" href="#L4486">4486</a><br /><a id="L4487" href="#L4487">4487</a><br /><a id="L4488" href="#L4488">4488</a><br /><a id="L4489" href="#L4489">4489</a><br /><a id="L4490" href="#L4490">4490</a><br /><a id="L4491" href="#L4491">4491</a><br /><a id="L4492" href="#L4492">4492</a><br /><a id="L4493" href="#L4493">4493</a><br /><a id="L4494" href="#L4494">4494</a><br /><a id="L4495" href="#L4495">4495</a><br /><a id="L4496" href="#L4496">4496</a><br /><a id="L4497" href="#L4497">4497</a><br /><a id="L4498" href="#L4498">4498</a><br /><a id="L4499" href="#L4499">4499</a><br /><a id="L4500" href="#L4500">4500</a><br /><a id="L4501" href="#L4501">4501</a><br /><a id="L4502" href="#L4502">4502</a><br /><a id="L4503" href="#L4503">4503</a><br /><a id="L4504" href="#L4504">4504</a><br /><a id="L4505" href="#L4505">4505</a><br /><a id="L4506" href="#L4506">4506</a><br /><a id="L4507" href="#L4507">4507</a><br /><a id="L4508" href="#L4508">4508</a><br /><a id="L4509" href="#L4509">4509</a><br /><a id="L4510" href="#L4510">4510</a><br /><a id="L4511" href="#L4511">4511</a><br /><a id="L4512" href="#L4512">4512</a><br /><a id="L4513" href="#L4513">4513</a><br /><a id="L4514" href="#L4514">4514</a><br /><a id="L4515" href="#L4515">4515</a><br /><a id="L4516" href="#L4516">4516</a><br /><a id="L4517" href="#L4517">4517</a><br /><a id="L4518" href="#L4518">4518</a><br /><a id="L4519" href="#L4519">4519</a><br /><a id="L4520" href="#L4520">4520</a><br /><a id="L4521" href="#L4521">4521</a><br /><a id="L4522" href="#L4522">4522</a><br /><a id="L4523" href="#L4523">4523</a><br /><a id="L4524" href="#L4524">4524</a><br /><a id="L4525" href="#L4525">4525</a><br /><a id="L4526" href="#L4526">4526</a><br /><a id="L4527" href="#L4527">4527</a><br /><a id="L4528" href="#L4528">4528</a><br /><a id="L4529" href="#L4529">4529</a><br /><a id="L4530" href="#L4530">4530</a><br /><a id="L4531" href="#L4531">4531</a><br /><a id="L4532" href="#L4532">4532</a><br /><a id="L4533" href="#L4533">4533</a><br /><a id="L4534" href="#L4534">4534</a><br /><a id="L4535" href="#L4535">4535</a><br /><a id="L4536" href="#L4536">4536</a><br /><a id="L4537" href="#L4537">4537</a><br /><a id="L4538" href="#L4538">4538</a><br /><a id="L4539" href="#L4539">4539</a><br /><a id="L4540" href="#L4540">4540</a><br /><a id="L4541" href="#L4541">4541</a><br /><a id="L4542" href="#L4542">4542</a><br /><a id="L4543" href="#L4543">4543</a><br /><a id="L4544" href="#L4544">4544</a><br /><a id="L4545" href="#L4545">4545</a><br /><a id="L4546" href="#L4546">4546</a><br /><a id="L4547" href="#L4547">4547</a><br /><a id="L4548" href="#L4548">4548</a><br /><a id="L4549" href="#L4549">4549</a><br /><a id="L4550" href="#L4550">4550</a><br /><a id="L4551" href="#L4551">4551</a><br /><a id="L4552" href="#L4552">4552</a><br /><a id="L4553" href="#L4553">4553</a><br /><a id="L4554" href="#L4554">4554</a><br /><a id="L4555" href="#L4555">4555</a><br /><a id="L4556" href="#L4556">4556</a><br /><a id="L4557" href="#L4557">4557</a><br /><a id="L4558" href="#L4558">4558</a><br /><a id="L4559" href="#L4559">4559</a><br /><a id="L4560" href="#L4560">4560</a><br /><a id="L4561" href="#L4561">4561</a><br /><a id="L4562" href="#L4562">4562</a><br /><a id="L4563" href="#L4563">4563</a><br /><a id="L4564" href="#L4564">4564</a><br /><a id="L4565" href="#L4565">4565</a><br /><a id="L4566" href="#L4566">4566</a><br /><a id="L4567" href="#L4567">4567</a><br /><a id="L4568" href="#L4568">4568</a><br /><a id="L4569" href="#L4569">4569</a><br /><a id="L4570" href="#L4570">4570</a><br /><a id="L4571" href="#L4571">4571</a><br /><a id="L4572" href="#L4572">4572</a><br /><a id="L4573" href="#L4573">4573</a><br /><a id="L4574" href="#L4574">4574</a><br /><a id="L4575" href="#L4575">4575</a><br /><a id="L4576" href="#L4576">4576</a><br /><a id="L4577" href="#L4577">4577</a><br /><a id="L4578" href="#L4578">4578</a><br /><a id="L4579" href="#L4579">4579</a><br /><a id="L4580" href="#L4580">4580</a><br /><a id="L4581" href="#L4581">4581</a><br /><a id="L4582" href="#L4582">4582</a><br /><a id="L4583" href="#L4583">4583</a><br /><a id="L4584" href="#L4584">4584</a><br /><a id="L4585" href="#L4585">4585</a><br /><a id="L4586" href="#L4586">4586</a><br /><a id="L4587" href="#L4587">4587</a><br /><a id="L4588" href="#L4588">4588</a><br /><a id="L4589" href="#L4589">4589</a><br /><a id="L4590" href="#L4590">4590</a><br /><a id="L4591" href="#L4591">4591</a><br /><a id="L4592" href="#L4592">4592</a><br /><a id="L4593" href="#L4593">4593</a><br /><a id="L4594" href="#L4594">4594</a><br /><a id="L4595" href="#L4595">4595</a><br /><a id="L4596" href="#L4596">4596</a><br /><a id="L4597" href="#L4597">4597</a><br /><a id="L4598" href="#L4598">4598</a><br /><a id="L4599" href="#L4599">4599</a><br /><a id="L4600" href="#L4600">4600</a><br /><a id="L4601" href="#L4601">4601</a><br /><a id="L4602" href="#L4602">4602</a><br /><a id="L4603" href="#L4603">4603</a><br /><a id="L4604" href="#L4604">4604</a><br /><a id="L4605" href="#L4605">4605</a><br /><a id="L4606" href="#L4606">4606</a><br /><a id="L4607" href="#L4607">4607</a><br /><a id="L4608" href="#L4608">4608</a><br /><a id="L4609" href="#L4609">4609</a><br /><a id="L4610" href="#L4610">4610</a><br /><a id="L4611" href="#L4611">4611</a><br /><a id="L4612" href="#L4612">4612</a><br /><a id="L4613" href="#L4613">4613</a><br /><a id="L4614" href="#L4614">4614</a><br /><a id="L4615" href="#L4615">4615</a><br /><a id="L4616" href="#L4616">4616</a><br /><a id="L4617" href="#L4617">4617</a><br /><a id="L4618" href="#L4618">4618</a><br /><a id="L4619" href="#L4619">4619</a><br /><a id="L4620" href="#L4620">4620</a><br /><a id="L4621" href="#L4621">4621</a><br /><a id="L4622" href="#L4622">4622</a><br /><a id="L4623" href="#L4623">4623</a><br /><a id="L4624" href="#L4624">4624</a><br /><a id="L4625" href="#L4625">4625</a><br /><a id="L4626" href="#L4626">4626</a><br /><a id="L4627" href="#L4627">4627</a><br /><a id="L4628" href="#L4628">4628</a><br /><a id="L4629" href="#L4629">4629</a><br /><a id="L4630" href="#L4630">4630</a><br /><a id="L4631" href="#L4631">4631</a><br /><a id="L4632" href="#L4632">4632</a><br /><a id="L4633" href="#L4633">4633</a><br /><a id="L4634" href="#L4634">4634</a><br /><a id="L4635" href="#L4635">4635</a><br /><a id="L4636" href="#L4636">4636</a><br /><a id="L4637" href="#L4637">4637</a><br /><a id="L4638" href="#L4638">4638</a><br /><a id="L4639" href="#L4639">4639</a><br /><a id="L4640" href="#L4640">4640</a><br /><a id="L4641" href="#L4641">4641</a><br /><a id="L4642" href="#L4642">4642</a><br /><a id="L4643" href="#L4643">4643</a><br /><a id="L4644" href="#L4644">4644</a><br /><a id="L4645" href="#L4645">4645</a><br /><a id="L4646" href="#L4646">4646</a><br /><a id="L4647" href="#L4647">4647</a><br /><a id="L4648" href="#L4648">4648</a><br /><a id="L4649" href="#L4649">4649</a><br /><a id="L4650" href="#L4650">4650</a><br /><a id="L4651" href="#L4651">4651</a><br /><a id="L4652" href="#L4652">4652</a><br /><a id="L4653" href="#L4653">4653</a><br /><a id="L4654" href="#L4654">4654</a><br /><a id="L4655" href="#L4655">4655</a><br /><a id="L4656" href="#L4656">4656</a><br /><a id="L4657" href="#L4657">4657</a><br /><a id="L4658" href="#L4658">4658</a><br /><a id="L4659" href="#L4659">4659</a><br /><a id="L4660" href="#L4660">4660</a><br /><a id="L4661" href="#L4661">4661</a><br /><a id="L4662" href="#L4662">4662</a><br /><a id="L4663" href="#L4663">4663</a><br /><a id="L4664" href="#L4664">4664</a><br /><a id="L4665" href="#L4665">4665</a><br /><a id="L4666" href="#L4666">4666</a><br /><a id="L4667" href="#L4667">4667</a><br /><a id="L4668" href="#L4668">4668</a><br /><a id="L4669" href="#L4669">4669</a><br /><a id="L4670" href="#L4670">4670</a><br /><a id="L4671" href="#L4671">4671</a><br /><a id="L4672" href="#L4672">4672</a><br /><a id="L4673" href="#L4673">4673</a><br /><a id="L4674" href="#L4674">4674</a><br /><a id="L4675" href="#L4675">4675</a><br /><a id="L4676" href="#L4676">4676</a><br /><a id="L4677" href="#L4677">4677</a><br /><a id="L4678" href="#L4678">4678</a><br /><a id="L4679" href="#L4679">4679</a><br /><a id="L4680" href="#L4680">4680</a><br /><a id="L4681" href="#L4681">4681</a><br /><a id="L4682" href="#L4682">4682</a><br /><a id="L4683" href="#L4683">4683</a><br /><a id="L4684" href="#L4684">4684</a><br /><a id="L4685" href="#L4685">4685</a><br /><a id="L4686" href="#L4686">4686</a><br /><a id="L4687" href="#L4687">4687</a><br /><a id="L4688" href="#L4688">4688</a><br /><a id="L4689" href="#L4689">4689</a><br /><a id="L4690" href="#L4690">4690</a><br /><a id="L4691" href="#L4691">4691</a><br /><a id="L4692" href="#L4692">4692</a><br /><a id="L4693" href="#L4693">4693</a><br /><a id="L4694" href="#L4694">4694</a><br /><a id="L4695" href="#L4695">4695</a><br /><a id="L4696" href="#L4696">4696</a><br /><a id="L4697" href="#L4697">4697</a><br /><a id="L4698" href="#L4698">4698</a><br /><a id="L4699" href="#L4699">4699</a><br /><a id="L4700" href="#L4700">4700</a><br /><a id="L4701" href="#L4701">4701</a><br /><a id="L4702" href="#L4702">4702</a><br /><a id="L4703" href="#L4703">4703</a><br /><a id="L4704" href="#L4704">4704</a><br /><a id="L4705" href="#L4705">4705</a><br /><a id="L4706" href="#L4706">4706</a><br /><a id="L4707" href="#L4707">4707</a><br /><a id="L4708" href="#L4708">4708</a><br /><a id="L4709" href="#L4709">4709</a><br /><a id="L4710" href="#L4710">4710</a><br /><a id="L4711" href="#L4711">4711</a><br /><a id="L4712" href="#L4712">4712</a><br /><a id="L4713" href="#L4713">4713</a><br /><a id="L4714" href="#L4714">4714</a><br /><a id="L4715" href="#L4715">4715</a><br /><a id="L4716" href="#L4716">4716</a><br /><a id="L4717" href="#L4717">4717</a><br /><a id="L4718" href="#L4718">4718</a><br /><a id="L4719" href="#L4719">4719</a><br /><a id="L4720" href="#L4720">4720</a><br /><a id="L4721" href="#L4721">4721</a><br /><a id="L4722" href="#L4722">4722</a><br /><a id="L4723" href="#L4723">4723</a><br /><a id="L4724" href="#L4724">4724</a><br /><a id="L4725" href="#L4725">4725</a><br /><a id="L4726" href="#L4726">4726</a><br /><a id="L4727" href="#L4727">4727</a><br /><a id="L4728" href="#L4728">4728</a><br /><a id="L4729" href="#L4729">4729</a><br /><a id="L4730" href="#L4730">4730</a><br /><a id="L4731" href="#L4731">4731</a><br /><a id="L4732" href="#L4732">4732</a><br /><a id="L4733" href="#L4733">4733</a><br /><a id="L4734" href="#L4734">4734</a><br /><a id="L4735" href="#L4735">4735</a><br /><a id="L4736" href="#L4736">4736</a><br /><a id="L4737" href="#L4737">4737</a><br /><a id="L4738" href="#L4738">4738</a><br /><a id="L4739" href="#L4739">4739</a><br /><a id="L4740" href="#L4740">4740</a><br /><a id="L4741" href="#L4741">4741</a><br /><a id="L4742" href="#L4742">4742</a><br /><a id="L4743" href="#L4743">4743</a><br /><a id="L4744" href="#L4744">4744</a><br /><a id="L4745" href="#L4745">4745</a><br /><a id="L4746" href="#L4746">4746</a><br /><a id="L4747" href="#L4747">4747</a><br /><a id="L4748" href="#L4748">4748</a><br /><a id="L4749" href="#L4749">4749</a><br /><a id="L4750" href="#L4750">4750</a><br /><a id="L4751" href="#L4751">4751</a><br /><a id="L4752" href="#L4752">4752</a><br /><a id="L4753" href="#L4753">4753</a><br /><a id="L4754" href="#L4754">4754</a><br /><a id="L4755" href="#L4755">4755</a><br /><a id="L4756" href="#L4756">4756</a><br /><a id="L4757" href="#L4757">4757</a><br /><a id="L4758" href="#L4758">4758</a><br /><a id="L4759" href="#L4759">4759</a><br /><a id="L4760" href="#L4760">4760</a><br /><a id="L4761" href="#L4761">4761</a><br /><a id="L4762" href="#L4762">4762</a><br /><a id="L4763" href="#L4763">4763</a><br /><a id="L4764" href="#L4764">4764</a><br /><a id="L4765" href="#L4765">4765</a><br /><a id="L4766" href="#L4766">4766</a><br /><a id="L4767" href="#L4767">4767</a><br /><a id="L4768" href="#L4768">4768</a><br /><a id="L4769" href="#L4769">4769</a><br /><a id="L4770" href="#L4770">4770</a><br /><a id="L4771" href="#L4771">4771</a><br /><a id="L4772" href="#L4772">4772</a><br /><a id="L4773" href="#L4773">4773</a><br /><a id="L4774" href="#L4774">4774</a><br /><a id="L4775" href="#L4775">4775</a><br /><a id="L4776" href="#L4776">4776</a><br /><a id="L4777" href="#L4777">4777</a><br /><a id="L4778" href="#L4778">4778</a><br /><a id="L4779" href="#L4779">4779</a><br /><a id="L4780" href="#L4780">4780</a><br /><a id="L4781" href="#L4781">4781</a><br /><a id="L4782" href="#L4782">4782</a><br /><a id="L4783" href="#L4783">4783</a><br /><a id="L4784" href="#L4784">4784</a><br /><a id="L4785" href="#L4785">4785</a><br /><a id="L4786" href="#L4786">4786</a><br /><a id="L4787" href="#L4787">4787</a><br /><a id="L4788" href="#L4788">4788</a><br /><a id="L4789" href="#L4789">4789</a><br /><a id="L4790" href="#L4790">4790</a><br /><a id="L4791" href="#L4791">4791</a><br /><a id="L4792" href="#L4792">4792</a><br /><a id="L4793" href="#L4793">4793</a><br /><a id="L4794" href="#L4794">4794</a><br /><a id="L4795" href="#L4795">4795</a><br /><a id="L4796" href="#L4796">4796</a><br /><a id="L4797" href="#L4797">4797</a><br /><a id="L4798" href="#L4798">4798</a><br /><a id="L4799" href="#L4799">4799</a><br /><a id="L4800" href="#L4800">4800</a><br /><a id="L4801" href="#L4801">4801</a><br /><a id="L4802" href="#L4802">4802</a><br /><a id="L4803" href="#L4803">4803</a><br /><a id="L4804" href="#L4804">4804</a><br /><a id="L4805" href="#L4805">4805</a><br /><a id="L4806" href="#L4806">4806</a><br /><a id="L4807" href="#L4807">4807</a><br /><a id="L4808" href="#L4808">4808</a><br /><a id="L4809" href="#L4809">4809</a><br /><a id="L4810" href="#L4810">4810</a><br /><a id="L4811" href="#L4811">4811</a><br /><a id="L4812" href="#L4812">4812</a><br /><a id="L4813" href="#L4813">4813</a><br /><a id="L4814" href="#L4814">4814</a><br /><a id="L4815" href="#L4815">4815</a><br /><a id="L4816" href="#L4816">4816</a><br /><a id="L4817" href="#L4817">4817</a><br /><a id="L4818" href="#L4818">4818</a><br /><a id="L4819" href="#L4819">4819</a><br /><a id="L4820" href="#L4820">4820</a><br /><a id="L4821" href="#L4821">4821</a><br /><a id="L4822" href="#L4822">4822</a><br /><a id="L4823" href="#L4823">4823</a><br /><a id="L4824" href="#L4824">4824</a><br /><a id="L4825" href="#L4825">4825</a><br /><a id="L4826" href="#L4826">4826</a><br /><a id="L4827" href="#L4827">4827</a><br /><a id="L4828" href="#L4828">4828</a><br /><a id="L4829" href="#L4829">4829</a><br /><a id="L4830" href="#L4830">4830</a><br /><a id="L4831" href="#L4831">4831</a><br /><a id="L4832" href="#L4832">4832</a><br /><a id="L4833" href="#L4833">4833</a><br /><a id="L4834" href="#L4834">4834</a><br /><a id="L4835" href="#L4835">4835</a><br /><a id="L4836" href="#L4836">4836</a><br /><a id="L4837" href="#L4837">4837</a><br /><a id="L4838" href="#L4838">4838</a><br /><a id="L4839" href="#L4839">4839</a><br /><a id="L4840" href="#L4840">4840</a><br /><a id="L4841" href="#L4841">4841</a><br /><a id="L4842" href="#L4842">4842</a><br /><a id="L4843" href="#L4843">4843</a><br /><a id="L4844" href="#L4844">4844</a><br /><a id="L4845" href="#L4845">4845</a><br /><a id="L4846" href="#L4846">4846</a><br /><a id="L4847" href="#L4847">4847</a><br /><a id="L4848" href="#L4848">4848</a><br /><a id="L4849" href="#L4849">4849</a><br /><a id="L4850" href="#L4850">4850</a><br /><a id="L4851" href="#L4851">4851</a><br /><a id="L4852" href="#L4852">4852</a><br /><a id="L4853" href="#L4853">4853</a><br /><a id="L4854" href="#L4854">4854</a><br /><a id="L4855" href="#L4855">4855</a><br /><a id="L4856" href="#L4856">4856</a><br /><a id="L4857" href="#L4857">4857</a><br /><a id="L4858" href="#L4858">4858</a><br /><a id="L4859" href="#L4859">4859</a><br /><a id="L4860" href="#L4860">4860</a><br /><a id="L4861" href="#L4861">4861</a><br /><a id="L4862" href="#L4862">4862</a><br /><a id="L4863" href="#L4863">4863</a><br /><a id="L4864" href="#L4864">4864</a><br /><a id="L4865" href="#L4865">4865</a><br /><a id="L4866" href="#L4866">4866</a><br /><a id="L4867" href="#L4867">4867</a><br /><a id="L4868" href="#L4868">4868</a><br /><a id="L4869" href="#L4869">4869</a><br /><a id="L4870" href="#L4870">4870</a><br /><a id="L4871" href="#L4871">4871</a><br /><a id="L4872" href="#L4872">4872</a><br /><a id="L4873" href="#L4873">4873</a><br /><a id="L4874" href="#L4874">4874</a><br /><a id="L4875" href="#L4875">4875</a><br /><a id="L4876" href="#L4876">4876</a><br /><a id="L4877" href="#L4877">4877</a><br /><a id="L4878" href="#L4878">4878</a><br /><a id="L4879" href="#L4879">4879</a><br /><a id="L4880" href="#L4880">4880</a><br /><a id="L4881" href="#L4881">4881</a><br /><a id="L4882" href="#L4882">4882</a><br /><a id="L4883" href="#L4883">4883</a><br /><a id="L4884" href="#L4884">4884</a><br /><a id="L4885" href="#L4885">4885</a><br /><a id="L4886" href="#L4886">4886</a><br /><a id="L4887" href="#L4887">4887</a><br /><a id="L4888" href="#L4888">4888</a><br /><a id="L4889" href="#L4889">4889</a><br /><a id="L4890" href="#L4890">4890</a><br /><a id="L4891" href="#L4891">4891</a><br /><a id="L4892" href="#L4892">4892</a><br /><a id="L4893" href="#L4893">4893</a><br /><a id="L4894" href="#L4894">4894</a><br /><a id="L4895" href="#L4895">4895</a><br /><a id="L4896" href="#L4896">4896</a><br /><a id="L4897" href="#L4897">4897</a><br /><a id="L4898" href="#L4898">4898</a><br /><a id="L4899" href="#L4899">4899</a><br /><a id="L4900" href="#L4900">4900</a><br /><a id="L4901" href="#L4901">4901</a><br /><a id="L4902" href="#L4902">4902</a><br /><a id="L4903" href="#L4903">4903</a><br /><a id="L4904" href="#L4904">4904</a><br /><a id="L4905" href="#L4905">4905</a><br /><a id="L4906" href="#L4906">4906</a><br /><a id="L4907" href="#L4907">4907</a><br /><a id="L4908" href="#L4908">4908</a><br /><a id="L4909" href="#L4909">4909</a><br /><a id="L4910" href="#L4910">4910</a><br /><a id="L4911" href="#L4911">4911</a><br /><a id="L4912" href="#L4912">4912</a><br /><a id="L4913" href="#L4913">4913</a><br /><a id="L4914" href="#L4914">4914</a><br /><a id="L4915" href="#L4915">4915</a><br /><a id="L4916" href="#L4916">4916</a><br /><a id="L4917" href="#L4917">4917</a><br /><a id="L4918" href="#L4918">4918</a><br /><a id="L4919" href="#L4919">4919</a><br /><a id="L4920" href="#L4920">4920</a><br /><a id="L4921" href="#L4921">4921</a><br /><a id="L4922" href="#L4922">4922</a><br /><a id="L4923" href="#L4923">4923</a><br /><a id="L4924" href="#L4924">4924</a><br /><a id="L4925" href="#L4925">4925</a><br /><a id="L4926" href="#L4926">4926</a><br /><a id="L4927" href="#L4927">4927</a><br /><a id="L4928" href="#L4928">4928</a><br /><a id="L4929" href="#L4929">4929</a><br /><a id="L4930" href="#L4930">4930</a><br /><a id="L4931" href="#L4931">4931</a><br /><a id="L4932" href="#L4932">4932</a><br /><a id="L4933" href="#L4933">4933</a><br /><a id="L4934" href="#L4934">4934</a><br /><a id="L4935" href="#L4935">4935</a><br /><a id="L4936" href="#L4936">4936</a><br /><a id="L4937" href="#L4937">4937</a><br /><a id="L4938" href="#L4938">4938</a><br /><a id="L4939" href="#L4939">4939</a><br /><a id="L4940" href="#L4940">4940</a><br /><a id="L4941" href="#L4941">4941</a><br /><a id="L4942" href="#L4942">4942</a><br /><a id="L4943" href="#L4943">4943</a><br /><a id="L4944" href="#L4944">4944</a><br /><a id="L4945" href="#L4945">4945</a><br /><a id="L4946" href="#L4946">4946</a><br /><a id="L4947" href="#L4947">4947</a><br /><a id="L4948" href="#L4948">4948</a><br /><a id="L4949" href="#L4949">4949</a><br /><a id="L4950" href="#L4950">4950</a><br /><a id="L4951" href="#L4951">4951</a><br /><a id="L4952" href="#L4952">4952</a><br /><a id="L4953" href="#L4953">4953</a><br /><a id="L4954" href="#L4954">4954</a><br /><a id="L4955" href="#L4955">4955</a><br /><a id="L4956" href="#L4956">4956</a><br /><a id="L4957" href="#L4957">4957</a><br /><a id="L4958" href="#L4958">4958</a><br /><a id="L4959" href="#L4959">4959</a><br /><a id="L4960" href="#L4960">4960</a><br /><a id="L4961" href="#L4961">4961</a><br /><a id="L4962" href="#L4962">4962</a><br /><a id="L4963" href="#L4963">4963</a><br /><a id="L4964" href="#L4964">4964</a><br /><a id="L4965" href="#L4965">4965</a><br /><a id="L4966" href="#L4966">4966</a><br /><a id="L4967" href="#L4967">4967</a><br /><a id="L4968" href="#L4968">4968</a><br /><a id="L4969" href="#L4969">4969</a><br /><a id="L4970" href="#L4970">4970</a><br /><a id="L4971" href="#L4971">4971</a><br /><a id="L4972" href="#L4972">4972</a><br /><a id="L4973" href="#L4973">4973</a><br /><a id="L4974" href="#L4974">4974</a><br /><a id="L4975" href="#L4975">4975</a><br /><a id="L4976" href="#L4976">4976</a><br /><a id="L4977" href="#L4977">4977</a><br /><a id="L4978" href="#L4978">4978</a><br /><a id="L4979" href="#L4979">4979</a><br /><a id="L4980" href="#L4980">4980</a><br /><a id="L4981" href="#L4981">4981</a><br /><a id="L4982" href="#L4982">4982</a><br /><a id="L4983" href="#L4983">4983</a><br /><a id="L4984" href="#L4984">4984</a><br /><a id="L4985" href="#L4985">4985</a><br /><a id="L4986" href="#L4986">4986</a><br /><a id="L4987" href="#L4987">4987</a><br /><a id="L4988" href="#L4988">4988</a><br /><a id="L4989" href="#L4989">4989</a><br /><a id="L4990" href="#L4990">4990</a><br /><a id="L4991" href="#L4991">4991</a><br /><a id="L4992" href="#L4992">4992</a><br /><a id="L4993" href="#L4993">4993</a><br /><a id="L4994" href="#L4994">4994</a><br /><a id="L4995" href="#L4995">4995</a><br /><a id="L4996" href="#L4996">4996</a><br /><a id="L4997" href="#L4997">4997</a><br /><a id="L4998" href="#L4998">4998</a><br /><a id="L4999" href="#L4999">4999</a><br /><a id="L5000" href="#L5000">5000</a><br /><a id="L5001" href="#L5001">5001</a><br /><a id="L5002" href="#L5002">5002</a><br /><a id="L5003" href="#L5003">5003</a><br /><a id="L5004" href="#L5004">5004</a><br /><a id="L5005" href="#L5005">5005</a><br /><a id="L5006" href="#L5006">5006</a><br /><a id="L5007" href="#L5007">5007</a><br /><a id="L5008" href="#L5008">5008</a><br /><a id="L5009" href="#L5009">5009</a><br /><a id="L5010" href="#L5010">5010</a><br /><a id="L5011" href="#L5011">5011</a><br /><a id="L5012" href="#L5012">5012</a><br /><a id="L5013" href="#L5013">5013</a><br /><a id="L5014" href="#L5014">5014</a><br /><a id="L5015" href="#L5015">5015</a><br /><a id="L5016" href="#L5016">5016</a><br /><a id="L5017" href="#L5017">5017</a><br /><a id="L5018" href="#L5018">5018</a><br /><a id="L5019" href="#L5019">5019</a><br /><a id="L5020" href="#L5020">5020</a><br /><a id="L5021" href="#L5021">5021</a><br /><a id="L5022" href="#L5022">5022</a><br /><a id="L5023" href="#L5023">5023</a><br /><a id="L5024" href="#L5024">5024</a><br /><a id="L5025" href="#L5025">5025</a><br /><a id="L5026" href="#L5026">5026</a><br /><a id="L5027" href="#L5027">5027</a><br /><a id="L5028" href="#L5028">5028</a><br /><a id="L5029" href="#L5029">5029</a><br /><a id="L5030" href="#L5030">5030</a><br /><a id="L5031" href="#L5031">5031</a><br /><a id="L5032" href="#L5032">5032</a><br /><a id="L5033" href="#L5033">5033</a><br /><a id="L5034" href="#L5034">5034</a><br /><a id="L5035" href="#L5035">5035</a><br /><a id="L5036" href="#L5036">5036</a><br /><a id="L5037" href="#L5037">5037</a><br /><a id="L5038" href="#L5038">5038</a><br /><a id="L5039" href="#L5039">5039</a><br /><a id="L5040" href="#L5040">5040</a><br /><a id="L5041" href="#L5041">5041</a><br /><a id="L5042" href="#L5042">5042</a><br /><a id="L5043" href="#L5043">5043</a><br /><a id="L5044" href="#L5044">5044</a><br /><a id="L5045" href="#L5045">5045</a><br /><a id="L5046" href="#L5046">5046</a><br /><a id="L5047" href="#L5047">5047</a><br /><a id="L5048" href="#L5048">5048</a><br /><a id="L5049" href="#L5049">5049</a><br /><a id="L5050" href="#L5050">5050</a><br /><a id="L5051" href="#L5051">5051</a><br /><a id="L5052" href="#L5052">5052</a><br /><a id="L5053" href="#L5053">5053</a><br /><a id="L5054" href="#L5054">5054</a><br /><a id="L5055" href="#L5055">5055</a><br /><a id="L5056" href="#L5056">5056</a><br /><a id="L5057" href="#L5057">5057</a><br /><a id="L5058" href="#L5058">5058</a><br /><a id="L5059" href="#L5059">5059</a><br /><a id="L5060" href="#L5060">5060</a><br /><a id="L5061" href="#L5061">5061</a><br /><a id="L5062" href="#L5062">5062</a><br /><a id="L5063" href="#L5063">5063</a><br /><a id="L5064" href="#L5064">5064</a><br /><a id="L5065" href="#L5065">5065</a><br /><a id="L5066" href="#L5066">5066</a><br /><a id="L5067" href="#L5067">5067</a><br /><a id="L5068" href="#L5068">5068</a><br /><a id="L5069" href="#L5069">5069</a><br /><a id="L5070" href="#L5070">5070</a><br /><a id="L5071" href="#L5071">5071</a><br /><a id="L5072" href="#L5072">5072</a><br /><a id="L5073" href="#L5073">5073</a><br /><a id="L5074" href="#L5074">5074</a><br /><a id="L5075" href="#L5075">5075</a><br /><a id="L5076" href="#L5076">5076</a><br /><a id="L5077" href="#L5077">5077</a><br /><a id="L5078" href="#L5078">5078</a><br /><a id="L5079" href="#L5079">5079</a><br /><a id="L5080" href="#L5080">5080</a><br /><a id="L5081" href="#L5081">5081</a><br /><a id="L5082" href="#L5082">5082</a><br /><a id="L5083" href="#L5083">5083</a><br /><a id="L5084" href="#L5084">5084</a><br /><a id="L5085" href="#L5085">5085</a><br /><a id="L5086" href="#L5086">5086</a><br /><a id="L5087" href="#L5087">5087</a><br /><a id="L5088" href="#L5088">5088</a><br /><a id="L5089" href="#L5089">5089</a><br /><a id="L5090" href="#L5090">5090</a><br /><a id="L5091" href="#L5091">5091</a><br /><a id="L5092" href="#L5092">5092</a><br /><a id="L5093" href="#L5093">5093</a><br /><a id="L5094" href="#L5094">5094</a><br /><a id="L5095" href="#L5095">5095</a><br /><a id="L5096" href="#L5096">5096</a><br /><a id="L5097" href="#L5097">5097</a><br /><a id="L5098" href="#L5098">5098</a><br /><a id="L5099" href="#L5099">5099</a><br /><a id="L5100" href="#L5100">5100</a><br /><a id="L5101" href="#L5101">5101</a><br /><a id="L5102" href="#L5102">5102</a><br /><a id="L5103" href="#L5103">5103</a><br /><a id="L5104" href="#L5104">5104</a><br /><a id="L5105" href="#L5105">5105</a><br /><a id="L5106" href="#L5106">5106</a><br /><a id="L5107" href="#L5107">5107</a><br /><a id="L5108" href="#L5108">5108</a><br /><a id="L5109" href="#L5109">5109</a><br /><a id="L5110" href="#L5110">5110</a><br /><a id="L5111" href="#L5111">5111</a><br /><a id="L5112" href="#L5112">5112</a><br /><a id="L5113" href="#L5113">5113</a><br /><a id="L5114" href="#L5114">5114</a><br /><a id="L5115" href="#L5115">5115</a><br /><a id="L5116" href="#L5116">5116</a><br /><a id="L5117" href="#L5117">5117</a><br /><a id="L5118" href="#L5118">5118</a><br /><a id="L5119" href="#L5119">5119</a><br /><a id="L5120" href="#L5120">5120</a><br /><a id="L5121" href="#L5121">5121</a><br /><a id="L5122" href="#L5122">5122</a><br /><a id="L5123" href="#L5123">5123</a><br /><a id="L5124" href="#L5124">5124</a><br /><a id="L5125" href="#L5125">5125</a><br /><a id="L5126" href="#L5126">5126</a><br /><a id="L5127" href="#L5127">5127</a><br /><a id="L5128" href="#L5128">5128</a><br /><a id="L5129" href="#L5129">5129</a><br /><a id="L5130" href="#L5130">5130</a><br /><a id="L5131" href="#L5131">5131</a><br /><a id="L5132" href="#L5132">5132</a><br /><a id="L5133" href="#L5133">5133</a><br /><a id="L5134" href="#L5134">5134</a><br /><a id="L5135" href="#L5135">5135</a><br /><a id="L5136" href="#L5136">5136</a><br /><a id="L5137" href="#L5137">5137</a><br /><a id="L5138" href="#L5138">5138</a><br /><a id="L5139" href="#L5139">5139</a><br /><a id="L5140" href="#L5140">5140</a><br /><a id="L5141" href="#L5141">5141</a><br /><a id="L5142" href="#L5142">5142</a><br /><a id="L5143" href="#L5143">5143</a><br /><a id="L5144" href="#L5144">5144</a><br /><a id="L5145" href="#L5145">5145</a><br /><a id="L5146" href="#L5146">5146</a><br /><a id="L5147" href="#L5147">5147</a><br /><a id="L5148" href="#L5148">5148</a><br /><a id="L5149" href="#L5149">5149</a><br /><a id="L5150" href="#L5150">5150</a><br /><a id="L5151" href="#L5151">5151</a><br /><a id="L5152" href="#L5152">5152</a><br /><a id="L5153" href="#L5153">5153</a><br /><a id="L5154" href="#L5154">5154</a><br /><a id="L5155" href="#L5155">5155</a><br /><a id="L5156" href="#L5156">5156</a><br /><a id="L5157" href="#L5157">5157</a><br /><a id="L5158" href="#L5158">5158</a><br /><a id="L5159" href="#L5159">5159</a><br /><a id="L5160" href="#L5160">5160</a><br /><a id="L5161" href="#L5161">5161</a><br /><a id="L5162" href="#L5162">5162</a><br /><a id="L5163" href="#L5163">5163</a><br /><a id="L5164" href="#L5164">5164</a><br /><a id="L5165" href="#L5165">5165</a><br /><a id="L5166" href="#L5166">5166</a><br /><a id="L5167" href="#L5167">5167</a><br /><a id="L5168" href="#L5168">5168</a><br /><a id="L5169" href="#L5169">5169</a><br /><a id="L5170" href="#L5170">5170</a><br /><a id="L5171" href="#L5171">5171</a><br /><a id="L5172" href="#L5172">5172</a><br /><a id="L5173" href="#L5173">5173</a><br /><a id="L5174" href="#L5174">5174</a><br /><a id="L5175" href="#L5175">5175</a><br /><a id="L5176" href="#L5176">5176</a><br /><a id="L5177" href="#L5177">5177</a><br /><a id="L5178" href="#L5178">5178</a><br /><a id="L5179" href="#L5179">5179</a><br /><a id="L5180" href="#L5180">5180</a><br /><a id="L5181" href="#L5181">5181</a><br /><a id="L5182" href="#L5182">5182</a><br /><a id="L5183" href="#L5183">5183</a><br /><a id="L5184" href="#L5184">5184</a><br /><a id="L5185" href="#L5185">5185</a><br /><a id="L5186" href="#L5186">5186</a><br /><a id="L5187" href="#L5187">5187</a><br /><a id="L5188" href="#L5188">5188</a><br /><a id="L5189" href="#L5189">5189</a><br /><a id="L5190" href="#L5190">5190</a><br /><a id="L5191" href="#L5191">5191</a><br /><a id="L5192" href="#L5192">5192</a><br /><a id="L5193" href="#L5193">5193</a><br /><a id="L5194" href="#L5194">5194</a><br /><a id="L5195" href="#L5195">5195</a><br /><a id="L5196" href="#L5196">5196</a><br /><a id="L5197" href="#L5197">5197</a><br /><a id="L5198" href="#L5198">5198</a><br /><a id="L5199" href="#L5199">5199</a><br /><a id="L5200" href="#L5200">5200</a><br /><a id="L5201" href="#L5201">5201</a><br /><a id="L5202" href="#L5202">5202</a><br /><a id="L5203" href="#L5203">5203</a><br /><a id="L5204" href="#L5204">5204</a><br /><a id="L5205" href="#L5205">5205</a><br /><a id="L5206" href="#L5206">5206</a><br /><a id="L5207" href="#L5207">5207</a><br /><a id="L5208" href="#L5208">5208</a><br /><a id="L5209" href="#L5209">5209</a><br /><a id="L5210" href="#L5210">5210</a><br /><a id="L5211" href="#L5211">5211</a><br /><a id="L5212" href="#L5212">5212</a><br /><a id="L5213" href="#L5213">5213</a><br /><a id="L5214" href="#L5214">5214</a><br /><a id="L5215" href="#L5215">5215</a><br /><a id="L5216" href="#L5216">5216</a><br /><a id="L5217" href="#L5217">5217</a><br /><a id="L5218" href="#L5218">5218</a><br /><a id="L5219" href="#L5219">5219</a><br /><a id="L5220" href="#L5220">5220</a><br /><a id="L5221" href="#L5221">5221</a><br /><a id="L5222" href="#L5222">5222</a><br /><a id="L5223" href="#L5223">5223</a><br /><a id="L5224" href="#L5224">5224</a><br /><a id="L5225" href="#L5225">5225</a><br /><a id="L5226" href="#L5226">5226</a><br /><a id="L5227" href="#L5227">5227</a><br /><a id="L5228" href="#L5228">5228</a><br /><a id="L5229" href="#L5229">5229</a><br /><a id="L5230" href="#L5230">5230</a><br /><a id="L5231" href="#L5231">5231</a><br /><a id="L5232" href="#L5232">5232</a><br /><a id="L5233" href="#L5233">5233</a><br /><a id="L5234" href="#L5234">5234</a><br /><a id="L5235" href="#L5235">5235</a><br /><a id="L5236" href="#L5236">5236</a><br /><a id="L5237" href="#L5237">5237</a><br /><a id="L5238" href="#L5238">5238</a><br /><a id="L5239" href="#L5239">5239</a><br /><a id="L5240" href="#L5240">5240</a><br /><a id="L5241" href="#L5241">5241</a><br /><a id="L5242" href="#L5242">5242</a><br /><a id="L5243" href="#L5243">5243</a><br /><a id="L5244" href="#L5244">5244</a><br /><a id="L5245" href="#L5245">5245</a><br /><a id="L5246" href="#L5246">5246</a><br /><a id="L5247" href="#L5247">5247</a><br /><a id="L5248" href="#L5248">5248</a><br /><a id="L5249" href="#L5249">5249</a><br /><a id="L5250" href="#L5250">5250</a><br /><a id="L5251" href="#L5251">5251</a><br /><a id="L5252" href="#L5252">5252</a><br /><a id="L5253" href="#L5253">5253</a><br /><a id="L5254" href="#L5254">5254</a><br /><a id="L5255" href="#L5255">5255</a><br /><a id="L5256" href="#L5256">5256</a><br /><a id="L5257" href="#L5257">5257</a><br /><a id="L5258" href="#L5258">5258</a><br /><a id="L5259" href="#L5259">5259</a><br /><a id="L5260" href="#L5260">5260</a><br /><a id="L5261" href="#L5261">5261</a><br /><a id="L5262" href="#L5262">5262</a><br /><a id="L5263" href="#L5263">5263</a><br /><a id="L5264" href="#L5264">5264</a><br /><a id="L5265" href="#L5265">5265</a><br /><a id="L5266" href="#L5266">5266</a><br /><a id="L5267" href="#L5267">5267</a><br /><a id="L5268" href="#L5268">5268</a><br /><a id="L5269" href="#L5269">5269</a><br /><a id="L5270" href="#L5270">5270</a><br /><a id="L5271" href="#L5271">5271</a><br /><a id="L5272" href="#L5272">5272</a><br /><a id="L5273" href="#L5273">5273</a><br /><a id="L5274" href="#L5274">5274</a><br /><a id="L5275" href="#L5275">5275</a><br /><a id="L5276" href="#L5276">5276</a><br /><a id="L5277" href="#L5277">5277</a><br /><a id="L5278" href="#L5278">5278</a><br /><a id="L5279" href="#L5279">5279</a><br /><a id="L5280" href="#L5280">5280</a><br /><a id="L5281" href="#L5281">5281</a><br /><a id="L5282" href="#L5282">5282</a><br /><a id="L5283" href="#L5283">5283</a><br /><a id="L5284" href="#L5284">5284</a><br /><a id="L5285" href="#L5285">5285</a><br /><a id="L5286" href="#L5286">5286</a><br /><a id="L5287" href="#L5287">5287</a><br /><a id="L5288" href="#L5288">5288</a><br /><a id="L5289" href="#L5289">5289</a><br /><a id="L5290" href="#L5290">5290</a><br /><a id="L5291" href="#L5291">5291</a><br /><a id="L5292" href="#L5292">5292</a><br /><a id="L5293" href="#L5293">5293</a><br /><a id="L5294" href="#L5294">5294</a><br /><a id="L5295" href="#L5295">5295</a><br /><a id="L5296" href="#L5296">5296</a><br /><a id="L5297" href="#L5297">5297</a><br /><a id="L5298" href="#L5298">5298</a><br /><a id="L5299" href="#L5299">5299</a><br /><a id="L5300" href="#L5300">5300</a><br /><a id="L5301" href="#L5301">5301</a><br /><a id="L5302" href="#L5302">5302</a><br /><a id="L5303" href="#L5303">5303</a><br /><a id="L5304" href="#L5304">5304</a><br /><a id="L5305" href="#L5305">5305</a><br /><a id="L5306" href="#L5306">5306</a><br /><a id="L5307" href="#L5307">5307</a><br /><a id="L5308" href="#L5308">5308</a><br /><a id="L5309" href="#L5309">5309</a><br /><a id="L5310" href="#L5310">5310</a><br /><a id="L5311" href="#L5311">5311</a><br /><a id="L5312" href="#L5312">5312</a><br /><a id="L5313" href="#L5313">5313</a><br /><a id="L5314" href="#L5314">5314</a><br /><a id="L5315" href="#L5315">5315</a><br /><a id="L5316" href="#L5316">5316</a><br /><a id="L5317" href="#L5317">5317</a><br /><a id="L5318" href="#L5318">5318</a><br /><a id="L5319" href="#L5319">5319</a><br /><a id="L5320" href="#L5320">5320</a><br /><a id="L5321" href="#L5321">5321</a><br /><a id="L5322" href="#L5322">5322</a><br /><a id="L5323" href="#L5323">5323</a><br /><a id="L5324" href="#L5324">5324</a><br /><a id="L5325" href="#L5325">5325</a><br /><a id="L5326" href="#L5326">5326</a><br /><a id="L5327" href="#L5327">5327</a><br /><a id="L5328" href="#L5328">5328</a><br /><a id="L5329" href="#L5329">5329</a><br /><a id="L5330" href="#L5330">5330</a><br /><a id="L5331" href="#L5331">5331</a><br /><a id="L5332" href="#L5332">5332</a><br /><a id="L5333" href="#L5333">5333</a><br /><a id="L5334" href="#L5334">5334</a><br /><a id="L5335" href="#L5335">5335</a><br /><a id="L5336" href="#L5336">5336</a><br /><a id="L5337" href="#L5337">5337</a><br /><a id="L5338" href="#L5338">5338</a><br /><a id="L5339" href="#L5339">5339</a><br /><a id="L5340" href="#L5340">5340</a><br /><a id="L5341" href="#L5341">5341</a><br /><a id="L5342" href="#L5342">5342</a><br /><a id="L5343" href="#L5343">5343</a><br /><a id="L5344" href="#L5344">5344</a><br /><a id="L5345" href="#L5345">5345</a><br /><a id="L5346" href="#L5346">5346</a><br /><a id="L5347" href="#L5347">5347</a><br /><a id="L5348" href="#L5348">5348</a><br /><a id="L5349" href="#L5349">5349</a><br /><a id="L5350" href="#L5350">5350</a><br /><a id="L5351" href="#L5351">5351</a><br /><a id="L5352" href="#L5352">5352</a><br /><a id="L5353" href="#L5353">5353</a><br /><a id="L5354" href="#L5354">5354</a><br /><a id="L5355" href="#L5355">5355</a><br /><a id="L5356" href="#L5356">5356</a><br /><a id="L5357" href="#L5357">5357</a><br /><a id="L5358" href="#L5358">5358</a><br /><a id="L5359" href="#L5359">5359</a><br /><a id="L5360" href="#L5360">5360</a><br /><a id="L5361" href="#L5361">5361</a><br /><a id="L5362" href="#L5362">5362</a><br /><a id="L5363" href="#L5363">5363</a><br /><a id="L5364" href="#L5364">5364</a><br /><a id="L5365" href="#L5365">5365</a><br /><a id="L5366" href="#L5366">5366</a><br /><a id="L5367" href="#L5367">5367</a><br /><a id="L5368" href="#L5368">5368</a><br /><a id="L5369" href="#L5369">5369</a><br /><a id="L5370" href="#L5370">5370</a><br /><a id="L5371" href="#L5371">5371</a><br /><a id="L5372" href="#L5372">5372</a><br /><a id="L5373" href="#L5373">5373</a><br /><a id="L5374" href="#L5374">5374</a><br /><a id="L5375" href="#L5375">5375</a><br /><a id="L5376" href="#L5376">5376</a><br /><a id="L5377" href="#L5377">5377</a><br /><a id="L5378" href="#L5378">5378</a><br /><a id="L5379" href="#L5379">5379</a><br /><a id="L5380" href="#L5380">5380</a><br /><a id="L5381" href="#L5381">5381</a><br /><a id="L5382" href="#L5382">5382</a><br /><a id="L5383" href="#L5383">5383</a><br /><a id="L5384" href="#L5384">5384</a><br /><a id="L5385" href="#L5385">5385</a><br /><a id="L5386" href="#L5386">5386</a><br /><a id="L5387" href="#L5387">5387</a><br /><a id="L5388" href="#L5388">5388</a><br /><a id="L5389" href="#L5389">5389</a><br /><a id="L5390" href="#L5390">5390</a><br /><a id="L5391" href="#L5391">5391</a><br /><a id="L5392" href="#L5392">5392</a><br /><a id="L5393" href="#L5393">5393</a><br /><a id="L5394" href="#L5394">5394</a><br /><a id="L5395" href="#L5395">5395</a><br /><a id="L5396" href="#L5396">5396</a><br /><a id="L5397" href="#L5397">5397</a><br /><a id="L5398" href="#L5398">5398</a><br /><a id="L5399" href="#L5399">5399</a><br /><a id="L5400" href="#L5400">5400</a><br /><a id="L5401" href="#L5401">5401</a><br /><a id="L5402" href="#L5402">5402</a><br /><a id="L5403" href="#L5403">5403</a><br /><a id="L5404" href="#L5404">5404</a><br /><a id="L5405" href="#L5405">5405</a><br /><a id="L5406" href="#L5406">5406</a><br /><a id="L5407" href="#L5407">5407</a><br /><a id="L5408" href="#L5408">5408</a><br /><a id="L5409" href="#L5409">5409</a><br /><a id="L5410" href="#L5410">5410</a><br /><a id="L5411" href="#L5411">5411</a><br /><a id="L5412" href="#L5412">5412</a><br /><a id="L5413" href="#L5413">5413</a><br /><a id="L5414" href="#L5414">5414</a><br /><a id="L5415" href="#L5415">5415</a><br /><a id="L5416" href="#L5416">5416</a><br /><a id="L5417" href="#L5417">5417</a><br /><a id="L5418" href="#L5418">5418</a><br /><a id="L5419" href="#L5419">5419</a><br /><a id="L5420" href="#L5420">5420</a><br /><a id="L5421" href="#L5421">5421</a><br /><a id="L5422" href="#L5422">5422</a><br /><a id="L5423" href="#L5423">5423</a><br /><a id="L5424" href="#L5424">5424</a><br /><a id="L5425" href="#L5425">5425</a><br /><a id="L5426" href="#L5426">5426</a><br /><a id="L5427" href="#L5427">5427</a><br /><a id="L5428" href="#L5428">5428</a><br /><a id="L5429" href="#L5429">5429</a><br /><a id="L5430" href="#L5430">5430</a><br /><a id="L5431" href="#L5431">5431</a><br /><a id="L5432" href="#L5432">5432</a><br /><a id="L5433" href="#L5433">5433</a><br /><a id="L5434" href="#L5434">5434</a><br /><a id="L5435" href="#L5435">5435</a><br /><a id="L5436" href="#L5436">5436</a><br /><a id="L5437" href="#L5437">5437</a><br /><a id="L5438" href="#L5438">5438</a><br /><a id="L5439" href="#L5439">5439</a><br /><a id="L5440" href="#L5440">5440</a><br /><a id="L5441" href="#L5441">5441</a><br /><a id="L5442" href="#L5442">5442</a><br /><a id="L5443" href="#L5443">5443</a><br /><a id="L5444" href="#L5444">5444</a><br /><a id="L5445" href="#L5445">5445</a><br /><a id="L5446" href="#L5446">5446</a><br /><a id="L5447" href="#L5447">5447</a><br /><a id="L5448" href="#L5448">5448</a><br /><a id="L5449" href="#L5449">5449</a><br /><a id="L5450" href="#L5450">5450</a><br /><a id="L5451" href="#L5451">5451</a><br /><a id="L5452" href="#L5452">5452</a><br /><a id="L5453" href="#L5453">5453</a><br /><a id="L5454" href="#L5454">5454</a><br /><a id="L5455" href="#L5455">5455</a><br /><a id="L5456" href="#L5456">5456</a><br /><a id="L5457" href="#L5457">5457</a><br /><a id="L5458" href="#L5458">5458</a><br /><a id="L5459" href="#L5459">5459</a><br /><a id="L5460" href="#L5460">5460</a><br /><a id="L5461" href="#L5461">5461</a><br /><a id="L5462" href="#L5462">5462</a><br /><a id="L5463" href="#L5463">5463</a><br /><a id="L5464" href="#L5464">5464</a><br /><a id="L5465" href="#L5465">5465</a><br /><a id="L5466" href="#L5466">5466</a><br /><a id="L5467" href="#L5467">5467</a><br /><a id="L5468" href="#L5468">5468</a><br /><a id="L5469" href="#L5469">5469</a><br /><a id="L5470" href="#L5470">5470</a><br /><a id="L5471" href="#L5471">5471</a><br /><a id="L5472" href="#L5472">5472</a><br /><a id="L5473" href="#L5473">5473</a><br /><a id="L5474" href="#L5474">5474</a><br /><a id="L5475" href="#L5475">5475</a><br /><a id="L5476" href="#L5476">5476</a><br /><a id="L5477" href="#L5477">5477</a><br /><a id="L5478" href="#L5478">5478</a><br /><a id="L5479" href="#L5479">5479</a><br /><a id="L5480" href="#L5480">5480</a><br /><a id="L5481" href="#L5481">5481</a><br /><a id="L5482" href="#L5482">5482</a><br /><a id="L5483" href="#L5483">5483</a><br /><a id="L5484" href="#L5484">5484</a><br /><a id="L5485" href="#L5485">5485</a><br /><a id="L5486" href="#L5486">5486</a><br /><a id="L5487" href="#L5487">5487</a><br /><a id="L5488" href="#L5488">5488</a><br /><a id="L5489" href="#L5489">5489</a><br /><a id="L5490" href="#L5490">5490</a><br /><a id="L5491" href="#L5491">5491</a><br /><a id="L5492" href="#L5492">5492</a><br /><a id="L5493" href="#L5493">5493</a><br /><a id="L5494" href="#L5494">5494</a><br /><a id="L5495" href="#L5495">5495</a><br /><a id="L5496" href="#L5496">5496</a><br /><a id="L5497" href="#L5497">5497</a><br /><a id="L5498" href="#L5498">5498</a><br /><a id="L5499" href="#L5499">5499</a><br /><a id="L5500" href="#L5500">5500</a><br /><a id="L5501" href="#L5501">5501</a><br /><a id="L5502" href="#L5502">5502</a><br /><a id="L5503" href="#L5503">5503</a><br /><a id="L5504" href="#L5504">5504</a><br /><a id="L5505" href="#L5505">5505</a><br /><a id="L5506" href="#L5506">5506</a><br /><a id="L5507" href="#L5507">5507</a><br /><a id="L5508" href="#L5508">5508</a><br /><a id="L5509" href="#L5509">5509</a><br /><a id="L5510" href="#L5510">5510</a><br /><a id="L5511" href="#L5511">5511</a><br /><a id="L5512" href="#L5512">5512</a><br /><a id="L5513" href="#L5513">5513</a><br /><a id="L5514" href="#L5514">5514</a><br /><a id="L5515" href="#L5515">5515</a><br /><a id="L5516" href="#L5516">5516</a><br /><a id="L5517" href="#L5517">5517</a><br /><a id="L5518" href="#L5518">5518</a><br /><a id="L5519" href="#L5519">5519</a><br /><a id="L5520" href="#L5520">5520</a><br /><a id="L5521" href="#L5521">5521</a><br /><a id="L5522" href="#L5522">5522</a><br /><a id="L5523" href="#L5523">5523</a><br /><a id="L5524" href="#L5524">5524</a><br /><a id="L5525" href="#L5525">5525</a><br /><a id="L5526" href="#L5526">5526</a><br /><a id="L5527" href="#L5527">5527</a><br /><a id="L5528" href="#L5528">5528</a><br /><a id="L5529" href="#L5529">5529</a><br /><a id="L5530" href="#L5530">5530</a><br /><a id="L5531" href="#L5531">5531</a><br /><a id="L5532" href="#L5532">5532</a><br /><a id="L5533" href="#L5533">5533</a><br /><a id="L5534" href="#L5534">5534</a><br /><a id="L5535" href="#L5535">5535</a><br /><a id="L5536" href="#L5536">5536</a><br /><a id="L5537" href="#L5537">5537</a><br /><a id="L5538" href="#L5538">5538</a><br /><a id="L5539" href="#L5539">5539</a><br /><a id="L5540" href="#L5540">5540</a><br /><a id="L5541" href="#L5541">5541</a><br /><a id="L5542" href="#L5542">5542</a><br /><a id="L5543" href="#L5543">5543</a><br /><a id="L5544" href="#L5544">5544</a><br /><a id="L5545" href="#L5545">5545</a><br /><a id="L5546" href="#L5546">5546</a><br /><a id="L5547" href="#L5547">5547</a><br /><a id="L5548" href="#L5548">5548</a><br /><a id="L5549" href="#L5549">5549</a><br /><a id="L5550" href="#L5550">5550</a><br /><a id="L5551" href="#L5551">5551</a><br /><a id="L5552" href="#L5552">5552</a><br /><a id="L5553" href="#L5553">5553</a><br /><a id="L5554" href="#L5554">5554</a><br /><a id="L5555" href="#L5555">5555</a><br /><a id="L5556" href="#L5556">5556</a><br /><a id="L5557" href="#L5557">5557</a><br /><a id="L5558" href="#L5558">5558</a><br /><a id="L5559" href="#L5559">5559</a><br /><a id="L5560" href="#L5560">5560</a><br /><a id="L5561" href="#L5561">5561</a><br /><a id="L5562" href="#L5562">5562</a><br /><a id="L5563" href="#L5563">5563</a><br /><a id="L5564" href="#L5564">5564</a><br /><a id="L5565" href="#L5565">5565</a><br /><a id="L5566" href="#L5566">5566</a><br /><a id="L5567" href="#L5567">5567</a><br /><a id="L5568" href="#L5568">5568</a><br /><a id="L5569" href="#L5569">5569</a><br /><a id="L5570" href="#L5570">5570</a><br /><a id="L5571" href="#L5571">5571</a><br /><a id="L5572" href="#L5572">5572</a><br /><a id="L5573" href="#L5573">5573</a><br /><a id="L5574" href="#L5574">5574</a><br /><a id="L5575" href="#L5575">5575</a><br /><a id="L5576" href="#L5576">5576</a><br /><a id="L5577" href="#L5577">5577</a><br /><a id="L5578" href="#L5578">5578</a><br /><a id="L5579" href="#L5579">5579</a><br /><a id="L5580" href="#L5580">5580</a><br /><a id="L5581" href="#L5581">5581</a><br /><a id="L5582" href="#L5582">5582</a><br /><a id="L5583" href="#L5583">5583</a><br /><a id="L5584" href="#L5584">5584</a><br /><a id="L5585" href="#L5585">5585</a><br /><a id="L5586" href="#L5586">5586</a><br /><a id="L5587" href="#L5587">5587</a><br /><a id="L5588" href="#L5588">5588</a><br /><a id="L5589" href="#L5589">5589</a><br /><a id="L5590" href="#L5590">5590</a><br /><a id="L5591" href="#L5591">5591</a><br /><a id="L5592" href="#L5592">5592</a><br /><a id="L5593" href="#L5593">5593</a><br /><a id="L5594" href="#L5594">5594</a><br /><a id="L5595" href="#L5595">5595</a><br /><a id="L5596" href="#L5596">5596</a><br /><a id="L5597" href="#L5597">5597</a><br /><a id="L5598" href="#L5598">5598</a><br /><a id="L5599" href="#L5599">5599</a><br /><a id="L5600" href="#L5600">5600</a><br /><a id="L5601" href="#L5601">5601</a><br /><a id="L5602" href="#L5602">5602</a><br /><a id="L5603" href="#L5603">5603</a><br /><a id="L5604" href="#L5604">5604</a><br /><a id="L5605" href="#L5605">5605</a><br /><a id="L5606" href="#L5606">5606</a><br /><a id="L5607" href="#L5607">5607</a><br /><a id="L5608" href="#L5608">5608</a><br /><a id="L5609" href="#L5609">5609</a><br /><a id="L5610" href="#L5610">5610</a><br /><a id="L5611" href="#L5611">5611</a><br /><a id="L5612" href="#L5612">5612</a><br /><a id="L5613" href="#L5613">5613</a><br /><a id="L5614" href="#L5614">5614</a><br /><a id="L5615" href="#L5615">5615</a><br /><a id="L5616" href="#L5616">5616</a><br /><a id="L5617" href="#L5617">5617</a><br /><a id="L5618" href="#L5618">5618</a><br /><a id="L5619" href="#L5619">5619</a><br /><a id="L5620" href="#L5620">5620</a><br /><a id="L5621" href="#L5621">5621</a><br /><a id="L5622" href="#L5622">5622</a><br /><a id="L5623" href="#L5623">5623</a><br /><a id="L5624" href="#L5624">5624</a><br /><a id="L5625" href="#L5625">5625</a><br /><a id="L5626" href="#L5626">5626</a><br /><a id="L5627" href="#L5627">5627</a><br /><a id="L5628" href="#L5628">5628</a><br /><a id="L5629" href="#L5629">5629</a><br /><a id="L5630" href="#L5630">5630</a><br /><a id="L5631" href="#L5631">5631</a><br /><a id="L5632" href="#L5632">5632</a><br /><a id="L5633" href="#L5633">5633</a><br /><a id="L5634" href="#L5634">5634</a><br /><a id="L5635" href="#L5635">5635</a><br /><a id="L5636" href="#L5636">5636</a><br /><a id="L5637" href="#L5637">5637</a><br /><a id="L5638" href="#L5638">5638</a><br /><a id="L5639" href="#L5639">5639</a><br /><a id="L5640" href="#L5640">5640</a><br /><a id="L5641" href="#L5641">5641</a><br /><a id="L5642" href="#L5642">5642</a><br /><a id="L5643" href="#L5643">5643</a><br /><a id="L5644" href="#L5644">5644</a><br /><a id="L5645" href="#L5645">5645</a><br /><a id="L5646" href="#L5646">5646</a><br /><a id="L5647" href="#L5647">5647</a><br /><a id="L5648" href="#L5648">5648</a><br /><a id="L5649" href="#L5649">5649</a><br /><a id="L5650" href="#L5650">5650</a><br /><a id="L5651" href="#L5651">5651</a><br /><a id="L5652" href="#L5652">5652</a><br /><a id="L5653" href="#L5653">5653</a><br /><a id="L5654" href="#L5654">5654</a><br /><a id="L5655" href="#L5655">5655</a><br /><a id="L5656" href="#L5656">5656</a><br /><a id="L5657" href="#L5657">5657</a><br /><a id="L5658" href="#L5658">5658</a><br /><a id="L5659" href="#L5659">5659</a><br /><a id="L5660" href="#L5660">5660</a><br /><a id="L5661" href="#L5661">5661</a><br /><a id="L5662" href="#L5662">5662</a><br /><a id="L5663" href="#L5663">5663</a><br /><a id="L5664" href="#L5664">5664</a><br /><a id="L5665" href="#L5665">5665</a><br /><a id="L5666" href="#L5666">5666</a><br /><a id="L5667" href="#L5667">5667</a><br /><a id="L5668" href="#L5668">5668</a><br /><a id="L5669" href="#L5669">5669</a><br /><a id="L5670" href="#L5670">5670</a><br /><a id="L5671" href="#L5671">5671</a><br /><a id="L5672" href="#L5672">5672</a><br /><a id="L5673" href="#L5673">5673</a><br /><a id="L5674" href="#L5674">5674</a><br /><a id="L5675" href="#L5675">5675</a><br /><a id="L5676" href="#L5676">5676</a><br /><a id="L5677" href="#L5677">5677</a><br /><a id="L5678" href="#L5678">5678</a><br /><a id="L5679" href="#L5679">5679</a><br /><a id="L5680" href="#L5680">5680</a><br /><a id="L5681" href="#L5681">5681</a><br /><a id="L5682" href="#L5682">5682</a><br /><a id="L5683" href="#L5683">5683</a><br /><a id="L5684" href="#L5684">5684</a><br /><a id="L5685" href="#L5685">5685</a><br /><a id="L5686" href="#L5686">5686</a><br /><a id="L5687" href="#L5687">5687</a><br /><a id="L5688" href="#L5688">5688</a><br /><a id="L5689" href="#L5689">5689</a><br /><a id="L5690" href="#L5690">5690</a><br /><a id="L5691" href="#L5691">5691</a><br /><a id="L5692" href="#L5692">5692</a><br /><a id="L5693" href="#L5693">5693</a><br /><a id="L5694" href="#L5694">5694</a><br /><a id="L5695" href="#L5695">5695</a><br /><a id="L5696" href="#L5696">5696</a><br /><a id="L5697" href="#L5697">5697</a><br /><a id="L5698" href="#L5698">5698</a><br /><a id="L5699" href="#L5699">5699</a><br /><a id="L5700" href="#L5700">5700</a><br /><a id="L5701" href="#L5701">5701</a><br /><a id="L5702" href="#L5702">5702</a><br /><a id="L5703" href="#L5703">5703</a><br /><a id="L5704" href="#L5704">5704</a><br /><a id="L5705" href="#L5705">5705</a><br /><a id="L5706" href="#L5706">5706</a><br /><a id="L5707" href="#L5707">5707</a><br /><a id="L5708" href="#L5708">5708</a><br /><a id="L5709" href="#L5709">5709</a><br /><a id="L5710" href="#L5710">5710</a><br /><a id="L5711" href="#L5711">5711</a><br /><a id="L5712" href="#L5712">5712</a><br /><a id="L5713" href="#L5713">5713</a><br /><a id="L5714" href="#L5714">5714</a><br /><a id="L5715" href="#L5715">5715</a><br /><a id="L5716" href="#L5716">5716</a><br /><a id="L5717" href="#L5717">5717</a><br /><a id="L5718" href="#L5718">5718</a><br /><a id="L5719" href="#L5719">5719</a><br /><a id="L5720" href="#L5720">5720</a><br /><a id="L5721" href="#L5721">5721</a><br /><a id="L5722" href="#L5722">5722</a><br /><a id="L5723" href="#L5723">5723</a><br /><a id="L5724" href="#L5724">5724</a><br /><a id="L5725" href="#L5725">5725</a><br /><a id="L5726" href="#L5726">5726</a><br /><a id="L5727" href="#L5727">5727</a><br /><a id="L5728" href="#L5728">5728</a><br /><a id="L5729" href="#L5729">5729</a><br /><a id="L5730" href="#L5730">5730</a><br /><a id="L5731" href="#L5731">5731</a><br /><a id="L5732" href="#L5732">5732</a><br /><a id="L5733" href="#L5733">5733</a><br /><a id="L5734" href="#L5734">5734</a><br /><a id="L5735" href="#L5735">5735</a><br /><a id="L5736" href="#L5736">5736</a><br /><a id="L5737" href="#L5737">5737</a><br /><a id="L5738" href="#L5738">5738</a><br /><a id="L5739" href="#L5739">5739</a><br /><a id="L5740" href="#L5740">5740</a><br /><a id="L5741" href="#L5741">5741</a><br /><a id="L5742" href="#L5742">5742</a><br /><a id="L5743" href="#L5743">5743</a><br /><a id="L5744" href="#L5744">5744</a><br /><a id="L5745" href="#L5745">5745</a><br /><a id="L5746" href="#L5746">5746</a><br /><a id="L5747" href="#L5747">5747</a><br /><a id="L5748" href="#L5748">5748</a><br /><a id="L5749" href="#L5749">5749</a><br /><a id="L5750" href="#L5750">5750</a><br /><a id="L5751" href="#L5751">5751</a><br /><a id="L5752" href="#L5752">5752</a><br /><a id="L5753" href="#L5753">5753</a><br /><a id="L5754" href="#L5754">5754</a><br /><a id="L5755" href="#L5755">5755</a><br /><a id="L5756" href="#L5756">5756</a><br /><a id="L5757" href="#L5757">5757</a><br /><a id="L5758" href="#L5758">5758</a><br /><a id="L5759" href="#L5759">5759</a><br /><a id="L5760" href="#L5760">5760</a><br /><a id="L5761" href="#L5761">5761</a><br /><a id="L5762" href="#L5762">5762</a><br /><a id="L5763" href="#L5763">5763</a><br /><a id="L5764" href="#L5764">5764</a><br /><a id="L5765" href="#L5765">5765</a><br /><a id="L5766" href="#L5766">5766</a><br /><a id="L5767" href="#L5767">5767</a><br /><a id="L5768" href="#L5768">5768</a><br /><a id="L5769" href="#L5769">5769</a><br /><a id="L5770" href="#L5770">5770</a><br /><a id="L5771" href="#L5771">5771</a><br /><a id="L5772" href="#L5772">5772</a><br /><a id="L5773" href="#L5773">5773</a><br /><a id="L5774" href="#L5774">5774</a><br /><a id="L5775" href="#L5775">5775</a><br /><a id="L5776" href="#L5776">5776</a><br /><a id="L5777" href="#L5777">5777</a><br /><a id="L5778" href="#L5778">5778</a><br /><a id="L5779" href="#L5779">5779</a><br /><a id="L5780" href="#L5780">5780</a><br /><a id="L5781" href="#L5781">5781</a><br /><a id="L5782" href="#L5782">5782</a><br /><a id="L5783" href="#L5783">5783</a><br /><a id="L5784" href="#L5784">5784</a><br /><a id="L5785" href="#L5785">5785</a><br /><a id="L5786" href="#L5786">5786</a><br /><a id="L5787" href="#L5787">5787</a><br /><a id="L5788" href="#L5788">5788</a><br /><a id="L5789" href="#L5789">5789</a><br /><a id="L5790" href="#L5790">5790</a><br /><a id="L5791" href="#L5791">5791</a><br /><a id="L5792" href="#L5792">5792</a><br /><a id="L5793" href="#L5793">5793</a><br /><a id="L5794" href="#L5794">5794</a><br /><a id="L5795" href="#L5795">5795</a><br /><a id="L5796" href="#L5796">5796</a><br /><a id="L5797" href="#L5797">5797</a><br /><a id="L5798" href="#L5798">5798</a><br /><a id="L5799" href="#L5799">5799</a><br /><a id="L5800" href="#L5800">5800</a><br /><a id="L5801" href="#L5801">5801</a><br /><a id="L5802" href="#L5802">5802</a><br /><a id="L5803" href="#L5803">5803</a><br /><a id="L5804" href="#L5804">5804</a><br /><a id="L5805" href="#L5805">5805</a><br /><a id="L5806" href="#L5806">5806</a><br /><a id="L5807" href="#L5807">5807</a><br /><a id="L5808" href="#L5808">5808</a><br /><a id="L5809" href="#L5809">5809</a><br /><a id="L5810" href="#L5810">5810</a><br /><a id="L5811" href="#L5811">5811</a><br /><a id="L5812" href="#L5812">5812</a><br /><a id="L5813" href="#L5813">5813</a><br /><a id="L5814" href="#L5814">5814</a><br /><a id="L5815" href="#L5815">5815</a><br /><a id="L5816" href="#L5816">5816</a><br /><a id="L5817" href="#L5817">5817</a><br /><a id="L5818" href="#L5818">5818</a><br /><a id="L5819" href="#L5819">5819</a><br /><a id="L5820" href="#L5820">5820</a><br /><a id="L5821" href="#L5821">5821</a><br /><a id="L5822" href="#L5822">5822</a><br /><a id="L5823" href="#L5823">5823</a><br /><a id="L5824" href="#L5824">5824</a><br /><a id="L5825" href="#L5825">5825</a><br /><a id="L5826" href="#L5826">5826</a><br /><a id="L5827" href="#L5827">5827</a><br /><a id="L5828" href="#L5828">5828</a><br /><a id="L5829" href="#L5829">5829</a><br /><a id="L5830" href="#L5830">5830</a><br /><a id="L5831" href="#L5831">5831</a><br /><a id="L5832" href="#L5832">5832</a><br /><a id="L5833" href="#L5833">5833</a><br /><a id="L5834" href="#L5834">5834</a><br /><a id="L5835" href="#L5835">5835</a><br /><a id="L5836" href="#L5836">5836</a><br /><a id="L5837" href="#L5837">5837</a><br /><a id="L5838" href="#L5838">5838</a><br /><a id="L5839" href="#L5839">5839</a><br /><a id="L5840" href="#L5840">5840</a><br /><a id="L5841" href="#L5841">5841</a><br /><a id="L5842" href="#L5842">5842</a><br /><a id="L5843" href="#L5843">5843</a><br /><a id="L5844" href="#L5844">5844</a><br /><a id="L5845" href="#L5845">5845</a><br /><a id="L5846" href="#L5846">5846</a><br /><a id="L5847" href="#L5847">5847</a><br /><a id="L5848" href="#L5848">5848</a><br /><a id="L5849" href="#L5849">5849</a><br /><a id="L5850" href="#L5850">5850</a><br /><a id="L5851" href="#L5851">5851</a><br /><a id="L5852" href="#L5852">5852</a><br /><a id="L5853" href="#L5853">5853</a><br /><a id="L5854" href="#L5854">5854</a><br /><a id="L5855" href="#L5855">5855</a><br /><a id="L5856" href="#L5856">5856</a><br /><a id="L5857" href="#L5857">5857</a><br /><a id="L5858" href="#L5858">5858</a><br /><a id="L5859" href="#L5859">5859</a><br /><a id="L5860" href="#L5860">5860</a><br /><a id="L5861" href="#L5861">5861</a><br /><a id="L5862" href="#L5862">5862</a><br /><a id="L5863" href="#L5863">5863</a><br /><a id="L5864" href="#L5864">5864</a><br /><a id="L5865" href="#L5865">5865</a><br /><a id="L5866" href="#L5866">5866</a><br /><a id="L5867" href="#L5867">5867</a><br /><a id="L5868" href="#L5868">5868</a><br /><a id="L5869" href="#L5869">5869</a><br /><a id="L5870" href="#L5870">5870</a><br /><a id="L5871" href="#L5871">5871</a><br /><a id="L5872" href="#L5872">5872</a><br /><a id="L5873" href="#L5873">5873</a><br /><a id="L5874" href="#L5874">5874</a><br /><a id="L5875" href="#L5875">5875</a><br /><a id="L5876" href="#L5876">5876</a><br /><a id="L5877" href="#L5877">5877</a><br /><a id="L5878" href="#L5878">5878</a><br /><a id="L5879" href="#L5879">5879</a><br /><a id="L5880" href="#L5880">5880</a><br /><a id="L5881" href="#L5881">5881</a><br /><a id="L5882" href="#L5882">5882</a><br /><a id="L5883" href="#L5883">5883</a><br /><a id="L5884" href="#L5884">5884</a><br /><a id="L5885" href="#L5885">5885</a><br /><a id="L5886" href="#L5886">5886</a><br /><a id="L5887" href="#L5887">5887</a><br /><a id="L5888" href="#L5888">5888</a><br /><a id="L5889" href="#L5889">5889</a><br /><a id="L5890" href="#L5890">5890</a><br /><a id="L5891" href="#L5891">5891</a><br /><a id="L5892" href="#L5892">5892</a><br /><a id="L5893" href="#L5893">5893</a><br /><a id="L5894" href="#L5894">5894</a><br /><a id="L5895" href="#L5895">5895</a><br /><a id="L5896" href="#L5896">5896</a><br /><a id="L5897" href="#L5897">5897</a><br /><a id="L5898" href="#L5898">5898</a><br /><a id="L5899" href="#L5899">5899</a><br /><a id="L5900" href="#L5900">5900</a><br /><a id="L5901" href="#L5901">5901</a><br /><a id="L5902" href="#L5902">5902</a><br /><a id="L5903" href="#L5903">5903</a><br /><a id="L5904" href="#L5904">5904</a><br /><a id="L5905" href="#L5905">5905</a><br /><a id="L5906" href="#L5906">5906</a><br /><a id="L5907" href="#L5907">5907</a><br /><a id="L5908" href="#L5908">5908</a><br /><a id="L5909" href="#L5909">5909</a><br /><a id="L5910" href="#L5910">5910</a><br /><a id="L5911" href="#L5911">5911</a><br /><a id="L5912" href="#L5912">5912</a><br /><a id="L5913" href="#L5913">5913</a><br /><a id="L5914" href="#L5914">5914</a><br /><a id="L5915" href="#L5915">5915</a><br /><a id="L5916" href="#L5916">5916</a><br /><a id="L5917" href="#L5917">5917</a><br /><a id="L5918" href="#L5918">5918</a><br /><a id="L5919" href="#L5919">5919</a><br /><a id="L5920" href="#L5920">5920</a><br /><a id="L5921" href="#L5921">5921</a><br /><a id="L5922" href="#L5922">5922</a><br /><a id="L5923" href="#L5923">5923</a><br /><a id="L5924" href="#L5924">5924</a><br /><a id="L5925" href="#L5925">5925</a><br /><a id="L5926" href="#L5926">5926</a><br /><a id="L5927" href="#L5927">5927</a><br /><a id="L5928" href="#L5928">5928</a><br /><a id="L5929" href="#L5929">5929</a><br /><a id="L5930" href="#L5930">5930</a><br /><a id="L5931" href="#L5931">5931</a><br /><a id="L5932" href="#L5932">5932</a><br /><a id="L5933" href="#L5933">5933</a><br /><a id="L5934" href="#L5934">5934</a><br /><a id="L5935" href="#L5935">5935</a><br /><a id="L5936" href="#L5936">5936</a><br /><a id="L5937" href="#L5937">5937</a><br /><a id="L5938" href="#L5938">5938</a><br /><a id="L5939" href="#L5939">5939</a><br /><a id="L5940" href="#L5940">5940</a><br /><a id="L5941" href="#L5941">5941</a><br /><a id="L5942" href="#L5942">5942</a><br /><a id="L5943" href="#L5943">5943</a><br /><a id="L5944" href="#L5944">5944</a><br /><a id="L5945" href="#L5945">5945</a><br /><a id="L5946" href="#L5946">5946</a><br /><a id="L5947" href="#L5947">5947</a><br /><a id="L5948" href="#L5948">5948</a><br /><a id="L5949" href="#L5949">5949</a><br /><a id="L5950" href="#L5950">5950</a><br /><a id="L5951" href="#L5951">5951</a><br /><a id="L5952" href="#L5952">5952</a><br /><a id="L5953" href="#L5953">5953</a><br /><a id="L5954" href="#L5954">5954</a><br /><a id="L5955" href="#L5955">5955</a><br /><a id="L5956" href="#L5956">5956</a><br /><a id="L5957" href="#L5957">5957</a><br /><a id="L5958" href="#L5958">5958</a><br /><a id="L5959" href="#L5959">5959</a><br /><a id="L5960" href="#L5960">5960</a><br /><a id="L5961" href="#L5961">5961</a><br /><a id="L5962" href="#L5962">5962</a><br /><a id="L5963" href="#L5963">5963</a><br /><a id="L5964" href="#L5964">5964</a><br /><a id="L5965" href="#L5965">5965</a><br /><a id="L5966" href="#L5966">5966</a><br /><a id="L5967" href="#L5967">5967</a><br /><a id="L5968" href="#L5968">5968</a><br /><a id="L5969" href="#L5969">5969</a><br /><a id="L5970" href="#L5970">5970</a><br /><a id="L5971" href="#L5971">5971</a><br /><a id="L5972" href="#L5972">5972</a><br /><a id="L5973" href="#L5973">5973</a><br /><a id="L5974" href="#L5974">5974</a><br /><a id="L5975" href="#L5975">5975</a><br /><a id="L5976" href="#L5976">5976</a><br /><a id="L5977" href="#L5977">5977</a><br /><a id="L5978" href="#L5978">5978</a><br /><a id="L5979" href="#L5979">5979</a><br /><a id="L5980" href="#L5980">5980</a><br /><a id="L5981" href="#L5981">5981</a><br /><a id="L5982" href="#L5982">5982</a><br /><a id="L5983" href="#L5983">5983</a><br /><a id="L5984" href="#L5984">5984</a><br /><a id="L5985" href="#L5985">5985</a><br /><a id="L5986" href="#L5986">5986</a><br /><a id="L5987" href="#L5987">5987</a><br /><a id="L5988" href="#L5988">5988</a><br /><a id="L5989" href="#L5989">5989</a><br /><a id="L5990" href="#L5990">5990</a><br /><a id="L5991" href="#L5991">5991</a><br /><a id="L5992" href="#L5992">5992</a><br /><a id="L5993" href="#L5993">5993</a><br /><a id="L5994" href="#L5994">5994</a><br /><a id="L5995" href="#L5995">5995</a><br /><a id="L5996" href="#L5996">5996</a><br /><a id="L5997" href="#L5997">5997</a><br /><a id="L5998" href="#L5998">5998</a><br /><a id="L5999" href="#L5999">5999</a><br /><a id="L6000" href="#L6000">6000</a><br /><a id="L6001" href="#L6001">6001</a><br /><a id="L6002" href="#L6002">6002</a><br /><a id="L6003" href="#L6003">6003</a><br /><a id="L6004" href="#L6004">6004</a><br /><a id="L6005" href="#L6005">6005</a><br /><a id="L6006" href="#L6006">6006</a><br /><a id="L6007" href="#L6007">6007</a><br /><a id="L6008" href="#L6008">6008</a><br /><a id="L6009" href="#L6009">6009</a><br /><a id="L6010" href="#L6010">6010</a><br /><a id="L6011" href="#L6011">6011</a><br /><a id="L6012" href="#L6012">6012</a><br /><a id="L6013" href="#L6013">6013</a><br /><a id="L6014" href="#L6014">6014</a><br /><a id="L6015" href="#L6015">6015</a><br /><a id="L6016" href="#L6016">6016</a><br /><a id="L6017" href="#L6017">6017</a><br /><a id="L6018" href="#L6018">6018</a><br /><a id="L6019" href="#L6019">6019</a><br /><a id="L6020" href="#L6020">6020</a><br /><a id="L6021" href="#L6021">6021</a><br /><a id="L6022" href="#L6022">6022</a><br /><a id="L6023" href="#L6023">6023</a><br /><a id="L6024" href="#L6024">6024</a><br /><a id="L6025" href="#L6025">6025</a><br /><a id="L6026" href="#L6026">6026</a><br /><a id="L6027" href="#L6027">6027</a><br /><a id="L6028" href="#L6028">6028</a><br /><a id="L6029" href="#L6029">6029</a><br /><a id="L6030" href="#L6030">6030</a><br /><a id="L6031" href="#L6031">6031</a><br /><a id="L6032" href="#L6032">6032</a><br /><a id="L6033" href="#L6033">6033</a><br /><a id="L6034" href="#L6034">6034</a><br /><a id="L6035" href="#L6035">6035</a><br /><a id="L6036" href="#L6036">6036</a><br /><a id="L6037" href="#L6037">6037</a><br /><a id="L6038" href="#L6038">6038</a><br /><a id="L6039" href="#L6039">6039</a><br /><a id="L6040" href="#L6040">6040</a><br /><a id="L6041" href="#L6041">6041</a><br /><a id="L6042" href="#L6042">6042</a><br /><a id="L6043" href="#L6043">6043</a><br /><a id="L6044" href="#L6044">6044</a><br /><a id="L6045" href="#L6045">6045</a><br /><a id="L6046" href="#L6046">6046</a><br /><a id="L6047" href="#L6047">6047</a><br /><a id="L6048" href="#L6048">6048</a><br /><a id="L6049" href="#L6049">6049</a><br /><a id="L6050" href="#L6050">6050</a><br /><a id="L6051" href="#L6051">6051</a><br /><a id="L6052" href="#L6052">6052</a><br /><a id="L6053" href="#L6053">6053</a><br /><a id="L6054" href="#L6054">6054</a><br /><a id="L6055" href="#L6055">6055</a><br /><a id="L6056" href="#L6056">6056</a><br /><a id="L6057" href="#L6057">6057</a><br /><a id="L6058" href="#L6058">6058</a><br /><a id="L6059" href="#L6059">6059</a><br /><a id="L6060" href="#L6060">6060</a><br /><a id="L6061" href="#L6061">6061</a><br /><a id="L6062" href="#L6062">6062</a><br /><a id="L6063" href="#L6063">6063</a><br /><a id="L6064" href="#L6064">6064</a><br /><a id="L6065" href="#L6065">6065</a><br /><a id="L6066" href="#L6066">6066</a><br /><a id="L6067" href="#L6067">6067</a><br /><a id="L6068" href="#L6068">6068</a><br /><a id="L6069" href="#L6069">6069</a><br /><a id="L6070" href="#L6070">6070</a><br /><a id="L6071" href="#L6071">6071</a><br /><a id="L6072" href="#L6072">6072</a><br /><a id="L6073" href="#L6073">6073</a><br /><a id="L6074" href="#L6074">6074</a><br /><a id="L6075" href="#L6075">6075</a><br /><a id="L6076" href="#L6076">6076</a><br /><a id="L6077" href="#L6077">6077</a><br /><a id="L6078" href="#L6078">6078</a><br /><a id="L6079" href="#L6079">6079</a><br /><a id="L6080" href="#L6080">6080</a><br /><a id="L6081" href="#L6081">6081</a><br /><a id="L6082" href="#L6082">6082</a><br /><a id="L6083" href="#L6083">6083</a><br /><a id="L6084" href="#L6084">6084</a><br /><a id="L6085" href="#L6085">6085</a><br /><a id="L6086" href="#L6086">6086</a><br /><a id="L6087" href="#L6087">6087</a><br /><a id="L6088" href="#L6088">6088</a><br /><a id="L6089" href="#L6089">6089</a><br /><a id="L6090" href="#L6090">6090</a><br /><a id="L6091" href="#L6091">6091</a><br /><a id="L6092" href="#L6092">6092</a><br /><a id="L6093" href="#L6093">6093</a><br /><a id="L6094" href="#L6094">6094</a><br /><a id="L6095" href="#L6095">6095</a><br /><a id="L6096" href="#L6096">6096</a><br /><a id="L6097" href="#L6097">6097</a><br /><a id="L6098" href="#L6098">6098</a><br /><a id="L6099" href="#L6099">6099</a><br /><a id="L6100" href="#L6100">6100</a><br /><a id="L6101" href="#L6101">6101</a><br /><a id="L6102" href="#L6102">6102</a><br /><a id="L6103" href="#L6103">6103</a><br /><a id="L6104" href="#L6104">6104</a><br /><a id="L6105" href="#L6105">6105</a><br /><a id="L6106" href="#L6106">6106</a><br /><a id="L6107" href="#L6107">6107</a><br /><a id="L6108" href="#L6108">6108</a><br /><a id="L6109" href="#L6109">6109</a><br /><a id="L6110" href="#L6110">6110</a><br /><a id="L6111" href="#L6111">6111</a><br /><a id="L6112" href="#L6112">6112</a><br /><a id="L6113" href="#L6113">6113</a><br /><a id="L6114" href="#L6114">6114</a><br /><a id="L6115" href="#L6115">6115</a><br /><a id="L6116" href="#L6116">6116</a><br /><a id="L6117" href="#L6117">6117</a><br /><a id="L6118" href="#L6118">6118</a><br /><a id="L6119" href="#L6119">6119</a><br /><a id="L6120" href="#L6120">6120</a><br /><a id="L6121" href="#L6121">6121</a><br /><a id="L6122" href="#L6122">6122</a><br /><a id="L6123" href="#L6123">6123</a><br /><a id="L6124" href="#L6124">6124</a><br /><a id="L6125" href="#L6125">6125</a><br /><a id="L6126" href="#L6126">6126</a><br /><a id="L6127" href="#L6127">6127</a><br /><a id="L6128" href="#L6128">6128</a><br /><a id="L6129" href="#L6129">6129</a><br /><a id="L6130" href="#L6130">6130</a><br /><a id="L6131" href="#L6131">6131</a><br /><a id="L6132" href="#L6132">6132</a><br /><a id="L6133" href="#L6133">6133</a><br /><a id="L6134" href="#L6134">6134</a><br /><a id="L6135" href="#L6135">6135</a><br /><a id="L6136" href="#L6136">6136</a><br /><a id="L6137" href="#L6137">6137</a><br /><a id="L6138" href="#L6138">6138</a><br /><a id="L6139" href="#L6139">6139</a><br /><a id="L6140" href="#L6140">6140</a><br /><a id="L6141" href="#L6141">6141</a><br /><a id="L6142" href="#L6142">6142</a><br /><a id="L6143" href="#L6143">6143</a><br /><a id="L6144" href="#L6144">6144</a><br /><a id="L6145" href="#L6145">6145</a><br /><a id="L6146" href="#L6146">6146</a><br /><a id="L6147" href="#L6147">6147</a><br /><a id="L6148" href="#L6148">6148</a><br /><a id="L6149" href="#L6149">6149</a><br /><a id="L6150" href="#L6150">6150</a><br /><a id="L6151" href="#L6151">6151</a><br /><a id="L6152" href="#L6152">6152</a><br /><a id="L6153" href="#L6153">6153</a><br /><a id="L6154" href="#L6154">6154</a><br /><a id="L6155" href="#L6155">6155</a><br /><a id="L6156" href="#L6156">6156</a><br /><a id="L6157" href="#L6157">6157</a><br /><a id="L6158" href="#L6158">6158</a><br /><a id="L6159" href="#L6159">6159</a><br /><a id="L6160" href="#L6160">6160</a><br /><a id="L6161" href="#L6161">6161</a><br /><a id="L6162" href="#L6162">6162</a><br /><a id="L6163" href="#L6163">6163</a><br /><a id="L6164" href="#L6164">6164</a><br /><a id="L6165" href="#L6165">6165</a><br /><a id="L6166" href="#L6166">6166</a><br /><a id="L6167" href="#L6167">6167</a><br /><a id="L6168" href="#L6168">6168</a><br /><a id="L6169" href="#L6169">6169</a><br /><a id="L6170" href="#L6170">6170</a><br /><a id="L6171" href="#L6171">6171</a><br /><a id="L6172" href="#L6172">6172</a><br /><a id="L6173" href="#L6173">6173</a><br /><a id="L6174" href="#L6174">6174</a><br /><a id="L6175" href="#L6175">6175</a><br /><a id="L6176" href="#L6176">6176</a><br /><a id="L6177" href="#L6177">6177</a><br /><a id="L6178" href="#L6178">6178</a><br /><a id="L6179" href="#L6179">6179</a><br /><a id="L6180" href="#L6180">6180</a><br /><a id="L6181" href="#L6181">6181</a><br /><a id="L6182" href="#L6182">6182</a><br /><a id="L6183" href="#L6183">6183</a><br /><a id="L6184" href="#L6184">6184</a><br /><a id="L6185" href="#L6185">6185</a><br /><a id="L6186" href="#L6186">6186</a><br /><a id="L6187" href="#L6187">6187</a><br /><a id="L6188" href="#L6188">6188</a><br /><a id="L6189" href="#L6189">6189</a><br /><a id="L6190" href="#L6190">6190</a><br /><a id="L6191" href="#L6191">6191</a><br /><a id="L6192" href="#L6192">6192</a><br /><a id="L6193" href="#L6193">6193</a><br /><a id="L6194" href="#L6194">6194</a><br /><a id="L6195" href="#L6195">6195</a><br /><a id="L6196" href="#L6196">6196</a><br /><a id="L6197" href="#L6197">6197</a><br /><a id="L6198" href="#L6198">6198</a><br /><a id="L6199" href="#L6199">6199</a><br /><a id="L6200" href="#L6200">6200</a><br /><a id="L6201" href="#L6201">6201</a><br /><a id="L6202" href="#L6202">6202</a><br /><a id="L6203" href="#L6203">6203</a><br /><a id="L6204" href="#L6204">6204</a><br /><a id="L6205" href="#L6205">6205</a><br /><a id="L6206" href="#L6206">6206</a><br /><a id="L6207" href="#L6207">6207</a><br /><a id="L6208" href="#L6208">6208</a><br /><a id="L6209" href="#L6209">6209</a><br /><a id="L6210" href="#L6210">6210</a><br /><a id="L6211" href="#L6211">6211</a><br /><a id="L6212" href="#L6212">6212</a><br /><a id="L6213" href="#L6213">6213</a><br /><a id="L6214" href="#L6214">6214</a><br /><a id="L6215" href="#L6215">6215</a><br /><a id="L6216" href="#L6216">6216</a><br /><a id="L6217" href="#L6217">6217</a><br /><a id="L6218" href="#L6218">6218</a><br /><a id="L6219" href="#L6219">6219</a><br /><a id="L6220" href="#L6220">6220</a><br /><a id="L6221" href="#L6221">6221</a><br /><a id="L6222" href="#L6222">6222</a><br /><a id="L6223" href="#L6223">6223</a><br /><a id="L6224" href="#L6224">6224</a><br /><a id="L6225" href="#L6225">6225</a><br /><a id="L6226" href="#L6226">6226</a><br /><a id="L6227" href="#L6227">6227</a><br /><a id="L6228" href="#L6228">6228</a><br /><a id="L6229" href="#L6229">6229</a><br /><a id="L6230" href="#L6230">6230</a><br /><a id="L6231" href="#L6231">6231</a><br /><a id="L6232" href="#L6232">6232</a><br /><a id="L6233" href="#L6233">6233</a><br /><a id="L6234" href="#L6234">6234</a><br /><a id="L6235" href="#L6235">6235</a><br /><a id="L6236" href="#L6236">6236</a><br /><a id="L6237" href="#L6237">6237</a><br /><a id="L6238" href="#L6238">6238</a><br /><a id="L6239" href="#L6239">6239</a><br /><a id="L6240" href="#L6240">6240</a><br /><a id="L6241" href="#L6241">6241</a><br /><a id="L6242" href="#L6242">6242</a><br /><a id="L6243" href="#L6243">6243</a><br /><a id="L6244" href="#L6244">6244</a><br /><a id="L6245" href="#L6245">6245</a><br /><a id="L6246" href="#L6246">6246</a><br /><a id="L6247" href="#L6247">6247</a><br /><a id="L6248" href="#L6248">6248</a><br /><a id="L6249" href="#L6249">6249</a><br /><a id="L6250" href="#L6250">6250</a><br /><a id="L6251" href="#L6251">6251</a><br /><a id="L6252" href="#L6252">6252</a><br /><a id="L6253" href="#L6253">6253</a><br /><a id="L6254" href="#L6254">6254</a><br /><a id="L6255" href="#L6255">6255</a><br /><a id="L6256" href="#L6256">6256</a><br /><a id="L6257" href="#L6257">6257</a><br /><a id="L6258" href="#L6258">6258</a><br /><a id="L6259" href="#L6259">6259</a><br /><a id="L6260" href="#L6260">6260</a><br /><a id="L6261" href="#L6261">6261</a><br /><a id="L6262" href="#L6262">6262</a><br /><a id="L6263" href="#L6263">6263</a><br /><a id="L6264" href="#L6264">6264</a><br /><a id="L6265" href="#L6265">6265</a><br /><a id="L6266" href="#L6266">6266</a><br /><a id="L6267" href="#L6267">6267</a><br /><a id="L6268" href="#L6268">6268</a><br /><a id="L6269" href="#L6269">6269</a><br /><a id="L6270" href="#L6270">6270</a><br /><a id="L6271" href="#L6271">6271</a><br /><a id="L6272" href="#L6272">6272</a><br /><a id="L6273" href="#L6273">6273</a><br /><a id="L6274" href="#L6274">6274</a><br /><a id="L6275" href="#L6275">6275</a><br /><a id="L6276" href="#L6276">6276</a><br /><a id="L6277" href="#L6277">6277</a><br /><a id="L6278" href="#L6278">6278</a><br /><a id="L6279" href="#L6279">6279</a><br /><a id="L6280" href="#L6280">6280</a><br /><a id="L6281" href="#L6281">6281</a><br /><a id="L6282" href="#L6282">6282</a><br /><a id="L6283" href="#L6283">6283</a><br /><a id="L6284" href="#L6284">6284</a><br /><a id="L6285" href="#L6285">6285</a><br /><a id="L6286" href="#L6286">6286</a><br /><a id="L6287" href="#L6287">6287</a><br /><a id="L6288" href="#L6288">6288</a><br /><a id="L6289" href="#L6289">6289</a><br /><a id="L6290" href="#L6290">6290</a><br /><a id="L6291" href="#L6291">6291</a><br /><a id="L6292" href="#L6292">6292</a><br /><a id="L6293" href="#L6293">6293</a><br /><a id="L6294" href="#L6294">6294</a><br /><a id="L6295" href="#L6295">6295</a><br /><a id="L6296" href="#L6296">6296</a><br /><a id="L6297" href="#L6297">6297</a><br /><a id="L6298" href="#L6298">6298</a><br /><a id="L6299" href="#L6299">6299</a><br /><a id="L6300" href="#L6300">6300</a><br /><a id="L6301" href="#L6301">6301</a><br /><a id="L6302" href="#L6302">6302</a><br /><a id="L6303" href="#L6303">6303</a><br /><a id="L6304" href="#L6304">6304</a><br /><a id="L6305" href="#L6305">6305</a><br /><a id="L6306" href="#L6306">6306</a><br /><a id="L6307" href="#L6307">6307</a><br /><a id="L6308" href="#L6308">6308</a><br /><a id="L6309" href="#L6309">6309</a><br /><a id="L6310" href="#L6310">6310</a><br /><a id="L6311" href="#L6311">6311</a><br /><a id="L6312" href="#L6312">6312</a><br /><a id="L6313" href="#L6313">6313</a><br /><a id="L6314" href="#L6314">6314</a><br /><a id="L6315" href="#L6315">6315</a><br /><a id="L6316" href="#L6316">6316</a><br /><a id="L6317" href="#L6317">6317</a><br /><a id="L6318" href="#L6318">6318</a><br /><a id="L6319" href="#L6319">6319</a><br /><a id="L6320" href="#L6320">6320</a><br /><a id="L6321" href="#L6321">6321</a><br /><a id="L6322" href="#L6322">6322</a><br /><a id="L6323" href="#L6323">6323</a><br /><a id="L6324" href="#L6324">6324</a><br /><a id="L6325" href="#L6325">6325</a><br /><a id="L6326" href="#L6326">6326</a><br /><a id="L6327" href="#L6327">6327</a><br /><a id="L6328" href="#L6328">6328</a><br /><a id="L6329" href="#L6329">6329</a><br /><a id="L6330" href="#L6330">6330</a><br /><a id="L6331" href="#L6331">6331</a><br /><a id="L6332" href="#L6332">6332</a><br /><a id="L6333" href="#L6333">6333</a><br /><a id="L6334" href="#L6334">6334</a><br /><a id="L6335" href="#L6335">6335</a><br /><a id="L6336" href="#L6336">6336</a><br /><a id="L6337" href="#L6337">6337</a><br /><a id="L6338" href="#L6338">6338</a><br /><a id="L6339" href="#L6339">6339</a><br /><a id="L6340" href="#L6340">6340</a><br /><a id="L6341" href="#L6341">6341</a><br /><a id="L6342" href="#L6342">6342</a><br /><a id="L6343" href="#L6343">6343</a><br /><a id="L6344" href="#L6344">6344</a><br /><a id="L6345" href="#L6345">6345</a><br /><a id="L6346" href="#L6346">6346</a><br /><a id="L6347" href="#L6347">6347</a><br /><a id="L6348" href="#L6348">6348</a><br /><a id="L6349" href="#L6349">6349</a><br /><a id="L6350" href="#L6350">6350</a><br /><a id="L6351" href="#L6351">6351</a><br /><a id="L6352" href="#L6352">6352</a><br /><a id="L6353" href="#L6353">6353</a><br /><a id="L6354" href="#L6354">6354</a><br /><a id="L6355" href="#L6355">6355</a><br /><a id="L6356" href="#L6356">6356</a><br /><a id="L6357" href="#L6357">6357</a><br /><a id="L6358" href="#L6358">6358</a><br /><a id="L6359" href="#L6359">6359</a><br /><a id="L6360" href="#L6360">6360</a><br /><a id="L6361" href="#L6361">6361</a><br /><a id="L6362" href="#L6362">6362</a><br /><a id="L6363" href="#L6363">6363</a><br /><a id="L6364" href="#L6364">6364</a><br /><a id="L6365" href="#L6365">6365</a><br /><a id="L6366" href="#L6366">6366</a><br /><a id="L6367" href="#L6367">6367</a><br /><a id="L6368" href="#L6368">6368</a><br /><a id="L6369" href="#L6369">6369</a><br /><a id="L6370" href="#L6370">6370</a><br /><a id="L6371" href="#L6371">6371</a><br /><a id="L6372" href="#L6372">6372</a><br /><a id="L6373" href="#L6373">6373</a><br /><a id="L6374" href="#L6374">6374</a><br /><a id="L6375" href="#L6375">6375</a><br /><a id="L6376" href="#L6376">6376</a><br /><a id="L6377" href="#L6377">6377</a><br /><a id="L6378" href="#L6378">6378</a><br /><a id="L6379" href="#L6379">6379</a><br /><a id="L6380" href="#L6380">6380</a><br /><a id="L6381" href="#L6381">6381</a><br /><a id="L6382" href="#L6382">6382</a><br /><a id="L6383" href="#L6383">6383</a><br /><a id="L6384" href="#L6384">6384</a><br /><a id="L6385" href="#L6385">6385</a><br /><a id="L6386" href="#L6386">6386</a><br /><a id="L6387" href="#L6387">6387</a><br /><a id="L6388" href="#L6388">6388</a><br /><a id="L6389" href="#L6389">6389</a><br /><a id="L6390" href="#L6390">6390</a><br /><a id="L6391" href="#L6391">6391</a><br /><a id="L6392" href="#L6392">6392</a><br /><a id="L6393" href="#L6393">6393</a><br /><a id="L6394" href="#L6394">6394</a><br /><a id="L6395" href="#L6395">6395</a><br /><a id="L6396" href="#L6396">6396</a><br /><a id="L6397" href="#L6397">6397</a><br /><a id="L6398" href="#L6398">6398</a><br /><a id="L6399" href="#L6399">6399</a><br /><a id="L6400" href="#L6400">6400</a><br /><a id="L6401" href="#L6401">6401</a><br /><a id="L6402" href="#L6402">6402</a><br /><a id="L6403" href="#L6403">6403</a><br /><a id="L6404" href="#L6404">6404</a><br /><a id="L6405" href="#L6405">6405</a><br /><a id="L6406" href="#L6406">6406</a><br /><a id="L6407" href="#L6407">6407</a><br /><a id="L6408" href="#L6408">6408</a><br /><a id="L6409" href="#L6409">6409</a><br /><a id="L6410" href="#L6410">6410</a><br /><a id="L6411" href="#L6411">6411</a><br /><a id="L6412" href="#L6412">6412</a><br /><a id="L6413" href="#L6413">6413</a><br /><a id="L6414" href="#L6414">6414</a><br /><a id="L6415" href="#L6415">6415</a><br /><a id="L6416" href="#L6416">6416</a><br /><a id="L6417" href="#L6417">6417</a><br /><a id="L6418" href="#L6418">6418</a><br /><a id="L6419" href="#L6419">6419</a><br /><a id="L6420" href="#L6420">6420</a><br /><a id="L6421" href="#L6421">6421</a><br /><a id="L6422" href="#L6422">6422</a><br /><a id="L6423" href="#L6423">6423</a><br /><a id="L6424" href="#L6424">6424</a><br /><a id="L6425" href="#L6425">6425</a><br /><a id="L6426" href="#L6426">6426</a><br /><a id="L6427" href="#L6427">6427</a><br /><a id="L6428" href="#L6428">6428</a><br /><a id="L6429" href="#L6429">6429</a><br /><a id="L6430" href="#L6430">6430</a><br /><a id="L6431" href="#L6431">6431</a><br /><a id="L6432" href="#L6432">6432</a><br /><a id="L6433" href="#L6433">6433</a><br /><a id="L6434" href="#L6434">6434</a><br /><a id="L6435" href="#L6435">6435</a><br /><a id="L6436" href="#L6436">6436</a><br /><a id="L6437" href="#L6437">6437</a><br /><a id="L6438" href="#L6438">6438</a><br /><a id="L6439" href="#L6439">6439</a><br /><a id="L6440" href="#L6440">6440</a><br /><a id="L6441" href="#L6441">6441</a><br /><a id="L6442" href="#L6442">6442</a><br /><a id="L6443" href="#L6443">6443</a><br /><a id="L6444" href="#L6444">6444</a><br /><a id="L6445" href="#L6445">6445</a><br /><a id="L6446" href="#L6446">6446</a><br /><a id="L6447" href="#L6447">6447</a><br /><a id="L6448" href="#L6448">6448</a><br /><a id="L6449" href="#L6449">6449</a><br /><a id="L6450" href="#L6450">6450</a><br /><a id="L6451" href="#L6451">6451</a><br /><a id="L6452" href="#L6452">6452</a><br /><a id="L6453" href="#L6453">6453</a><br /><a id="L6454" href="#L6454">6454</a><br /><a id="L6455" href="#L6455">6455</a><br /><a id="L6456" href="#L6456">6456</a><br /><a id="L6457" href="#L6457">6457</a><br /><a id="L6458" href="#L6458">6458</a><br /><a id="L6459" href="#L6459">6459</a><br /><a id="L6460" href="#L6460">6460</a><br /><a id="L6461" href="#L6461">6461</a><br /><a id="L6462" href="#L6462">6462</a><br /><a id="L6463" href="#L6463">6463</a><br /><a id="L6464" href="#L6464">6464</a><br /><a id="L6465" href="#L6465">6465</a><br /><a id="L6466" href="#L6466">6466</a><br /><a id="L6467" href="#L6467">6467</a><br /><a id="L6468" href="#L6468">6468</a><br /><a id="L6469" href="#L6469">6469</a><br /><a id="L6470" href="#L6470">6470</a><br /><a id="L6471" href="#L6471">6471</a><br /><a id="L6472" href="#L6472">6472</a><br /><a id="L6473" href="#L6473">6473</a><br /><a id="L6474" href="#L6474">6474</a><br /><a id="L6475" href="#L6475">6475</a><br /><a id="L6476" href="#L6476">6476</a><br /><a id="L6477" href="#L6477">6477</a><br /><a id="L6478" href="#L6478">6478</a><br /><a id="L6479" href="#L6479">6479</a><br /><a id="L6480" href="#L6480">6480</a><br /><a id="L6481" href="#L6481">6481</a><br /><a id="L6482" href="#L6482">6482</a><br /><a id="L6483" href="#L6483">6483</a><br /><a id="L6484" href="#L6484">6484</a><br /><a id="L6485" href="#L6485">6485</a><br /><a id="L6486" href="#L6486">6486</a><br /><a id="L6487" href="#L6487">6487</a><br /><a id="L6488" href="#L6488">6488</a><br /><a id="L6489" href="#L6489">6489</a><br /><a id="L6490" href="#L6490">6490</a><br /><a id="L6491" href="#L6491">6491</a><br /><a id="L6492" href="#L6492">6492</a><br /><a id="L6493" href="#L6493">6493</a><br /><a id="L6494" href="#L6494">6494</a><br /><a id="L6495" href="#L6495">6495</a><br /><a id="L6496" href="#L6496">6496</a><br /><a id="L6497" href="#L6497">6497</a><br /><a id="L6498" href="#L6498">6498</a><br /><a id="L6499" href="#L6499">6499</a><br /><a id="L6500" href="#L6500">6500</a><br /><a id="L6501" href="#L6501">6501</a><br /><a id="L6502" href="#L6502">6502</a><br /><a id="L6503" href="#L6503">6503</a><br /><a id="L6504" href="#L6504">6504</a><br /><a id="L6505" href="#L6505">6505</a><br /><a id="L6506" href="#L6506">6506</a><br /><a id="L6507" href="#L6507">6507</a><br /><a id="L6508" href="#L6508">6508</a><br /><a id="L6509" href="#L6509">6509</a><br /><a id="L6510" href="#L6510">6510</a><br /><a id="L6511" href="#L6511">6511</a><br /><a id="L6512" href="#L6512">6512</a><br /><a id="L6513" href="#L6513">6513</a><br /><a id="L6514" href="#L6514">6514</a><br /><a id="L6515" href="#L6515">6515</a><br /><a id="L6516" href="#L6516">6516</a><br /><a id="L6517" href="#L6517">6517</a><br /><a id="L6518" href="#L6518">6518</a><br /><a id="L6519" href="#L6519">6519</a><br /><a id="L6520" href="#L6520">6520</a><br /><a id="L6521" href="#L6521">6521</a><br /><a id="L6522" href="#L6522">6522</a><br /><a id="L6523" href="#L6523">6523</a><br /><a id="L6524" href="#L6524">6524</a><br /><a id="L6525" href="#L6525">6525</a><br /><a id="L6526" href="#L6526">6526</a><br /><a id="L6527" href="#L6527">6527</a><br /><a id="L6528" href="#L6528">6528</a><br /><a id="L6529" href="#L6529">6529</a><br /><a id="L6530" href="#L6530">6530</a><br /><a id="L6531" href="#L6531">6531</a><br /><a id="L6532" href="#L6532">6532</a><br /><a id="L6533" href="#L6533">6533</a><br /><a id="L6534" href="#L6534">6534</a><br /><a id="L6535" href="#L6535">6535</a><br /><a id="L6536" href="#L6536">6536</a><br /><a id="L6537" href="#L6537">6537</a><br /><a id="L6538" href="#L6538">6538</a><br /><a id="L6539" href="#L6539">6539</a><br /><a id="L6540" href="#L6540">6540</a><br /><a id="L6541" href="#L6541">6541</a><br /><a id="L6542" href="#L6542">6542</a><br /><a id="L6543" href="#L6543">6543</a><br /><a id="L6544" href="#L6544">6544</a><br /><a id="L6545" href="#L6545">6545</a><br /><a id="L6546" href="#L6546">6546</a><br /><a id="L6547" href="#L6547">6547</a><br /><a id="L6548" href="#L6548">6548</a><br /><a id="L6549" href="#L6549">6549</a><br /><a id="L6550" href="#L6550">6550</a><br /><a id="L6551" href="#L6551">6551</a><br /><a id="L6552" href="#L6552">6552</a><br /><a id="L6553" href="#L6553">6553</a><br /><a id="L6554" href="#L6554">6554</a><br /><a id="L6555" href="#L6555">6555</a><br /><a id="L6556" href="#L6556">6556</a><br /><a id="L6557" href="#L6557">6557</a><br /><a id="L6558" href="#L6558">6558</a><br /><a id="L6559" href="#L6559">6559</a><br /><a id="L6560" href="#L6560">6560</a><br /><a id="L6561" href="#L6561">6561</a><br /><a id="L6562" href="#L6562">6562</a><br /><a id="L6563" href="#L6563">6563</a><br /><a id="L6564" href="#L6564">6564</a><br /><a id="L6565" href="#L6565">6565</a><br /><a id="L6566" href="#L6566">6566</a><br /><a id="L6567" href="#L6567">6567</a><br /><a id="L6568" href="#L6568">6568</a><br /><a id="L6569" href="#L6569">6569</a><br /><a id="L6570" href="#L6570">6570</a><br /><a id="L6571" href="#L6571">6571</a><br /><a id="L6572" href="#L6572">6572</a><br /><a id="L6573" href="#L6573">6573</a><br /><a id="L6574" href="#L6574">6574</a><br /><a id="L6575" href="#L6575">6575</a><br /><a id="L6576" href="#L6576">6576</a><br /><a id="L6577" href="#L6577">6577</a><br /><a id="L6578" href="#L6578">6578</a><br /><a id="L6579" href="#L6579">6579</a><br /><a id="L6580" href="#L6580">6580</a><br /><a id="L6581" href="#L6581">6581</a><br /><a id="L6582" href="#L6582">6582</a><br /><a id="L6583" href="#L6583">6583</a><br /><a id="L6584" href="#L6584">6584</a><br /><a id="L6585" href="#L6585">6585</a><br /><a id="L6586" href="#L6586">6586</a><br /><a id="L6587" href="#L6587">6587</a><br /><a id="L6588" href="#L6588">6588</a><br /><a id="L6589" href="#L6589">6589</a><br /><a id="L6590" href="#L6590">6590</a><br /><a id="L6591" href="#L6591">6591</a><br /><a id="L6592" href="#L6592">6592</a><br /><a id="L6593" href="#L6593">6593</a><br /><a id="L6594" href="#L6594">6594</a><br /><a id="L6595" href="#L6595">6595</a><br /><a id="L6596" href="#L6596">6596</a><br /><a id="L6597" href="#L6597">6597</a><br /><a id="L6598" href="#L6598">6598</a><br /><a id="L6599" href="#L6599">6599</a><br /><a id="L6600" href="#L6600">6600</a><br /><a id="L6601" href="#L6601">6601</a><br /><a id="L6602" href="#L6602">6602</a><br /><a id="L6603" href="#L6603">6603</a><br /><a id="L6604" href="#L6604">6604</a><br /><a id="L6605" href="#L6605">6605</a><br /><a id="L6606" href="#L6606">6606</a><br /><a id="L6607" href="#L6607">6607</a><br /><a id="L6608" href="#L6608">6608</a><br /><a id="L6609" href="#L6609">6609</a><br /><a id="L6610" href="#L6610">6610</a><br /><a id="L6611" href="#L6611">6611</a><br /><a id="L6612" href="#L6612">6612</a><br /><a id="L6613" href="#L6613">6613</a><br /><a id="L6614" href="#L6614">6614</a><br /><a id="L6615" href="#L6615">6615</a><br /><a id="L6616" href="#L6616">6616</a><br /><a id="L6617" href="#L6617">6617</a><br /><a id="L6618" href="#L6618">6618</a><br /><a id="L6619" href="#L6619">6619</a><br /><a id="L6620" href="#L6620">6620</a><br /><a id="L6621" href="#L6621">6621</a><br /><a id="L6622" href="#L6622">6622</a><br /><a id="L6623" href="#L6623">6623</a><br /><a id="L6624" href="#L6624">6624</a><br /><a id="L6625" href="#L6625">6625</a><br /><a id="L6626" href="#L6626">6626</a><br /><a id="L6627" href="#L6627">6627</a><br /><a id="L6628" href="#L6628">6628</a><br /><a id="L6629" href="#L6629">6629</a><br /><a id="L6630" href="#L6630">6630</a><br /><a id="L6631" href="#L6631">6631</a><br /><a id="L6632" href="#L6632">6632</a><br /><a id="L6633" href="#L6633">6633</a><br /><a id="L6634" href="#L6634">6634</a><br /><a id="L6635" href="#L6635">6635</a><br /><a id="L6636" href="#L6636">6636</a><br /><a id="L6637" href="#L6637">6637</a><br /><a id="L6638" href="#L6638">6638</a><br /><a id="L6639" href="#L6639">6639</a><br /><a id="L6640" href="#L6640">6640</a><br /><a id="L6641" href="#L6641">6641</a><br /><a id="L6642" href="#L6642">6642</a><br /><a id="L6643" href="#L6643">6643</a><br /><a id="L6644" href="#L6644">6644</a><br /><a id="L6645" href="#L6645">6645</a><br /><a id="L6646" href="#L6646">6646</a><br /><a id="L6647" href="#L6647">6647</a><br /><a id="L6648" href="#L6648">6648</a><br /><a id="L6649" href="#L6649">6649</a><br /><a id="L6650" href="#L6650">6650</a><br /><a id="L6651" href="#L6651">6651</a><br /><a id="L6652" href="#L6652">6652</a><br /><a id="L6653" href="#L6653">6653</a><br /><a id="L6654" href="#L6654">6654</a><br /><a id="L6655" href="#L6655">6655</a><br /><a id="L6656" href="#L6656">6656</a><br /><a id="L6657" href="#L6657">6657</a><br /><a id="L6658" href="#L6658">6658</a><br /><a id="L6659" href="#L6659">6659</a><br /><a id="L6660" href="#L6660">6660</a><br /><a id="L6661" href="#L6661">6661</a><br /><a id="L6662" href="#L6662">6662</a><br /><a id="L6663" href="#L6663">6663</a><br /><a id="L6664" href="#L6664">6664</a><br /><a id="L6665" href="#L6665">6665</a><br /><a id="L6666" href="#L6666">6666</a><br /><a id="L6667" href="#L6667">6667</a><br /><a id="L6668" href="#L6668">6668</a><br /><a id="L6669" href="#L6669">6669</a><br /><a id="L6670" href="#L6670">6670</a><br /><a id="L6671" href="#L6671">6671</a><br /><a id="L6672" href="#L6672">6672</a><br /><a id="L6673" href="#L6673">6673</a><br /><a id="L6674" href="#L6674">6674</a><br /><a id="L6675" href="#L6675">6675</a><br /><a id="L6676" href="#L6676">6676</a><br /><a id="L6677" href="#L6677">6677</a><br /><a id="L6678" href="#L6678">6678</a><br /><a id="L6679" href="#L6679">6679</a><br /><a id="L6680" href="#L6680">6680</a><br /><a id="L6681" href="#L6681">6681</a><br /><a id="L6682" href="#L6682">6682</a><br /><a id="L6683" href="#L6683">6683</a><br /><a id="L6684" href="#L6684">6684</a><br /><a id="L6685" href="#L6685">6685</a><br /><a id="L6686" href="#L6686">6686</a><br /><a id="L6687" href="#L6687">6687</a><br /><a id="L6688" href="#L6688">6688</a><br /><a id="L6689" href="#L6689">6689</a><br /><a id="L6690" href="#L6690">6690</a><br /><a id="L6691" href="#L6691">6691</a><br /><a id="L6692" href="#L6692">6692</a><br /><a id="L6693" href="#L6693">6693</a><br /><a id="L6694" href="#L6694">6694</a><br /><a id="L6695" href="#L6695">6695</a><br /><a id="L6696" href="#L6696">6696</a><br /><a id="L6697" href="#L6697">6697</a><br /><a id="L6698" href="#L6698">6698</a><br /><a id="L6699" href="#L6699">6699</a><br /><a id="L6700" href="#L6700">6700</a><br /><a id="L6701" href="#L6701">6701</a><br /><a id="L6702" href="#L6702">6702</a><br /><a id="L6703" href="#L6703">6703</a><br /><a id="L6704" href="#L6704">6704</a><br /><a id="L6705" href="#L6705">6705</a><br /><a id="L6706" href="#L6706">6706</a><br /><a id="L6707" href="#L6707">6707</a><br /><a id="L6708" href="#L6708">6708</a><br /><a id="L6709" href="#L6709">6709</a><br /><a id="L6710" href="#L6710">6710</a><br /><a id="L6711" href="#L6711">6711</a><br /><a id="L6712" href="#L6712">6712</a><br /><a id="L6713" href="#L6713">6713</a><br /><a id="L6714" href="#L6714">6714</a><br /><a id="L6715" href="#L6715">6715</a><br /><a id="L6716" href="#L6716">6716</a><br /><a id="L6717" href="#L6717">6717</a><br /><a id="L6718" href="#L6718">6718</a><br /><a id="L6719" href="#L6719">6719</a><br /><a id="L6720" href="#L6720">6720</a><br /><a id="L6721" href="#L6721">6721</a><br /><a id="L6722" href="#L6722">6722</a><br /><a id="L6723" href="#L6723">6723</a><br /><a id="L6724" href="#L6724">6724</a><br /><a id="L6725" href="#L6725">6725</a><br /><a id="L6726" href="#L6726">6726</a><br /><a id="L6727" href="#L6727">6727</a><br /><a id="L6728" href="#L6728">6728</a><br /><a id="L6729" href="#L6729">6729</a><br /><a id="L6730" href="#L6730">6730</a><br /><a id="L6731" href="#L6731">6731</a><br /><a id="L6732" href="#L6732">6732</a><br /><a id="L6733" href="#L6733">6733</a><br /><a id="L6734" href="#L6734">6734</a><br /><a id="L6735" href="#L6735">6735</a><br /><a id="L6736" href="#L6736">6736</a><br /><a id="L6737" href="#L6737">6737</a><br /><a id="L6738" href="#L6738">6738</a><br /><a id="L6739" href="#L6739">6739</a><br /><a id="L6740" href="#L6740">6740</a><br /><a id="L6741" href="#L6741">6741</a><br /><a id="L6742" href="#L6742">6742</a><br /><a id="L6743" href="#L6743">6743</a><br /><a id="L6744" href="#L6744">6744</a><br /><a id="L6745" href="#L6745">6745</a><br /><a id="L6746" href="#L6746">6746</a><br /><a id="L6747" href="#L6747">6747</a><br /><a id="L6748" href="#L6748">6748</a><br /><a id="L6749" href="#L6749">6749</a><br /><a id="L6750" href="#L6750">6750</a><br /><a id="L6751" href="#L6751">6751</a><br /><a id="L6752" href="#L6752">6752</a><br /><a id="L6753" href="#L6753">6753</a><br /><a id="L6754" href="#L6754">6754</a><br /><a id="L6755" href="#L6755">6755</a><br /><a id="L6756" href="#L6756">6756</a><br /><a id="L6757" href="#L6757">6757</a><br /><a id="L6758" href="#L6758">6758</a><br /><a id="L6759" href="#L6759">6759</a><br /><a id="L6760" href="#L6760">6760</a><br /><a id="L6761" href="#L6761">6761</a><br /><a id="L6762" href="#L6762">6762</a><br /><a id="L6763" href="#L6763">6763</a><br /><a id="L6764" href="#L6764">6764</a><br /><a id="L6765" href="#L6765">6765</a><br /><a id="L6766" href="#L6766">6766</a><br /><a id="L6767" href="#L6767">6767</a><br /><a id="L6768" href="#L6768">6768</a><br /><a id="L6769" href="#L6769">6769</a><br /><a id="L6770" href="#L6770">6770</a><br /><a id="L6771" href="#L6771">6771</a><br /><a id="L6772" href="#L6772">6772</a><br /><a id="L6773" href="#L6773">6773</a><br /><a id="L6774" href="#L6774">6774</a><br /><a id="L6775" href="#L6775">6775</a><br /><a id="L6776" href="#L6776">6776</a><br /><a id="L6777" href="#L6777">6777</a><br /><a id="L6778" href="#L6778">6778</a><br /><a id="L6779" href="#L6779">6779</a><br /><a id="L6780" href="#L6780">6780</a><br /><a id="L6781" href="#L6781">6781</a><br /><a id="L6782" href="#L6782">6782</a><br /><a id="L6783" href="#L6783">6783</a><br /><a id="L6784" href="#L6784">6784</a><br /><a id="L6785" href="#L6785">6785</a><br /><a id="L6786" href="#L6786">6786</a><br /><a id="L6787" href="#L6787">6787</a><br /><a id="L6788" href="#L6788">6788</a><br /><a id="L6789" href="#L6789">6789</a><br /><a id="L6790" href="#L6790">6790</a><br /><a id="L6791" href="#L6791">6791</a><br /><a id="L6792" href="#L6792">6792</a><br /><a id="L6793" href="#L6793">6793</a><br /><a id="L6794" href="#L6794">6794</a><br /><a id="L6795" href="#L6795">6795</a><br /><a id="L6796" href="#L6796">6796</a><br /><a id="L6797" href="#L6797">6797</a><br /><a id="L6798" href="#L6798">6798</a><br /><a id="L6799" href="#L6799">6799</a><br /><a id="L6800" href="#L6800">6800</a><br /><a id="L6801" href="#L6801">6801</a><br /><a id="L6802" href="#L6802">6802</a><br /><a id="L6803" href="#L6803">6803</a><br /><a id="L6804" href="#L6804">6804</a><br /><a id="L6805" href="#L6805">6805</a><br /><a id="L6806" href="#L6806">6806</a><br /><a id="L6807" href="#L6807">6807</a><br /><a id="L6808" href="#L6808">6808</a><br /><a id="L6809" href="#L6809">6809</a><br /><a id="L6810" href="#L6810">6810</a><br /><a id="L6811" href="#L6811">6811</a><br /><a id="L6812" href="#L6812">6812</a><br /><a id="L6813" href="#L6813">6813</a><br /><a id="L6814" href="#L6814">6814</a><br /><a id="L6815" href="#L6815">6815</a><br /><a id="L6816" href="#L6816">6816</a><br /><a id="L6817" href="#L6817">6817</a><br /><a id="L6818" href="#L6818">6818</a><br /><a id="L6819" href="#L6819">6819</a><br /><a id="L6820" href="#L6820">6820</a><br /><a id="L6821" href="#L6821">6821</a><br /><a id="L6822" href="#L6822">6822</a><br /><a id="L6823" href="#L6823">6823</a><br /><a id="L6824" href="#L6824">6824</a><br /><a id="L6825" href="#L6825">6825</a><br /><a id="L6826" href="#L6826">6826</a><br /><a id="L6827" href="#L6827">6827</a><br /><a id="L6828" href="#L6828">6828</a><br /><a id="L6829" href="#L6829">6829</a><br /><a id="L6830" href="#L6830">6830</a><br /><a id="L6831" href="#L6831">6831</a><br /><a id="L6832" href="#L6832">6832</a><br /><a id="L6833" href="#L6833">6833</a><br /><a id="L6834" href="#L6834">6834</a><br /><a id="L6835" href="#L6835">6835</a><br /><a id="L6836" href="#L6836">6836</a><br /><a id="L6837" href="#L6837">6837</a><br /><a id="L6838" href="#L6838">6838</a><br /><a id="L6839" href="#L6839">6839</a><br /><a id="L6840" href="#L6840">6840</a><br /><a id="L6841" href="#L6841">6841</a><br /><a id="L6842" href="#L6842">6842</a><br /><a id="L6843" href="#L6843">6843</a><br /><a id="L6844" href="#L6844">6844</a><br /><a id="L6845" href="#L6845">6845</a><br /><a id="L6846" href="#L6846">6846</a><br /><a id="L6847" href="#L6847">6847</a><br /><a id="L6848" href="#L6848">6848</a><br /><a id="L6849" href="#L6849">6849</a><br /><a id="L6850" href="#L6850">6850</a><br /><a id="L6851" href="#L6851">6851</a><br /><a id="L6852" href="#L6852">6852</a><br /><a id="L6853" href="#L6853">6853</a><br /><a id="L6854" href="#L6854">6854</a><br /><a id="L6855" href="#L6855">6855</a><br /><a id="L6856" href="#L6856">6856</a><br /><a id="L6857" href="#L6857">6857</a><br /><a id="L6858" href="#L6858">6858</a><br /><a id="L6859" href="#L6859">6859</a><br /><a id="L6860" href="#L6860">6860</a><br /><a id="L6861" href="#L6861">6861</a><br /><a id="L6862" href="#L6862">6862</a><br /><a id="L6863" href="#L6863">6863</a><br /><a id="L6864" href="#L6864">6864</a><br /><a id="L6865" href="#L6865">6865</a><br /><a id="L6866" href="#L6866">6866</a><br /><a id="L6867" href="#L6867">6867</a><br /><a id="L6868" href="#L6868">6868</a><br /><a id="L6869" href="#L6869">6869</a><br /><a id="L6870" href="#L6870">6870</a><br /><a id="L6871" href="#L6871">6871</a><br /><a id="L6872" href="#L6872">6872</a><br /><a id="L6873" href="#L6873">6873</a><br /><a id="L6874" href="#L6874">6874</a><br /><a id="L6875" href="#L6875">6875</a><br /><a id="L6876" href="#L6876">6876</a><br /><a id="L6877" href="#L6877">6877</a><br /><a id="L6878" href="#L6878">6878</a><br /><a id="L6879" href="#L6879">6879</a><br /><a id="L6880" href="#L6880">6880</a><br /><a id="L6881" href="#L6881">6881</a><br /><a id="L6882" href="#L6882">6882</a><br /><a id="L6883" href="#L6883">6883</a><br /><a id="L6884" href="#L6884">6884</a><br /><a id="L6885" href="#L6885">6885</a><br /><a id="L6886" href="#L6886">6886</a><br /><a id="L6887" href="#L6887">6887</a><br /><a id="L6888" href="#L6888">6888</a><br /><a id="L6889" href="#L6889">6889</a><br /><a id="L6890" href="#L6890">6890</a><br /><a id="L6891" href="#L6891">6891</a><br /><a id="L6892" href="#L6892">6892</a><br /><a id="L6893" href="#L6893">6893</a><br /><a id="L6894" href="#L6894">6894</a><br /><a id="L6895" href="#L6895">6895</a><br /><a id="L6896" href="#L6896">6896</a><br /><a id="L6897" href="#L6897">6897</a><br /><a id="L6898" href="#L6898">6898</a><br /><a id="L6899" href="#L6899">6899</a><br /><a id="L6900" href="#L6900">6900</a><br /><a id="L6901" href="#L6901">6901</a><br /><a id="L6902" href="#L6902">6902</a><br /><a id="L6903" href="#L6903">6903</a><br /><a id="L6904" href="#L6904">6904</a><br /><a id="L6905" href="#L6905">6905</a><br /><a id="L6906" href="#L6906">6906</a><br /><a id="L6907" href="#L6907">6907</a><br /><a id="L6908" href="#L6908">6908</a><br /><a id="L6909" href="#L6909">6909</a><br /><a id="L6910" href="#L6910">6910</a><br /><a id="L6911" href="#L6911">6911</a><br /><a id="L6912" href="#L6912">6912</a><br /><a id="L6913" href="#L6913">6913</a><br /><a id="L6914" href="#L6914">6914</a><br /><a id="L6915" href="#L6915">6915</a><br /><a id="L6916" href="#L6916">6916</a><br /><a id="L6917" href="#L6917">6917</a><br /><a id="L6918" href="#L6918">6918</a><br /><a id="L6919" href="#L6919">6919</a><br /><a id="L6920" href="#L6920">6920</a><br /><a id="L6921" href="#L6921">6921</a><br /><a id="L6922" href="#L6922">6922</a><br /><a id="L6923" href="#L6923">6923</a><br /><a id="L6924" href="#L6924">6924</a><br /><a id="L6925" href="#L6925">6925</a><br /><a id="L6926" href="#L6926">6926</a><br /><a id="L6927" href="#L6927">6927</a><br /><a id="L6928" href="#L6928">6928</a><br /><a id="L6929" href="#L6929">6929</a><br /><a id="L6930" href="#L6930">6930</a><br /><a id="L6931" href="#L6931">6931</a><br /><a id="L6932" href="#L6932">6932</a><br /><a id="L6933" href="#L6933">6933</a><br /><a id="L6934" href="#L6934">6934</a><br /><a id="L6935" href="#L6935">6935</a><br /><a id="L6936" href="#L6936">6936</a><br /><a id="L6937" href="#L6937">6937</a><br /><a id="L6938" href="#L6938">6938</a><br /><a id="L6939" href="#L6939">6939</a><br /><a id="L6940" href="#L6940">6940</a><br /><a id="L6941" href="#L6941">6941</a><br /><a id="L6942" href="#L6942">6942</a><br /><a id="L6943" href="#L6943">6943</a><br /><a id="L6944" href="#L6944">6944</a><br /><a id="L6945" href="#L6945">6945</a><br /><a id="L6946" href="#L6946">6946</a><br /><a id="L6947" href="#L6947">6947</a><br /><a id="L6948" href="#L6948">6948</a><br /><a id="L6949" href="#L6949">6949</a><br /><a id="L6950" href="#L6950">6950</a><br /><a id="L6951" href="#L6951">6951</a><br /><a id="L6952" href="#L6952">6952</a><br /><a id="L6953" href="#L6953">6953</a><br /><a id="L6954" href="#L6954">6954</a><br /><a id="L6955" href="#L6955">6955</a><br /><a id="L6956" href="#L6956">6956</a><br /><a id="L6957" href="#L6957">6957</a><br /><a id="L6958" href="#L6958">6958</a><br /><a id="L6959" href="#L6959">6959</a><br /><a id="L6960" href="#L6960">6960</a><br /><a id="L6961" href="#L6961">6961</a><br /><a id="L6962" href="#L6962">6962</a><br /><a id="L6963" href="#L6963">6963</a><br /><a id="L6964" href="#L6964">6964</a><br /><a id="L6965" href="#L6965">6965</a><br /><a id="L6966" href="#L6966">6966</a><br /><a id="L6967" href="#L6967">6967</a><br /><a id="L6968" href="#L6968">6968</a><br /><a id="L6969" href="#L6969">6969</a><br /><a id="L6970" href="#L6970">6970</a><br /><a id="L6971" href="#L6971">6971</a><br /><a id="L6972" href="#L6972">6972</a><br /><a id="L6973" href="#L6973">6973</a><br /><a id="L6974" href="#L6974">6974</a><br /><a id="L6975" href="#L6975">6975</a><br /><a id="L6976" href="#L6976">6976</a><br /><a id="L6977" href="#L6977">6977</a><br /><a id="L6978" href="#L6978">6978</a><br /><a id="L6979" href="#L6979">6979</a><br /><a id="L6980" href="#L6980">6980</a><br /><a id="L6981" href="#L6981">6981</a><br /><a id="L6982" href="#L6982">6982</a><br /><a id="L6983" href="#L6983">6983</a><br /><a id="L6984" href="#L6984">6984</a><br /><a id="L6985" href="#L6985">6985</a><br /><a id="L6986" href="#L6986">6986</a><br /><a id="L6987" href="#L6987">6987</a><br /><a id="L6988" href="#L6988">6988</a><br /><a id="L6989" href="#L6989">6989</a><br /><a id="L6990" href="#L6990">6990</a><br /><a id="L6991" href="#L6991">6991</a><br /><a id="L6992" href="#L6992">6992</a><br /><a id="L6993" href="#L6993">6993</a><br /><a id="L6994" href="#L6994">6994</a><br /><a id="L6995" href="#L6995">6995</a><br /><a id="L6996" href="#L6996">6996</a><br /><a id="L6997" href="#L6997">6997</a><br /><a id="L6998" href="#L6998">6998</a><br /><a id="L6999" href="#L6999">6999</a><br /><a id="L7000" href="#L7000">7000</a><br /><a id="L7001" href="#L7001">7001</a><br /><a id="L7002" href="#L7002">7002</a><br /><a id="L7003" href="#L7003">7003</a><br /><a id="L7004" href="#L7004">7004</a><br /><a id="L7005" href="#L7005">7005</a><br /><a id="L7006" href="#L7006">7006</a><br /><a id="L7007" href="#L7007">7007</a><br /><a id="L7008" href="#L7008">7008</a><br /><a id="L7009" href="#L7009">7009</a><br /><a id="L7010" href="#L7010">7010</a><br /><a id="L7011" href="#L7011">7011</a><br /><a id="L7012" href="#L7012">7012</a><br /><a id="L7013" href="#L7013">7013</a><br /><a id="L7014" href="#L7014">7014</a><br /><a id="L7015" href="#L7015">7015</a><br /><a id="L7016" href="#L7016">7016</a><br /><a id="L7017" href="#L7017">7017</a><br /><a id="L7018" href="#L7018">7018</a><br /><a id="L7019" href="#L7019">7019</a><br /><a id="L7020" href="#L7020">7020</a><br /><a id="L7021" href="#L7021">7021</a><br /><a id="L7022" href="#L7022">7022</a><br /><a id="L7023" href="#L7023">7023</a><br /><a id="L7024" href="#L7024">7024</a><br /><a id="L7025" href="#L7025">7025</a><br /><a id="L7026" href="#L7026">7026</a><br /><a id="L7027" href="#L7027">7027</a><br /><a id="L7028" href="#L7028">7028</a><br /><a id="L7029" href="#L7029">7029</a><br /><a id="L7030" href="#L7030">7030</a><br /><a id="L7031" href="#L7031">7031</a><br /><a id="L7032" href="#L7032">7032</a><br /><a id="L7033" href="#L7033">7033</a><br /><a id="L7034" href="#L7034">7034</a><br /><a id="L7035" href="#L7035">7035</a><br /><a id="L7036" href="#L7036">7036</a><br /><a id="L7037" href="#L7037">7037</a><br /><a id="L7038" href="#L7038">7038</a><br /><a id="L7039" href="#L7039">7039</a><br /><a id="L7040" href="#L7040">7040</a><br /><a id="L7041" href="#L7041">7041</a><br /><a id="L7042" href="#L7042">7042</a><br /><a id="L7043" href="#L7043">7043</a><br /><a id="L7044" href="#L7044">7044</a><br /><a id="L7045" href="#L7045">7045</a><br /><a id="L7046" href="#L7046">7046</a><br /><a id="L7047" href="#L7047">7047</a><br /><a id="L7048" href="#L7048">7048</a><br /><a id="L7049" href="#L7049">7049</a><br /><a id="L7050" href="#L7050">7050</a><br /><a id="L7051" href="#L7051">7051</a><br /><a id="L7052" href="#L7052">7052</a><br /><a id="L7053" href="#L7053">7053</a><br /><a id="L7054" href="#L7054">7054</a><br /><a id="L7055" href="#L7055">7055</a><br /><a id="L7056" href="#L7056">7056</a><br /><a id="L7057" href="#L7057">7057</a><br /><a id="L7058" href="#L7058">7058</a><br /><a id="L7059" href="#L7059">7059</a><br /><a id="L7060" href="#L7060">7060</a><br /><a id="L7061" href="#L7061">7061</a><br /><a id="L7062" href="#L7062">7062</a><br /><a id="L7063" href="#L7063">7063</a><br /><a id="L7064" href="#L7064">7064</a><br /><a id="L7065" href="#L7065">7065</a><br /><a id="L7066" href="#L7066">7066</a><br /><a id="L7067" href="#L7067">7067</a><br /><a id="L7068" href="#L7068">7068</a><br /><a id="L7069" href="#L7069">7069</a><br /><a id="L7070" href="#L7070">7070</a><br /><a id="L7071" href="#L7071">7071</a><br /><a id="L7072" href="#L7072">7072</a><br /><a id="L7073" href="#L7073">7073</a><br /><a id="L7074" href="#L7074">7074</a><br /><a id="L7075" href="#L7075">7075</a><br /><a id="L7076" href="#L7076">7076</a><br /><a id="L7077" href="#L7077">7077</a><br /><a id="L7078" href="#L7078">7078</a><br /><a id="L7079" href="#L7079">7079</a><br /><a id="L7080" href="#L7080">7080</a><br /><a id="L7081" href="#L7081">7081</a><br /><a id="L7082" href="#L7082">7082</a><br /><a id="L7083" href="#L7083">7083</a><br /><a id="L7084" href="#L7084">7084</a><br /><a id="L7085" href="#L7085">7085</a><br /><a id="L7086" href="#L7086">7086</a><br /><a id="L7087" href="#L7087">7087</a><br /><a id="L7088" href="#L7088">7088</a><br /><a id="L7089" href="#L7089">7089</a><br /><a id="L7090" href="#L7090">7090</a><br /><a id="L7091" href="#L7091">7091</a><br /><a id="L7092" href="#L7092">7092</a><br /><a id="L7093" href="#L7093">7093</a><br /><a id="L7094" href="#L7094">7094</a><br /><a id="L7095" href="#L7095">7095</a><br /><a id="L7096" href="#L7096">7096</a><br /><a id="L7097" href="#L7097">7097</a><br /><a id="L7098" href="#L7098">7098</a><br /><a id="L7099" href="#L7099">7099</a><br /><a id="L7100" href="#L7100">7100</a><br /><a id="L7101" href="#L7101">7101</a><br /><a id="L7102" href="#L7102">7102</a><br /><a id="L7103" href="#L7103">7103</a><br /><a id="L7104" href="#L7104">7104</a><br /><a id="L7105" href="#L7105">7105</a><br /><a id="L7106" href="#L7106">7106</a><br /><a id="L7107" href="#L7107">7107</a><br /><a id="L7108" href="#L7108">7108</a><br /><a id="L7109" href="#L7109">7109</a><br /><a id="L7110" href="#L7110">7110</a><br /><a id="L7111" href="#L7111">7111</a><br /><a id="L7112" href="#L7112">7112</a><br /><a id="L7113" href="#L7113">7113</a><br /><a id="L7114" href="#L7114">7114</a><br /><a id="L7115" href="#L7115">7115</a><br /><a id="L7116" href="#L7116">7116</a><br /><a id="L7117" href="#L7117">7117</a><br /><a id="L7118" href="#L7118">7118</a><br /><a id="L7119" href="#L7119">7119</a><br /><a id="L7120" href="#L7120">7120</a><br /><a id="L7121" href="#L7121">7121</a><br /><a id="L7122" href="#L7122">7122</a><br /><a id="L7123" href="#L7123">7123</a><br /><a id="L7124" href="#L7124">7124</a><br /><a id="L7125" href="#L7125">7125</a><br /><a id="L7126" href="#L7126">7126</a><br /><a id="L7127" href="#L7127">7127</a><br /><a id="L7128" href="#L7128">7128</a><br /><a id="L7129" href="#L7129">7129</a><br /><a id="L7130" href="#L7130">7130</a><br /><a id="L7131" href="#L7131">7131</a><br /><a id="L7132" href="#L7132">7132</a><br /><a id="L7133" href="#L7133">7133</a><br /><a id="L7134" href="#L7134">7134</a><br /><a id="L7135" href="#L7135">7135</a><br /><a id="L7136" href="#L7136">7136</a><br /><a id="L7137" href="#L7137">7137</a><br /><a id="L7138" href="#L7138">7138</a><br /><a id="L7139" href="#L7139">7139</a><br /><a id="L7140" href="#L7140">7140</a><br /><a id="L7141" href="#L7141">7141</a><br /><a id="L7142" href="#L7142">7142</a><br /><a id="L7143" href="#L7143">7143</a><br /><a id="L7144" href="#L7144">7144</a><br /><a id="L7145" href="#L7145">7145</a><br /><a id="L7146" href="#L7146">7146</a><br /><a id="L7147" href="#L7147">7147</a><br /><a id="L7148" href="#L7148">7148</a><br /><a id="L7149" href="#L7149">7149</a><br /><a id="L7150" href="#L7150">7150</a><br /><a id="L7151" href="#L7151">7151</a><br /><a id="L7152" href="#L7152">7152</a><br /><a id="L7153" href="#L7153">7153</a><br /><a id="L7154" href="#L7154">7154</a><br /><a id="L7155" href="#L7155">7155</a><br /><a id="L7156" href="#L7156">7156</a><br /><a id="L7157" href="#L7157">7157</a><br /><a id="L7158" href="#L7158">7158</a><br /><a id="L7159" href="#L7159">7159</a><br /><a id="L7160" href="#L7160">7160</a><br /><a id="L7161" href="#L7161">7161</a><br /><a id="L7162" href="#L7162">7162</a><br /><a id="L7163" href="#L7163">7163</a><br /><a id="L7164" href="#L7164">7164</a><br /><a id="L7165" href="#L7165">7165</a><br /><a id="L7166" href="#L7166">7166</a><br /><a id="L7167" href="#L7167">7167</a><br /><a id="L7168" href="#L7168">7168</a><br /><a id="L7169" href="#L7169">7169</a><br /><a id="L7170" href="#L7170">7170</a><br /><a id="L7171" href="#L7171">7171</a><br /><a id="L7172" href="#L7172">7172</a><br /><a id="L7173" href="#L7173">7173</a><br /><a id="L7174" href="#L7174">7174</a><br /><a id="L7175" href="#L7175">7175</a><br /><a id="L7176" href="#L7176">7176</a><br /><a id="L7177" href="#L7177">7177</a><br /><a id="L7178" href="#L7178">7178</a><br /><a id="L7179" href="#L7179">7179</a><br /><a id="L7180" href="#L7180">7180</a><br /><a id="L7181" href="#L7181">7181</a><br /><a id="L7182" href="#L7182">7182</a><br /><a id="L7183" href="#L7183">7183</a><br /><a id="L7184" href="#L7184">7184</a><br /><a id="L7185" href="#L7185">7185</a><br /><a id="L7186" href="#L7186">7186</a><br /><a id="L7187" href="#L7187">7187</a><br /><a id="L7188" href="#L7188">7188</a><br /><a id="L7189" href="#L7189">7189</a><br /><a id="L7190" href="#L7190">7190</a><br /><a id="L7191" href="#L7191">7191</a><br /><a id="L7192" href="#L7192">7192</a><br /><a id="L7193" href="#L7193">7193</a><br /><a id="L7194" href="#L7194">7194</a><br /><a id="L7195" href="#L7195">7195</a><br /><a id="L7196" href="#L7196">7196</a><br /><a id="L7197" href="#L7197">7197</a><br /><a id="L7198" href="#L7198">7198</a><br /><a id="L7199" href="#L7199">7199</a><br /><a id="L7200" href="#L7200">7200</a><br /><a id="L7201" href="#L7201">7201</a><br /><a id="L7202" href="#L7202">7202</a><br /><a id="L7203" href="#L7203">7203</a><br /><a id="L7204" href="#L7204">7204</a><br /><a id="L7205" href="#L7205">7205</a><br /><a id="L7206" href="#L7206">7206</a><br /><a id="L7207" href="#L7207">7207</a><br /><a id="L7208" href="#L7208">7208</a><br /><a id="L7209" href="#L7209">7209</a><br /><a id="L7210" href="#L7210">7210</a><br /><a id="L7211" href="#L7211">7211</a><br /><a id="L7212" href="#L7212">7212</a><br /><a id="L7213" href="#L7213">7213</a><br /><a id="L7214" href="#L7214">7214</a><br /><a id="L7215" href="#L7215">7215</a><br /><a id="L7216" href="#L7216">7216</a><br /><a id="L7217" href="#L7217">7217</a><br /><a id="L7218" href="#L7218">7218</a><br /><a id="L7219" href="#L7219">7219</a><br /><a id="L7220" href="#L7220">7220</a><br /><a id="L7221" href="#L7221">7221</a><br /><a id="L7222" href="#L7222">7222</a><br /><a id="L7223" href="#L7223">7223</a><br /><a id="L7224" href="#L7224">7224</a><br /><a id="L7225" href="#L7225">7225</a><br /><a id="L7226" href="#L7226">7226</a><br /><a id="L7227" href="#L7227">7227</a><br /><a id="L7228" href="#L7228">7228</a><br /><a id="L7229" href="#L7229">7229</a><br /><a id="L7230" href="#L7230">7230</a><br /><a id="L7231" href="#L7231">7231</a><br /><a id="L7232" href="#L7232">7232</a><br /><a id="L7233" href="#L7233">7233</a><br /><a id="L7234" href="#L7234">7234</a><br /><a id="L7235" href="#L7235">7235</a><br /><a id="L7236" href="#L7236">7236</a><br /><a id="L7237" href="#L7237">7237</a><br /><a id="L7238" href="#L7238">7238</a><br /></pre>
    </td>
    <td>
      <pre><code id="sourcecode" class="cpp"><span id="line1" class="codeline ">/*
</span><span id="line2" class="codeline "> * xxHash - Extremely Fast Hash algorithm
</span><span id="line3" class="codeline "> * Header File
</span><span id="line4" class="codeline "> * Copyright (C) 2012-2023 Yann Collet
</span><span id="line5" class="codeline "> *
</span><span id="line6" class="codeline "> * BSD 2-Clause License (https://www.opensource.org/licenses/bsd-license.php)
</span><span id="line7" class="codeline "> *
</span><span id="line8" class="codeline "> * Redistribution and use in source and binary forms, with or without
</span><span id="line9" class="codeline "> * modification, are permitted provided that the following conditions are
</span><span id="line10" class="codeline "> * met:
</span><span id="line11" class="codeline "> *
</span><span id="line12" class="codeline "> *    * Redistributions of source code must retain the above copyright
</span><span id="line13" class="codeline "> *      notice, this list of conditions and the following disclaimer.
</span><span id="line14" class="codeline "> *    * Redistributions in binary form must reproduce the above
</span><span id="line15" class="codeline "> *      copyright notice, this list of conditions and the following disclaimer
</span><span id="line16" class="codeline "> *      in the documentation and/or other materials provided with the
</span><span id="line17" class="codeline "> *      distribution.
</span><span id="line18" class="codeline "> *
</span><span id="line19" class="codeline "> * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
</span><span id="line20" class="codeline "> * &#34;AS IS&#34; AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
</span><span id="line21" class="codeline "> * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
</span><span id="line22" class="codeline "> * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
</span><span id="line23" class="codeline "> * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
</span><span id="line24" class="codeline "> * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
</span><span id="line25" class="codeline "> * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
</span><span id="line26" class="codeline "> * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
</span><span id="line27" class="codeline "> * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
</span><span id="line28" class="codeline "> * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
</span><span id="line29" class="codeline "> * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
</span><span id="line30" class="codeline "> *
</span><span id="line31" class="codeline "> * You can contact the author at:
</span><span id="line32" class="codeline "> *   - xxHash homepage: https://www.xxhash.com
</span><span id="line33" class="codeline "> *   - xxHash source repository: https://github.com/Cyan4973/xxHash
</span><span id="line34" class="codeline "> */
</span><span id="line35" class="codeline ">
</span><span id="line36" class="codeline ">/*!
</span><span id="line37" class="codeline "> * @mainpage xxHash
</span><span id="line38" class="codeline "> *
</span><span id="line39" class="codeline "> * xxHash is an extremely fast non-cryptographic hash algorithm, working at RAM speed
</span><span id="line40" class="codeline "> * limits.
</span><span id="line41" class="codeline "> *
</span><span id="line42" class="codeline "> * It is proposed in four flavors, in three families:
</span><span id="line43" class="codeline "> * 1. @ref XXH32_family
</span><span id="line44" class="codeline "> *   - Classic 32-bit hash function. Simple, compact, and runs on almost all
</span><span id="line45" class="codeline "> *     32-bit and 64-bit systems.
</span><span id="line46" class="codeline "> * 2. @ref XXH64_family
</span><span id="line47" class="codeline "> *   - Classic 64-bit adaptation of XXH32. Just as simple, and runs well on most
</span><span id="line48" class="codeline "> *     64-bit systems (but _not_ 32-bit systems).
</span><span id="line49" class="codeline "> * 3. @ref XXH3_family
</span><span id="line50" class="codeline "> *   - Modern 64-bit and 128-bit hash function family which features improved
</span><span id="line51" class="codeline "> *     strength and performance across the board, especially on smaller data.
</span><span id="line52" class="codeline "> *     It benefits greatly from SIMD and 64-bit without requiring it.
</span><span id="line53" class="codeline "> *
</span><span id="line54" class="codeline "> * Benchmarks
</span><span id="line55" class="codeline "> * ---
</span><span id="line56" class="codeline "> * The reference system uses an Intel i7-9700K CPU, and runs Ubuntu x64 20.04.
</span><span id="line57" class="codeline "> * The open source benchmark program is compiled with clang v10.0 using -O3 flag.
</span><span id="line58" class="codeline "> *
</span><span id="line59" class="codeline "> * | Hash Name            | ISA ext | Width | Large Data Speed | Small Data Velocity |
</span><span id="line60" class="codeline "> * | -------------------- | ------- | ----: | ---------------: | ------------------: |
</span><span id="line61" class="codeline "> * | XXH3_64bits()        | @b AVX2 |    64 |        59.4 GB/s |               133.1 |
</span><span id="line62" class="codeline "> * | MeowHash             | AES-NI  |   128 |        58.2 GB/s |                52.5 |
</span><span id="line63" class="codeline "> * | XXH3_128bits()       | @b AVX2 |   128 |        57.9 GB/s |               118.1 |
</span><span id="line64" class="codeline "> * | CLHash               | PCLMUL  |    64 |        37.1 GB/s |                58.1 |
</span><span id="line65" class="codeline "> * | XXH3_64bits()        | @b SSE2 |    64 |        31.5 GB/s |               133.1 |
</span><span id="line66" class="codeline "> * | XXH3_128bits()       | @b SSE2 |   128 |        29.6 GB/s |               118.1 |
</span><span id="line67" class="codeline "> * | RAM sequential read  |         |   N/A |        28.0 GB/s |                 N/A |
</span><span id="line68" class="codeline "> * | ahash                | AES-NI  |    64 |        22.5 GB/s |               107.2 |
</span><span id="line69" class="codeline "> * | City64               |         |    64 |        22.0 GB/s |                76.6 |
</span><span id="line70" class="codeline "> * | T1ha2                |         |    64 |        22.0 GB/s |                99.0 |
</span><span id="line71" class="codeline "> * | City128              |         |   128 |        21.7 GB/s |                57.7 |
</span><span id="line72" class="codeline "> * | FarmHash             | AES-NI  |    64 |        21.3 GB/s |                71.9 |
</span><span id="line73" class="codeline "> * | XXH64()              |         |    64 |        19.4 GB/s |                71.0 |
</span><span id="line74" class="codeline "> * | SpookyHash           |         |    64 |        19.3 GB/s |                53.2 |
</span><span id="line75" class="codeline "> * | Mum                  |         |    64 |        18.0 GB/s |                67.0 |
</span><span id="line76" class="codeline "> * | CRC32C               | SSE4.2  |    32 |        13.0 GB/s |                57.9 |
</span><span id="line77" class="codeline "> * | XXH32()              |         |    32 |         9.7 GB/s |                71.9 |
</span><span id="line78" class="codeline "> * | City32               |         |    32 |         9.1 GB/s |                66.0 |
</span><span id="line79" class="codeline "> * | Blake3*              | @b AVX2 |   256 |         4.4 GB/s |                 8.1 |
</span><span id="line80" class="codeline "> * | Murmur3              |         |    32 |         3.9 GB/s |                56.1 |
</span><span id="line81" class="codeline "> * | SipHash*             |         |    64 |         3.0 GB/s |                43.2 |
</span><span id="line82" class="codeline "> * | Blake3*              | @b SSE2 |   256 |         2.4 GB/s |                 8.1 |
</span><span id="line83" class="codeline "> * | HighwayHash          |         |    64 |         1.4 GB/s |                 6.0 |
</span><span id="line84" class="codeline "> * | FNV64                |         |    64 |         1.2 GB/s |                62.7 |
</span><span id="line85" class="codeline "> * | Blake2*              |         |   256 |         1.1 GB/s |                 5.1 |
</span><span id="line86" class="codeline "> * | SHA1*                |         |   160 |         0.8 GB/s |                 5.6 |
</span><span id="line87" class="codeline "> * | MD5*                 |         |   128 |         0.6 GB/s |                 7.8 |
</span><span id="line88" class="codeline "> * @note
</span><span id="line89" class="codeline "> *   - Hashes which require a specific ISA extension are noted. SSE2 is also noted,
</span><span id="line90" class="codeline "> *     even though it is mandatory on x64.
</span><span id="line91" class="codeline "> *   - Hashes with an asterisk are cryptographic. Note that MD5 is non-cryptographic
</span><span id="line92" class="codeline "> *     by modern standards.
</span><span id="line93" class="codeline "> *   - Small data velocity is a rough average of algorithm&#39;s efficiency for small
</span><span id="line94" class="codeline "> *     data. For more accurate information, see the wiki.
</span><span id="line95" class="codeline "> *   - More benchmarks and strength tests are found on the wiki:
</span><span id="line96" class="codeline "> *         https://github.com/Cyan4973/xxHash/wiki
</span><span id="line97" class="codeline "> *
</span><span id="line98" class="codeline "> * Usage
</span><span id="line99" class="codeline "> * ------
</span><span id="line100" class="codeline "> * All xxHash variants use a similar API. Changing the algorithm is a trivial
</span><span id="line101" class="codeline "> * substitution.
</span><span id="line102" class="codeline "> *
</span><span id="line103" class="codeline "> * @pre
</span><span id="line104" class="codeline "> *    For functions which take an input and length parameter, the following
</span><span id="line105" class="codeline "> *    requirements are assumed:
</span><span id="line106" class="codeline "> *    - The range from [`input`, `input + length`) is valid, readable memory.
</span><span id="line107" class="codeline "> *      - The only exception is if the `length` is `0`, `input` may be `NULL`.
</span><span id="line108" class="codeline "> *    - For C++, the objects must have the *TriviallyCopyable* property, as the
</span><span id="line109" class="codeline "> *      functions access bytes directly as if it was an array of `unsigned char`.
</span><span id="line110" class="codeline "> *
</span><span id="line111" class="codeline "> * @anchor single_shot_example
</span><span id="line112" class="codeline "> * **Single Shot**
</span><span id="line113" class="codeline "> *
</span><span id="line114" class="codeline "> * These functions are stateless functions which hash a contiguous block of memory,
</span><span id="line115" class="codeline "> * immediately returning the result. They are the easiest and usually the fastest
</span><span id="line116" class="codeline "> * option.
</span><span id="line117" class="codeline "> *
</span><span id="line118" class="codeline "> * XXH32(), XXH64(), XXH3_64bits(), XXH3_128bits()
</span><span id="line119" class="codeline "> *
</span><span id="line120" class="codeline "> * @code{.c}
</span><span id="line121" class="codeline "> *   #include &lt;string.h&gt;
</span><span id="line122" class="codeline "> *   #include &#34;xxhash.h&#34;
</span><span id="line123" class="codeline "> *
</span><span id="line124" class="codeline "> *   // Example for a function which hashes a null terminated string with XXH32().
</span><span id="line125" class="codeline "> *   XXH32_hash_t hash_string(const char* string, XXH32_hash_t seed)
</span><span id="line126" class="codeline "> *   {
</span><span id="line127" class="codeline "> *       // NULL pointers are only valid if the length is zero
</span><span id="line128" class="codeline "> *       size_t length = (string == NULL) ? 0 : strlen(string);
</span><span id="line129" class="codeline "> *       return XXH32(string, length, seed);
</span><span id="line130" class="codeline "> *   }
</span><span id="line131" class="codeline "> * @endcode
</span><span id="line132" class="codeline "> *
</span><span id="line133" class="codeline "> *
</span><span id="line134" class="codeline "> * @anchor streaming_example
</span><span id="line135" class="codeline "> * **Streaming**
</span><span id="line136" class="codeline "> *
</span><span id="line137" class="codeline "> * These groups of functions allow incremental hashing of unknown size, even
</span><span id="line138" class="codeline "> * more than what would fit in a size_t.
</span><span id="line139" class="codeline "> *
</span><span id="line140" class="codeline "> * XXH32_reset(), XXH64_reset(), XXH3_64bits_reset(), XXH3_128bits_reset()
</span><span id="line141" class="codeline "> *
</span><span id="line142" class="codeline "> * @code{.c}
</span><span id="line143" class="codeline "> *   #include &lt;stdio.h&gt;
</span><span id="line144" class="codeline "> *   #include &lt;assert.h&gt;
</span><span id="line145" class="codeline "> *   #include &#34;xxhash.h&#34;
</span><span id="line146" class="codeline "> *   // Example for a function which hashes a FILE incrementally with XXH3_64bits().
</span><span id="line147" class="codeline "> *   XXH64_hash_t hashFile(FILE* f)
</span><span id="line148" class="codeline "> *   {
</span><span id="line149" class="codeline "> *       // Allocate a state struct. Do not just use malloc() or new.
</span><span id="line150" class="codeline "> *       XXH3_state_t* state = XXH3_createState();
</span><span id="line151" class="codeline "> *       assert(state != NULL &amp;&amp; &#34;Out of memory!&#34;);
</span><span id="line152" class="codeline "> *       // Reset the state to start a new hashing session.
</span><span id="line153" class="codeline "> *       XXH3_64bits_reset(state);
</span><span id="line154" class="codeline "> *       char buffer[4096];
</span><span id="line155" class="codeline "> *       size_t count;
</span><span id="line156" class="codeline "> *       // Read the file in chunks
</span><span id="line157" class="codeline "> *       while ((count = fread(buffer, 1, sizeof(buffer), f)) != 0) {
</span><span id="line158" class="codeline "> *           // Run update() as many times as necessary to process the data
</span><span id="line159" class="codeline "> *           XXH3_64bits_update(state, buffer, count);
</span><span id="line160" class="codeline "> *       }
</span><span id="line161" class="codeline "> *       // Retrieve the finalized hash. This will not change the state.
</span><span id="line162" class="codeline "> *       XXH64_hash_t result = XXH3_64bits_digest(state);
</span><span id="line163" class="codeline "> *       // Free the state. Do not use free().
</span><span id="line164" class="codeline "> *       XXH3_freeState(state);
</span><span id="line165" class="codeline "> *       return result;
</span><span id="line166" class="codeline "> *   }
</span><span id="line167" class="codeline "> * @endcode
</span><span id="line168" class="codeline "> *
</span><span id="line169" class="codeline "> * Streaming functions generate the xxHash value from an incremental input.
</span><span id="line170" class="codeline "> * This method is slower than single-call functions, due to state management.
</span><span id="line171" class="codeline "> * For small inputs, prefer `XXH32()` and `XXH64()`, which are better optimized.
</span><span id="line172" class="codeline "> *
</span><span id="line173" class="codeline "> * An XXH state must first be allocated using `XXH*_createState()`.
</span><span id="line174" class="codeline "> *
</span><span id="line175" class="codeline "> * Start a new hash by initializing the state with a seed using `XXH*_reset()`.
</span><span id="line176" class="codeline "> *
</span><span id="line177" class="codeline "> * Then, feed the hash state by calling `XXH*_update()` as many times as necessary.
</span><span id="line178" class="codeline "> *
</span><span id="line179" class="codeline "> * The function returns an error code, with 0 meaning OK, and any other value
</span><span id="line180" class="codeline "> * meaning there is an error.
</span><span id="line181" class="codeline "> *
</span><span id="line182" class="codeline "> * Finally, a hash value can be produced anytime, by using `XXH*_digest()`.
</span><span id="line183" class="codeline "> * This function returns the nn-bits hash as an int or long long.
</span><span id="line184" class="codeline "> *
</span><span id="line185" class="codeline "> * It&#39;s still possible to continue inserting input into the hash state after a
</span><span id="line186" class="codeline "> * digest, and generate new hash values later on by invoking `XXH*_digest()`.
</span><span id="line187" class="codeline "> *
</span><span id="line188" class="codeline "> * When done, release the state using `XXH*_freeState()`.
</span><span id="line189" class="codeline "> *
</span><span id="line190" class="codeline "> *
</span><span id="line191" class="codeline "> * @anchor canonical_representation_example
</span><span id="line192" class="codeline "> * **Canonical Representation**
</span><span id="line193" class="codeline "> *
</span><span id="line194" class="codeline "> * The default return values from XXH functions are unsigned 32, 64 and 128 bit
</span><span id="line195" class="codeline "> * integers.
</span><span id="line196" class="codeline "> * This the simplest and fastest format for further post-processing.
</span><span id="line197" class="codeline "> *
</span><span id="line198" class="codeline "> * However, this leaves open the question of what is the order on the byte level,
</span><span id="line199" class="codeline "> * since little and big endian conventions will store the same number differently.
</span><span id="line200" class="codeline "> *
</span><span id="line201" class="codeline "> * The canonical representation settles this issue by mandating big-endian
</span><span id="line202" class="codeline "> * convention, the same convention as human-readable numbers (large digits first).
</span><span id="line203" class="codeline "> *
</span><span id="line204" class="codeline "> * When writing hash values to storage, sending them over a network, or printing
</span><span id="line205" class="codeline "> * them, it&#39;s highly recommended to use the canonical representation to ensure
</span><span id="line206" class="codeline "> * portability across a wider range of systems, present and future.
</span><span id="line207" class="codeline "> *
</span><span id="line208" class="codeline "> * The following functions allow transformation of hash values to and from
</span><span id="line209" class="codeline "> * canonical format.
</span><span id="line210" class="codeline "> *
</span><span id="line211" class="codeline "> * XXH32_canonicalFromHash(), XXH32_hashFromCanonical(),
</span><span id="line212" class="codeline "> * XXH64_canonicalFromHash(), XXH64_hashFromCanonical(),
</span><span id="line213" class="codeline "> * XXH128_canonicalFromHash(), XXH128_hashFromCanonical(),
</span><span id="line214" class="codeline "> *
</span><span id="line215" class="codeline "> * @code{.c}
</span><span id="line216" class="codeline "> *   #include &lt;stdio.h&gt;
</span><span id="line217" class="codeline "> *   #include &#34;xxhash.h&#34;
</span><span id="line218" class="codeline "> *
</span><span id="line219" class="codeline "> *   // Example for a function which prints XXH32_hash_t in human readable format
</span><span id="line220" class="codeline "> *   void printXxh32(XXH32_hash_t hash)
</span><span id="line221" class="codeline "> *   {
</span><span id="line222" class="codeline "> *       XXH32_canonical_t cano;
</span><span id="line223" class="codeline "> *       XXH32_canonicalFromHash(&amp;cano, hash);
</span><span id="line224" class="codeline "> *       size_t i;
</span><span id="line225" class="codeline "> *       for(i = 0; i &lt; sizeof(cano.digest); ++i) {
</span><span id="line226" class="codeline "> *           printf(&#34;%02x&#34;, cano.digest[i]);
</span><span id="line227" class="codeline "> *       }
</span><span id="line228" class="codeline "> *       printf(&#34;\n&#34;);
</span><span id="line229" class="codeline "> *   }
</span><span id="line230" class="codeline "> *
</span><span id="line231" class="codeline "> *   // Example for a function which converts XXH32_canonical_t to XXH32_hash_t
</span><span id="line232" class="codeline "> *   XXH32_hash_t convertCanonicalToXxh32(XXH32_canonical_t cano)
</span><span id="line233" class="codeline "> *   {
</span><span id="line234" class="codeline "> *       XXH32_hash_t hash = XXH32_hashFromCanonical(&amp;cano);
</span><span id="line235" class="codeline "> *       return hash;
</span><span id="line236" class="codeline "> *   }
</span><span id="line237" class="codeline "> * @endcode
</span><span id="line238" class="codeline "> *
</span><span id="line239" class="codeline "> *
</span><span id="line240" class="codeline "> * @file xxhash.h
</span><span id="line241" class="codeline "> * xxHash prototypes and implementation
</span><span id="line242" class="codeline "> */
</span><span id="line243" class="codeline ">
</span><span id="line244" class="codeline ">#if defined (__cplusplus)
</span><span id="line245" class="codeline ">extern &#34;C&#34; {
</span><span id="line246" class="codeline ">#endif
</span><span id="line247" class="codeline ">
</span><span id="line248" class="codeline ">/* ****************************
</span><span id="line249" class="codeline "> *  INLINE mode
</span><span id="line250" class="codeline "> ******************************/
</span><span id="line251" class="codeline ">/*!
</span><span id="line252" class="codeline "> * @defgroup public Public API
</span><span id="line253" class="codeline "> * Contains details on the public xxHash functions.
</span><span id="line254" class="codeline "> * @{
</span><span id="line255" class="codeline "> */
</span><span id="line256" class="codeline ">#ifdef XXH_DOXYGEN
</span><span id="line257" class="codeline ">/*!
</span><span id="line258" class="codeline "> * @brief Gives access to internal state declaration, required for static allocation.
</span><span id="line259" class="codeline "> *
</span><span id="line260" class="codeline "> * Incompatible with dynamic linking, due to risks of ABI changes.
</span><span id="line261" class="codeline "> *
</span><span id="line262" class="codeline "> * Usage:
</span><span id="line263" class="codeline "> * @code{.c}
</span><span id="line264" class="codeline "> *     #define XXH_STATIC_LINKING_ONLY
</span><span id="line265" class="codeline "> *     #include &#34;xxhash.h&#34;
</span><span id="line266" class="codeline "> * @endcode
</span><span id="line267" class="codeline "> */
</span><span id="line268" class="codeline ">#  define XXH_STATIC_LINKING_ONLY
</span><span id="line269" class="codeline ">/* Do not undef XXH_STATIC_LINKING_ONLY for Doxygen */
</span><span id="line270" class="codeline ">
</span><span id="line271" class="codeline ">/*!
</span><span id="line272" class="codeline "> * @brief Gives access to internal definitions.
</span><span id="line273" class="codeline "> *
</span><span id="line274" class="codeline "> * Usage:
</span><span id="line275" class="codeline "> * @code{.c}
</span><span id="line276" class="codeline "> *     #define XXH_STATIC_LINKING_ONLY
</span><span id="line277" class="codeline "> *     #define XXH_IMPLEMENTATION
</span><span id="line278" class="codeline "> *     #include &#34;xxhash.h&#34;
</span><span id="line279" class="codeline "> * @endcode
</span><span id="line280" class="codeline "> */
</span><span id="line281" class="codeline ">#  define XXH_IMPLEMENTATION
</span><span id="line282" class="codeline ">/* Do not undef XXH_IMPLEMENTATION for Doxygen */
</span><span id="line283" class="codeline ">
</span><span id="line284" class="codeline ">/*!
</span><span id="line285" class="codeline "> * @brief Exposes the implementation and marks all functions as `inline`.
</span><span id="line286" class="codeline "> *
</span><span id="line287" class="codeline "> * Use these build macros to inline xxhash into the target unit.
</span><span id="line288" class="codeline "> * Inlining improves performance on small inputs, especially when the length is
</span><span id="line289" class="codeline "> * expressed as a compile-time constant:
</span><span id="line290" class="codeline "> *
</span><span id="line291" class="codeline "> *  https://fastcompression.blogspot.com/2018/03/xxhash-for-small-keys-impressive-power.html
</span><span id="line292" class="codeline "> *
</span><span id="line293" class="codeline "> * It also keeps xxHash symbols private to the unit, so they are not exported.
</span><span id="line294" class="codeline "> *
</span><span id="line295" class="codeline "> * Usage:
</span><span id="line296" class="codeline "> * @code{.c}
</span><span id="line297" class="codeline "> *     #define XXH_INLINE_ALL
</span><span id="line298" class="codeline "> *     #include &#34;xxhash.h&#34;
</span><span id="line299" class="codeline "> * @endcode
</span><span id="line300" class="codeline "> * Do not compile and link xxhash.o as a separate object, as it is not useful.
</span><span id="line301" class="codeline "> */
</span><span id="line302" class="codeline ">#  define XXH_INLINE_ALL
</span><span id="line303" class="codeline ">#  undef XXH_INLINE_ALL
</span><span id="line304" class="codeline ">/*!
</span><span id="line305" class="codeline "> * @brief Exposes the implementation without marking functions as inline.
</span><span id="line306" class="codeline "> */
</span><span id="line307" class="codeline ">#  define XXH_PRIVATE_API
</span><span id="line308" class="codeline ">#  undef XXH_PRIVATE_API
</span><span id="line309" class="codeline ">/*!
</span><span id="line310" class="codeline "> * @brief Emulate a namespace by transparently prefixing all symbols.
</span><span id="line311" class="codeline "> *
</span><span id="line312" class="codeline "> * If you want to include _and expose_ xxHash functions from within your own
</span><span id="line313" class="codeline "> * library, but also want to avoid symbol collisions with other libraries which
</span><span id="line314" class="codeline "> * may also include xxHash, you can use @ref XXH_NAMESPACE to automatically prefix
</span><span id="line315" class="codeline "> * any public symbol from xxhash library with the value of @ref XXH_NAMESPACE
</span><span id="line316" class="codeline "> * (therefore, avoid empty or numeric values).
</span><span id="line317" class="codeline "> *
</span><span id="line318" class="codeline "> * Note that no change is required within the calling program as long as it
</span><span id="line319" class="codeline "> * includes `xxhash.h`: Regular symbol names will be automatically translated
</span><span id="line320" class="codeline "> * by this header.
</span><span id="line321" class="codeline "> */
</span><span id="line322" class="codeline ">#  define XXH_NAMESPACE /* YOUR NAME HERE */
</span><span id="line323" class="codeline ">#  undef XXH_NAMESPACE
</span><span id="line324" class="codeline ">#endif
</span><span id="line325" class="codeline ">
</span><span id="line326" class="codeline ">#if (defined(XXH_INLINE_ALL) || defined(XXH_PRIVATE_API)) \
</span><span id="line327" class="codeline ">    &amp;&amp; !defined(XXH_INLINE_ALL_31684351384)
</span><span id="line328" class="codeline ">   /* this section should be traversed only once */
</span><span id="line329" class="codeline ">#  define XXH_INLINE_ALL_31684351384
</span><span id="line330" class="codeline ">   /* give access to the advanced API, required to compile implementations */
</span><span id="line331" class="codeline ">#  undef XXH_STATIC_LINKING_ONLY   /* avoid macro redef */
</span><span id="line332" class="codeline ">#  define XXH_STATIC_LINKING_ONLY
</span><span id="line333" class="codeline ">   /* make all functions private */
</span><span id="line334" class="codeline ">#  undef XXH_PUBLIC_API
</span><span id="line335" class="codeline ">#  if defined(__GNUC__)
</span><span id="line336" class="codeline ">#    define XXH_PUBLIC_API static __inline __attribute__((__unused__))
</span><span id="line337" class="codeline ">#  elif defined (__cplusplus) || (defined (__STDC_VERSION__) &amp;&amp; (__STDC_VERSION__ &gt;= 199901L) /* C99 */)
</span><span id="line338" class="codeline ">#    define XXH_PUBLIC_API static inline
</span><span id="line339" class="codeline ">#  elif defined(_MSC_VER)
</span><span id="line340" class="codeline ">#    define XXH_PUBLIC_API static __inline
</span><span id="line341" class="codeline ">#  else
</span><span id="line342" class="codeline ">     /* note: this version may generate warnings for unused static functions */
</span><span id="line343" class="codeline ">#    define XXH_PUBLIC_API static
</span><span id="line344" class="codeline ">#  endif
</span><span id="line345" class="codeline ">
</span><span id="line346" class="codeline ">   /*
</span><span id="line347" class="codeline ">    * This part deals with the special case where a unit wants to inline xxHash,
</span><span id="line348" class="codeline ">    * but &#34;xxhash.h&#34; has previously been included without XXH_INLINE_ALL,
</span><span id="line349" class="codeline ">    * such as part of some previously included *.h header file.
</span><span id="line350" class="codeline ">    * Without further action, the new include would just be ignored,
</span><span id="line351" class="codeline ">    * and functions would effectively _not_ be inlined (silent failure).
</span><span id="line352" class="codeline ">    * The following macros solve this situation by prefixing all inlined names,
</span><span id="line353" class="codeline ">    * avoiding naming collision with previous inclusions.
</span><span id="line354" class="codeline ">    */
</span><span id="line355" class="codeline ">   /* Before that, we unconditionally #undef all symbols,
</span><span id="line356" class="codeline ">    * in case they were already defined with XXH_NAMESPACE.
</span><span id="line357" class="codeline ">    * They will then be redefined for XXH_INLINE_ALL
</span><span id="line358" class="codeline ">    */
</span><span id="line359" class="codeline ">#  undef XXH_versionNumber
</span><span id="line360" class="codeline ">    /* XXH32 */
</span><span id="line361" class="codeline ">#  undef XXH32
</span><span id="line362" class="codeline ">#  undef XXH32_createState
</span><span id="line363" class="codeline ">#  undef XXH32_freeState
</span><span id="line364" class="codeline ">#  undef XXH32_reset
</span><span id="line365" class="codeline ">#  undef XXH32_update
</span><span id="line366" class="codeline ">#  undef XXH32_digest
</span><span id="line367" class="codeline ">#  undef XXH32_copyState
</span><span id="line368" class="codeline ">#  undef XXH32_canonicalFromHash
</span><span id="line369" class="codeline ">#  undef XXH32_hashFromCanonical
</span><span id="line370" class="codeline ">    /* XXH64 */
</span><span id="line371" class="codeline ">#  undef XXH64
</span><span id="line372" class="codeline ">#  undef XXH64_createState
</span><span id="line373" class="codeline ">#  undef XXH64_freeState
</span><span id="line374" class="codeline ">#  undef XXH64_reset
</span><span id="line375" class="codeline ">#  undef XXH64_update
</span><span id="line376" class="codeline ">#  undef XXH64_digest
</span><span id="line377" class="codeline ">#  undef XXH64_copyState
</span><span id="line378" class="codeline ">#  undef XXH64_canonicalFromHash
</span><span id="line379" class="codeline ">#  undef XXH64_hashFromCanonical
</span><span id="line380" class="codeline ">    /* XXH3_64bits */
</span><span id="line381" class="codeline ">#  undef XXH3_64bits
</span><span id="line382" class="codeline ">#  undef XXH3_64bits_withSecret
</span><span id="line383" class="codeline ">#  undef XXH3_64bits_withSeed
</span><span id="line384" class="codeline ">#  undef XXH3_64bits_withSecretandSeed
</span><span id="line385" class="codeline ">#  undef XXH3_createState
</span><span id="line386" class="codeline ">#  undef XXH3_freeState
</span><span id="line387" class="codeline ">#  undef XXH3_copyState
</span><span id="line388" class="codeline ">#  undef XXH3_64bits_reset
</span><span id="line389" class="codeline ">#  undef XXH3_64bits_reset_withSeed
</span><span id="line390" class="codeline ">#  undef XXH3_64bits_reset_withSecret
</span><span id="line391" class="codeline ">#  undef XXH3_64bits_update
</span><span id="line392" class="codeline ">#  undef XXH3_64bits_digest
</span><span id="line393" class="codeline ">#  undef XXH3_generateSecret
</span><span id="line394" class="codeline ">    /* XXH3_128bits */
</span><span id="line395" class="codeline ">#  undef XXH128
</span><span id="line396" class="codeline ">#  undef XXH3_128bits
</span><span id="line397" class="codeline ">#  undef XXH3_128bits_withSeed
</span><span id="line398" class="codeline ">#  undef XXH3_128bits_withSecret
</span><span id="line399" class="codeline ">#  undef XXH3_128bits_reset
</span><span id="line400" class="codeline ">#  undef XXH3_128bits_reset_withSeed
</span><span id="line401" class="codeline ">#  undef XXH3_128bits_reset_withSecret
</span><span id="line402" class="codeline ">#  undef XXH3_128bits_reset_withSecretandSeed
</span><span id="line403" class="codeline ">#  undef XXH3_128bits_update
</span><span id="line404" class="codeline ">#  undef XXH3_128bits_digest
</span><span id="line405" class="codeline ">#  undef XXH128_isEqual
</span><span id="line406" class="codeline ">#  undef XXH128_cmp
</span><span id="line407" class="codeline ">#  undef XXH128_canonicalFromHash
</span><span id="line408" class="codeline ">#  undef XXH128_hashFromCanonical
</span><span id="line409" class="codeline ">    /* Finally, free the namespace itself */
</span><span id="line410" class="codeline ">#  undef XXH_NAMESPACE
</span><span id="line411" class="codeline ">
</span><span id="line412" class="codeline ">    /* employ the namespace for XXH_INLINE_ALL */
</span><span id="line413" class="codeline ">#  define XXH_NAMESPACE XXH_INLINE_
</span><span id="line414" class="codeline ">   /*
</span><span id="line415" class="codeline ">    * Some identifiers (enums, type names) are not symbols,
</span><span id="line416" class="codeline ">    * but they must nonetheless be renamed to avoid redeclaration.
</span><span id="line417" class="codeline ">    * Alternative solution: do not redeclare them.
</span><span id="line418" class="codeline ">    * However, this requires some #ifdefs, and has a more dispersed impact.
</span><span id="line419" class="codeline ">    * Meanwhile, renaming can be achieved in a single place.
</span><span id="line420" class="codeline ">    */
</span><span id="line421" class="codeline ">#  define XXH_IPREF(Id)   XXH_NAMESPACE ## Id
</span><span id="line422" class="codeline ">#  define XXH_OK XXH_IPREF(XXH_OK)
</span><span id="line423" class="codeline ">#  define XXH_ERROR XXH_IPREF(XXH_ERROR)
</span><span id="line424" class="codeline ">#  define XXH_errorcode XXH_IPREF(XXH_errorcode)
</span><span id="line425" class="codeline ">#  define XXH32_canonical_t  XXH_IPREF(XXH32_canonical_t)
</span><span id="line426" class="codeline ">#  define XXH64_canonical_t  XXH_IPREF(XXH64_canonical_t)
</span><span id="line427" class="codeline ">#  define XXH128_canonical_t XXH_IPREF(XXH128_canonical_t)
</span><span id="line428" class="codeline ">#  define XXH32_state_s XXH_IPREF(XXH32_state_s)
</span><span id="line429" class="codeline ">#  define XXH32_state_t XXH_IPREF(XXH32_state_t)
</span><span id="line430" class="codeline ">#  define XXH64_state_s XXH_IPREF(XXH64_state_s)
</span><span id="line431" class="codeline ">#  define XXH64_state_t XXH_IPREF(XXH64_state_t)
</span><span id="line432" class="codeline ">#  define XXH3_state_s  XXH_IPREF(XXH3_state_s)
</span><span id="line433" class="codeline ">#  define XXH3_state_t  XXH_IPREF(XXH3_state_t)
</span><span id="line434" class="codeline ">#  define XXH128_hash_t XXH_IPREF(XXH128_hash_t)
</span><span id="line435" class="codeline ">   /* Ensure the header is parsed again, even if it was previously included */
</span><span id="line436" class="codeline ">#  undef XXHASH_H_5627135585666179
</span><span id="line437" class="codeline ">#  undef XXHASH_H_STATIC_13879238742
</span><span id="line438" class="codeline ">#endif /* XXH_INLINE_ALL || XXH_PRIVATE_API */
</span><span id="line439" class="codeline ">
</span><span id="line440" class="codeline ">/* ****************************************************************
</span><span id="line441" class="codeline "> *  Stable API
</span><span id="line442" class="codeline "> *****************************************************************/
</span><span id="line443" class="codeline ">#ifndef XXHASH_H_5627135585666179
</span><span id="line444" class="codeline ">#define XXHASH_H_5627135585666179 1
</span><span id="line445" class="codeline ">
</span><span id="line446" class="codeline ">/*! @brief Marks a global symbol. */
</span><span id="line447" class="codeline ">#if !defined(XXH_INLINE_ALL) &amp;&amp; !defined(XXH_PRIVATE_API)
</span><span id="line448" class="codeline ">#  if defined(_WIN32) &amp;&amp; defined(_MSC_VER) &amp;&amp; (defined(XXH_IMPORT) || defined(XXH_EXPORT))
</span><span id="line449" class="codeline ">#    ifdef XXH_EXPORT
</span><span id="line450" class="codeline ">#      define XXH_PUBLIC_API __declspec(dllexport)
</span><span id="line451" class="codeline ">#    elif XXH_IMPORT
</span><span id="line452" class="codeline ">#      define XXH_PUBLIC_API __declspec(dllimport)
</span><span id="line453" class="codeline ">#    endif
</span><span id="line454" class="codeline ">#  else
</span><span id="line455" class="codeline ">#    define XXH_PUBLIC_API   /* do nothing */
</span><span id="line456" class="codeline ">#  endif
</span><span id="line457" class="codeline ">#endif
</span><span id="line458" class="codeline ">
</span><span id="line459" class="codeline ">#ifdef XXH_NAMESPACE
</span><span id="line460" class="codeline ">#  define XXH_CAT(A,B) A##B
</span><span id="line461" class="codeline ">#  define XXH_NAME2(A,B) XXH_CAT(A,B)
</span><span id="line462" class="codeline ">#  define XXH_versionNumber XXH_NAME2(XXH_NAMESPACE, XXH_versionNumber)
</span><span id="line463" class="codeline ">/* XXH32 */
</span><span id="line464" class="codeline ">#  define XXH32 XXH_NAME2(XXH_NAMESPACE, XXH32)
</span><span id="line465" class="codeline ">#  define XXH32_createState XXH_NAME2(XXH_NAMESPACE, XXH32_createState)
</span><span id="line466" class="codeline ">#  define XXH32_freeState XXH_NAME2(XXH_NAMESPACE, XXH32_freeState)
</span><span id="line467" class="codeline ">#  define XXH32_reset XXH_NAME2(XXH_NAMESPACE, XXH32_reset)
</span><span id="line468" class="codeline ">#  define XXH32_update XXH_NAME2(XXH_NAMESPACE, XXH32_update)
</span><span id="line469" class="codeline ">#  define XXH32_digest XXH_NAME2(XXH_NAMESPACE, XXH32_digest)
</span><span id="line470" class="codeline ">#  define XXH32_copyState XXH_NAME2(XXH_NAMESPACE, XXH32_copyState)
</span><span id="line471" class="codeline ">#  define XXH32_canonicalFromHash XXH_NAME2(XXH_NAMESPACE, XXH32_canonicalFromHash)
</span><span id="line472" class="codeline ">#  define XXH32_hashFromCanonical XXH_NAME2(XXH_NAMESPACE, XXH32_hashFromCanonical)
</span><span id="line473" class="codeline ">/* XXH64 */
</span><span id="line474" class="codeline ">#  define XXH64 XXH_NAME2(XXH_NAMESPACE, XXH64)
</span><span id="line475" class="codeline ">#  define XXH64_createState XXH_NAME2(XXH_NAMESPACE, XXH64_createState)
</span><span id="line476" class="codeline ">#  define XXH64_freeState XXH_NAME2(XXH_NAMESPACE, XXH64_freeState)
</span><span id="line477" class="codeline ">#  define XXH64_reset XXH_NAME2(XXH_NAMESPACE, XXH64_reset)
</span><span id="line478" class="codeline ">#  define XXH64_update XXH_NAME2(XXH_NAMESPACE, XXH64_update)
</span><span id="line479" class="codeline ">#  define XXH64_digest XXH_NAME2(XXH_NAMESPACE, XXH64_digest)
</span><span id="line480" class="codeline ">#  define XXH64_copyState XXH_NAME2(XXH_NAMESPACE, XXH64_copyState)
</span><span id="line481" class="codeline ">#  define XXH64_canonicalFromHash XXH_NAME2(XXH_NAMESPACE, XXH64_canonicalFromHash)
</span><span id="line482" class="codeline ">#  define XXH64_hashFromCanonical XXH_NAME2(XXH_NAMESPACE, XXH64_hashFromCanonical)
</span><span id="line483" class="codeline ">/* XXH3_64bits */
</span><span id="line484" class="codeline ">#  define XXH3_64bits XXH_NAME2(XXH_NAMESPACE, XXH3_64bits)
</span><span id="line485" class="codeline ">#  define XXH3_64bits_withSecret XXH_NAME2(XXH_NAMESPACE, XXH3_64bits_withSecret)
</span><span id="line486" class="codeline ">#  define XXH3_64bits_withSeed XXH_NAME2(XXH_NAMESPACE, XXH3_64bits_withSeed)
</span><span id="line487" class="codeline ">#  define XXH3_64bits_withSecretandSeed XXH_NAME2(XXH_NAMESPACE, XXH3_64bits_withSecretandSeed)
</span><span id="line488" class="codeline ">#  define XXH3_createState XXH_NAME2(XXH_NAMESPACE, XXH3_createState)
</span><span id="line489" class="codeline ">#  define XXH3_freeState XXH_NAME2(XXH_NAMESPACE, XXH3_freeState)
</span><span id="line490" class="codeline ">#  define XXH3_copyState XXH_NAME2(XXH_NAMESPACE, XXH3_copyState)
</span><span id="line491" class="codeline ">#  define XXH3_64bits_reset XXH_NAME2(XXH_NAMESPACE, XXH3_64bits_reset)
</span><span id="line492" class="codeline ">#  define XXH3_64bits_reset_withSeed XXH_NAME2(XXH_NAMESPACE, XXH3_64bits_reset_withSeed)
</span><span id="line493" class="codeline ">#  define XXH3_64bits_reset_withSecret XXH_NAME2(XXH_NAMESPACE, XXH3_64bits_reset_withSecret)
</span><span id="line494" class="codeline ">#  define XXH3_64bits_reset_withSecretandSeed XXH_NAME2(XXH_NAMESPACE, XXH3_64bits_reset_withSecretandSeed)
</span><span id="line495" class="codeline ">#  define XXH3_64bits_update XXH_NAME2(XXH_NAMESPACE, XXH3_64bits_update)
</span><span id="line496" class="codeline ">#  define XXH3_64bits_digest XXH_NAME2(XXH_NAMESPACE, XXH3_64bits_digest)
</span><span id="line497" class="codeline ">#  define XXH3_generateSecret XXH_NAME2(XXH_NAMESPACE, XXH3_generateSecret)
</span><span id="line498" class="codeline ">#  define XXH3_generateSecret_fromSeed XXH_NAME2(XXH_NAMESPACE, XXH3_generateSecret_fromSeed)
</span><span id="line499" class="codeline ">/* XXH3_128bits */
</span><span id="line500" class="codeline ">#  define XXH128 XXH_NAME2(XXH_NAMESPACE, XXH128)
</span><span id="line501" class="codeline ">#  define XXH3_128bits XXH_NAME2(XXH_NAMESPACE, XXH3_128bits)
</span><span id="line502" class="codeline ">#  define XXH3_128bits_withSeed XXH_NAME2(XXH_NAMESPACE, XXH3_128bits_withSeed)
</span><span id="line503" class="codeline ">#  define XXH3_128bits_withSecret XXH_NAME2(XXH_NAMESPACE, XXH3_128bits_withSecret)
</span><span id="line504" class="codeline ">#  define XXH3_128bits_withSecretandSeed XXH_NAME2(XXH_NAMESPACE, XXH3_128bits_withSecretandSeed)
</span><span id="line505" class="codeline ">#  define XXH3_128bits_reset XXH_NAME2(XXH_NAMESPACE, XXH3_128bits_reset)
</span><span id="line506" class="codeline ">#  define XXH3_128bits_reset_withSeed XXH_NAME2(XXH_NAMESPACE, XXH3_128bits_reset_withSeed)
</span><span id="line507" class="codeline ">#  define XXH3_128bits_reset_withSecret XXH_NAME2(XXH_NAMESPACE, XXH3_128bits_reset_withSecret)
</span><span id="line508" class="codeline ">#  define XXH3_128bits_reset_withSecretandSeed XXH_NAME2(XXH_NAMESPACE, XXH3_128bits_reset_withSecretandSeed)
</span><span id="line509" class="codeline ">#  define XXH3_128bits_update XXH_NAME2(XXH_NAMESPACE, XXH3_128bits_update)
</span><span id="line510" class="codeline ">#  define XXH3_128bits_digest XXH_NAME2(XXH_NAMESPACE, XXH3_128bits_digest)
</span><span id="line511" class="codeline ">#  define XXH128_isEqual XXH_NAME2(XXH_NAMESPACE, XXH128_isEqual)
</span><span id="line512" class="codeline ">#  define XXH128_cmp     XXH_NAME2(XXH_NAMESPACE, XXH128_cmp)
</span><span id="line513" class="codeline ">#  define XXH128_canonicalFromHash XXH_NAME2(XXH_NAMESPACE, XXH128_canonicalFromHash)
</span><span id="line514" class="codeline ">#  define XXH128_hashFromCanonical XXH_NAME2(XXH_NAMESPACE, XXH128_hashFromCanonical)
</span><span id="line515" class="codeline ">#endif
</span><span id="line516" class="codeline ">
</span><span id="line517" class="codeline ">
</span><span id="line518" class="codeline ">/* *************************************
</span><span id="line519" class="codeline ">*  Compiler specifics
</span><span id="line520" class="codeline ">***************************************/
</span><span id="line521" class="codeline ">
</span><span id="line522" class="codeline ">/* specific declaration modes for Windows */
</span><span id="line523" class="codeline ">#if !defined(XXH_INLINE_ALL) &amp;&amp; !defined(XXH_PRIVATE_API)
</span><span id="line524" class="codeline ">#  if defined(_WIN32) &amp;&amp; defined(_MSC_VER) &amp;&amp; (defined(XXH_IMPORT) || defined(XXH_EXPORT))
</span><span id="line525" class="codeline ">#    ifdef XXH_EXPORT
</span><span id="line526" class="codeline ">#      define XXH_PUBLIC_API __declspec(dllexport)
</span><span id="line527" class="codeline ">#    elif XXH_IMPORT
</span><span id="line528" class="codeline ">#      define XXH_PUBLIC_API __declspec(dllimport)
</span><span id="line529" class="codeline ">#    endif
</span><span id="line530" class="codeline ">#  else
</span><span id="line531" class="codeline ">#    define XXH_PUBLIC_API   /* do nothing */
</span><span id="line532" class="codeline ">#  endif
</span><span id="line533" class="codeline ">#endif
</span><span id="line534" class="codeline ">
</span><span id="line535" class="codeline ">#if defined (__GNUC__)
</span><span id="line536" class="codeline "># define XXH_CONSTF  __attribute__((__const__))
</span><span id="line537" class="codeline "># define XXH_PUREF   __attribute__((__pure__))
</span><span id="line538" class="codeline "># define XXH_MALLOCF __attribute__((__malloc__))
</span><span id="line539" class="codeline ">#else
</span><span id="line540" class="codeline "># define XXH_CONSTF  /* disable */
</span><span id="line541" class="codeline "># define XXH_PUREF
</span><span id="line542" class="codeline "># define XXH_MALLOCF
</span><span id="line543" class="codeline ">#endif
</span><span id="line544" class="codeline ">
</span><span id="line545" class="codeline ">/* *************************************
</span><span id="line546" class="codeline ">*  Version
</span><span id="line547" class="codeline ">***************************************/
</span><span id="line548" class="codeline ">#define XXH_VERSION_MAJOR    0
</span><span id="line549" class="codeline ">#define XXH_VERSION_MINOR    8
</span><span id="line550" class="codeline ">#define XXH_VERSION_RELEASE  3
</span><span id="line551" class="codeline ">/*! @brief Version number, encoded as two digits each */
</span><span id="line552" class="codeline ">#define XXH_VERSION_NUMBER  (XXH_VERSION_MAJOR *100*100 + XXH_VERSION_MINOR *100 + XXH_VERSION_RELEASE)
</span><span id="line553" class="codeline ">
</span><span id="line554" class="codeline ">/*!
</span><span id="line555" class="codeline "> * @brief Obtains the xxHash version.
</span><span id="line556" class="codeline "> *
</span><span id="line557" class="codeline "> * This is mostly useful when xxHash is compiled as a shared library,
</span><span id="line558" class="codeline "> * since the returned value comes from the library, as opposed to header file.
</span><span id="line559" class="codeline "> *
</span><span id="line560" class="codeline "> * @return @ref XXH_VERSION_NUMBER of the invoked library.
</span><span id="line561" class="codeline "> */
</span><span id="line562" class="codeline ">XXH_PUBLIC_API XXH_CONSTF unsigned XXH_versionNumber (void);
</span><span id="line563" class="codeline ">
</span><span id="line564" class="codeline ">
</span><span id="line565" class="codeline ">/* ****************************
</span><span id="line566" class="codeline ">*  Common basic types
</span><span id="line567" class="codeline ">******************************/
</span><span id="line568" class="codeline ">#include &lt;stddef.h&gt;   /* size_t */
</span><span id="line569" class="codeline ">/*!
</span><span id="line570" class="codeline "> * @brief Exit code for the streaming API.
</span><span id="line571" class="codeline "> */
</span><span id="line572" class="codeline ">typedef enum {
</span><span id="line573" class="codeline ">    XXH_OK = 0, /*!&lt; OK */
</span><span id="line574" class="codeline ">    XXH_ERROR   /*!&lt; Error */
</span><span id="line575" class="codeline ">} XXH_errorcode;
</span><span id="line576" class="codeline ">
</span><span id="line577" class="codeline ">
</span><span id="line578" class="codeline ">/*-**********************************************************************
</span><span id="line579" class="codeline ">*  32-bit hash
</span><span id="line580" class="codeline ">************************************************************************/
</span><span id="line581" class="codeline ">#if defined(XXH_DOXYGEN) /* Don&#39;t show &lt;stdint.h&gt; include */
</span><span id="line582" class="codeline ">/*!
</span><span id="line583" class="codeline "> * @brief An unsigned 32-bit integer.
</span><span id="line584" class="codeline "> *
</span><span id="line585" class="codeline "> * Not necessarily defined to `uint32_t` but functionally equivalent.
</span><span id="line586" class="codeline "> */
</span><span id="line587" class="codeline ">typedef uint32_t XXH32_hash_t;
</span><span id="line588" class="codeline ">
</span><span id="line589" class="codeline ">#elif !defined (__VMS) \
</span><span id="line590" class="codeline ">  &amp;&amp; (defined (__cplusplus) \
</span><span id="line591" class="codeline ">  || (defined (__STDC_VERSION__) &amp;&amp; (__STDC_VERSION__ &gt;= 199901L) /* C99 */) )
</span><span id="line592" class="codeline ">#   ifdef _AIX
</span><span id="line593" class="codeline ">#     include &lt;inttypes.h&gt;
</span><span id="line594" class="codeline ">#   else
</span><span id="line595" class="codeline ">#     include &lt;stdint.h&gt;
</span><span id="line596" class="codeline ">#   endif
</span><span id="line597" class="codeline ">    typedef uint32_t XXH32_hash_t;
</span><span id="line598" class="codeline ">
</span><span id="line599" class="codeline ">#else
</span><span id="line600" class="codeline ">#   include &lt;limits.h&gt;
</span><span id="line601" class="codeline ">#   if UINT_MAX == 0xFFFFFFFFUL
</span><span id="line602" class="codeline ">      typedef unsigned int XXH32_hash_t;
</span><span id="line603" class="codeline ">#   elif ULONG_MAX == 0xFFFFFFFFUL
</span><span id="line604" class="codeline ">      typedef unsigned long XXH32_hash_t;
</span><span id="line605" class="codeline ">#   else
</span><span id="line606" class="codeline ">#     error &#34;unsupported platform: need a 32-bit type&#34;
</span><span id="line607" class="codeline ">#   endif
</span><span id="line608" class="codeline ">#endif
</span><span id="line609" class="codeline ">
</span><span id="line610" class="codeline ">/*!
</span><span id="line611" class="codeline "> * @}
</span><span id="line612" class="codeline "> *
</span><span id="line613" class="codeline "> * @defgroup XXH32_family XXH32 family
</span><span id="line614" class="codeline "> * @ingroup public
</span><span id="line615" class="codeline "> * Contains functions used in the classic 32-bit xxHash algorithm.
</span><span id="line616" class="codeline "> *
</span><span id="line617" class="codeline "> * @note
</span><span id="line618" class="codeline "> *   XXH32 is useful for older platforms, with no or poor 64-bit performance.
</span><span id="line619" class="codeline "> *   Note that the @ref XXH3_family provides competitive speed for both 32-bit
</span><span id="line620" class="codeline "> *   and 64-bit systems, and offers true 64/128 bit hash results.
</span><span id="line621" class="codeline "> *
</span><span id="line622" class="codeline "> * @see @ref XXH64_family, @ref XXH3_family : Other xxHash families
</span><span id="line623" class="codeline "> * @see @ref XXH32_impl for implementation details
</span><span id="line624" class="codeline "> * @{
</span><span id="line625" class="codeline "> */
</span><span id="line626" class="codeline ">
</span><span id="line627" class="codeline ">/*!
</span><span id="line628" class="codeline "> * @brief Calculates the 32-bit hash of @p input using xxHash32.
</span><span id="line629" class="codeline "> *
</span><span id="line630" class="codeline "> * @param input The block of data to be hashed, at least @p length bytes in size.
</span><span id="line631" class="codeline "> * @param length The length of @p input, in bytes.
</span><span id="line632" class="codeline "> * @param seed The 32-bit seed to alter the hash&#39;s output predictably.
</span><span id="line633" class="codeline "> *
</span><span id="line634" class="codeline "> * @pre
</span><span id="line635" class="codeline "> *   The memory between @p input and @p input + @p length must be valid,
</span><span id="line636" class="codeline "> *   readable, contiguous memory. However, if @p length is `0`, @p input may be
</span><span id="line637" class="codeline "> *   `NULL`. In C++, this also must be *TriviallyCopyable*.
</span><span id="line638" class="codeline "> *
</span><span id="line639" class="codeline "> * @return The calculated 32-bit xxHash32 value.
</span><span id="line640" class="codeline "> *
</span><span id="line641" class="codeline "> * @see @ref single_shot_example &#34;Single Shot Example&#34; for an example.
</span><span id="line642" class="codeline "> */
</span><span id="line643" class="codeline ">XXH_PUBLIC_API XXH_PUREF XXH32_hash_t XXH32 (const void* input, size_t length, XXH32_hash_t seed);
</span><span id="line644" class="codeline ">
</span><span id="line645" class="codeline ">#ifndef XXH_NO_STREAM
</span><span id="line646" class="codeline ">/*!
</span><span id="line647" class="codeline "> * @typedef struct XXH32_state_s XXH32_state_t
</span><span id="line648" class="codeline "> * @brief The opaque state struct for the XXH32 streaming API.
</span><span id="line649" class="codeline "> *
</span><span id="line650" class="codeline "> * @see XXH32_state_s for details.
</span><span id="line651" class="codeline "> * @see @ref streaming_example &#34;Streaming Example&#34;
</span><span id="line652" class="codeline "> */
</span><span id="line653" class="codeline ">typedef struct XXH32_state_s XXH32_state_t;
</span><span id="line654" class="codeline ">
</span><span id="line655" class="codeline ">/*!
</span><span id="line656" class="codeline "> * @brief Allocates an @ref XXH32_state_t.
</span><span id="line657" class="codeline "> *
</span><span id="line658" class="codeline "> * @return An allocated pointer of @ref XXH32_state_t on success.
</span><span id="line659" class="codeline "> * @return `NULL` on failure.
</span><span id="line660" class="codeline "> *
</span><span id="line661" class="codeline "> * @note Must be freed with XXH32_freeState().
</span><span id="line662" class="codeline "> *
</span><span id="line663" class="codeline "> * @see @ref streaming_example &#34;Streaming Example&#34;
</span><span id="line664" class="codeline "> */
</span><span id="line665" class="codeline ">XXH_PUBLIC_API XXH_MALLOCF XXH32_state_t* XXH32_createState(void);
</span><span id="line666" class="codeline ">/*!
</span><span id="line667" class="codeline "> * @brief Frees an @ref XXH32_state_t.
</span><span id="line668" class="codeline "> *
</span><span id="line669" class="codeline "> * @param statePtr A pointer to an @ref XXH32_state_t allocated with @ref XXH32_createState().
</span><span id="line670" class="codeline "> *
</span><span id="line671" class="codeline "> * @return @ref XXH_OK.
</span><span id="line672" class="codeline "> *
</span><span id="line673" class="codeline "> * @note @p statePtr must be allocated with XXH32_createState().
</span><span id="line674" class="codeline "> *
</span><span id="line675" class="codeline "> * @see @ref streaming_example &#34;Streaming Example&#34;
</span><span id="line676" class="codeline "> *
</span><span id="line677" class="codeline "> */
</span><span id="line678" class="codeline ">XXH_PUBLIC_API XXH_errorcode  XXH32_freeState(XXH32_state_t* statePtr);
</span><span id="line679" class="codeline ">/*!
</span><span id="line680" class="codeline "> * @brief Copies one @ref XXH32_state_t to another.
</span><span id="line681" class="codeline "> *
</span><span id="line682" class="codeline "> * @param dst_state The state to copy to.
</span><span id="line683" class="codeline "> * @param src_state The state to copy from.
</span><span id="line684" class="codeline "> * @pre
</span><span id="line685" class="codeline "> *   @p dst_state and @p src_state must not be `NULL` and must not overlap.
</span><span id="line686" class="codeline "> */
</span><span id="line687" class="codeline ">XXH_PUBLIC_API void XXH32_copyState(XXH32_state_t* dst_state, const XXH32_state_t* src_state);
</span><span id="line688" class="codeline ">
</span><span id="line689" class="codeline ">/*!
</span><span id="line690" class="codeline "> * @brief Resets an @ref XXH32_state_t to begin a new hash.
</span><span id="line691" class="codeline "> *
</span><span id="line692" class="codeline "> * @param statePtr The state struct to reset.
</span><span id="line693" class="codeline "> * @param seed The 32-bit seed to alter the hash result predictably.
</span><span id="line694" class="codeline "> *
</span><span id="line695" class="codeline "> * @pre
</span><span id="line696" class="codeline "> *   @p statePtr must not be `NULL`.
</span><span id="line697" class="codeline "> *
</span><span id="line698" class="codeline "> * @return @ref XXH_OK on success.
</span><span id="line699" class="codeline "> * @return @ref XXH_ERROR on failure.
</span><span id="line700" class="codeline "> *
</span><span id="line701" class="codeline "> * @note This function resets and seeds a state. Call it before @ref XXH32_update().
</span><span id="line702" class="codeline "> *
</span><span id="line703" class="codeline "> * @see @ref streaming_example &#34;Streaming Example&#34;
</span><span id="line704" class="codeline "> */
</span><span id="line705" class="codeline ">XXH_PUBLIC_API XXH_errorcode XXH32_reset  (XXH32_state_t* statePtr, XXH32_hash_t seed);
</span><span id="line706" class="codeline ">
</span><span id="line707" class="codeline ">/*!
</span><span id="line708" class="codeline "> * @brief Consumes a block of @p input to an @ref XXH32_state_t.
</span><span id="line709" class="codeline "> *
</span><span id="line710" class="codeline "> * @param statePtr The state struct to update.
</span><span id="line711" class="codeline "> * @param input The block of data to be hashed, at least @p length bytes in size.
</span><span id="line712" class="codeline "> * @param length The length of @p input, in bytes.
</span><span id="line713" class="codeline "> *
</span><span id="line714" class="codeline "> * @pre
</span><span id="line715" class="codeline "> *   @p statePtr must not be `NULL`.
</span><span id="line716" class="codeline "> * @pre
</span><span id="line717" class="codeline "> *   The memory between @p input and @p input + @p length must be valid,
</span><span id="line718" class="codeline "> *   readable, contiguous memory. However, if @p length is `0`, @p input may be
</span><span id="line719" class="codeline "> *   `NULL`. In C++, this also must be *TriviallyCopyable*.
</span><span id="line720" class="codeline "> *
</span><span id="line721" class="codeline "> * @return @ref XXH_OK on success.
</span><span id="line722" class="codeline "> * @return @ref XXH_ERROR on failure.
</span><span id="line723" class="codeline "> *
</span><span id="line724" class="codeline "> * @note Call this to incrementally consume blocks of data.
</span><span id="line725" class="codeline "> *
</span><span id="line726" class="codeline "> * @see @ref streaming_example &#34;Streaming Example&#34;
</span><span id="line727" class="codeline "> */
</span><span id="line728" class="codeline ">XXH_PUBLIC_API XXH_errorcode XXH32_update (XXH32_state_t* statePtr, const void* input, size_t length);
</span><span id="line729" class="codeline ">
</span><span id="line730" class="codeline ">/*!
</span><span id="line731" class="codeline "> * @brief Returns the calculated hash value from an @ref XXH32_state_t.
</span><span id="line732" class="codeline "> *
</span><span id="line733" class="codeline "> * @param statePtr The state struct to calculate the hash from.
</span><span id="line734" class="codeline "> *
</span><span id="line735" class="codeline "> * @pre
</span><span id="line736" class="codeline "> *  @p statePtr must not be `NULL`.
</span><span id="line737" class="codeline "> *
</span><span id="line738" class="codeline "> * @return The calculated 32-bit xxHash32 value from that state.
</span><span id="line739" class="codeline "> *
</span><span id="line740" class="codeline "> * @note
</span><span id="line741" class="codeline "> *   Calling XXH32_digest() will not affect @p statePtr, so you can update,
</span><span id="line742" class="codeline "> *   digest, and update again.
</span><span id="line743" class="codeline "> *
</span><span id="line744" class="codeline "> * @see @ref streaming_example &#34;Streaming Example&#34;
</span><span id="line745" class="codeline "> */
</span><span id="line746" class="codeline ">XXH_PUBLIC_API XXH_PUREF XXH32_hash_t XXH32_digest (const XXH32_state_t* statePtr);
</span><span id="line747" class="codeline ">#endif /* !XXH_NO_STREAM */
</span><span id="line748" class="codeline ">
</span><span id="line749" class="codeline ">/*******   Canonical representation   *******/
</span><span id="line750" class="codeline ">
</span><span id="line751" class="codeline ">/*!
</span><span id="line752" class="codeline "> * @brief Canonical (big endian) representation of @ref XXH32_hash_t.
</span><span id="line753" class="codeline "> */
</span><span id="line754" class="codeline ">typedef struct {
</span><span id="line755" class="codeline ">    unsigned char digest[4]; /*!&lt; Hash bytes, big endian */
</span><span id="line756" class="codeline ">} XXH32_canonical_t;
</span><span id="line757" class="codeline ">
</span><span id="line758" class="codeline ">/*!
</span><span id="line759" class="codeline "> * @brief Converts an @ref XXH32_hash_t to a big endian @ref XXH32_canonical_t.
</span><span id="line760" class="codeline "> *
</span><span id="line761" class="codeline "> * @param dst  The @ref XXH32_canonical_t pointer to be stored to.
</span><span id="line762" class="codeline "> * @param hash The @ref XXH32_hash_t to be converted.
</span><span id="line763" class="codeline "> *
</span><span id="line764" class="codeline "> * @pre
</span><span id="line765" class="codeline "> *   @p dst must not be `NULL`.
</span><span id="line766" class="codeline "> *
</span><span id="line767" class="codeline "> * @see @ref canonical_representation_example &#34;Canonical Representation Example&#34;
</span><span id="line768" class="codeline "> */
</span><span id="line769" class="codeline ">XXH_PUBLIC_API void XXH32_canonicalFromHash(XXH32_canonical_t* dst, XXH32_hash_t hash);
</span><span id="line770" class="codeline ">
</span><span id="line771" class="codeline ">/*!
</span><span id="line772" class="codeline "> * @brief Converts an @ref XXH32_canonical_t to a native @ref XXH32_hash_t.
</span><span id="line773" class="codeline "> *
</span><span id="line774" class="codeline "> * @param src The @ref XXH32_canonical_t to convert.
</span><span id="line775" class="codeline "> *
</span><span id="line776" class="codeline "> * @pre
</span><span id="line777" class="codeline "> *   @p src must not be `NULL`.
</span><span id="line778" class="codeline "> *
</span><span id="line779" class="codeline "> * @return The converted hash.
</span><span id="line780" class="codeline "> *
</span><span id="line781" class="codeline "> * @see @ref canonical_representation_example &#34;Canonical Representation Example&#34;
</span><span id="line782" class="codeline "> */
</span><span id="line783" class="codeline ">XXH_PUBLIC_API XXH_PUREF XXH32_hash_t XXH32_hashFromCanonical(const XXH32_canonical_t* src);
</span><span id="line784" class="codeline ">
</span><span id="line785" class="codeline ">
</span><span id="line786" class="codeline ">/*! @cond Doxygen ignores this part */
</span><span id="line787" class="codeline ">#ifdef __has_attribute
</span><span id="line788" class="codeline "># define XXH_HAS_ATTRIBUTE(x) __has_attribute(x)
</span><span id="line789" class="codeline ">#else
</span><span id="line790" class="codeline "># define XXH_HAS_ATTRIBUTE(x) 0
</span><span id="line791" class="codeline ">#endif
</span><span id="line792" class="codeline ">/*! @endcond */
</span><span id="line793" class="codeline ">
</span><span id="line794" class="codeline ">/*! @cond Doxygen ignores this part */
</span><span id="line795" class="codeline ">/*
</span><span id="line796" class="codeline "> * C23 __STDC_VERSION__ number hasn&#39;t been specified yet. For now
</span><span id="line797" class="codeline "> * leave as `201711L` (C17 + 1).
</span><span id="line798" class="codeline "> * TODO: Update to correct value when its been specified.
</span><span id="line799" class="codeline "> */
</span><span id="line800" class="codeline ">#define XXH_C23_VN 201711L
</span><span id="line801" class="codeline ">/*! @endcond */
</span><span id="line802" class="codeline ">
</span><span id="line803" class="codeline ">/*! @cond Doxygen ignores this part */
</span><span id="line804" class="codeline ">/* C-language Attributes are added in C23. */
</span><span id="line805" class="codeline ">#if defined(__STDC_VERSION__) &amp;&amp; (__STDC_VERSION__ &gt;= XXH_C23_VN) &amp;&amp; defined(__has_c_attribute)
</span><span id="line806" class="codeline "># define XXH_HAS_C_ATTRIBUTE(x) __has_c_attribute(x)
</span><span id="line807" class="codeline ">#else
</span><span id="line808" class="codeline "># define XXH_HAS_C_ATTRIBUTE(x) 0
</span><span id="line809" class="codeline ">#endif
</span><span id="line810" class="codeline ">/*! @endcond */
</span><span id="line811" class="codeline ">
</span><span id="line812" class="codeline ">/*! @cond Doxygen ignores this part */
</span><span id="line813" class="codeline ">#if defined(__cplusplus) &amp;&amp; defined(__has_cpp_attribute)
</span><span id="line814" class="codeline "># define XXH_HAS_CPP_ATTRIBUTE(x) __has_cpp_attribute(x)
</span><span id="line815" class="codeline ">#else
</span><span id="line816" class="codeline "># define XXH_HAS_CPP_ATTRIBUTE(x) 0
</span><span id="line817" class="codeline ">#endif
</span><span id="line818" class="codeline ">/*! @endcond */
</span><span id="line819" class="codeline ">
</span><span id="line820" class="codeline ">/*! @cond Doxygen ignores this part */
</span><span id="line821" class="codeline ">/*
</span><span id="line822" class="codeline "> * Define XXH_FALLTHROUGH macro for annotating switch case with the &#39;fallthrough&#39; attribute
</span><span id="line823" class="codeline "> * introduced in CPP17 and C23.
</span><span id="line824" class="codeline "> * CPP17 : https://en.cppreference.com/w/cpp/language/attributes/fallthrough
</span><span id="line825" class="codeline "> * C23   : https://en.cppreference.com/w/c/language/attributes/fallthrough
</span><span id="line826" class="codeline "> */
</span><span id="line827" class="codeline ">#if XXH_HAS_C_ATTRIBUTE(fallthrough) || XXH_HAS_CPP_ATTRIBUTE(fallthrough)
</span><span id="line828" class="codeline "># define XXH_FALLTHROUGH [[fallthrough]]
</span><span id="line829" class="codeline ">#elif XXH_HAS_ATTRIBUTE(__fallthrough__)
</span><span id="line830" class="codeline "># define XXH_FALLTHROUGH __attribute__ ((__fallthrough__))
</span><span id="line831" class="codeline ">#else
</span><span id="line832" class="codeline "># define XXH_FALLTHROUGH /* fallthrough */
</span><span id="line833" class="codeline ">#endif
</span><span id="line834" class="codeline ">/*! @endcond */
</span><span id="line835" class="codeline ">
</span><span id="line836" class="codeline ">/*! @cond Doxygen ignores this part */
</span><span id="line837" class="codeline ">/*
</span><span id="line838" class="codeline "> * Define XXH_NOESCAPE for annotated pointers in public API.
</span><span id="line839" class="codeline "> * https://clang.llvm.org/docs/AttributeReference.html#noescape
</span><span id="line840" class="codeline "> * As of writing this, only supported by clang.
</span><span id="line841" class="codeline "> */
</span><span id="line842" class="codeline ">#if XXH_HAS_ATTRIBUTE(noescape)
</span><span id="line843" class="codeline "># define XXH_NOESCAPE __attribute__((__noescape__))
</span><span id="line844" class="codeline ">#else
</span><span id="line845" class="codeline "># define XXH_NOESCAPE
</span><span id="line846" class="codeline ">#endif
</span><span id="line847" class="codeline ">/*! @endcond */
</span><span id="line848" class="codeline ">
</span><span id="line849" class="codeline ">
</span><span id="line850" class="codeline ">/*!
</span><span id="line851" class="codeline "> * @}
</span><span id="line852" class="codeline "> * @ingroup public
</span><span id="line853" class="codeline "> * @{
</span><span id="line854" class="codeline "> */
</span><span id="line855" class="codeline ">
</span><span id="line856" class="codeline ">#ifndef XXH_NO_LONG_LONG
</span><span id="line857" class="codeline ">/*-**********************************************************************
</span><span id="line858" class="codeline ">*  64-bit hash
</span><span id="line859" class="codeline ">************************************************************************/
</span><span id="line860" class="codeline ">#if defined(XXH_DOXYGEN) /* don&#39;t include &lt;stdint.h&gt; */
</span><span id="line861" class="codeline ">/*!
</span><span id="line862" class="codeline "> * @brief An unsigned 64-bit integer.
</span><span id="line863" class="codeline "> *
</span><span id="line864" class="codeline "> * Not necessarily defined to `uint64_t` but functionally equivalent.
</span><span id="line865" class="codeline "> */
</span><span id="line866" class="codeline ">typedef uint64_t XXH64_hash_t;
</span><span id="line867" class="codeline ">#elif !defined (__VMS) \
</span><span id="line868" class="codeline ">  &amp;&amp; (defined (__cplusplus) \
</span><span id="line869" class="codeline ">  || (defined (__STDC_VERSION__) &amp;&amp; (__STDC_VERSION__ &gt;= 199901L) /* C99 */) )
</span><span id="line870" class="codeline ">#   ifdef _AIX
</span><span id="line871" class="codeline ">#     include &lt;inttypes.h&gt;
</span><span id="line872" class="codeline ">#   else
</span><span id="line873" class="codeline ">#     include &lt;stdint.h&gt;
</span><span id="line874" class="codeline ">#   endif
</span><span id="line875" class="codeline ">   typedef uint64_t XXH64_hash_t;
</span><span id="line876" class="codeline ">#else
</span><span id="line877" class="codeline ">#  include &lt;limits.h&gt;
</span><span id="line878" class="codeline ">#  if defined(__LP64__) &amp;&amp; ULONG_MAX == 0xFFFFFFFFFFFFFFFFULL
</span><span id="line879" class="codeline ">     /* LP64 ABI says uint64_t is unsigned long */
</span><span id="line880" class="codeline ">     typedef unsigned long XXH64_hash_t;
</span><span id="line881" class="codeline ">#  else
</span><span id="line882" class="codeline ">     /* the following type must have a width of 64-bit */
</span><span id="line883" class="codeline ">     typedef unsigned long long XXH64_hash_t;
</span><span id="line884" class="codeline ">#  endif
</span><span id="line885" class="codeline ">#endif
</span><span id="line886" class="codeline ">
</span><span id="line887" class="codeline ">/*!
</span><span id="line888" class="codeline "> * @}
</span><span id="line889" class="codeline "> *
</span><span id="line890" class="codeline "> * @defgroup XXH64_family XXH64 family
</span><span id="line891" class="codeline "> * @ingroup public
</span><span id="line892" class="codeline "> * @{
</span><span id="line893" class="codeline "> * Contains functions used in the classic 64-bit xxHash algorithm.
</span><span id="line894" class="codeline "> *
</span><span id="line895" class="codeline "> * @note
</span><span id="line896" class="codeline "> *   XXH3 provides competitive speed for both 32-bit and 64-bit systems,
</span><span id="line897" class="codeline "> *   and offers true 64/128 bit hash results.
</span><span id="line898" class="codeline "> *   It provides better speed for systems with vector processing capabilities.
</span><span id="line899" class="codeline "> */
</span><span id="line900" class="codeline ">
</span><span id="line901" class="codeline ">/*!
</span><span id="line902" class="codeline "> * @brief Calculates the 64-bit hash of @p input using xxHash64.
</span><span id="line903" class="codeline "> *
</span><span id="line904" class="codeline "> * @param input The block of data to be hashed, at least @p length bytes in size.
</span><span id="line905" class="codeline "> * @param length The length of @p input, in bytes.
</span><span id="line906" class="codeline "> * @param seed The 64-bit seed to alter the hash&#39;s output predictably.
</span><span id="line907" class="codeline "> *
</span><span id="line908" class="codeline "> * @pre
</span><span id="line909" class="codeline "> *   The memory between @p input and @p input + @p length must be valid,
</span><span id="line910" class="codeline "> *   readable, contiguous memory. However, if @p length is `0`, @p input may be
</span><span id="line911" class="codeline "> *   `NULL`. In C++, this also must be *TriviallyCopyable*.
</span><span id="line912" class="codeline "> *
</span><span id="line913" class="codeline "> * @return The calculated 64-bit xxHash64 value.
</span><span id="line914" class="codeline "> *
</span><span id="line915" class="codeline "> * @see @ref single_shot_example &#34;Single Shot Example&#34; for an example.
</span><span id="line916" class="codeline "> */
</span><span id="line917" class="codeline ">XXH_PUBLIC_API XXH_PUREF XXH64_hash_t XXH64(XXH_NOESCAPE const void* input, size_t length, XXH64_hash_t seed);
</span><span id="line918" class="codeline ">
</span><span id="line919" class="codeline ">/*******   Streaming   *******/
</span><span id="line920" class="codeline ">#ifndef XXH_NO_STREAM
</span><span id="line921" class="codeline ">/*!
</span><span id="line922" class="codeline "> * @brief The opaque state struct for the XXH64 streaming API.
</span><span id="line923" class="codeline "> *
</span><span id="line924" class="codeline "> * @see XXH64_state_s for details.
</span><span id="line925" class="codeline "> * @see @ref streaming_example &#34;Streaming Example&#34;
</span><span id="line926" class="codeline "> */
</span><span id="line927" class="codeline ">typedef struct XXH64_state_s XXH64_state_t;   /* incomplete type */
</span><span id="line928" class="codeline ">
</span><span id="line929" class="codeline ">/*!
</span><span id="line930" class="codeline "> * @brief Allocates an @ref XXH64_state_t.
</span><span id="line931" class="codeline "> *
</span><span id="line932" class="codeline "> * @return An allocated pointer of @ref XXH64_state_t on success.
</span><span id="line933" class="codeline "> * @return `NULL` on failure.
</span><span id="line934" class="codeline "> *
</span><span id="line935" class="codeline "> * @note Must be freed with XXH64_freeState().
</span><span id="line936" class="codeline "> *
</span><span id="line937" class="codeline "> * @see @ref streaming_example &#34;Streaming Example&#34;
</span><span id="line938" class="codeline "> */
</span><span id="line939" class="codeline ">XXH_PUBLIC_API XXH_MALLOCF XXH64_state_t* XXH64_createState(void);
</span><span id="line940" class="codeline ">
</span><span id="line941" class="codeline ">/*!
</span><span id="line942" class="codeline "> * @brief Frees an @ref XXH64_state_t.
</span><span id="line943" class="codeline "> *
</span><span id="line944" class="codeline "> * @param statePtr A pointer to an @ref XXH64_state_t allocated with @ref XXH64_createState().
</span><span id="line945" class="codeline "> *
</span><span id="line946" class="codeline "> * @return @ref XXH_OK.
</span><span id="line947" class="codeline "> *
</span><span id="line948" class="codeline "> * @note @p statePtr must be allocated with XXH64_createState().
</span><span id="line949" class="codeline "> *
</span><span id="line950" class="codeline "> * @see @ref streaming_example &#34;Streaming Example&#34;
</span><span id="line951" class="codeline "> */
</span><span id="line952" class="codeline ">XXH_PUBLIC_API XXH_errorcode  XXH64_freeState(XXH64_state_t* statePtr);
</span><span id="line953" class="codeline ">
</span><span id="line954" class="codeline ">/*!
</span><span id="line955" class="codeline "> * @brief Copies one @ref XXH64_state_t to another.
</span><span id="line956" class="codeline "> *
</span><span id="line957" class="codeline "> * @param dst_state The state to copy to.
</span><span id="line958" class="codeline "> * @param src_state The state to copy from.
</span><span id="line959" class="codeline "> * @pre
</span><span id="line960" class="codeline "> *   @p dst_state and @p src_state must not be `NULL` and must not overlap.
</span><span id="line961" class="codeline "> */
</span><span id="line962" class="codeline ">XXH_PUBLIC_API void XXH64_copyState(XXH_NOESCAPE XXH64_state_t* dst_state, const XXH64_state_t* src_state);
</span><span id="line963" class="codeline ">
</span><span id="line964" class="codeline ">/*!
</span><span id="line965" class="codeline "> * @brief Resets an @ref XXH64_state_t to begin a new hash.
</span><span id="line966" class="codeline "> *
</span><span id="line967" class="codeline "> * @param statePtr The state struct to reset.
</span><span id="line968" class="codeline "> * @param seed The 64-bit seed to alter the hash result predictably.
</span><span id="line969" class="codeline "> *
</span><span id="line970" class="codeline "> * @pre
</span><span id="line971" class="codeline "> *   @p statePtr must not be `NULL`.
</span><span id="line972" class="codeline "> *
</span><span id="line973" class="codeline "> * @return @ref XXH_OK on success.
</span><span id="line974" class="codeline "> * @return @ref XXH_ERROR on failure.
</span><span id="line975" class="codeline "> *
</span><span id="line976" class="codeline "> * @note This function resets and seeds a state. Call it before @ref XXH64_update().
</span><span id="line977" class="codeline "> *
</span><span id="line978" class="codeline "> * @see @ref streaming_example &#34;Streaming Example&#34;
</span><span id="line979" class="codeline "> */
</span><span id="line980" class="codeline ">XXH_PUBLIC_API XXH_errorcode XXH64_reset  (XXH_NOESCAPE XXH64_state_t* statePtr, XXH64_hash_t seed);
</span><span id="line981" class="codeline ">
</span><span id="line982" class="codeline ">/*!
</span><span id="line983" class="codeline "> * @brief Consumes a block of @p input to an @ref XXH64_state_t.
</span><span id="line984" class="codeline "> *
</span><span id="line985" class="codeline "> * @param statePtr The state struct to update.
</span><span id="line986" class="codeline "> * @param input The block of data to be hashed, at least @p length bytes in size.
</span><span id="line987" class="codeline "> * @param length The length of @p input, in bytes.
</span><span id="line988" class="codeline "> *
</span><span id="line989" class="codeline "> * @pre
</span><span id="line990" class="codeline "> *   @p statePtr must not be `NULL`.
</span><span id="line991" class="codeline "> * @pre
</span><span id="line992" class="codeline "> *   The memory between @p input and @p input + @p length must be valid,
</span><span id="line993" class="codeline "> *   readable, contiguous memory. However, if @p length is `0`, @p input may be
</span><span id="line994" class="codeline "> *   `NULL`. In C++, this also must be *TriviallyCopyable*.
</span><span id="line995" class="codeline "> *
</span><span id="line996" class="codeline "> * @return @ref XXH_OK on success.
</span><span id="line997" class="codeline "> * @return @ref XXH_ERROR on failure.
</span><span id="line998" class="codeline "> *
</span><span id="line999" class="codeline "> * @note Call this to incrementally consume blocks of data.
</span><span id="line1000" class="codeline "> *
</span><span id="line1001" class="codeline "> * @see @ref streaming_example &#34;Streaming Example&#34;
</span><span id="line1002" class="codeline "> */
</span><span id="line1003" class="codeline ">XXH_PUBLIC_API XXH_errorcode XXH64_update (XXH_NOESCAPE XXH64_state_t* statePtr, XXH_NOESCAPE const void* input, size_t length);
</span><span id="line1004" class="codeline ">
</span><span id="line1005" class="codeline ">/*!
</span><span id="line1006" class="codeline "> * @brief Returns the calculated hash value from an @ref XXH64_state_t.
</span><span id="line1007" class="codeline "> *
</span><span id="line1008" class="codeline "> * @param statePtr The state struct to calculate the hash from.
</span><span id="line1009" class="codeline "> *
</span><span id="line1010" class="codeline "> * @pre
</span><span id="line1011" class="codeline "> *  @p statePtr must not be `NULL`.
</span><span id="line1012" class="codeline "> *
</span><span id="line1013" class="codeline "> * @return The calculated 64-bit xxHash64 value from that state.
</span><span id="line1014" class="codeline "> *
</span><span id="line1015" class="codeline "> * @note
</span><span id="line1016" class="codeline "> *   Calling XXH64_digest() will not affect @p statePtr, so you can update,
</span><span id="line1017" class="codeline "> *   digest, and update again.
</span><span id="line1018" class="codeline "> *
</span><span id="line1019" class="codeline "> * @see @ref streaming_example &#34;Streaming Example&#34;
</span><span id="line1020" class="codeline "> */
</span><span id="line1021" class="codeline ">XXH_PUBLIC_API XXH_PUREF XXH64_hash_t XXH64_digest (XXH_NOESCAPE const XXH64_state_t* statePtr);
</span><span id="line1022" class="codeline ">#endif /* !XXH_NO_STREAM */
</span><span id="line1023" class="codeline ">/*******   Canonical representation   *******/
</span><span id="line1024" class="codeline ">
</span><span id="line1025" class="codeline ">/*!
</span><span id="line1026" class="codeline "> * @brief Canonical (big endian) representation of @ref XXH64_hash_t.
</span><span id="line1027" class="codeline "> */
</span><span id="line1028" class="codeline ">typedef struct { unsigned char digest[sizeof(XXH64_hash_t)]; } XXH64_canonical_t;
</span><span id="line1029" class="codeline ">
</span><span id="line1030" class="codeline ">/*!
</span><span id="line1031" class="codeline "> * @brief Converts an @ref XXH64_hash_t to a big endian @ref XXH64_canonical_t.
</span><span id="line1032" class="codeline "> *
</span><span id="line1033" class="codeline "> * @param dst The @ref XXH64_canonical_t pointer to be stored to.
</span><span id="line1034" class="codeline "> * @param hash The @ref XXH64_hash_t to be converted.
</span><span id="line1035" class="codeline "> *
</span><span id="line1036" class="codeline "> * @pre
</span><span id="line1037" class="codeline "> *   @p dst must not be `NULL`.
</span><span id="line1038" class="codeline "> *
</span><span id="line1039" class="codeline "> * @see @ref canonical_representation_example &#34;Canonical Representation Example&#34;
</span><span id="line1040" class="codeline "> */
</span><span id="line1041" class="codeline ">XXH_PUBLIC_API void XXH64_canonicalFromHash(XXH_NOESCAPE XXH64_canonical_t* dst, XXH64_hash_t hash);
</span><span id="line1042" class="codeline ">
</span><span id="line1043" class="codeline ">/*!
</span><span id="line1044" class="codeline "> * @brief Converts an @ref XXH64_canonical_t to a native @ref XXH64_hash_t.
</span><span id="line1045" class="codeline "> *
</span><span id="line1046" class="codeline "> * @param src The @ref XXH64_canonical_t to convert.
</span><span id="line1047" class="codeline "> *
</span><span id="line1048" class="codeline "> * @pre
</span><span id="line1049" class="codeline "> *   @p src must not be `NULL`.
</span><span id="line1050" class="codeline "> *
</span><span id="line1051" class="codeline "> * @return The converted hash.
</span><span id="line1052" class="codeline "> *
</span><span id="line1053" class="codeline "> * @see @ref canonical_representation_example &#34;Canonical Representation Example&#34;
</span><span id="line1054" class="codeline "> */
</span><span id="line1055" class="codeline ">XXH_PUBLIC_API XXH_PUREF XXH64_hash_t XXH64_hashFromCanonical(XXH_NOESCAPE const XXH64_canonical_t* src);
</span><span id="line1056" class="codeline ">
</span><span id="line1057" class="codeline ">#ifndef XXH_NO_XXH3
</span><span id="line1058" class="codeline ">
</span><span id="line1059" class="codeline ">/*!
</span><span id="line1060" class="codeline "> * @}
</span><span id="line1061" class="codeline "> * ************************************************************************
</span><span id="line1062" class="codeline "> * @defgroup XXH3_family XXH3 family
</span><span id="line1063" class="codeline "> * @ingroup public
</span><span id="line1064" class="codeline "> * @{
</span><span id="line1065" class="codeline "> *
</span><span id="line1066" class="codeline "> * XXH3 is a more recent hash algorithm featuring:
</span><span id="line1067" class="codeline "> *  - Improved speed for both small and large inputs
</span><span id="line1068" class="codeline "> *  - True 64-bit and 128-bit outputs
</span><span id="line1069" class="codeline "> *  - SIMD acceleration
</span><span id="line1070" class="codeline "> *  - Improved 32-bit viability
</span><span id="line1071" class="codeline "> *
</span><span id="line1072" class="codeline "> * Speed analysis methodology is explained here:
</span><span id="line1073" class="codeline "> *
</span><span id="line1074" class="codeline "> *    https://fastcompression.blogspot.com/2019/03/presenting-xxh3.html
</span><span id="line1075" class="codeline "> *
</span><span id="line1076" class="codeline "> * Compared to XXH64, expect XXH3 to run approximately
</span><span id="line1077" class="codeline "> * ~2x faster on large inputs and &gt;3x faster on small ones,
</span><span id="line1078" class="codeline "> * exact differences vary depending on platform.
</span><span id="line1079" class="codeline "> *
</span><span id="line1080" class="codeline "> * XXH3&#39;s speed benefits greatly from SIMD and 64-bit arithmetic,
</span><span id="line1081" class="codeline "> * but does not require it.
</span><span id="line1082" class="codeline "> * Most 32-bit and 64-bit targets that can run XXH32 smoothly can run XXH3
</span><span id="line1083" class="codeline "> * at competitive speeds, even without vector support. Further details are
</span><span id="line1084" class="codeline "> * explained in the implementation.
</span><span id="line1085" class="codeline "> *
</span><span id="line1086" class="codeline "> * XXH3 has a fast scalar implementation, but it also includes accelerated SIMD
</span><span id="line1087" class="codeline "> * implementations for many common platforms:
</span><span id="line1088" class="codeline "> *   - AVX512
</span><span id="line1089" class="codeline "> *   - AVX2
</span><span id="line1090" class="codeline "> *   - SSE2
</span><span id="line1091" class="codeline "> *   - ARM NEON
</span><span id="line1092" class="codeline "> *   - WebAssembly SIMD128
</span><span id="line1093" class="codeline "> *   - POWER8 VSX
</span><span id="line1094" class="codeline "> *   - s390x ZVector
</span><span id="line1095" class="codeline "> * This can be controlled via the @ref XXH_VECTOR macro, but it automatically
</span><span id="line1096" class="codeline "> * selects the best version according to predefined macros. For the x86 family, an
</span><span id="line1097" class="codeline "> * automatic runtime dispatcher is included separately in @ref xxh_x86dispatch.c.
</span><span id="line1098" class="codeline "> *
</span><span id="line1099" class="codeline "> * XXH3 implementation is portable:
</span><span id="line1100" class="codeline "> * it has a generic C90 formulation that can be compiled on any platform,
</span><span id="line1101" class="codeline "> * all implementations generate exactly the same hash value on all platforms.
</span><span id="line1102" class="codeline "> * Starting from v0.8.0, it&#39;s also labelled &#34;stable&#34;, meaning that
</span><span id="line1103" class="codeline "> * any future version will also generate the same hash value.
</span><span id="line1104" class="codeline "> *
</span><span id="line1105" class="codeline "> * XXH3 offers 2 variants, _64bits and _128bits.
</span><span id="line1106" class="codeline "> *
</span><span id="line1107" class="codeline "> * When only 64 bits are needed, prefer invoking the _64bits variant, as it
</span><span id="line1108" class="codeline "> * reduces the amount of mixing, resulting in faster speed on small inputs.
</span><span id="line1109" class="codeline "> * It&#39;s also generally simpler to manipulate a scalar return type than a struct.
</span><span id="line1110" class="codeline "> *
</span><span id="line1111" class="codeline "> * The API supports one-shot hashing, streaming mode, and custom secrets.
</span><span id="line1112" class="codeline "> */
</span><span id="line1113" class="codeline ">
</span><span id="line1114" class="codeline ">/*!
</span><span id="line1115" class="codeline "> * @ingroup tuning
</span><span id="line1116" class="codeline "> * @brief Possible values for @ref XXH_VECTOR.
</span><span id="line1117" class="codeline "> *
</span><span id="line1118" class="codeline "> * Unless set explicitly, determined automatically.
</span><span id="line1119" class="codeline "> */
</span><span id="line1120" class="codeline ">#  define XXH_SCALAR 0 /*!&lt; Portable scalar version */
</span><span id="line1121" class="codeline ">#  define XXH_SSE2   1 /*!&lt; SSE2 for Pentium 4, Opteron, all x86_64. */
</span><span id="line1122" class="codeline ">#  define XXH_AVX2   2 /*!&lt; AVX2 for Haswell and Bulldozer */
</span><span id="line1123" class="codeline ">#  define XXH_AVX512 3 /*!&lt; AVX512 for Skylake and Icelake */
</span><span id="line1124" class="codeline ">#  define XXH_NEON   4 /*!&lt; NEON for most ARMv7-A, all AArch64, and WASM SIMD128 */
</span><span id="line1125" class="codeline ">#  define XXH_VSX    5 /*!&lt; VSX and ZVector for POWER8/z13 (64-bit) */
</span><span id="line1126" class="codeline ">#  define XXH_SVE    6 /*!&lt; SVE for some ARMv8-A and ARMv9-A */
</span><span id="line1127" class="codeline ">#  define XXH_LSX    7 /*!&lt; LSX (128-bit SIMD) for LoongArch64 */
</span><span id="line1128" class="codeline ">
</span><span id="line1129" class="codeline ">
</span><span id="line1130" class="codeline ">/*-**********************************************************************
</span><span id="line1131" class="codeline ">*  XXH3 64-bit variant
</span><span id="line1132" class="codeline ">************************************************************************/
</span><span id="line1133" class="codeline ">
</span><span id="line1134" class="codeline ">/*!
</span><span id="line1135" class="codeline "> * @brief Calculates 64-bit unseeded variant of XXH3 hash of @p input.
</span><span id="line1136" class="codeline "> *
</span><span id="line1137" class="codeline "> * @param input  The block of data to be hashed, at least @p length bytes in size.
</span><span id="line1138" class="codeline "> * @param length The length of @p input, in bytes.
</span><span id="line1139" class="codeline "> *
</span><span id="line1140" class="codeline "> * @pre
</span><span id="line1141" class="codeline "> *   The memory between @p input and @p input + @p length must be valid,
</span><span id="line1142" class="codeline "> *   readable, contiguous memory. However, if @p length is `0`, @p input may be
</span><span id="line1143" class="codeline "> *   `NULL`. In C++, this also must be *TriviallyCopyable*.
</span><span id="line1144" class="codeline "> *
</span><span id="line1145" class="codeline "> * @return The calculated 64-bit XXH3 hash value.
</span><span id="line1146" class="codeline "> *
</span><span id="line1147" class="codeline "> * @note
</span><span id="line1148" class="codeline "> *   This is equivalent to @ref XXH3_64bits_withSeed() with a seed of `0`, however
</span><span id="line1149" class="codeline "> *   it may have slightly better performance due to constant propagation of the
</span><span id="line1150" class="codeline "> *   defaults.
</span><span id="line1151" class="codeline "> *
</span><span id="line1152" class="codeline "> * @see
</span><span id="line1153" class="codeline "> *    XXH3_64bits_withSeed(), XXH3_64bits_withSecret(): other seeding variants
</span><span id="line1154" class="codeline "> * @see @ref single_shot_example &#34;Single Shot Example&#34; for an example.
</span><span id="line1155" class="codeline "> */
</span><span id="line1156" class="codeline ">XXH_PUBLIC_API XXH_PUREF XXH64_hash_t XXH3_64bits(XXH_NOESCAPE const void* input, size_t length);
</span><span id="line1157" class="codeline ">
</span><span id="line1158" class="codeline ">/*!
</span><span id="line1159" class="codeline "> * @brief Calculates 64-bit seeded variant of XXH3 hash of @p input.
</span><span id="line1160" class="codeline "> *
</span><span id="line1161" class="codeline "> * @param input  The block of data to be hashed, at least @p length bytes in size.
</span><span id="line1162" class="codeline "> * @param length The length of @p input, in bytes.
</span><span id="line1163" class="codeline "> * @param seed   The 64-bit seed to alter the hash result predictably.
</span><span id="line1164" class="codeline "> *
</span><span id="line1165" class="codeline "> * @pre
</span><span id="line1166" class="codeline "> *   The memory between @p input and @p input + @p length must be valid,
</span><span id="line1167" class="codeline "> *   readable, contiguous memory. However, if @p length is `0`, @p input may be
</span><span id="line1168" class="codeline "> *   `NULL`. In C++, this also must be *TriviallyCopyable*.
</span><span id="line1169" class="codeline "> *
</span><span id="line1170" class="codeline "> * @return The calculated 64-bit XXH3 hash value.
</span><span id="line1171" class="codeline "> *
</span><span id="line1172" class="codeline "> * @note
</span><span id="line1173" class="codeline "> *    seed == 0 produces the same results as @ref XXH3_64bits().
</span><span id="line1174" class="codeline "> *
</span><span id="line1175" class="codeline "> * This variant generates a custom secret on the fly based on default secret
</span><span id="line1176" class="codeline "> * altered using the @p seed value.
</span><span id="line1177" class="codeline "> *
</span><span id="line1178" class="codeline "> * While this operation is decently fast, note that it&#39;s not completely free.
</span><span id="line1179" class="codeline "> *
</span><span id="line1180" class="codeline "> * @see @ref single_shot_example &#34;Single Shot Example&#34; for an example.
</span><span id="line1181" class="codeline "> */
</span><span id="line1182" class="codeline ">XXH_PUBLIC_API XXH_PUREF XXH64_hash_t XXH3_64bits_withSeed(XXH_NOESCAPE const void* input, size_t length, XXH64_hash_t seed);
</span><span id="line1183" class="codeline ">
</span><span id="line1184" class="codeline ">/*!
</span><span id="line1185" class="codeline "> * The bare minimum size for a custom secret.
</span><span id="line1186" class="codeline "> *
</span><span id="line1187" class="codeline "> * @see
</span><span id="line1188" class="codeline "> *  XXH3_64bits_withSecret(), XXH3_64bits_reset_withSecret(),
</span><span id="line1189" class="codeline "> *  XXH3_128bits_withSecret(), XXH3_128bits_reset_withSecret().
</span><span id="line1190" class="codeline "> */
</span><span id="line1191" class="codeline ">#define XXH3_SECRET_SIZE_MIN 136
</span><span id="line1192" class="codeline ">
</span><span id="line1193" class="codeline ">/*!
</span><span id="line1194" class="codeline "> * @brief Calculates 64-bit variant of XXH3 with a custom &#34;secret&#34;.
</span><span id="line1195" class="codeline "> *
</span><span id="line1196" class="codeline "> * @param data       The block of data to be hashed, at least @p len bytes in size.
</span><span id="line1197" class="codeline "> * @param len        The length of @p data, in bytes.
</span><span id="line1198" class="codeline "> * @param secret     The secret data.
</span><span id="line1199" class="codeline "> * @param secretSize The length of @p secret, in bytes.
</span><span id="line1200" class="codeline "> *
</span><span id="line1201" class="codeline "> * @return The calculated 64-bit XXH3 hash value.
</span><span id="line1202" class="codeline "> *
</span><span id="line1203" class="codeline "> * @pre
</span><span id="line1204" class="codeline "> *   The memory between @p data and @p data + @p len must be valid,
</span><span id="line1205" class="codeline "> *   readable, contiguous memory. However, if @p length is `0`, @p data may be
</span><span id="line1206" class="codeline "> *   `NULL`. In C++, this also must be *TriviallyCopyable*.
</span><span id="line1207" class="codeline "> *
</span><span id="line1208" class="codeline "> * It&#39;s possible to provide any blob of bytes as a &#34;secret&#34; to generate the hash.
</span><span id="line1209" class="codeline "> * This makes it more difficult for an external actor to prepare an intentional collision.
</span><span id="line1210" class="codeline "> * The main condition is that @p secretSize *must* be large enough (&gt;= @ref XXH3_SECRET_SIZE_MIN).
</span><span id="line1211" class="codeline "> * However, the quality of the secret impacts the dispersion of the hash algorithm.
</span><span id="line1212" class="codeline "> * Therefore, the secret _must_ look like a bunch of random bytes.
</span><span id="line1213" class="codeline "> * Avoid &#34;trivial&#34; or structured data such as repeated sequences or a text document.
</span><span id="line1214" class="codeline "> * Whenever in doubt about the &#34;randomness&#34; of the blob of bytes,
</span><span id="line1215" class="codeline "> * consider employing @ref XXH3_generateSecret() instead (see below).
</span><span id="line1216" class="codeline "> * It will generate a proper high entropy secret derived from the blob of bytes.
</span><span id="line1217" class="codeline "> * Another advantage of using XXH3_generateSecret() is that
</span><span id="line1218" class="codeline "> * it guarantees that all bits within the initial blob of bytes
</span><span id="line1219" class="codeline "> * will impact every bit of the output.
</span><span id="line1220" class="codeline "> * This is not necessarily the case when using the blob of bytes directly
</span><span id="line1221" class="codeline "> * because, when hashing _small_ inputs, only a portion of the secret is employed.
</span><span id="line1222" class="codeline "> *
</span><span id="line1223" class="codeline "> * @see @ref single_shot_example &#34;Single Shot Example&#34; for an example.
</span><span id="line1224" class="codeline "> */
</span><span id="line1225" class="codeline ">XXH_PUBLIC_API XXH_PUREF XXH64_hash_t XXH3_64bits_withSecret(XXH_NOESCAPE const void* data, size_t len, XXH_NOESCAPE const void* secret, size_t secretSize);
</span><span id="line1226" class="codeline ">
</span><span id="line1227" class="codeline ">
</span><span id="line1228" class="codeline ">/*******   Streaming   *******/
</span><span id="line1229" class="codeline ">#ifndef XXH_NO_STREAM
</span><span id="line1230" class="codeline ">/*
</span><span id="line1231" class="codeline "> * Streaming requires state maintenance.
</span><span id="line1232" class="codeline "> * This operation costs memory and CPU.
</span><span id="line1233" class="codeline "> * As a consequence, streaming is slower than one-shot hashing.
</span><span id="line1234" class="codeline "> * For better performance, prefer one-shot functions whenever applicable.
</span><span id="line1235" class="codeline "> */
</span><span id="line1236" class="codeline ">
</span><span id="line1237" class="codeline ">/*!
</span><span id="line1238" class="codeline "> * @brief The opaque state struct for the XXH3 streaming API.
</span><span id="line1239" class="codeline "> *
</span><span id="line1240" class="codeline "> * @see XXH3_state_s for details.
</span><span id="line1241" class="codeline "> * @see @ref streaming_example &#34;Streaming Example&#34;
</span><span id="line1242" class="codeline "> */
</span><span id="line1243" class="codeline ">typedef struct XXH3_state_s XXH3_state_t;
</span><span id="line1244" class="codeline ">XXH_PUBLIC_API XXH_MALLOCF XXH3_state_t* XXH3_createState(void);
</span><span id="line1245" class="codeline ">XXH_PUBLIC_API XXH_errorcode XXH3_freeState(XXH3_state_t* statePtr);
</span><span id="line1246" class="codeline ">
</span><span id="line1247" class="codeline ">/*!
</span><span id="line1248" class="codeline "> * @brief Copies one @ref XXH3_state_t to another.
</span><span id="line1249" class="codeline "> *
</span><span id="line1250" class="codeline "> * @param dst_state The state to copy to.
</span><span id="line1251" class="codeline "> * @param src_state The state to copy from.
</span><span id="line1252" class="codeline "> * @pre
</span><span id="line1253" class="codeline "> *   @p dst_state and @p src_state must not be `NULL` and must not overlap.
</span><span id="line1254" class="codeline "> */
</span><span id="line1255" class="codeline ">XXH_PUBLIC_API void XXH3_copyState(XXH_NOESCAPE XXH3_state_t* dst_state, XXH_NOESCAPE const XXH3_state_t* src_state);
</span><span id="line1256" class="codeline ">
</span><span id="line1257" class="codeline ">/*!
</span><span id="line1258" class="codeline "> * @brief Resets an @ref XXH3_state_t to begin a new hash.
</span><span id="line1259" class="codeline "> *
</span><span id="line1260" class="codeline "> * @param statePtr The state struct to reset.
</span><span id="line1261" class="codeline "> *
</span><span id="line1262" class="codeline "> * @pre
</span><span id="line1263" class="codeline "> *   @p statePtr must not be `NULL`.
</span><span id="line1264" class="codeline "> *
</span><span id="line1265" class="codeline "> * @return @ref XXH_OK on success.
</span><span id="line1266" class="codeline "> * @return @ref XXH_ERROR on failure.
</span><span id="line1267" class="codeline "> *
</span><span id="line1268" class="codeline "> * @note
</span><span id="line1269" class="codeline "> *   - This function resets `statePtr` and generate a secret with default parameters.
</span><span id="line1270" class="codeline "> *   - Call this function before @ref XXH3_64bits_update().
</span><span id="line1271" class="codeline "> *   - Digest will be equivalent to `XXH3_64bits()`.
</span><span id="line1272" class="codeline "> *
</span><span id="line1273" class="codeline "> * @see @ref streaming_example &#34;Streaming Example&#34;
</span><span id="line1274" class="codeline "> *
</span><span id="line1275" class="codeline "> */
</span><span id="line1276" class="codeline ">XXH_PUBLIC_API XXH_errorcode XXH3_64bits_reset(XXH_NOESCAPE XXH3_state_t* statePtr);
</span><span id="line1277" class="codeline ">
</span><span id="line1278" class="codeline ">/*!
</span><span id="line1279" class="codeline "> * @brief Resets an @ref XXH3_state_t with 64-bit seed to begin a new hash.
</span><span id="line1280" class="codeline "> *
</span><span id="line1281" class="codeline "> * @param statePtr The state struct to reset.
</span><span id="line1282" class="codeline "> * @param seed     The 64-bit seed to alter the hash result predictably.
</span><span id="line1283" class="codeline "> *
</span><span id="line1284" class="codeline "> * @pre
</span><span id="line1285" class="codeline "> *   @p statePtr must not be `NULL`.
</span><span id="line1286" class="codeline "> *
</span><span id="line1287" class="codeline "> * @return @ref XXH_OK on success.
</span><span id="line1288" class="codeline "> * @return @ref XXH_ERROR on failure.
</span><span id="line1289" class="codeline "> *
</span><span id="line1290" class="codeline "> * @note
</span><span id="line1291" class="codeline "> *   - This function resets `statePtr` and generate a secret from `seed`.
</span><span id="line1292" class="codeline "> *   - Call this function before @ref XXH3_64bits_update().
</span><span id="line1293" class="codeline "> *   - Digest will be equivalent to `XXH3_64bits_withSeed()`.
</span><span id="line1294" class="codeline "> *
</span><span id="line1295" class="codeline "> * @see @ref streaming_example &#34;Streaming Example&#34;
</span><span id="line1296" class="codeline "> *
</span><span id="line1297" class="codeline "> */
</span><span id="line1298" class="codeline ">XXH_PUBLIC_API XXH_errorcode XXH3_64bits_reset_withSeed(XXH_NOESCAPE XXH3_state_t* statePtr, XXH64_hash_t seed);
</span><span id="line1299" class="codeline ">
</span><span id="line1300" class="codeline ">/*!
</span><span id="line1301" class="codeline "> * @brief Resets an @ref XXH3_state_t with secret data to begin a new hash.
</span><span id="line1302" class="codeline "> *
</span><span id="line1303" class="codeline "> * @param statePtr The state struct to reset.
</span><span id="line1304" class="codeline "> * @param secret     The secret data.
</span><span id="line1305" class="codeline "> * @param secretSize The length of @p secret, in bytes.
</span><span id="line1306" class="codeline "> *
</span><span id="line1307" class="codeline "> * @pre
</span><span id="line1308" class="codeline "> *   @p statePtr must not be `NULL`.
</span><span id="line1309" class="codeline "> *
</span><span id="line1310" class="codeline "> * @return @ref XXH_OK on success.
</span><span id="line1311" class="codeline "> * @return @ref XXH_ERROR on failure.
</span><span id="line1312" class="codeline "> *
</span><span id="line1313" class="codeline "> * @note
</span><span id="line1314" class="codeline "> *   `secret` is referenced, it _must outlive_ the hash streaming session.
</span><span id="line1315" class="codeline "> *
</span><span id="line1316" class="codeline "> * Similar to one-shot API, `secretSize` must be &gt;= @ref XXH3_SECRET_SIZE_MIN,
</span><span id="line1317" class="codeline "> * and the quality of produced hash values depends on secret&#39;s entropy
</span><span id="line1318" class="codeline "> * (secret&#39;s content should look like a bunch of random bytes).
</span><span id="line1319" class="codeline "> * When in doubt about the randomness of a candidate `secret`,
</span><span id="line1320" class="codeline "> * consider employing `XXH3_generateSecret()` instead (see below).
</span><span id="line1321" class="codeline "> *
</span><span id="line1322" class="codeline "> * @see @ref streaming_example &#34;Streaming Example&#34;
</span><span id="line1323" class="codeline "> */
</span><span id="line1324" class="codeline ">XXH_PUBLIC_API XXH_errorcode XXH3_64bits_reset_withSecret(XXH_NOESCAPE XXH3_state_t* statePtr, XXH_NOESCAPE const void* secret, size_t secretSize);
</span><span id="line1325" class="codeline ">
</span><span id="line1326" class="codeline ">/*!
</span><span id="line1327" class="codeline "> * @brief Consumes a block of @p input to an @ref XXH3_state_t.
</span><span id="line1328" class="codeline "> *
</span><span id="line1329" class="codeline "> * @param statePtr The state struct to update.
</span><span id="line1330" class="codeline "> * @param input The block of data to be hashed, at least @p length bytes in size.
</span><span id="line1331" class="codeline "> * @param length The length of @p input, in bytes.
</span><span id="line1332" class="codeline "> *
</span><span id="line1333" class="codeline "> * @pre
</span><span id="line1334" class="codeline "> *   @p statePtr must not be `NULL`.
</span><span id="line1335" class="codeline "> * @pre
</span><span id="line1336" class="codeline "> *   The memory between @p input and @p input + @p length must be valid,
</span><span id="line1337" class="codeline "> *   readable, contiguous memory. However, if @p length is `0`, @p input may be
</span><span id="line1338" class="codeline "> *   `NULL`. In C++, this also must be *TriviallyCopyable*.
</span><span id="line1339" class="codeline "> *
</span><span id="line1340" class="codeline "> * @return @ref XXH_OK on success.
</span><span id="line1341" class="codeline "> * @return @ref XXH_ERROR on failure.
</span><span id="line1342" class="codeline "> *
</span><span id="line1343" class="codeline "> * @note Call this to incrementally consume blocks of data.
</span><span id="line1344" class="codeline "> *
</span><span id="line1345" class="codeline "> * @see @ref streaming_example &#34;Streaming Example&#34;
</span><span id="line1346" class="codeline "> */
</span><span id="line1347" class="codeline ">XXH_PUBLIC_API XXH_errorcode XXH3_64bits_update (XXH_NOESCAPE XXH3_state_t* statePtr, XXH_NOESCAPE const void* input, size_t length);
</span><span id="line1348" class="codeline ">
</span><span id="line1349" class="codeline ">/*!
</span><span id="line1350" class="codeline "> * @brief Returns the calculated XXH3 64-bit hash value from an @ref XXH3_state_t.
</span><span id="line1351" class="codeline "> *
</span><span id="line1352" class="codeline "> * @param statePtr The state struct to calculate the hash from.
</span><span id="line1353" class="codeline "> *
</span><span id="line1354" class="codeline "> * @pre
</span><span id="line1355" class="codeline "> *  @p statePtr must not be `NULL`.
</span><span id="line1356" class="codeline "> *
</span><span id="line1357" class="codeline "> * @return The calculated XXH3 64-bit hash value from that state.
</span><span id="line1358" class="codeline "> *
</span><span id="line1359" class="codeline "> * @note
</span><span id="line1360" class="codeline "> *   Calling XXH3_64bits_digest() will not affect @p statePtr, so you can update,
</span><span id="line1361" class="codeline "> *   digest, and update again.
</span><span id="line1362" class="codeline "> *
</span><span id="line1363" class="codeline "> * @see @ref streaming_example &#34;Streaming Example&#34;
</span><span id="line1364" class="codeline "> */
</span><span id="line1365" class="codeline ">XXH_PUBLIC_API XXH_PUREF XXH64_hash_t  XXH3_64bits_digest (XXH_NOESCAPE const XXH3_state_t* statePtr);
</span><span id="line1366" class="codeline ">#endif /* !XXH_NO_STREAM */
</span><span id="line1367" class="codeline ">
</span><span id="line1368" class="codeline ">/* note : canonical representation of XXH3 is the same as XXH64
</span><span id="line1369" class="codeline "> * since they both produce XXH64_hash_t values */
</span><span id="line1370" class="codeline ">
</span><span id="line1371" class="codeline ">
</span><span id="line1372" class="codeline ">/*-**********************************************************************
</span><span id="line1373" class="codeline ">*  XXH3 128-bit variant
</span><span id="line1374" class="codeline ">************************************************************************/
</span><span id="line1375" class="codeline ">
</span><span id="line1376" class="codeline ">/*!
</span><span id="line1377" class="codeline "> * @brief The return value from 128-bit hashes.
</span><span id="line1378" class="codeline "> *
</span><span id="line1379" class="codeline "> * Stored in little endian order, although the fields themselves are in native
</span><span id="line1380" class="codeline "> * endianness.
</span><span id="line1381" class="codeline "> */
</span><span id="line1382" class="codeline ">typedef struct {
</span><span id="line1383" class="codeline ">    XXH64_hash_t low64;   /*!&lt; `value &amp; 0xFFFFFFFFFFFFFFFF` */
</span><span id="line1384" class="codeline ">    XXH64_hash_t high64;  /*!&lt; `value &gt;&gt; 64` */
</span><span id="line1385" class="codeline ">} XXH128_hash_t;
</span><span id="line1386" class="codeline ">
</span><span id="line1387" class="codeline ">/*!
</span><span id="line1388" class="codeline "> * @brief Calculates 128-bit unseeded variant of XXH3 of @p data.
</span><span id="line1389" class="codeline "> *
</span><span id="line1390" class="codeline "> * @param data The block of data to be hashed, at least @p length bytes in size.
</span><span id="line1391" class="codeline "> * @param len  The length of @p data, in bytes.
</span><span id="line1392" class="codeline "> *
</span><span id="line1393" class="codeline "> * @return The calculated 128-bit variant of XXH3 value.
</span><span id="line1394" class="codeline "> *
</span><span id="line1395" class="codeline "> * The 128-bit variant of XXH3 has more strength, but it has a bit of overhead
</span><span id="line1396" class="codeline "> * for shorter inputs.
</span><span id="line1397" class="codeline "> *
</span><span id="line1398" class="codeline "> * This is equivalent to @ref XXH3_128bits_withSeed() with a seed of `0`, however
</span><span id="line1399" class="codeline "> * it may have slightly better performance due to constant propagation of the
</span><span id="line1400" class="codeline "> * defaults.
</span><span id="line1401" class="codeline "> *
</span><span id="line1402" class="codeline "> * @see XXH3_128bits_withSeed(), XXH3_128bits_withSecret(): other seeding variants
</span><span id="line1403" class="codeline "> * @see @ref single_shot_example &#34;Single Shot Example&#34; for an example.
</span><span id="line1404" class="codeline "> */
</span><span id="line1405" class="codeline ">XXH_PUBLIC_API XXH_PUREF XXH128_hash_t XXH3_128bits(XXH_NOESCAPE const void* data, size_t len);
</span><span id="line1406" class="codeline ">/*! @brief Calculates 128-bit seeded variant of XXH3 hash of @p data.
</span><span id="line1407" class="codeline "> *
</span><span id="line1408" class="codeline "> * @param data The block of data to be hashed, at least @p length bytes in size.
</span><span id="line1409" class="codeline "> * @param len  The length of @p data, in bytes.
</span><span id="line1410" class="codeline "> * @param seed The 64-bit seed to alter the hash result predictably.
</span><span id="line1411" class="codeline "> *
</span><span id="line1412" class="codeline "> * @return The calculated 128-bit variant of XXH3 value.
</span><span id="line1413" class="codeline "> *
</span><span id="line1414" class="codeline "> * @note
</span><span id="line1415" class="codeline "> *    seed == 0 produces the same results as @ref XXH3_64bits().
</span><span id="line1416" class="codeline "> *
</span><span id="line1417" class="codeline "> * This variant generates a custom secret on the fly based on default secret
</span><span id="line1418" class="codeline "> * altered using the @p seed value.
</span><span id="line1419" class="codeline "> *
</span><span id="line1420" class="codeline "> * While this operation is decently fast, note that it&#39;s not completely free.
</span><span id="line1421" class="codeline "> *
</span><span id="line1422" class="codeline "> * @see XXH3_128bits(), XXH3_128bits_withSecret(): other seeding variants
</span><span id="line1423" class="codeline "> * @see @ref single_shot_example &#34;Single Shot Example&#34; for an example.
</span><span id="line1424" class="codeline "> */
</span><span id="line1425" class="codeline ">XXH_PUBLIC_API XXH_PUREF XXH128_hash_t XXH3_128bits_withSeed(XXH_NOESCAPE const void* data, size_t len, XXH64_hash_t seed);
</span><span id="line1426" class="codeline ">/*!
</span><span id="line1427" class="codeline "> * @brief Calculates 128-bit variant of XXH3 with a custom &#34;secret&#34;.
</span><span id="line1428" class="codeline "> *
</span><span id="line1429" class="codeline "> * @param data       The block of data to be hashed, at least @p len bytes in size.
</span><span id="line1430" class="codeline "> * @param len        The length of @p data, in bytes.
</span><span id="line1431" class="codeline "> * @param secret     The secret data.
</span><span id="line1432" class="codeline "> * @param secretSize The length of @p secret, in bytes.
</span><span id="line1433" class="codeline "> *
</span><span id="line1434" class="codeline "> * @return The calculated 128-bit variant of XXH3 value.
</span><span id="line1435" class="codeline "> *
</span><span id="line1436" class="codeline "> * It&#39;s possible to provide any blob of bytes as a &#34;secret&#34; to generate the hash.
</span><span id="line1437" class="codeline "> * This makes it more difficult for an external actor to prepare an intentional collision.
</span><span id="line1438" class="codeline "> * The main condition is that @p secretSize *must* be large enough (&gt;= @ref XXH3_SECRET_SIZE_MIN).
</span><span id="line1439" class="codeline "> * However, the quality of the secret impacts the dispersion of the hash algorithm.
</span><span id="line1440" class="codeline "> * Therefore, the secret _must_ look like a bunch of random bytes.
</span><span id="line1441" class="codeline "> * Avoid &#34;trivial&#34; or structured data such as repeated sequences or a text document.
</span><span id="line1442" class="codeline "> * Whenever in doubt about the &#34;randomness&#34; of the blob of bytes,
</span><span id="line1443" class="codeline "> * consider employing @ref XXH3_generateSecret() instead (see below).
</span><span id="line1444" class="codeline "> * It will generate a proper high entropy secret derived from the blob of bytes.
</span><span id="line1445" class="codeline "> * Another advantage of using XXH3_generateSecret() is that
</span><span id="line1446" class="codeline "> * it guarantees that all bits within the initial blob of bytes
</span><span id="line1447" class="codeline "> * will impact every bit of the output.
</span><span id="line1448" class="codeline "> * This is not necessarily the case when using the blob of bytes directly
</span><span id="line1449" class="codeline "> * because, when hashing _small_ inputs, only a portion of the secret is employed.
</span><span id="line1450" class="codeline "> *
</span><span id="line1451" class="codeline "> * @see @ref single_shot_example &#34;Single Shot Example&#34; for an example.
</span><span id="line1452" class="codeline "> */
</span><span id="line1453" class="codeline ">XXH_PUBLIC_API XXH_PUREF XXH128_hash_t XXH3_128bits_withSecret(XXH_NOESCAPE const void* data, size_t len, XXH_NOESCAPE const void* secret, size_t secretSize);
</span><span id="line1454" class="codeline ">
</span><span id="line1455" class="codeline ">/*******   Streaming   *******/
</span><span id="line1456" class="codeline ">#ifndef XXH_NO_STREAM
</span><span id="line1457" class="codeline ">/*
</span><span id="line1458" class="codeline "> * Streaming requires state maintenance.
</span><span id="line1459" class="codeline "> * This operation costs memory and CPU.
</span><span id="line1460" class="codeline "> * As a consequence, streaming is slower than one-shot hashing.
</span><span id="line1461" class="codeline "> * For better performance, prefer one-shot functions whenever applicable.
</span><span id="line1462" class="codeline "> *
</span><span id="line1463" class="codeline "> * XXH3_128bits uses the same XXH3_state_t as XXH3_64bits().
</span><span id="line1464" class="codeline "> * Use already declared XXH3_createState() and XXH3_freeState().
</span><span id="line1465" class="codeline "> *
</span><span id="line1466" class="codeline "> * All reset and streaming functions have same meaning as their 64-bit counterpart.
</span><span id="line1467" class="codeline "> */
</span><span id="line1468" class="codeline ">
</span><span id="line1469" class="codeline ">/*!
</span><span id="line1470" class="codeline "> * @brief Resets an @ref XXH3_state_t to begin a new hash.
</span><span id="line1471" class="codeline "> *
</span><span id="line1472" class="codeline "> * @param statePtr The state struct to reset.
</span><span id="line1473" class="codeline "> *
</span><span id="line1474" class="codeline "> * @pre
</span><span id="line1475" class="codeline "> *   @p statePtr must not be `NULL`.
</span><span id="line1476" class="codeline "> *
</span><span id="line1477" class="codeline "> * @return @ref XXH_OK on success.
</span><span id="line1478" class="codeline "> * @return @ref XXH_ERROR on failure.
</span><span id="line1479" class="codeline "> *
</span><span id="line1480" class="codeline "> * @note
</span><span id="line1481" class="codeline "> *   - This function resets `statePtr` and generate a secret with default parameters.
</span><span id="line1482" class="codeline "> *   - Call it before @ref XXH3_128bits_update().
</span><span id="line1483" class="codeline "> *   - Digest will be equivalent to `XXH3_128bits()`.
</span><span id="line1484" class="codeline "> *
</span><span id="line1485" class="codeline "> * @see @ref streaming_example &#34;Streaming Example&#34;
</span><span id="line1486" class="codeline "> */
</span><span id="line1487" class="codeline ">XXH_PUBLIC_API XXH_errorcode XXH3_128bits_reset(XXH_NOESCAPE XXH3_state_t* statePtr);
</span><span id="line1488" class="codeline ">
</span><span id="line1489" class="codeline ">/*!
</span><span id="line1490" class="codeline "> * @brief Resets an @ref XXH3_state_t with 64-bit seed to begin a new hash.
</span><span id="line1491" class="codeline "> *
</span><span id="line1492" class="codeline "> * @param statePtr The state struct to reset.
</span><span id="line1493" class="codeline "> * @param seed     The 64-bit seed to alter the hash result predictably.
</span><span id="line1494" class="codeline "> *
</span><span id="line1495" class="codeline "> * @pre
</span><span id="line1496" class="codeline "> *   @p statePtr must not be `NULL`.
</span><span id="line1497" class="codeline "> *
</span><span id="line1498" class="codeline "> * @return @ref XXH_OK on success.
</span><span id="line1499" class="codeline "> * @return @ref XXH_ERROR on failure.
</span><span id="line1500" class="codeline "> *
</span><span id="line1501" class="codeline "> * @note
</span><span id="line1502" class="codeline "> *   - This function resets `statePtr` and generate a secret from `seed`.
</span><span id="line1503" class="codeline "> *   - Call it before @ref XXH3_128bits_update().
</span><span id="line1504" class="codeline "> *   - Digest will be equivalent to `XXH3_128bits_withSeed()`.
</span><span id="line1505" class="codeline "> *
</span><span id="line1506" class="codeline "> * @see @ref streaming_example &#34;Streaming Example&#34;
</span><span id="line1507" class="codeline "> */
</span><span id="line1508" class="codeline ">XXH_PUBLIC_API XXH_errorcode XXH3_128bits_reset_withSeed(XXH_NOESCAPE XXH3_state_t* statePtr, XXH64_hash_t seed);
</span><span id="line1509" class="codeline ">/*!
</span><span id="line1510" class="codeline "> * @brief Resets an @ref XXH3_state_t with secret data to begin a new hash.
</span><span id="line1511" class="codeline "> *
</span><span id="line1512" class="codeline "> * @param statePtr   The state struct to reset.
</span><span id="line1513" class="codeline "> * @param secret     The secret data.
</span><span id="line1514" class="codeline "> * @param secretSize The length of @p secret, in bytes.
</span><span id="line1515" class="codeline "> *
</span><span id="line1516" class="codeline "> * @pre
</span><span id="line1517" class="codeline "> *   @p statePtr must not be `NULL`.
</span><span id="line1518" class="codeline "> *
</span><span id="line1519" class="codeline "> * @return @ref XXH_OK on success.
</span><span id="line1520" class="codeline "> * @return @ref XXH_ERROR on failure.
</span><span id="line1521" class="codeline "> *
</span><span id="line1522" class="codeline "> * `secret` is referenced, it _must outlive_ the hash streaming session.
</span><span id="line1523" class="codeline "> * Similar to one-shot API, `secretSize` must be &gt;= @ref XXH3_SECRET_SIZE_MIN,
</span><span id="line1524" class="codeline "> * and the quality of produced hash values depends on secret&#39;s entropy
</span><span id="line1525" class="codeline "> * (secret&#39;s content should look like a bunch of random bytes).
</span><span id="line1526" class="codeline "> * When in doubt about the randomness of a candidate `secret`,
</span><span id="line1527" class="codeline "> * consider employing `XXH3_generateSecret()` instead (see below).
</span><span id="line1528" class="codeline "> *
</span><span id="line1529" class="codeline "> * @see @ref streaming_example &#34;Streaming Example&#34;
</span><span id="line1530" class="codeline "> */
</span><span id="line1531" class="codeline ">XXH_PUBLIC_API XXH_errorcode XXH3_128bits_reset_withSecret(XXH_NOESCAPE XXH3_state_t* statePtr, XXH_NOESCAPE const void* secret, size_t secretSize);
</span><span id="line1532" class="codeline ">
</span><span id="line1533" class="codeline ">/*!
</span><span id="line1534" class="codeline "> * @brief Consumes a block of @p input to an @ref XXH3_state_t.
</span><span id="line1535" class="codeline "> *
</span><span id="line1536" class="codeline "> * Call this to incrementally consume blocks of data.
</span><span id="line1537" class="codeline "> *
</span><span id="line1538" class="codeline "> * @param statePtr The state struct to update.
</span><span id="line1539" class="codeline "> * @param input The block of data to be hashed, at least @p length bytes in size.
</span><span id="line1540" class="codeline "> * @param length The length of @p input, in bytes.
</span><span id="line1541" class="codeline "> *
</span><span id="line1542" class="codeline "> * @pre
</span><span id="line1543" class="codeline "> *   @p statePtr must not be `NULL`.
</span><span id="line1544" class="codeline "> *
</span><span id="line1545" class="codeline "> * @return @ref XXH_OK on success.
</span><span id="line1546" class="codeline "> * @return @ref XXH_ERROR on failure.
</span><span id="line1547" class="codeline "> *
</span><span id="line1548" class="codeline "> * @note
</span><span id="line1549" class="codeline "> *   The memory between @p input and @p input + @p length must be valid,
</span><span id="line1550" class="codeline "> *   readable, contiguous memory. However, if @p length is `0`, @p input may be
</span><span id="line1551" class="codeline "> *   `NULL`. In C++, this also must be *TriviallyCopyable*.
</span><span id="line1552" class="codeline "> *
</span><span id="line1553" class="codeline "> */
</span><span id="line1554" class="codeline ">XXH_PUBLIC_API XXH_errorcode XXH3_128bits_update (XXH_NOESCAPE XXH3_state_t* statePtr, XXH_NOESCAPE const void* input, size_t length);
</span><span id="line1555" class="codeline ">
</span><span id="line1556" class="codeline ">/*!
</span><span id="line1557" class="codeline "> * @brief Returns the calculated XXH3 128-bit hash value from an @ref XXH3_state_t.
</span><span id="line1558" class="codeline "> *
</span><span id="line1559" class="codeline "> * @param statePtr The state struct to calculate the hash from.
</span><span id="line1560" class="codeline "> *
</span><span id="line1561" class="codeline "> * @pre
</span><span id="line1562" class="codeline "> *  @p statePtr must not be `NULL`.
</span><span id="line1563" class="codeline "> *
</span><span id="line1564" class="codeline "> * @return The calculated XXH3 128-bit hash value from that state.
</span><span id="line1565" class="codeline "> *
</span><span id="line1566" class="codeline "> * @note
</span><span id="line1567" class="codeline "> *   Calling XXH3_128bits_digest() will not affect @p statePtr, so you can update,
</span><span id="line1568" class="codeline "> *   digest, and update again.
</span><span id="line1569" class="codeline "> *
</span><span id="line1570" class="codeline "> */
</span><span id="line1571" class="codeline ">XXH_PUBLIC_API XXH_PUREF XXH128_hash_t XXH3_128bits_digest (XXH_NOESCAPE const XXH3_state_t* statePtr);
</span><span id="line1572" class="codeline ">#endif /* !XXH_NO_STREAM */
</span><span id="line1573" class="codeline ">
</span><span id="line1574" class="codeline ">/* Following helper functions make it possible to compare XXH128_hast_t values.
</span><span id="line1575" class="codeline "> * Since XXH128_hash_t is a structure, this capability is not offered by the language.
</span><span id="line1576" class="codeline "> * Note: For better performance, these functions can be inlined using XXH_INLINE_ALL */
</span><span id="line1577" class="codeline ">
</span><span id="line1578" class="codeline ">/*!
</span><span id="line1579" class="codeline "> * @brief Check equality of two XXH128_hash_t values
</span><span id="line1580" class="codeline "> *
</span><span id="line1581" class="codeline "> * @param h1 The 128-bit hash value.
</span><span id="line1582" class="codeline "> * @param h2 Another 128-bit hash value.
</span><span id="line1583" class="codeline "> *
</span><span id="line1584" class="codeline "> * @return `1` if `h1` and `h2` are equal.
</span><span id="line1585" class="codeline "> * @return `0` if they are not.
</span><span id="line1586" class="codeline "> */
</span><span id="line1587" class="codeline ">XXH_PUBLIC_API XXH_PUREF int XXH128_isEqual(XXH128_hash_t h1, XXH128_hash_t h2);
</span><span id="line1588" class="codeline ">
</span><span id="line1589" class="codeline ">/*!
</span><span id="line1590" class="codeline "> * @brief Compares two @ref XXH128_hash_t
</span><span id="line1591" class="codeline "> *
</span><span id="line1592" class="codeline "> * This comparator is compatible with stdlib&#39;s `qsort()`/`bsearch()`.
</span><span id="line1593" class="codeline "> *
</span><span id="line1594" class="codeline "> * @param h128_1 Left-hand side value
</span><span id="line1595" class="codeline "> * @param h128_2 Right-hand side value
</span><span id="line1596" class="codeline "> *
</span><span id="line1597" class="codeline "> * @return &gt;0 if @p h128_1  &gt; @p h128_2
</span><span id="line1598" class="codeline "> * @return =0 if @p h128_1 == @p h128_2
</span><span id="line1599" class="codeline "> * @return &lt;0 if @p h128_1  &lt; @p h128_2
</span><span id="line1600" class="codeline "> */
</span><span id="line1601" class="codeline ">XXH_PUBLIC_API XXH_PUREF int XXH128_cmp(XXH_NOESCAPE const void* h128_1, XXH_NOESCAPE const void* h128_2);
</span><span id="line1602" class="codeline ">
</span><span id="line1603" class="codeline ">
</span><span id="line1604" class="codeline ">/*******   Canonical representation   *******/
</span><span id="line1605" class="codeline ">typedef struct { unsigned char digest[sizeof(XXH128_hash_t)]; } XXH128_canonical_t;
</span><span id="line1606" class="codeline ">
</span><span id="line1607" class="codeline ">
</span><span id="line1608" class="codeline ">/*!
</span><span id="line1609" class="codeline "> * @brief Converts an @ref XXH128_hash_t to a big endian @ref XXH128_canonical_t.
</span><span id="line1610" class="codeline "> *
</span><span id="line1611" class="codeline "> * @param dst  The @ref XXH128_canonical_t pointer to be stored to.
</span><span id="line1612" class="codeline "> * @param hash The @ref XXH128_hash_t to be converted.
</span><span id="line1613" class="codeline "> *
</span><span id="line1614" class="codeline "> * @pre
</span><span id="line1615" class="codeline "> *   @p dst must not be `NULL`.
</span><span id="line1616" class="codeline "> * @see @ref canonical_representation_example &#34;Canonical Representation Example&#34;
</span><span id="line1617" class="codeline "> */
</span><span id="line1618" class="codeline ">XXH_PUBLIC_API void XXH128_canonicalFromHash(XXH_NOESCAPE XXH128_canonical_t* dst, XXH128_hash_t hash);
</span><span id="line1619" class="codeline ">
</span><span id="line1620" class="codeline ">/*!
</span><span id="line1621" class="codeline "> * @brief Converts an @ref XXH128_canonical_t to a native @ref XXH128_hash_t.
</span><span id="line1622" class="codeline "> *
</span><span id="line1623" class="codeline "> * @param src The @ref XXH128_canonical_t to convert.
</span><span id="line1624" class="codeline "> *
</span><span id="line1625" class="codeline "> * @pre
</span><span id="line1626" class="codeline "> *   @p src must not be `NULL`.
</span><span id="line1627" class="codeline "> *
</span><span id="line1628" class="codeline "> * @return The converted hash.
</span><span id="line1629" class="codeline "> * @see @ref canonical_representation_example &#34;Canonical Representation Example&#34;
</span><span id="line1630" class="codeline "> */
</span><span id="line1631" class="codeline ">XXH_PUBLIC_API XXH_PUREF XXH128_hash_t XXH128_hashFromCanonical(XXH_NOESCAPE const XXH128_canonical_t* src);
</span><span id="line1632" class="codeline ">
</span><span id="line1633" class="codeline ">
</span><span id="line1634" class="codeline ">#endif  /* !XXH_NO_XXH3 */
</span><span id="line1635" class="codeline ">#endif  /* XXH_NO_LONG_LONG */
</span><span id="line1636" class="codeline ">
</span><span id="line1637" class="codeline ">/*!
</span><span id="line1638" class="codeline "> * @}
</span><span id="line1639" class="codeline "> */
</span><span id="line1640" class="codeline ">#endif /* XXHASH_H_5627135585666179 */
</span><span id="line1641" class="codeline ">
</span><span id="line1642" class="codeline ">
</span><span id="line1643" class="codeline ">
</span><span id="line1644" class="codeline ">#if defined(XXH_STATIC_LINKING_ONLY) &amp;&amp; !defined(XXHASH_H_STATIC_13879238742)
</span><span id="line1645" class="codeline ">#define XXHASH_H_STATIC_13879238742
</span><span id="line1646" class="codeline ">/* ****************************************************************************
</span><span id="line1647" class="codeline "> * This section contains declarations which are not guaranteed to remain stable.
</span><span id="line1648" class="codeline "> * They may change in future versions, becoming incompatible with a different
</span><span id="line1649" class="codeline "> * version of the library.
</span><span id="line1650" class="codeline "> * These declarations should only be used with static linking.
</span><span id="line1651" class="codeline "> * Never use them in association with dynamic linking!
</span><span id="line1652" class="codeline "> ***************************************************************************** */
</span><span id="line1653" class="codeline ">
</span><span id="line1654" class="codeline ">/*
</span><span id="line1655" class="codeline "> * These definitions are only present to allow static allocation
</span><span id="line1656" class="codeline "> * of XXH states, on stack or in a struct, for example.
</span><span id="line1657" class="codeline "> * Never **ever** access their members directly.
</span><span id="line1658" class="codeline "> */
</span><span id="line1659" class="codeline ">
</span><span id="line1660" class="codeline ">/*!
</span><span id="line1661" class="codeline "> * @internal
</span><span id="line1662" class="codeline "> * @brief Structure for XXH32 streaming API.
</span><span id="line1663" class="codeline "> *
</span><span id="line1664" class="codeline "> * @note This is only defined when @ref XXH_STATIC_LINKING_ONLY,
</span><span id="line1665" class="codeline "> * @ref XXH_INLINE_ALL, or @ref XXH_IMPLEMENTATION is defined. Otherwise it is
</span><span id="line1666" class="codeline "> * an opaque type. This allows fields to safely be changed.
</span><span id="line1667" class="codeline "> *
</span><span id="line1668" class="codeline "> * Typedef&#39;d to @ref XXH32_state_t.
</span><span id="line1669" class="codeline "> * Do not access the members of this struct directly.
</span><span id="line1670" class="codeline "> * @see XXH64_state_s, XXH3_state_s
</span><span id="line1671" class="codeline "> */
</span><span id="line1672" class="codeline ">struct XXH32_state_s {
</span><span id="line1673" class="codeline ">   XXH32_hash_t total_len_32; /*!&lt; Total length hashed, modulo 2^32 */
</span><span id="line1674" class="codeline ">   XXH32_hash_t large_len;    /*!&lt; Whether the hash is &gt;= 16 (handles @ref total_len_32 overflow) */
</span><span id="line1675" class="codeline ">   XXH32_hash_t acc[4];       /*!&lt; Accumulator lanes */
</span><span id="line1676" class="codeline ">   unsigned char buffer[16];  /*!&lt; Internal buffer for partial reads. */
</span><span id="line1677" class="codeline ">   XXH32_hash_t bufferedSize; /*!&lt; Amount of data in @ref buffer */
</span><span id="line1678" class="codeline ">   XXH32_hash_t reserved;     /*!&lt; Reserved field. Do not read nor write to it. */
</span><span id="line1679" class="codeline ">};   /* typedef&#39;d to XXH32_state_t */
</span><span id="line1680" class="codeline ">
</span><span id="line1681" class="codeline ">
</span><span id="line1682" class="codeline ">#ifndef XXH_NO_LONG_LONG  /* defined when there is no 64-bit support */
</span><span id="line1683" class="codeline ">
</span><span id="line1684" class="codeline ">/*!
</span><span id="line1685" class="codeline "> * @internal
</span><span id="line1686" class="codeline "> * @brief Structure for XXH64 streaming API.
</span><span id="line1687" class="codeline "> *
</span><span id="line1688" class="codeline "> * @note This is only defined when @ref XXH_STATIC_LINKING_ONLY,
</span><span id="line1689" class="codeline "> * @ref XXH_INLINE_ALL, or @ref XXH_IMPLEMENTATION is defined. Otherwise it is
</span><span id="line1690" class="codeline "> * an opaque type. This allows fields to safely be changed.
</span><span id="line1691" class="codeline "> *
</span><span id="line1692" class="codeline "> * Typedef&#39;d to @ref XXH64_state_t.
</span><span id="line1693" class="codeline "> * Do not access the members of this struct directly.
</span><span id="line1694" class="codeline "> * @see XXH32_state_s, XXH3_state_s
</span><span id="line1695" class="codeline "> */
</span><span id="line1696" class="codeline ">struct XXH64_state_s {
</span><span id="line1697" class="codeline ">   XXH64_hash_t total_len;    /*!&lt; Total length hashed. This is always 64-bit. */
</span><span id="line1698" class="codeline ">   XXH64_hash_t acc[4];       /*!&lt; Accumulator lanes */
</span><span id="line1699" class="codeline ">   unsigned char buffer[32];  /*!&lt; Internal buffer for partial reads.. */
</span><span id="line1700" class="codeline ">   XXH32_hash_t bufferedSize; /*!&lt; Amount of data in @ref buffer */
</span><span id="line1701" class="codeline ">   XXH32_hash_t reserved32;   /*!&lt; Reserved field, needed for padding anyways*/
</span><span id="line1702" class="codeline ">   XXH64_hash_t reserved64;   /*!&lt; Reserved field. Do not read or write to it. */
</span><span id="line1703" class="codeline ">};   /* typedef&#39;d to XXH64_state_t */
</span><span id="line1704" class="codeline ">
</span><span id="line1705" class="codeline ">#ifndef XXH_NO_XXH3
</span><span id="line1706" class="codeline ">
</span><span id="line1707" class="codeline ">#if defined(__STDC_VERSION__) &amp;&amp; (__STDC_VERSION__ &gt;= 201112L) /* &gt;= C11 */
</span><span id="line1708" class="codeline ">#  define XXH_ALIGN(n)      _Alignas(n)
</span><span id="line1709" class="codeline ">#elif defined(__cplusplus) &amp;&amp; (__cplusplus &gt;= 201103L) /* &gt;= C++11 */
</span><span id="line1710" class="codeline ">/* In C++ alignas() is a keyword */
</span><span id="line1711" class="codeline ">#  define XXH_ALIGN(n)      alignas(n)
</span><span id="line1712" class="codeline ">#elif defined(__GNUC__)
</span><span id="line1713" class="codeline ">#  define XXH_ALIGN(n)      __attribute__ ((aligned(n)))
</span><span id="line1714" class="codeline ">#elif defined(_MSC_VER)
</span><span id="line1715" class="codeline ">#  define XXH_ALIGN(n)      __declspec(align(n))
</span><span id="line1716" class="codeline ">#else
</span><span id="line1717" class="codeline ">#  define XXH_ALIGN(n)   /* disabled */
</span><span id="line1718" class="codeline ">#endif
</span><span id="line1719" class="codeline ">
</span><span id="line1720" class="codeline ">/* Old GCC versions only accept the attribute after the type in structures. */
</span><span id="line1721" class="codeline ">#if !(defined(__STDC_VERSION__) &amp;&amp; (__STDC_VERSION__ &gt;= 201112L))   /* C11+ */ \
</span><span id="line1722" class="codeline ">    &amp;&amp; ! (defined(__cplusplus) &amp;&amp; (__cplusplus &gt;= 201103L)) /* &gt;= C++11 */ \
</span><span id="line1723" class="codeline ">    &amp;&amp; defined(__GNUC__)
</span><span id="line1724" class="codeline ">#   define XXH_ALIGN_MEMBER(align, type) type XXH_ALIGN(align)
</span><span id="line1725" class="codeline ">#else
</span><span id="line1726" class="codeline ">#   define XXH_ALIGN_MEMBER(align, type) XXH_ALIGN(align) type
</span><span id="line1727" class="codeline ">#endif
</span><span id="line1728" class="codeline ">
</span><span id="line1729" class="codeline ">/*!
</span><span id="line1730" class="codeline "> * @brief The size of the internal XXH3 buffer.
</span><span id="line1731" class="codeline "> *
</span><span id="line1732" class="codeline "> * This is the optimal update size for incremental hashing.
</span><span id="line1733" class="codeline "> *
</span><span id="line1734" class="codeline "> * @see XXH3_64b_update(), XXH3_128b_update().
</span><span id="line1735" class="codeline "> */
</span><span id="line1736" class="codeline ">#define XXH3_INTERNALBUFFER_SIZE 256
</span><span id="line1737" class="codeline ">
</span><span id="line1738" class="codeline ">/*!
</span><span id="line1739" class="codeline "> * @internal
</span><span id="line1740" class="codeline "> * @brief Default size of the secret buffer (and @ref XXH3_kSecret).
</span><span id="line1741" class="codeline "> *
</span><span id="line1742" class="codeline "> * This is the size used in @ref XXH3_kSecret and the seeded functions.
</span><span id="line1743" class="codeline "> *
</span><span id="line1744" class="codeline "> * Not to be confused with @ref XXH3_SECRET_SIZE_MIN.
</span><span id="line1745" class="codeline "> */
</span><span id="line1746" class="codeline ">#define XXH3_SECRET_DEFAULT_SIZE 192
</span><span id="line1747" class="codeline ">
</span><span id="line1748" class="codeline ">/*!
</span><span id="line1749" class="codeline "> * @internal
</span><span id="line1750" class="codeline "> * @brief Structure for XXH3 streaming API.
</span><span id="line1751" class="codeline "> *
</span><span id="line1752" class="codeline "> * @note This is only defined when @ref XXH_STATIC_LINKING_ONLY,
</span><span id="line1753" class="codeline "> * @ref XXH_INLINE_ALL, or @ref XXH_IMPLEMENTATION is defined.
</span><span id="line1754" class="codeline "> * Otherwise it is an opaque type.
</span><span id="line1755" class="codeline "> * Never use this definition in combination with dynamic library.
</span><span id="line1756" class="codeline "> * This allows fields to safely be changed in the future.
</span><span id="line1757" class="codeline "> *
</span><span id="line1758" class="codeline "> * @note ** This structure has a strict alignment requirement of 64 bytes!! **
</span><span id="line1759" class="codeline "> * Do not allocate this with `malloc()` or `new`,
</span><span id="line1760" class="codeline "> * it will not be sufficiently aligned.
</span><span id="line1761" class="codeline "> * Use @ref XXH3_createState() and @ref XXH3_freeState(), or stack allocation.
</span><span id="line1762" class="codeline "> *
</span><span id="line1763" class="codeline "> * Typedef&#39;d to @ref XXH3_state_t.
</span><span id="line1764" class="codeline "> * Do never access the members of this struct directly.
</span><span id="line1765" class="codeline "> *
</span><span id="line1766" class="codeline "> * @see XXH3_INITSTATE() for stack initialization.
</span><span id="line1767" class="codeline "> * @see XXH3_createState(), XXH3_freeState().
</span><span id="line1768" class="codeline "> * @see XXH32_state_s, XXH64_state_s
</span><span id="line1769" class="codeline "> */
</span><span id="line1770" class="codeline ">struct XXH3_state_s {
</span><span id="line1771" class="codeline ">   XXH_ALIGN_MEMBER(64, XXH64_hash_t acc[8]);
</span><span id="line1772" class="codeline ">       /*!&lt; The 8 accumulators. See @ref XXH32_state_s::v and @ref XXH64_state_s::v */
</span><span id="line1773" class="codeline ">   XXH_ALIGN_MEMBER(64, unsigned char customSecret[XXH3_SECRET_DEFAULT_SIZE]);
</span><span id="line1774" class="codeline ">       /*!&lt; Used to store a custom secret generated from a seed. */
</span><span id="line1775" class="codeline ">   XXH_ALIGN_MEMBER(64, unsigned char buffer[XXH3_INTERNALBUFFER_SIZE]);
</span><span id="line1776" class="codeline ">       /*!&lt; The internal buffer. @see XXH32_state_s::mem32 */
</span><span id="line1777" class="codeline ">   XXH32_hash_t bufferedSize;
</span><span id="line1778" class="codeline ">       /*!&lt; The amount of memory in @ref buffer, @see XXH32_state_s::memsize */
</span><span id="line1779" class="codeline ">   XXH32_hash_t useSeed;
</span><span id="line1780" class="codeline ">       /*!&lt; Reserved field. Needed for padding on 64-bit. */
</span><span id="line1781" class="codeline ">   size_t nbStripesSoFar;
</span><span id="line1782" class="codeline ">       /*!&lt; Number or stripes processed. */
</span><span id="line1783" class="codeline ">   XXH64_hash_t totalLen;
</span><span id="line1784" class="codeline ">       /*!&lt; Total length hashed. 64-bit even on 32-bit targets. */
</span><span id="line1785" class="codeline ">   size_t nbStripesPerBlock;
</span><span id="line1786" class="codeline ">       /*!&lt; Number of stripes per block. */
</span><span id="line1787" class="codeline ">   size_t secretLimit;
</span><span id="line1788" class="codeline ">       /*!&lt; Size of @ref customSecret or @ref extSecret */
</span><span id="line1789" class="codeline ">   XXH64_hash_t seed;
</span><span id="line1790" class="codeline ">       /*!&lt; Seed for _withSeed variants. Must be zero otherwise, @see XXH3_INITSTATE() */
</span><span id="line1791" class="codeline ">   XXH64_hash_t reserved64;
</span><span id="line1792" class="codeline ">       /*!&lt; Reserved field. */
</span><span id="line1793" class="codeline ">   const unsigned char* extSecret;
</span><span id="line1794" class="codeline ">       /*!&lt; Reference to an external secret for the _withSecret variants, NULL
</span><span id="line1795" class="codeline ">        *   for other variants. */
</span><span id="line1796" class="codeline ">   /* note: there may be some padding at the end due to alignment on 64 bytes */
</span><span id="line1797" class="codeline ">}; /* typedef&#39;d to XXH3_state_t */
</span><span id="line1798" class="codeline ">
</span><span id="line1799" class="codeline ">#undef XXH_ALIGN_MEMBER
</span><span id="line1800" class="codeline ">
</span><span id="line1801" class="codeline ">/*!
</span><span id="line1802" class="codeline "> * @brief Initializes a stack-allocated `XXH3_state_s`.
</span><span id="line1803" class="codeline "> *
</span><span id="line1804" class="codeline "> * When the @ref XXH3_state_t structure is merely emplaced on stack,
</span><span id="line1805" class="codeline "> * it should be initialized with XXH3_INITSTATE() or a memset()
</span><span id="line1806" class="codeline "> * in case its first reset uses XXH3_NNbits_reset_withSeed().
</span><span id="line1807" class="codeline "> * This init can be omitted if the first reset uses default or _withSecret mode.
</span><span id="line1808" class="codeline "> * This operation isn&#39;t necessary when the state is created with XXH3_createState().
</span><span id="line1809" class="codeline "> * Note that this doesn&#39;t prepare the state for a streaming operation,
</span><span id="line1810" class="codeline "> * it&#39;s still necessary to use XXH3_NNbits_reset*() afterwards.
</span><span id="line1811" class="codeline "> */
</span><span id="line1812" class="codeline ">#define XXH3_INITSTATE(XXH3_state_ptr)                       \
</span><span id="line1813" class="codeline ">    do {                                                     \
</span><span id="line1814" class="codeline ">        XXH3_state_t* tmp_xxh3_state_ptr = (XXH3_state_ptr); \
</span><span id="line1815" class="codeline ">        tmp_xxh3_state_ptr-&gt;seed = 0;                        \
</span><span id="line1816" class="codeline ">        tmp_xxh3_state_ptr-&gt;extSecret = NULL;                \
</span><span id="line1817" class="codeline ">    } while(0)
</span><span id="line1818" class="codeline ">
</span><span id="line1819" class="codeline ">
</span><span id="line1820" class="codeline ">/*!
</span><span id="line1821" class="codeline "> * @brief Calculates the 128-bit hash of @p data using XXH3.
</span><span id="line1822" class="codeline "> *
</span><span id="line1823" class="codeline "> * @param data The block of data to be hashed, at least @p len bytes in size.
</span><span id="line1824" class="codeline "> * @param len  The length of @p data, in bytes.
</span><span id="line1825" class="codeline "> * @param seed The 64-bit seed to alter the hash&#39;s output predictably.
</span><span id="line1826" class="codeline "> *
</span><span id="line1827" class="codeline "> * @pre
</span><span id="line1828" class="codeline "> *   The memory between @p data and @p data + @p len must be valid,
</span><span id="line1829" class="codeline "> *   readable, contiguous memory. However, if @p len is `0`, @p data may be
</span><span id="line1830" class="codeline "> *   `NULL`. In C++, this also must be *TriviallyCopyable*.
</span><span id="line1831" class="codeline "> *
</span><span id="line1832" class="codeline "> * @return The calculated 128-bit XXH3 value.
</span><span id="line1833" class="codeline "> *
</span><span id="line1834" class="codeline "> * @see @ref single_shot_example &#34;Single Shot Example&#34; for an example.
</span><span id="line1835" class="codeline "> */
</span><span id="line1836" class="codeline ">XXH_PUBLIC_API XXH_PUREF XXH128_hash_t XXH128(XXH_NOESCAPE const void* data, size_t len, XXH64_hash_t seed);
</span><span id="line1837" class="codeline ">
</span><span id="line1838" class="codeline ">
</span><span id="line1839" class="codeline ">/* ===   Experimental API   === */
</span><span id="line1840" class="codeline ">/* Symbols defined below must be considered tied to a specific library version. */
</span><span id="line1841" class="codeline ">
</span><span id="line1842" class="codeline ">/*!
</span><span id="line1843" class="codeline "> * @brief Derive a high-entropy secret from any user-defined content, named customSeed.
</span><span id="line1844" class="codeline "> *
</span><span id="line1845" class="codeline "> * @param secretBuffer    A writable buffer for derived high-entropy secret data.
</span><span id="line1846" class="codeline "> * @param secretSize      Size of secretBuffer, in bytes.  Must be &gt;= XXH3_SECRET_SIZE_MIN.
</span><span id="line1847" class="codeline "> * @param customSeed      A user-defined content.
</span><span id="line1848" class="codeline "> * @param customSeedSize  Size of customSeed, in bytes.
</span><span id="line1849" class="codeline "> *
</span><span id="line1850" class="codeline "> * @return @ref XXH_OK on success.
</span><span id="line1851" class="codeline "> * @return @ref XXH_ERROR on failure.
</span><span id="line1852" class="codeline "> *
</span><span id="line1853" class="codeline "> * The generated secret can be used in combination with `*_withSecret()` functions.
</span><span id="line1854" class="codeline "> * The `_withSecret()` variants are useful to provide a higher level of protection
</span><span id="line1855" class="codeline "> * than 64-bit seed, as it becomes much more difficult for an external actor to
</span><span id="line1856" class="codeline "> * guess how to impact the calculation logic.
</span><span id="line1857" class="codeline "> *
</span><span id="line1858" class="codeline "> * The function accepts as input a custom seed of any length and any content,
</span><span id="line1859" class="codeline "> * and derives from it a high-entropy secret of length @p secretSize into an
</span><span id="line1860" class="codeline "> * already allocated buffer @p secretBuffer.
</span><span id="line1861" class="codeline "> *
</span><span id="line1862" class="codeline "> * The generated secret can then be used with any `*_withSecret()` variant.
</span><span id="line1863" class="codeline "> * The functions @ref XXH3_128bits_withSecret(), @ref XXH3_64bits_withSecret(),
</span><span id="line1864" class="codeline "> * @ref XXH3_128bits_reset_withSecret() and @ref XXH3_64bits_reset_withSecret()
</span><span id="line1865" class="codeline "> * are part of this list. They all accept a `secret` parameter
</span><span id="line1866" class="codeline "> * which must be large enough for implementation reasons (&gt;= @ref XXH3_SECRET_SIZE_MIN)
</span><span id="line1867" class="codeline "> * _and_ feature very high entropy (consist of random-looking bytes).
</span><span id="line1868" class="codeline "> * These conditions can be a high bar to meet, so @ref XXH3_generateSecret() can
</span><span id="line1869" class="codeline "> * be employed to ensure proper quality.
</span><span id="line1870" class="codeline "> *
</span><span id="line1871" class="codeline "> * @p customSeed can be anything. It can have any size, even small ones,
</span><span id="line1872" class="codeline "> * and its content can be anything, even &#34;poor entropy&#34; sources such as a bunch
</span><span id="line1873" class="codeline "> * of zeroes. The resulting `secret` will nonetheless provide all required qualities.
</span><span id="line1874" class="codeline "> *
</span><span id="line1875" class="codeline "> * @pre
</span><span id="line1876" class="codeline "> *   - @p secretSize must be &gt;= @ref XXH3_SECRET_SIZE_MIN
</span><span id="line1877" class="codeline "> *   - When @p customSeedSize &gt; 0, supplying NULL as customSeed is undefined behavior.
</span><span id="line1878" class="codeline "> *
</span><span id="line1879" class="codeline "> * Example code:
</span><span id="line1880" class="codeline "> * @code{.c}
</span><span id="line1881" class="codeline "> *    #include &lt;stdio.h&gt;
</span><span id="line1882" class="codeline "> *    #include &lt;stdlib.h&gt;
</span><span id="line1883" class="codeline "> *    #include &lt;string.h&gt;
</span><span id="line1884" class="codeline "> *    #define XXH_STATIC_LINKING_ONLY // expose unstable API
</span><span id="line1885" class="codeline "> *    #include &#34;xxhash.h&#34;
</span><span id="line1886" class="codeline "> *    // Hashes argv[2] using the entropy from argv[1].
</span><span id="line1887" class="codeline "> *    int main(int argc, char* argv[])
</span><span id="line1888" class="codeline "> *    {
</span><span id="line1889" class="codeline "> *        char secret[XXH3_SECRET_SIZE_MIN];
</span><span id="line1890" class="codeline "> *        if (argv != 3) { return 1; }
</span><span id="line1891" class="codeline "> *        XXH3_generateSecret(secret, sizeof(secret), argv[1], strlen(argv[1]));
</span><span id="line1892" class="codeline "> *        XXH64_hash_t h = XXH3_64bits_withSecret(
</span><span id="line1893" class="codeline "> *             argv[2], strlen(argv[2]),
</span><span id="line1894" class="codeline "> *             secret, sizeof(secret)
</span><span id="line1895" class="codeline "> *        );
</span><span id="line1896" class="codeline "> *        printf(&#34;%016llx\n&#34;, (unsigned long long) h);
</span><span id="line1897" class="codeline "> *    }
</span><span id="line1898" class="codeline "> * @endcode
</span><span id="line1899" class="codeline "> */
</span><span id="line1900" class="codeline ">XXH_PUBLIC_API XXH_errorcode XXH3_generateSecret(XXH_NOESCAPE void* secretBuffer, size_t secretSize, XXH_NOESCAPE const void* customSeed, size_t customSeedSize);
</span><span id="line1901" class="codeline ">
</span><span id="line1902" class="codeline ">/*!
</span><span id="line1903" class="codeline "> * @brief Generate the same secret as the _withSeed() variants.
</span><span id="line1904" class="codeline "> *
</span><span id="line1905" class="codeline "> * @param secretBuffer A writable buffer of @ref XXH3_SECRET_DEFAULT_SIZE bytes
</span><span id="line1906" class="codeline "> * @param seed         The 64-bit seed to alter the hash result predictably.
</span><span id="line1907" class="codeline "> *
</span><span id="line1908" class="codeline "> * The generated secret can be used in combination with
</span><span id="line1909" class="codeline "> *`*_withSecret()` and `_withSecretandSeed()` variants.
</span><span id="line1910" class="codeline "> *
</span><span id="line1911" class="codeline "> * Example C++ `std::string` hash class:
</span><span id="line1912" class="codeline "> * @code{.cpp}
</span><span id="line1913" class="codeline "> *    #include &lt;string&gt;
</span><span id="line1914" class="codeline "> *    #define XXH_STATIC_LINKING_ONLY // expose unstable API
</span><span id="line1915" class="codeline "> *    #include &#34;xxhash.h&#34;
</span><span id="line1916" class="codeline "> *    // Slow, seeds each time
</span><span id="line1917" class="codeline "> *    class HashSlow {
</span><span id="line1918" class="codeline "> *        XXH64_hash_t seed;
</span><span id="line1919" class="codeline "> *    public:
</span><span id="line1920" class="codeline "> *        HashSlow(XXH64_hash_t s) : seed{s} {}
</span><span id="line1921" class="codeline "> *        size_t operator()(const std::string&amp; x) const {
</span><span id="line1922" class="codeline "> *            return size_t{XXH3_64bits_withSeed(x.c_str(), x.length(), seed)};
</span><span id="line1923" class="codeline "> *        }
</span><span id="line1924" class="codeline "> *    };
</span><span id="line1925" class="codeline "> *    // Fast, caches the seeded secret for future uses.
</span><span id="line1926" class="codeline "> *    class HashFast {
</span><span id="line1927" class="codeline "> *        unsigned char secret[XXH3_SECRET_DEFAULT_SIZE];
</span><span id="line1928" class="codeline "> *    public:
</span><span id="line1929" class="codeline "> *        HashFast(XXH64_hash_t s) {
</span><span id="line1930" class="codeline "> *            XXH3_generateSecret_fromSeed(secret, seed);
</span><span id="line1931" class="codeline "> *        }
</span><span id="line1932" class="codeline "> *        size_t operator()(const std::string&amp; x) const {
</span><span id="line1933" class="codeline "> *            return size_t{
</span><span id="line1934" class="codeline "> *                XXH3_64bits_withSecret(x.c_str(), x.length(), secret, sizeof(secret))
</span><span id="line1935" class="codeline "> *            };
</span><span id="line1936" class="codeline "> *        }
</span><span id="line1937" class="codeline "> *    };
</span><span id="line1938" class="codeline "> * @endcode
</span><span id="line1939" class="codeline "> */
</span><span id="line1940" class="codeline ">XXH_PUBLIC_API void XXH3_generateSecret_fromSeed(XXH_NOESCAPE void* secretBuffer, XXH64_hash_t seed);
</span><span id="line1941" class="codeline ">
</span><span id="line1942" class="codeline ">/*!
</span><span id="line1943" class="codeline "> * @brief Maximum size of &#34;short&#34; key in bytes.
</span><span id="line1944" class="codeline "> */
</span><span id="line1945" class="codeline ">#define XXH3_MIDSIZE_MAX 240
</span><span id="line1946" class="codeline ">
</span><span id="line1947" class="codeline ">/*!
</span><span id="line1948" class="codeline "> * @brief Calculates 64/128-bit seeded variant of XXH3 hash of @p data.
</span><span id="line1949" class="codeline "> *
</span><span id="line1950" class="codeline "> * @param data       The block of data to be hashed, at least @p len bytes in size.
</span><span id="line1951" class="codeline "> * @param len        The length of @p data, in bytes.
</span><span id="line1952" class="codeline "> * @param secret     The secret data.
</span><span id="line1953" class="codeline "> * @param secretSize The length of @p secret, in bytes.
</span><span id="line1954" class="codeline "> * @param seed       The 64-bit seed to alter the hash result predictably.
</span><span id="line1955" class="codeline "> *
</span><span id="line1956" class="codeline "> * These variants generate hash values using either:
</span><span id="line1957" class="codeline "> * - @p seed for &#34;short&#34; keys (&lt; @ref XXH3_MIDSIZE_MAX = 240 bytes)
</span><span id="line1958" class="codeline "> * - @p secret for &#34;large&#34; keys (&gt;= @ref XXH3_MIDSIZE_MAX).
</span><span id="line1959" class="codeline "> *
</span><span id="line1960" class="codeline "> * This generally benefits speed, compared to `_withSeed()` or `_withSecret()`.
</span><span id="line1961" class="codeline "> * `_withSeed()` has to generate the secret on the fly for &#34;large&#34; keys.
</span><span id="line1962" class="codeline "> * It&#39;s fast, but can be perceptible for &#34;not so large&#34; keys (&lt; 1 KB).
</span><span id="line1963" class="codeline "> * `_withSecret()` has to generate the masks on the fly for &#34;small&#34; keys,
</span><span id="line1964" class="codeline "> * which requires more instructions than _withSeed() variants.
</span><span id="line1965" class="codeline "> * Therefore, _withSecretandSeed variant combines the best of both worlds.
</span><span id="line1966" class="codeline "> *
</span><span id="line1967" class="codeline "> * When @p secret has been generated by XXH3_generateSecret_fromSeed(),
</span><span id="line1968" class="codeline "> * this variant produces *exactly* the same results as `_withSeed()` variant,
</span><span id="line1969" class="codeline "> * hence offering only a pure speed benefit on &#34;large&#34; input,
</span><span id="line1970" class="codeline "> * by skipping the need to regenerate the secret for every large input.
</span><span id="line1971" class="codeline "> *
</span><span id="line1972" class="codeline "> * Another usage scenario is to hash the secret to a 64-bit hash value,
</span><span id="line1973" class="codeline "> * for example with XXH3_64bits(), which then becomes the seed,
</span><span id="line1974" class="codeline "> * and then employ both the seed and the secret in _withSecretandSeed().
</span><span id="line1975" class="codeline "> * On top of speed, an added benefit is that each bit in the secret
</span><span id="line1976" class="codeline "> * has a 50% chance to swap each bit in the output, via its impact to the seed.
</span><span id="line1977" class="codeline "> *
</span><span id="line1978" class="codeline "> * This is not guaranteed when using the secret directly in &#34;small data&#34; scenarios,
</span><span id="line1979" class="codeline "> * because only portions of the secret are employed for small data.
</span><span id="line1980" class="codeline "> */
</span><span id="line1981" class="codeline ">XXH_PUBLIC_API XXH_PUREF XXH64_hash_t
</span><span id="line1982" class="codeline ">XXH3_64bits_withSecretandSeed(XXH_NOESCAPE const void* data, size_t len,
</span><span id="line1983" class="codeline ">                              XXH_NOESCAPE const void* secret, size_t secretSize,
</span><span id="line1984" class="codeline ">                              XXH64_hash_t seed);
</span><span id="line1985" class="codeline ">
</span><span id="line1986" class="codeline ">/*!
</span><span id="line1987" class="codeline "> * @brief Calculates 128-bit seeded variant of XXH3 hash of @p data.
</span><span id="line1988" class="codeline "> *
</span><span id="line1989" class="codeline "> * @param data       The memory segment to be hashed, at least @p len bytes in size.
</span><span id="line1990" class="codeline "> * @param length     The length of @p data, in bytes.
</span><span id="line1991" class="codeline "> * @param secret     The secret used to alter hash result predictably.
</span><span id="line1992" class="codeline "> * @param secretSize The length of @p secret, in bytes (must be &gt;= XXH3_SECRET_SIZE_MIN)
</span><span id="line1993" class="codeline "> * @param seed64     The 64-bit seed to alter the hash result predictably.
</span><span id="line1994" class="codeline "> *
</span><span id="line1995" class="codeline "> * @return @ref XXH_OK on success.
</span><span id="line1996" class="codeline "> * @return @ref XXH_ERROR on failure.
</span><span id="line1997" class="codeline "> *
</span><span id="line1998" class="codeline "> * @see XXH3_64bits_withSecretandSeed(): contract is the same.
</span><span id="line1999" class="codeline "> */
</span><span id="line2000" class="codeline ">XXH_PUBLIC_API XXH_PUREF XXH128_hash_t
</span><span id="line2001" class="codeline ">XXH3_128bits_withSecretandSeed(XXH_NOESCAPE const void* input, size_t length,
</span><span id="line2002" class="codeline ">                               XXH_NOESCAPE const void* secret, size_t secretSize,
</span><span id="line2003" class="codeline ">                               XXH64_hash_t seed64);
</span><span id="line2004" class="codeline ">
</span><span id="line2005" class="codeline ">#ifndef XXH_NO_STREAM
</span><span id="line2006" class="codeline ">/*!
</span><span id="line2007" class="codeline "> * @brief Resets an @ref XXH3_state_t with secret data to begin a new hash.
</span><span id="line2008" class="codeline "> *
</span><span id="line2009" class="codeline "> * @param statePtr   A pointer to an @ref XXH3_state_t allocated with @ref XXH3_createState().
</span><span id="line2010" class="codeline "> * @param secret     The secret data.
</span><span id="line2011" class="codeline "> * @param secretSize The length of @p secret, in bytes.
</span><span id="line2012" class="codeline "> * @param seed64     The 64-bit seed to alter the hash result predictably.
</span><span id="line2013" class="codeline "> *
</span><span id="line2014" class="codeline "> * @return @ref XXH_OK on success.
</span><span id="line2015" class="codeline "> * @return @ref XXH_ERROR on failure.
</span><span id="line2016" class="codeline "> *
</span><span id="line2017" class="codeline "> * @see XXH3_64bits_withSecretandSeed(). Contract is identical.
</span><span id="line2018" class="codeline "> */
</span><span id="line2019" class="codeline ">XXH_PUBLIC_API XXH_errorcode
</span><span id="line2020" class="codeline ">XXH3_64bits_reset_withSecretandSeed(XXH_NOESCAPE XXH3_state_t* statePtr,
</span><span id="line2021" class="codeline ">                                    XXH_NOESCAPE const void* secret, size_t secretSize,
</span><span id="line2022" class="codeline ">                                    XXH64_hash_t seed64);
</span><span id="line2023" class="codeline ">
</span><span id="line2024" class="codeline ">/*!
</span><span id="line2025" class="codeline "> * @brief Resets an @ref XXH3_state_t with secret data to begin a new hash.
</span><span id="line2026" class="codeline "> *
</span><span id="line2027" class="codeline "> * @param statePtr   A pointer to an @ref XXH3_state_t allocated with @ref XXH3_createState().
</span><span id="line2028" class="codeline "> * @param secret     The secret data.
</span><span id="line2029" class="codeline "> * @param secretSize The length of @p secret, in bytes.
</span><span id="line2030" class="codeline "> * @param seed64     The 64-bit seed to alter the hash result predictably.
</span><span id="line2031" class="codeline "> *
</span><span id="line2032" class="codeline "> * @return @ref XXH_OK on success.
</span><span id="line2033" class="codeline "> * @return @ref XXH_ERROR on failure.
</span><span id="line2034" class="codeline "> *
</span><span id="line2035" class="codeline "> * @see XXH3_64bits_withSecretandSeed(). Contract is identical.
</span><span id="line2036" class="codeline "> *
</span><span id="line2037" class="codeline "> * Note: there was a bug in an earlier version of this function (&lt;= v0.8.2)
</span><span id="line2038" class="codeline "> * that would make it generate an incorrect hash value
</span><span id="line2039" class="codeline "> * when @p seed == 0 and @p length &lt; XXH3_MIDSIZE_MAX
</span><span id="line2040" class="codeline "> * and @p secret is different from XXH3_generateSecret_fromSeed().
</span><span id="line2041" class="codeline "> * As stated in the contract, the correct hash result must be
</span><span id="line2042" class="codeline "> * the same as XXH3_128bits_withSeed() when @p length &lt;= XXH3_MIDSIZE_MAX.
</span><span id="line2043" class="codeline "> * Results generated by this older version are wrong, hence not comparable.
</span><span id="line2044" class="codeline "> */
</span><span id="line2045" class="codeline ">XXH_PUBLIC_API XXH_errorcode
</span><span id="line2046" class="codeline ">XXH3_128bits_reset_withSecretandSeed(XXH_NOESCAPE XXH3_state_t* statePtr,
</span><span id="line2047" class="codeline ">                                     XXH_NOESCAPE const void* secret, size_t secretSize,
</span><span id="line2048" class="codeline ">                                     XXH64_hash_t seed64);
</span><span id="line2049" class="codeline ">
</span><span id="line2050" class="codeline ">#endif /* !XXH_NO_STREAM */
</span><span id="line2051" class="codeline ">
</span><span id="line2052" class="codeline ">#endif  /* !XXH_NO_XXH3 */
</span><span id="line2053" class="codeline ">#endif  /* XXH_NO_LONG_LONG */
</span><span id="line2054" class="codeline ">#if defined(XXH_INLINE_ALL) || defined(XXH_PRIVATE_API)
</span><span id="line2055" class="codeline ">#  define XXH_IMPLEMENTATION
</span><span id="line2056" class="codeline ">#endif
</span><span id="line2057" class="codeline ">
</span><span id="line2058" class="codeline ">#endif  /* defined(XXH_STATIC_LINKING_ONLY) &amp;&amp; !defined(XXHASH_H_STATIC_13879238742) */
</span><span id="line2059" class="codeline ">
</span><span id="line2060" class="codeline ">
</span><span id="line2061" class="codeline ">/* ======================================================================== */
</span><span id="line2062" class="codeline ">/* ======================================================================== */
</span><span id="line2063" class="codeline ">/* ======================================================================== */
</span><span id="line2064" class="codeline ">
</span><span id="line2065" class="codeline ">
</span><span id="line2066" class="codeline ">/*-**********************************************************************
</span><span id="line2067" class="codeline "> * xxHash implementation
</span><span id="line2068" class="codeline "> *-**********************************************************************
</span><span id="line2069" class="codeline "> * xxHash&#39;s implementation used to be hosted inside xxhash.c.
</span><span id="line2070" class="codeline "> *
</span><span id="line2071" class="codeline "> * However, inlining requires implementation to be visible to the compiler,
</span><span id="line2072" class="codeline "> * hence be included alongside the header.
</span><span id="line2073" class="codeline "> * Previously, implementation was hosted inside xxhash.c,
</span><span id="line2074" class="codeline "> * which was then #included when inlining was activated.
</span><span id="line2075" class="codeline "> * This construction created issues with a few build and install systems,
</span><span id="line2076" class="codeline "> * as it required xxhash.c to be stored in /include directory.
</span><span id="line2077" class="codeline "> *
</span><span id="line2078" class="codeline "> * xxHash implementation is now directly integrated within xxhash.h.
</span><span id="line2079" class="codeline "> * As a consequence, xxhash.c is no longer needed in /include.
</span><span id="line2080" class="codeline "> *
</span><span id="line2081" class="codeline "> * xxhash.c is still available and is still useful.
</span><span id="line2082" class="codeline "> * In a &#34;normal&#34; setup, when xxhash is not inlined,
</span><span id="line2083" class="codeline "> * xxhash.h only exposes the prototypes and public symbols,
</span><span id="line2084" class="codeline "> * while xxhash.c can be built into an object file xxhash.o
</span><span id="line2085" class="codeline "> * which can then be linked into the final binary.
</span><span id="line2086" class="codeline "> ************************************************************************/
</span><span id="line2087" class="codeline ">
</span><span id="line2088" class="codeline ">#if ( defined(XXH_INLINE_ALL) || defined(XXH_PRIVATE_API) \
</span><span id="line2089" class="codeline ">   || defined(XXH_IMPLEMENTATION) ) &amp;&amp; !defined(XXH_IMPLEM_13a8737387)
</span><span id="line2090" class="codeline ">#  define XXH_IMPLEM_13a8737387
</span><span id="line2091" class="codeline ">
</span><span id="line2092" class="codeline ">/* *************************************
</span><span id="line2093" class="codeline ">*  Tuning parameters
</span><span id="line2094" class="codeline ">***************************************/
</span><span id="line2095" class="codeline ">
</span><span id="line2096" class="codeline ">/*!
</span><span id="line2097" class="codeline "> * @defgroup tuning Tuning parameters
</span><span id="line2098" class="codeline "> * @{
</span><span id="line2099" class="codeline "> *
</span><span id="line2100" class="codeline "> * Various macros to control xxHash&#39;s behavior.
</span><span id="line2101" class="codeline "> */
</span><span id="line2102" class="codeline ">#ifdef XXH_DOXYGEN
</span><span id="line2103" class="codeline ">/*!
</span><span id="line2104" class="codeline "> * @brief Define this to disable 64-bit code.
</span><span id="line2105" class="codeline "> *
</span><span id="line2106" class="codeline "> * Useful if only using the @ref XXH32_family and you have a strict C90 compiler.
</span><span id="line2107" class="codeline "> */
</span><span id="line2108" class="codeline ">#  define XXH_NO_LONG_LONG
</span><span id="line2109" class="codeline ">#  undef XXH_NO_LONG_LONG /* don&#39;t actually */
</span><span id="line2110" class="codeline ">/*!
</span><span id="line2111" class="codeline "> * @brief Controls how unaligned memory is accessed.
</span><span id="line2112" class="codeline "> *
</span><span id="line2113" class="codeline "> * By default, access to unaligned memory is controlled by `memcpy()`, which is
</span><span id="line2114" class="codeline "> * safe and portable.
</span><span id="line2115" class="codeline "> *
</span><span id="line2116" class="codeline "> * Unfortunately, on some target/compiler combinations, the generated assembly
</span><span id="line2117" class="codeline "> * is sub-optimal.
</span><span id="line2118" class="codeline "> *
</span><span id="line2119" class="codeline "> * The below switch allow selection of a different access method
</span><span id="line2120" class="codeline "> * in the search for improved performance.
</span><span id="line2121" class="codeline "> *
</span><span id="line2122" class="codeline "> * @par Possible options:
</span><span id="line2123" class="codeline "> *
</span><span id="line2124" class="codeline "> *  - `XXH_FORCE_MEMORY_ACCESS=0` (default): `memcpy`
</span><span id="line2125" class="codeline "> *   @par
</span><span id="line2126" class="codeline "> *     Use `memcpy()`. Safe and portable. Note that most modern compilers will
</span><span id="line2127" class="codeline "> *     eliminate the function call and treat it as an unaligned access.
</span><span id="line2128" class="codeline "> *
</span><span id="line2129" class="codeline "> *  - `XXH_FORCE_MEMORY_ACCESS=1`: `__attribute__((aligned(1)))`
</span><span id="line2130" class="codeline "> *   @par
</span><span id="line2131" class="codeline "> *     Depends on compiler extensions and is therefore not portable.
</span><span id="line2132" class="codeline "> *     This method is safe _if_ your compiler supports it,
</span><span id="line2133" class="codeline "> *     and *generally* as fast or faster than `memcpy`.
</span><span id="line2134" class="codeline "> *
</span><span id="line2135" class="codeline "> *  - `XXH_FORCE_MEMORY_ACCESS=2`: Direct cast
</span><span id="line2136" class="codeline "> *  @par
</span><span id="line2137" class="codeline "> *     Casts directly and dereferences. This method doesn&#39;t depend on the
</span><span id="line2138" class="codeline "> *     compiler, but it violates the C standard as it directly dereferences an
</span><span id="line2139" class="codeline "> *     unaligned pointer. It can generate buggy code on targets which do not
</span><span id="line2140" class="codeline "> *     support unaligned memory accesses, but in some circumstances, it&#39;s the
</span><span id="line2141" class="codeline "> *     only known way to get the most performance.
</span><span id="line2142" class="codeline "> *
</span><span id="line2143" class="codeline "> *  - `XXH_FORCE_MEMORY_ACCESS=3`: Byteshift
</span><span id="line2144" class="codeline "> *  @par
</span><span id="line2145" class="codeline "> *     Also portable. This can generate the best code on old compilers which don&#39;t
</span><span id="line2146" class="codeline "> *     inline small `memcpy()` calls, and it might also be faster on big-endian
</span><span id="line2147" class="codeline "> *     systems which lack a native byteswap instruction. However, some compilers
</span><span id="line2148" class="codeline "> *     will emit literal byteshifts even if the target supports unaligned access.
</span><span id="line2149" class="codeline "> *
</span><span id="line2150" class="codeline "> *
</span><span id="line2151" class="codeline "> * @warning
</span><span id="line2152" class="codeline "> *   Methods 1 and 2 rely on implementation-defined behavior. Use these with
</span><span id="line2153" class="codeline "> *   care, as what works on one compiler/platform/optimization level may cause
</span><span id="line2154" class="codeline "> *   another to read garbage data or even crash.
</span><span id="line2155" class="codeline "> *
</span><span id="line2156" class="codeline "> * See https://fastcompression.blogspot.com/2015/08/accessing-unaligned-memory.html for details.
</span><span id="line2157" class="codeline "> *
</span><span id="line2158" class="codeline "> * Prefer these methods in priority order (0 &gt; 3 &gt; 1 &gt; 2)
</span><span id="line2159" class="codeline "> */
</span><span id="line2160" class="codeline ">#  define XXH_FORCE_MEMORY_ACCESS 0
</span><span id="line2161" class="codeline ">
</span><span id="line2162" class="codeline ">/*!
</span><span id="line2163" class="codeline "> * @def XXH_SIZE_OPT
</span><span id="line2164" class="codeline "> * @brief Controls how much xxHash optimizes for size.
</span><span id="line2165" class="codeline "> *
</span><span id="line2166" class="codeline "> * xxHash, when compiled, tends to result in a rather large binary size. This
</span><span id="line2167" class="codeline "> * is mostly due to heavy usage to forced inlining and constant folding of the
</span><span id="line2168" class="codeline "> * @ref XXH3_family to increase performance.
</span><span id="line2169" class="codeline "> *
</span><span id="line2170" class="codeline "> * However, some developers prefer size over speed. This option can
</span><span id="line2171" class="codeline "> * significantly reduce the size of the generated code. When using the `-Os`
</span><span id="line2172" class="codeline "> * or `-Oz` options on GCC or Clang, this is defined to 1 by default,
</span><span id="line2173" class="codeline "> * otherwise it is defined to 0.
</span><span id="line2174" class="codeline "> *
</span><span id="line2175" class="codeline "> * Most of these size optimizations can be controlled manually.
</span><span id="line2176" class="codeline "> *
</span><span id="line2177" class="codeline "> * This is a number from 0-2.
</span><span id="line2178" class="codeline "> *  - `XXH_SIZE_OPT` == 0: Default. xxHash makes no size optimizations. Speed
</span><span id="line2179" class="codeline "> *    comes first.
</span><span id="line2180" class="codeline "> *  - `XXH_SIZE_OPT` == 1: Default for `-Os` and `-Oz`. xxHash is more
</span><span id="line2181" class="codeline "> *    conservative and disables hacks that increase code size. It implies the
</span><span id="line2182" class="codeline "> *    options @ref XXH_NO_INLINE_HINTS == 1, @ref XXH_FORCE_ALIGN_CHECK == 0,
</span><span id="line2183" class="codeline "> *    and @ref XXH3_NEON_LANES == 8 if they are not already defined.
</span><span id="line2184" class="codeline "> *  - `XXH_SIZE_OPT` == 2: xxHash tries to make itself as small as possible.
</span><span id="line2185" class="codeline "> *    Performance may cry. For example, the single shot functions just use the
</span><span id="line2186" class="codeline "> *    streaming API.
</span><span id="line2187" class="codeline "> */
</span><span id="line2188" class="codeline ">#  define XXH_SIZE_OPT 0
</span><span id="line2189" class="codeline ">
</span><span id="line2190" class="codeline ">/*!
</span><span id="line2191" class="codeline "> * @def XXH_FORCE_ALIGN_CHECK
</span><span id="line2192" class="codeline "> * @brief If defined to non-zero, adds a special path for aligned inputs (XXH32()
</span><span id="line2193" class="codeline "> * and XXH64() only).
</span><span id="line2194" class="codeline "> *
</span><span id="line2195" class="codeline "> * This is an important performance trick for architectures without decent
</span><span id="line2196" class="codeline "> * unaligned memory access performance.
</span><span id="line2197" class="codeline "> *
</span><span id="line2198" class="codeline "> * It checks for input alignment, and when conditions are met, uses a &#34;fast
</span><span id="line2199" class="codeline "> * path&#34; employing direct 32-bit/64-bit reads, resulting in _dramatically
</span><span id="line2200" class="codeline "> * faster_ read speed.
</span><span id="line2201" class="codeline "> *
</span><span id="line2202" class="codeline "> * The check costs one initial branch per hash, which is generally negligible,
</span><span id="line2203" class="codeline "> * but not zero.
</span><span id="line2204" class="codeline "> *
</span><span id="line2205" class="codeline "> * Moreover, it&#39;s not useful to generate an additional code path if memory
</span><span id="line2206" class="codeline "> * access uses the same instruction for both aligned and unaligned
</span><span id="line2207" class="codeline "> * addresses (e.g. x86 and aarch64).
</span><span id="line2208" class="codeline "> *
</span><span id="line2209" class="codeline "> * In these cases, the alignment check can be removed by setting this macro to 0.
</span><span id="line2210" class="codeline "> * Then the code will always use unaligned memory access.
</span><span id="line2211" class="codeline "> * Align check is automatically disabled on x86, x64, ARM64, and some ARM chips
</span><span id="line2212" class="codeline "> * which are platforms known to offer good unaligned memory accesses performance.
</span><span id="line2213" class="codeline "> *
</span><span id="line2214" class="codeline "> * It is also disabled by default when @ref XXH_SIZE_OPT &gt;= 1.
</span><span id="line2215" class="codeline "> *
</span><span id="line2216" class="codeline "> * This option does not affect XXH3 (only XXH32 and XXH64).
</span><span id="line2217" class="codeline "> */
</span><span id="line2218" class="codeline ">#  define XXH_FORCE_ALIGN_CHECK 0
</span><span id="line2219" class="codeline ">
</span><span id="line2220" class="codeline ">/*!
</span><span id="line2221" class="codeline "> * @def XXH_NO_INLINE_HINTS
</span><span id="line2222" class="codeline "> * @brief When non-zero, sets all functions to `static`.
</span><span id="line2223" class="codeline "> *
</span><span id="line2224" class="codeline "> * By default, xxHash tries to force the compiler to inline almost all internal
</span><span id="line2225" class="codeline "> * functions.
</span><span id="line2226" class="codeline "> *
</span><span id="line2227" class="codeline "> * This can usually improve performance due to reduced jumping and improved
</span><span id="line2228" class="codeline "> * constant folding, but significantly increases the size of the binary which
</span><span id="line2229" class="codeline "> * might not be favorable.
</span><span id="line2230" class="codeline "> *
</span><span id="line2231" class="codeline "> * Additionally, sometimes the forced inlining can be detrimental to performance,
</span><span id="line2232" class="codeline "> * depending on the architecture.
</span><span id="line2233" class="codeline "> *
</span><span id="line2234" class="codeline "> * XXH_NO_INLINE_HINTS marks all internal functions as static, giving the
</span><span id="line2235" class="codeline "> * compiler full control on whether to inline or not.
</span><span id="line2236" class="codeline "> *
</span><span id="line2237" class="codeline "> * When not optimizing (-O0), using `-fno-inline` with GCC or Clang, or if
</span><span id="line2238" class="codeline "> * @ref XXH_SIZE_OPT &gt;= 1, this will automatically be defined.
</span><span id="line2239" class="codeline "> */
</span><span id="line2240" class="codeline ">#  define XXH_NO_INLINE_HINTS 0
</span><span id="line2241" class="codeline ">
</span><span id="line2242" class="codeline ">/*!
</span><span id="line2243" class="codeline "> * @def XXH3_INLINE_SECRET
</span><span id="line2244" class="codeline "> * @brief Determines whether to inline the XXH3 withSecret code.
</span><span id="line2245" class="codeline "> *
</span><span id="line2246" class="codeline "> * When the secret size is known, the compiler can improve the performance
</span><span id="line2247" class="codeline "> * of XXH3_64bits_withSecret() and XXH3_128bits_withSecret().
</span><span id="line2248" class="codeline "> *
</span><span id="line2249" class="codeline "> * However, if the secret size is not known, it doesn&#39;t have any benefit. This
</span><span id="line2250" class="codeline "> * happens when xxHash is compiled into a global symbol. Therefore, if
</span><span id="line2251" class="codeline "> * @ref XXH_INLINE_ALL is *not* defined, this will be defined to 0.
</span><span id="line2252" class="codeline "> *
</span><span id="line2253" class="codeline "> * Additionally, this defaults to 0 on GCC 12+, which has an issue with function pointers
</span><span id="line2254" class="codeline "> * that are *sometimes* force inline on -Og, and it is impossible to automatically
</span><span id="line2255" class="codeline "> * detect this optimization level.
</span><span id="line2256" class="codeline "> */
</span><span id="line2257" class="codeline ">#  define XXH3_INLINE_SECRET 0
</span><span id="line2258" class="codeline ">
</span><span id="line2259" class="codeline ">/*!
</span><span id="line2260" class="codeline "> * @def XXH32_ENDJMP
</span><span id="line2261" class="codeline "> * @brief Whether to use a jump for `XXH32_finalize`.
</span><span id="line2262" class="codeline "> *
</span><span id="line2263" class="codeline "> * For performance, `XXH32_finalize` uses multiple branches in the finalizer.
</span><span id="line2264" class="codeline "> * This is generally preferable for performance,
</span><span id="line2265" class="codeline "> * but depending on exact architecture, a jmp may be preferable.
</span><span id="line2266" class="codeline "> *
</span><span id="line2267" class="codeline "> * This setting is only possibly making a difference for very small inputs.
</span><span id="line2268" class="codeline "> */
</span><span id="line2269" class="codeline ">#  define XXH32_ENDJMP 0
</span><span id="line2270" class="codeline ">
</span><span id="line2271" class="codeline ">/*!
</span><span id="line2272" class="codeline "> * @internal
</span><span id="line2273" class="codeline "> * @brief Redefines old internal names.
</span><span id="line2274" class="codeline "> *
</span><span id="line2275" class="codeline "> * For compatibility with code that uses xxHash&#39;s internals before the names
</span><span id="line2276" class="codeline "> * were changed to improve namespacing. There is no other reason to use this.
</span><span id="line2277" class="codeline "> */
</span><span id="line2278" class="codeline ">#  define XXH_OLD_NAMES
</span><span id="line2279" class="codeline ">#  undef XXH_OLD_NAMES /* don&#39;t actually use, it is ugly. */
</span><span id="line2280" class="codeline ">
</span><span id="line2281" class="codeline ">/*!
</span><span id="line2282" class="codeline "> * @def XXH_NO_STREAM
</span><span id="line2283" class="codeline "> * @brief Disables the streaming API.
</span><span id="line2284" class="codeline "> *
</span><span id="line2285" class="codeline "> * When xxHash is not inlined and the streaming functions are not used, disabling
</span><span id="line2286" class="codeline "> * the streaming functions can improve code size significantly, especially with
</span><span id="line2287" class="codeline "> * the @ref XXH3_family which tends to make constant folded copies of itself.
</span><span id="line2288" class="codeline "> */
</span><span id="line2289" class="codeline ">#  define XXH_NO_STREAM
</span><span id="line2290" class="codeline ">#  undef XXH_NO_STREAM /* don&#39;t actually */
</span><span id="line2291" class="codeline ">#endif /* XXH_DOXYGEN */
</span><span id="line2292" class="codeline ">/*!
</span><span id="line2293" class="codeline "> * @}
</span><span id="line2294" class="codeline "> */
</span><span id="line2295" class="codeline ">
</span><span id="line2296" class="codeline ">#ifndef XXH_FORCE_MEMORY_ACCESS   /* can be defined externally, on command line for example */
</span><span id="line2297" class="codeline ">   /* prefer __packed__ structures (method 1) for GCC
</span><span id="line2298" class="codeline ">    * &lt; ARMv7 with unaligned access (e.g. Raspbian armhf) still uses byte shifting, so we use memcpy
</span><span id="line2299" class="codeline ">    * which for some reason does unaligned loads. */
</span><span id="line2300" class="codeline ">#  if defined(__GNUC__) &amp;&amp; !(defined(__ARM_ARCH) &amp;&amp; __ARM_ARCH &lt; 7 &amp;&amp; defined(__ARM_FEATURE_UNALIGNED))
</span><span id="line2301" class="codeline ">#    define XXH_FORCE_MEMORY_ACCESS 1
</span><span id="line2302" class="codeline ">#  endif
</span><span id="line2303" class="codeline ">#endif
</span><span id="line2304" class="codeline ">
</span><span id="line2305" class="codeline ">#ifndef XXH_SIZE_OPT
</span><span id="line2306" class="codeline ">   /* default to 1 for -Os or -Oz */
</span><span id="line2307" class="codeline ">#  if (defined(__GNUC__) || defined(__clang__)) &amp;&amp; defined(__OPTIMIZE_SIZE__)
</span><span id="line2308" class="codeline ">#    define XXH_SIZE_OPT 1
</span><span id="line2309" class="codeline ">#  else
</span><span id="line2310" class="codeline ">#    define XXH_SIZE_OPT 0
</span><span id="line2311" class="codeline ">#  endif
</span><span id="line2312" class="codeline ">#endif
</span><span id="line2313" class="codeline ">
</span><span id="line2314" class="codeline ">#ifndef XXH_FORCE_ALIGN_CHECK  /* can be defined externally */
</span><span id="line2315" class="codeline ">   /* don&#39;t check on sizeopt, x86, aarch64, or arm when unaligned access is available */
</span><span id="line2316" class="codeline ">#  if XXH_SIZE_OPT &gt;= 1 || \
</span><span id="line2317" class="codeline ">      defined(__i386)  || defined(__x86_64__) || defined(__aarch64__) || defined(__ARM_FEATURE_UNALIGNED) \
</span><span id="line2318" class="codeline ">   || defined(_M_IX86) || defined(_M_X64)     || defined(_M_ARM64)    || defined(_M_ARM) /* visual */
</span><span id="line2319" class="codeline ">#    define XXH_FORCE_ALIGN_CHECK 0
</span><span id="line2320" class="codeline ">#  else
</span><span id="line2321" class="codeline ">#    define XXH_FORCE_ALIGN_CHECK 1
</span><span id="line2322" class="codeline ">#  endif
</span><span id="line2323" class="codeline ">#endif
</span><span id="line2324" class="codeline ">
</span><span id="line2325" class="codeline ">#ifndef XXH_NO_INLINE_HINTS
</span><span id="line2326" class="codeline ">#  if XXH_SIZE_OPT &gt;= 1 || defined(__NO_INLINE__)  /* -O0, -fno-inline */
</span><span id="line2327" class="codeline ">#    define XXH_NO_INLINE_HINTS 1
</span><span id="line2328" class="codeline ">#  else
</span><span id="line2329" class="codeline ">#    define XXH_NO_INLINE_HINTS 0
</span><span id="line2330" class="codeline ">#  endif
</span><span id="line2331" class="codeline ">#endif
</span><span id="line2332" class="codeline ">
</span><span id="line2333" class="codeline ">#ifndef XXH3_INLINE_SECRET
</span><span id="line2334" class="codeline ">#  if (defined(__GNUC__) &amp;&amp; !defined(__clang__) &amp;&amp; __GNUC__ &gt;= 12) \
</span><span id="line2335" class="codeline ">     || !defined(XXH_INLINE_ALL)
</span><span id="line2336" class="codeline ">#    define XXH3_INLINE_SECRET 0
</span><span id="line2337" class="codeline ">#  else
</span><span id="line2338" class="codeline ">#    define XXH3_INLINE_SECRET 1
</span><span id="line2339" class="codeline ">#  endif
</span><span id="line2340" class="codeline ">#endif
</span><span id="line2341" class="codeline ">
</span><span id="line2342" class="codeline ">#ifndef XXH32_ENDJMP
</span><span id="line2343" class="codeline ">/* generally preferable for performance */
</span><span id="line2344" class="codeline ">#  define XXH32_ENDJMP 0
</span><span id="line2345" class="codeline ">#endif
</span><span id="line2346" class="codeline ">
</span><span id="line2347" class="codeline ">/*!
</span><span id="line2348" class="codeline "> * @defgroup impl Implementation
</span><span id="line2349" class="codeline "> * @{
</span><span id="line2350" class="codeline "> */
</span><span id="line2351" class="codeline ">
</span><span id="line2352" class="codeline ">
</span><span id="line2353" class="codeline ">/* *************************************
</span><span id="line2354" class="codeline ">*  Includes &amp; Memory related functions
</span><span id="line2355" class="codeline ">***************************************/
</span><span id="line2356" class="codeline ">#if defined(XXH_NO_STREAM)
</span><span id="line2357" class="codeline ">/* nothing */
</span><span id="line2358" class="codeline ">#elif defined(XXH_NO_STDLIB)
</span><span id="line2359" class="codeline ">
</span><span id="line2360" class="codeline ">/* When requesting to disable any mention of stdlib,
</span><span id="line2361" class="codeline "> * the library loses the ability to invoked malloc / free.
</span><span id="line2362" class="codeline "> * In practice, it means that functions like `XXH*_createState()`
</span><span id="line2363" class="codeline "> * will always fail, and return NULL.
</span><span id="line2364" class="codeline "> * This flag is useful in situations where
</span><span id="line2365" class="codeline "> * xxhash.h is integrated into some kernel, embedded or limited environment
</span><span id="line2366" class="codeline "> * without access to dynamic allocation.
</span><span id="line2367" class="codeline "> */
</span><span id="line2368" class="codeline ">
</span><span id="line2369" class="codeline ">static XXH_CONSTF void* XXH_malloc(size_t s) { (void)s; return NULL; }
</span><span id="line2370" class="codeline ">static void XXH_free(void* p) { (void)p; }
</span><span id="line2371" class="codeline ">
</span><span id="line2372" class="codeline ">#else
</span><span id="line2373" class="codeline ">
</span><span id="line2374" class="codeline ">/*
</span><span id="line2375" class="codeline "> * Modify the local functions below should you wish to use
</span><span id="line2376" class="codeline "> * different memory routines for malloc() and free()
</span><span id="line2377" class="codeline "> */
</span><span id="line2378" class="codeline ">#include &lt;stdlib.h&gt;
</span><span id="line2379" class="codeline ">
</span><span id="line2380" class="codeline ">/*!
</span><span id="line2381" class="codeline "> * @internal
</span><span id="line2382" class="codeline "> * @brief Modify this function to use a different routine than malloc().
</span><span id="line2383" class="codeline "> */
</span><span id="line2384" class="codeline ">static XXH_MALLOCF void* XXH_malloc(size_t s) { return malloc(s); }
</span><span id="line2385" class="codeline ">
</span><span id="line2386" class="codeline ">/*!
</span><span id="line2387" class="codeline "> * @internal
</span><span id="line2388" class="codeline "> * @brief Modify this function to use a different routine than free().
</span><span id="line2389" class="codeline "> */
</span><span id="line2390" class="codeline ">static void XXH_free(void* p) { free(p); }
</span><span id="line2391" class="codeline ">
</span><span id="line2392" class="codeline ">#endif  /* XXH_NO_STDLIB */
</span><span id="line2393" class="codeline ">
</span><span id="line2394" class="codeline ">#include &lt;string.h&gt;
</span><span id="line2395" class="codeline ">
</span><span id="line2396" class="codeline ">/*!
</span><span id="line2397" class="codeline "> * @internal
</span><span id="line2398" class="codeline "> * @brief Modify this function to use a different routine than memcpy().
</span><span id="line2399" class="codeline "> */
</span><span id="line2400" class="codeline ">static void* XXH_memcpy(void* dest, const void* src, size_t size)
</span><span id="line2401" class="codeline ">{
</span><span id="line2402" class="codeline ">    return memcpy(dest,src,size);
</span><span id="line2403" class="codeline ">}
</span><span id="line2404" class="codeline ">
</span><span id="line2405" class="codeline ">#include &lt;limits.h&gt;   /* ULLONG_MAX */
</span><span id="line2406" class="codeline ">
</span><span id="line2407" class="codeline ">
</span><span id="line2408" class="codeline ">/* *************************************
</span><span id="line2409" class="codeline ">*  Compiler Specific Options
</span><span id="line2410" class="codeline ">***************************************/
</span><span id="line2411" class="codeline ">#ifdef _MSC_VER /* Visual Studio warning fix */
</span><span id="line2412" class="codeline ">#  pragma warning(disable : 4127) /* disable: C4127: conditional expression is constant */
</span><span id="line2413" class="codeline ">#endif
</span><span id="line2414" class="codeline ">
</span><span id="line2415" class="codeline ">#if XXH_NO_INLINE_HINTS  /* disable inlining hints */
</span><span id="line2416" class="codeline ">#  if defined(__GNUC__) || defined(__clang__)
</span><span id="line2417" class="codeline ">#    define XXH_FORCE_INLINE static __attribute__((__unused__))
</span><span id="line2418" class="codeline ">#  else
</span><span id="line2419" class="codeline ">#    define XXH_FORCE_INLINE static
</span><span id="line2420" class="codeline ">#  endif
</span><span id="line2421" class="codeline ">#  define XXH_NO_INLINE static
</span><span id="line2422" class="codeline ">/* enable inlining hints */
</span><span id="line2423" class="codeline ">#elif defined(__GNUC__) || defined(__clang__)
</span><span id="line2424" class="codeline ">#  define XXH_FORCE_INLINE static __inline__ __attribute__((__always_inline__, __unused__))
</span><span id="line2425" class="codeline ">#  define XXH_NO_INLINE static __attribute__((__noinline__))
</span><span id="line2426" class="codeline ">#elif defined(_MSC_VER)  /* Visual Studio */
</span><span id="line2427" class="codeline ">#  define XXH_FORCE_INLINE static __forceinline
</span><span id="line2428" class="codeline ">#  define XXH_NO_INLINE static __declspec(noinline)
</span><span id="line2429" class="codeline ">#elif defined (__cplusplus) \
</span><span id="line2430" class="codeline ">  || (defined (__STDC_VERSION__) &amp;&amp; (__STDC_VERSION__ &gt;= 199901L))   /* C99 */
</span><span id="line2431" class="codeline ">#  define XXH_FORCE_INLINE static inline
</span><span id="line2432" class="codeline ">#  define XXH_NO_INLINE static
</span><span id="line2433" class="codeline ">#else
</span><span id="line2434" class="codeline ">#  define XXH_FORCE_INLINE static
</span><span id="line2435" class="codeline ">#  define XXH_NO_INLINE static
</span><span id="line2436" class="codeline ">#endif
</span><span id="line2437" class="codeline ">
</span><span id="line2438" class="codeline ">#if defined(XXH_INLINE_ALL)
</span><span id="line2439" class="codeline ">#  define XXH_STATIC XXH_FORCE_INLINE
</span><span id="line2440" class="codeline ">#else
</span><span id="line2441" class="codeline ">#  define XXH_STATIC static
</span><span id="line2442" class="codeline ">#endif
</span><span id="line2443" class="codeline ">
</span><span id="line2444" class="codeline ">#if XXH3_INLINE_SECRET
</span><span id="line2445" class="codeline ">#  define XXH3_WITH_SECRET_INLINE XXH_FORCE_INLINE
</span><span id="line2446" class="codeline ">#else
</span><span id="line2447" class="codeline ">#  define XXH3_WITH_SECRET_INLINE XXH_NO_INLINE
</span><span id="line2448" class="codeline ">#endif
</span><span id="line2449" class="codeline ">
</span><span id="line2450" class="codeline ">#if ((defined(sun) || defined(__sun)) &amp;&amp; __cplusplus) /* Solaris includes __STDC_VERSION__ with C++. Tested with GCC 5.5 */
</span><span id="line2451" class="codeline ">#  define XXH_RESTRICT   /* disable */
</span><span id="line2452" class="codeline ">#elif defined (__STDC_VERSION__) &amp;&amp; __STDC_VERSION__ &gt;= 199901L   /* &gt;= C99 */
</span><span id="line2453" class="codeline ">#  define XXH_RESTRICT   restrict
</span><span id="line2454" class="codeline ">#elif (defined (__GNUC__) &amp;&amp; ((__GNUC__ &gt; 3) || (__GNUC__ == 3 &amp;&amp; __GNUC_MINOR__ &gt;= 1))) \
</span><span id="line2455" class="codeline ">   || (defined (__clang__)) \
</span><span id="line2456" class="codeline ">   || (defined (_MSC_VER) &amp;&amp; (_MSC_VER &gt;= 1400)) \
</span><span id="line2457" class="codeline ">   || (defined (__INTEL_COMPILER) &amp;&amp; (__INTEL_COMPILER &gt;= 1300))
</span><span id="line2458" class="codeline ">/*
</span><span id="line2459" class="codeline "> * There are a LOT more compilers that recognize __restrict but this
</span><span id="line2460" class="codeline "> * covers the major ones.
</span><span id="line2461" class="codeline "> */
</span><span id="line2462" class="codeline ">#  define XXH_RESTRICT   __restrict
</span><span id="line2463" class="codeline ">#else
</span><span id="line2464" class="codeline ">#  define XXH_RESTRICT   /* disable */
</span><span id="line2465" class="codeline ">#endif
</span><span id="line2466" class="codeline ">
</span><span id="line2467" class="codeline ">/* *************************************
</span><span id="line2468" class="codeline ">*  Debug
</span><span id="line2469" class="codeline ">***************************************/
</span><span id="line2470" class="codeline ">/*!
</span><span id="line2471" class="codeline "> * @ingroup tuning
</span><span id="line2472" class="codeline "> * @def XXH_DEBUGLEVEL
</span><span id="line2473" class="codeline "> * @brief Sets the debugging level.
</span><span id="line2474" class="codeline "> *
</span><span id="line2475" class="codeline "> * XXH_DEBUGLEVEL is expected to be defined externally, typically via the
</span><span id="line2476" class="codeline "> * compiler&#39;s command line options. The value must be a number.
</span><span id="line2477" class="codeline "> */
</span><span id="line2478" class="codeline ">#ifndef XXH_DEBUGLEVEL
</span><span id="line2479" class="codeline ">#  ifdef DEBUGLEVEL /* backwards compat */
</span><span id="line2480" class="codeline ">#    define XXH_DEBUGLEVEL DEBUGLEVEL
</span><span id="line2481" class="codeline ">#  else
</span><span id="line2482" class="codeline ">#    define XXH_DEBUGLEVEL 0
</span><span id="line2483" class="codeline ">#  endif
</span><span id="line2484" class="codeline ">#endif
</span><span id="line2485" class="codeline ">
</span><span id="line2486" class="codeline ">#if (XXH_DEBUGLEVEL&gt;=1)
</span><span id="line2487" class="codeline ">#  include &lt;assert.h&gt;   /* note: can still be disabled with NDEBUG */
</span><span id="line2488" class="codeline ">#  define XXH_ASSERT(c)   assert(c)
</span><span id="line2489" class="codeline ">#else
</span><span id="line2490" class="codeline ">#  if defined(__INTEL_COMPILER)
</span><span id="line2491" class="codeline ">#    define XXH_ASSERT(c)   XXH_ASSUME((unsigned char) (c))
</span><span id="line2492" class="codeline ">#  else
</span><span id="line2493" class="codeline ">#    define XXH_ASSERT(c)   XXH_ASSUME(c)
</span><span id="line2494" class="codeline ">#  endif
</span><span id="line2495" class="codeline ">#endif
</span><span id="line2496" class="codeline ">
</span><span id="line2497" class="codeline ">/* note: use after variable declarations */
</span><span id="line2498" class="codeline ">#ifndef XXH_STATIC_ASSERT
</span><span id="line2499" class="codeline ">#  if defined(__STDC_VERSION__) &amp;&amp; (__STDC_VERSION__ &gt;= 201112L)    /* C11 */
</span><span id="line2500" class="codeline ">#    define XXH_STATIC_ASSERT_WITH_MESSAGE(c,m) do { _Static_assert((c),m); } while(0)
</span><span id="line2501" class="codeline ">#  elif defined(__cplusplus) &amp;&amp; (__cplusplus &gt;= 201103L)            /* C++11 */
</span><span id="line2502" class="codeline ">#    define XXH_STATIC_ASSERT_WITH_MESSAGE(c,m) do { static_assert((c),m); } while(0)
</span><span id="line2503" class="codeline ">#  else
</span><span id="line2504" class="codeline ">#    define XXH_STATIC_ASSERT_WITH_MESSAGE(c,m) do { struct xxh_sa { char x[(c) ? 1 : -1]; }; } while(0)
</span><span id="line2505" class="codeline ">#  endif
</span><span id="line2506" class="codeline ">#  define XXH_STATIC_ASSERT(c) XXH_STATIC_ASSERT_WITH_MESSAGE((c),#c)
</span><span id="line2507" class="codeline ">#endif
</span><span id="line2508" class="codeline ">
</span><span id="line2509" class="codeline ">/*!
</span><span id="line2510" class="codeline "> * @internal
</span><span id="line2511" class="codeline "> * @def XXH_COMPILER_GUARD(var)
</span><span id="line2512" class="codeline "> * @brief Used to prevent unwanted optimizations for @p var.
</span><span id="line2513" class="codeline "> *
</span><span id="line2514" class="codeline "> * It uses an empty GCC inline assembly statement with a register constraint
</span><span id="line2515" class="codeline "> * which forces @p var into a general purpose register (eg eax, ebx, ecx
</span><span id="line2516" class="codeline "> * on x86) and marks it as modified.
</span><span id="line2517" class="codeline "> *
</span><span id="line2518" class="codeline "> * This is used in a few places to avoid unwanted autovectorization (e.g.
</span><span id="line2519" class="codeline "> * XXH32_round()). All vectorization we want is explicit via intrinsics,
</span><span id="line2520" class="codeline "> * and _usually_ isn&#39;t wanted elsewhere.
</span><span id="line2521" class="codeline "> *
</span><span id="line2522" class="codeline "> * We also use it to prevent unwanted constant folding for AArch64 in
</span><span id="line2523" class="codeline "> * XXH3_initCustomSecret_scalar().
</span><span id="line2524" class="codeline "> */
</span><span id="line2525" class="codeline ">#if defined(__GNUC__) || defined(__clang__)
</span><span id="line2526" class="codeline ">#  define XXH_COMPILER_GUARD(var) __asm__(&#34;&#34; : &#34;+r&#34; (var))
</span><span id="line2527" class="codeline ">#else
</span><span id="line2528" class="codeline ">#  define XXH_COMPILER_GUARD(var) ((void)0)
</span><span id="line2529" class="codeline ">#endif
</span><span id="line2530" class="codeline ">
</span><span id="line2531" class="codeline ">/* Specifically for NEON vectors which use the &#34;w&#34; constraint, on
</span><span id="line2532" class="codeline "> * Clang. */
</span><span id="line2533" class="codeline ">#if defined(__clang__) &amp;&amp; defined(__ARM_ARCH) &amp;&amp; !defined(__wasm__)
</span><span id="line2534" class="codeline ">#  define XXH_COMPILER_GUARD_CLANG_NEON(var) __asm__(&#34;&#34; : &#34;+w&#34; (var))
</span><span id="line2535" class="codeline ">#else
</span><span id="line2536" class="codeline ">#  define XXH_COMPILER_GUARD_CLANG_NEON(var) ((void)0)
</span><span id="line2537" class="codeline ">#endif
</span><span id="line2538" class="codeline ">
</span><span id="line2539" class="codeline ">/* *************************************
</span><span id="line2540" class="codeline ">*  Basic Types
</span><span id="line2541" class="codeline ">***************************************/
</span><span id="line2542" class="codeline ">#if !defined (__VMS) \
</span><span id="line2543" class="codeline "> &amp;&amp; (defined (__cplusplus) \
</span><span id="line2544" class="codeline "> || (defined (__STDC_VERSION__) &amp;&amp; (__STDC_VERSION__ &gt;= 199901L) /* C99 */) )
</span><span id="line2545" class="codeline ">#   ifdef _AIX
</span><span id="line2546" class="codeline ">#     include &lt;inttypes.h&gt;
</span><span id="line2547" class="codeline ">#   else
</span><span id="line2548" class="codeline ">#     include &lt;stdint.h&gt;
</span><span id="line2549" class="codeline ">#   endif
</span><span id="line2550" class="codeline ">    typedef uint8_t xxh_u8;
</span><span id="line2551" class="codeline ">#else
</span><span id="line2552" class="codeline ">    typedef unsigned char xxh_u8;
</span><span id="line2553" class="codeline ">#endif
</span><span id="line2554" class="codeline ">typedef XXH32_hash_t xxh_u32;
</span><span id="line2555" class="codeline ">
</span><span id="line2556" class="codeline ">#ifdef XXH_OLD_NAMES
</span><span id="line2557" class="codeline ">#  warning &#34;XXH_OLD_NAMES is planned to be removed starting v0.9. If the program depends on it, consider moving away from it by employing newer type names directly&#34;
</span><span id="line2558" class="codeline ">#  define BYTE xxh_u8
</span><span id="line2559" class="codeline ">#  define U8   xxh_u8
</span><span id="line2560" class="codeline ">#  define U32  xxh_u32
</span><span id="line2561" class="codeline ">#endif
</span><span id="line2562" class="codeline ">
</span><span id="line2563" class="codeline ">/* ***   Memory access   *** */
</span><span id="line2564" class="codeline ">
</span><span id="line2565" class="codeline ">/*!
</span><span id="line2566" class="codeline "> * @internal
</span><span id="line2567" class="codeline "> * @fn xxh_u32 XXH_read32(const void* ptr)
</span><span id="line2568" class="codeline "> * @brief Reads an unaligned 32-bit integer from @p ptr in native endianness.
</span><span id="line2569" class="codeline "> *
</span><span id="line2570" class="codeline "> * Affected by @ref XXH_FORCE_MEMORY_ACCESS.
</span><span id="line2571" class="codeline "> *
</span><span id="line2572" class="codeline "> * @param ptr The pointer to read from.
</span><span id="line2573" class="codeline "> * @return The 32-bit native endian integer from the bytes at @p ptr.
</span><span id="line2574" class="codeline "> */
</span><span id="line2575" class="codeline ">
</span><span id="line2576" class="codeline ">/*!
</span><span id="line2577" class="codeline "> * @internal
</span><span id="line2578" class="codeline "> * @fn xxh_u32 XXH_readLE32(const void* ptr)
</span><span id="line2579" class="codeline "> * @brief Reads an unaligned 32-bit little endian integer from @p ptr.
</span><span id="line2580" class="codeline "> *
</span><span id="line2581" class="codeline "> * Affected by @ref XXH_FORCE_MEMORY_ACCESS.
</span><span id="line2582" class="codeline "> *
</span><span id="line2583" class="codeline "> * @param ptr The pointer to read from.
</span><span id="line2584" class="codeline "> * @return The 32-bit little endian integer from the bytes at @p ptr.
</span><span id="line2585" class="codeline "> */
</span><span id="line2586" class="codeline ">
</span><span id="line2587" class="codeline ">/*!
</span><span id="line2588" class="codeline "> * @internal
</span><span id="line2589" class="codeline "> * @fn xxh_u32 XXH_readBE32(const void* ptr)
</span><span id="line2590" class="codeline "> * @brief Reads an unaligned 32-bit big endian integer from @p ptr.
</span><span id="line2591" class="codeline "> *
</span><span id="line2592" class="codeline "> * Affected by @ref XXH_FORCE_MEMORY_ACCESS.
</span><span id="line2593" class="codeline "> *
</span><span id="line2594" class="codeline "> * @param ptr The pointer to read from.
</span><span id="line2595" class="codeline "> * @return The 32-bit big endian integer from the bytes at @p ptr.
</span><span id="line2596" class="codeline "> */
</span><span id="line2597" class="codeline ">
</span><span id="line2598" class="codeline ">/*!
</span><span id="line2599" class="codeline "> * @internal
</span><span id="line2600" class="codeline "> * @fn xxh_u32 XXH_readLE32_align(const void* ptr, XXH_alignment align)
</span><span id="line2601" class="codeline "> * @brief Like @ref XXH_readLE32(), but has an option for aligned reads.
</span><span id="line2602" class="codeline "> *
</span><span id="line2603" class="codeline "> * Affected by @ref XXH_FORCE_MEMORY_ACCESS.
</span><span id="line2604" class="codeline "> * Note that when @ref XXH_FORCE_ALIGN_CHECK == 0, the @p align parameter is
</span><span id="line2605" class="codeline "> * always @ref XXH_alignment::XXH_unaligned.
</span><span id="line2606" class="codeline "> *
</span><span id="line2607" class="codeline "> * @param ptr The pointer to read from.
</span><span id="line2608" class="codeline "> * @param align Whether @p ptr is aligned.
</span><span id="line2609" class="codeline "> * @pre
</span><span id="line2610" class="codeline "> *   If @p align == @ref XXH_alignment::XXH_aligned, @p ptr must be 4 byte
</span><span id="line2611" class="codeline "> *   aligned.
</span><span id="line2612" class="codeline "> * @return The 32-bit little endian integer from the bytes at @p ptr.
</span><span id="line2613" class="codeline "> */
</span><span id="line2614" class="codeline ">
</span><span id="line2615" class="codeline ">#if (defined(XXH_FORCE_MEMORY_ACCESS) &amp;&amp; (XXH_FORCE_MEMORY_ACCESS==3))
</span><span id="line2616" class="codeline ">/*
</span><span id="line2617" class="codeline "> * Manual byteshift. Best for old compilers which don&#39;t inline memcpy.
</span><span id="line2618" class="codeline "> * We actually directly use XXH_readLE32 and XXH_readBE32.
</span><span id="line2619" class="codeline "> */
</span><span id="line2620" class="codeline ">#elif (defined(XXH_FORCE_MEMORY_ACCESS) &amp;&amp; (XXH_FORCE_MEMORY_ACCESS==2))
</span><span id="line2621" class="codeline ">
</span><span id="line2622" class="codeline ">/*
</span><span id="line2623" class="codeline "> * Force direct memory access. Only works on CPU which support unaligned memory
</span><span id="line2624" class="codeline "> * access in hardware.
</span><span id="line2625" class="codeline "> */
</span><span id="line2626" class="codeline ">static xxh_u32 XXH_read32(const void* memPtr) { return *(const xxh_u32*) memPtr; }
</span><span id="line2627" class="codeline ">
</span><span id="line2628" class="codeline ">#elif (defined(XXH_FORCE_MEMORY_ACCESS) &amp;&amp; (XXH_FORCE_MEMORY_ACCESS==1))
</span><span id="line2629" class="codeline ">
</span><span id="line2630" class="codeline ">/*
</span><span id="line2631" class="codeline "> * __attribute__((aligned(1))) is supported by gcc and clang. Originally the
</span><span id="line2632" class="codeline "> * documentation claimed that it only increased the alignment, but actually it
</span><span id="line2633" class="codeline "> * can decrease it on gcc, clang, and icc:
</span><span id="line2634" class="codeline "> * https://gcc.gnu.org/bugzilla/show_bug.cgi?id=69502,
</span><span id="line2635" class="codeline "> * https://gcc.godbolt.org/z/xYez1j67Y.
</span><span id="line2636" class="codeline "> */
</span><span id="line2637" class="codeline ">#ifdef XXH_OLD_NAMES
</span><span id="line2638" class="codeline ">typedef union { xxh_u32 u32; } __attribute__((__packed__)) unalign;
</span><span id="line2639" class="codeline ">#endif
</span><span id="line2640" class="codeline ">static xxh_u32 XXH_read32(const void* ptr)
</span><span id="line2641" class="codeline ">{
</span><span id="line2642" class="codeline ">    typedef __attribute__((__aligned__(1))) xxh_u32 xxh_unalign32;
</span><span id="line2643" class="codeline ">    return *((const xxh_unalign32*)ptr);
</span><span id="line2644" class="codeline ">}
</span><span id="line2645" class="codeline ">
</span><span id="line2646" class="codeline ">#else
</span><span id="line2647" class="codeline ">
</span><span id="line2648" class="codeline ">/*
</span><span id="line2649" class="codeline "> * Portable and safe solution. Generally efficient.
</span><span id="line2650" class="codeline "> * see: https://fastcompression.blogspot.com/2015/08/accessing-unaligned-memory.html
</span><span id="line2651" class="codeline "> */
</span><span id="line2652" class="codeline ">static xxh_u32 XXH_read32(const void* memPtr)
</span><span id="line2653" class="codeline ">{
</span><span id="line2654" class="codeline ">    xxh_u32 val;
</span><span id="line2655" class="codeline ">    XXH_memcpy(&amp;val, memPtr, sizeof(val));
</span><span id="line2656" class="codeline ">    return val;
</span><span id="line2657" class="codeline ">}
</span><span id="line2658" class="codeline ">
</span><span id="line2659" class="codeline ">#endif   /* XXH_FORCE_DIRECT_MEMORY_ACCESS */
</span><span id="line2660" class="codeline ">
</span><span id="line2661" class="codeline ">
</span><span id="line2662" class="codeline ">/* ***   Endianness   *** */
</span><span id="line2663" class="codeline ">
</span><span id="line2664" class="codeline ">/*!
</span><span id="line2665" class="codeline "> * @ingroup tuning
</span><span id="line2666" class="codeline "> * @def XXH_CPU_LITTLE_ENDIAN
</span><span id="line2667" class="codeline "> * @brief Whether the target is little endian.
</span><span id="line2668" class="codeline "> *
</span><span id="line2669" class="codeline "> * Defined to 1 if the target is little endian, or 0 if it is big endian.
</span><span id="line2670" class="codeline "> * It can be defined externally, for example on the compiler command line.
</span><span id="line2671" class="codeline "> *
</span><span id="line2672" class="codeline "> * If it is not defined,
</span><span id="line2673" class="codeline "> * a runtime check (which is usually constant folded) is used instead.
</span><span id="line2674" class="codeline "> *
</span><span id="line2675" class="codeline "> * @note
</span><span id="line2676" class="codeline "> *   This is not necessarily defined to an integer constant.
</span><span id="line2677" class="codeline "> *
</span><span id="line2678" class="codeline "> * @see XXH_isLittleEndian() for the runtime check.
</span><span id="line2679" class="codeline "> */
</span><span id="line2680" class="codeline ">#ifndef XXH_CPU_LITTLE_ENDIAN
</span><span id="line2681" class="codeline ">/*
</span><span id="line2682" class="codeline "> * Try to detect endianness automatically, to avoid the nonstandard behavior
</span><span id="line2683" class="codeline "> * in `XXH_isLittleEndian()`
</span><span id="line2684" class="codeline "> */
</span><span id="line2685" class="codeline ">#  if defined(_WIN32) /* Windows is always little endian */ \
</span><span id="line2686" class="codeline ">     || defined(__LITTLE_ENDIAN__) \
</span><span id="line2687" class="codeline ">     || (defined(__BYTE_ORDER__) &amp;&amp; __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__)
</span><span id="line2688" class="codeline ">#    define XXH_CPU_LITTLE_ENDIAN 1
</span><span id="line2689" class="codeline ">#  elif defined(__BIG_ENDIAN__) \
</span><span id="line2690" class="codeline ">     || (defined(__BYTE_ORDER__) &amp;&amp; __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__)
</span><span id="line2691" class="codeline ">#    define XXH_CPU_LITTLE_ENDIAN 0
</span><span id="line2692" class="codeline ">#  else
</span><span id="line2693" class="codeline ">/*!
</span><span id="line2694" class="codeline "> * @internal
</span><span id="line2695" class="codeline "> * @brief Runtime check for @ref XXH_CPU_LITTLE_ENDIAN.
</span><span id="line2696" class="codeline "> *
</span><span id="line2697" class="codeline "> * Most compilers will constant fold this.
</span><span id="line2698" class="codeline "> */
</span><span id="line2699" class="codeline ">static int XXH_isLittleEndian(void)
</span><span id="line2700" class="codeline ">{
</span><span id="line2701" class="codeline ">    /*
</span><span id="line2702" class="codeline ">     * Portable and well-defined behavior.
</span><span id="line2703" class="codeline ">     * Don&#39;t use static: it is detrimental to performance.
</span><span id="line2704" class="codeline ">     */
</span><span id="line2705" class="codeline ">    const union { xxh_u32 u; xxh_u8 c[4]; } one = { 1 };
</span><span id="line2706" class="codeline ">    return one.c[0];
</span><span id="line2707" class="codeline ">}
</span><span id="line2708" class="codeline ">#   define XXH_CPU_LITTLE_ENDIAN   XXH_isLittleEndian()
</span><span id="line2709" class="codeline ">#  endif
</span><span id="line2710" class="codeline ">#endif
</span><span id="line2711" class="codeline ">
</span><span id="line2712" class="codeline ">
</span><span id="line2713" class="codeline ">
</span><span id="line2714" class="codeline ">
</span><span id="line2715" class="codeline ">/* ****************************************
</span><span id="line2716" class="codeline ">*  Compiler-specific Functions and Macros
</span><span id="line2717" class="codeline ">******************************************/
</span><span id="line2718" class="codeline ">#define XXH_GCC_VERSION (__GNUC__ * 100 + __GNUC_MINOR__)
</span><span id="line2719" class="codeline ">
</span><span id="line2720" class="codeline ">#ifdef __has_builtin
</span><span id="line2721" class="codeline ">#  define XXH_HAS_BUILTIN(x) __has_builtin(x)
</span><span id="line2722" class="codeline ">#else
</span><span id="line2723" class="codeline ">#  define XXH_HAS_BUILTIN(x) 0
</span><span id="line2724" class="codeline ">#endif
</span><span id="line2725" class="codeline ">
</span><span id="line2726" class="codeline ">
</span><span id="line2727" class="codeline ">
</span><span id="line2728" class="codeline ">/*
</span><span id="line2729" class="codeline "> * C23 and future versions have standard &#34;unreachable()&#34;.
</span><span id="line2730" class="codeline "> * Once it has been implemented reliably we can add it as an
</span><span id="line2731" class="codeline "> * additional case:
</span><span id="line2732" class="codeline "> *
</span><span id="line2733" class="codeline "> * ```
</span><span id="line2734" class="codeline "> * #if defined(__STDC_VERSION__) &amp;&amp; (__STDC_VERSION__ &gt;= XXH_C23_VN)
</span><span id="line2735" class="codeline "> * #  include &lt;stddef.h&gt;
</span><span id="line2736" class="codeline "> * #  ifdef unreachable
</span><span id="line2737" class="codeline "> * #    define XXH_UNREACHABLE() unreachable()
</span><span id="line2738" class="codeline "> * #  endif
</span><span id="line2739" class="codeline "> * #endif
</span><span id="line2740" class="codeline "> * ```
</span><span id="line2741" class="codeline "> *
</span><span id="line2742" class="codeline "> * Note C++23 also has std::unreachable() which can be detected
</span><span id="line2743" class="codeline "> * as follows:
</span><span id="line2744" class="codeline "> * ```
</span><span id="line2745" class="codeline "> * #if defined(__cpp_lib_unreachable) &amp;&amp; (__cpp_lib_unreachable &gt;= 202202L)
</span><span id="line2746" class="codeline "> * #  include &lt;utility&gt;
</span><span id="line2747" class="codeline "> * #  define XXH_UNREACHABLE() std::unreachable()
</span><span id="line2748" class="codeline "> * #endif
</span><span id="line2749" class="codeline "> * ```
</span><span id="line2750" class="codeline "> * NB: `__cpp_lib_unreachable` is defined in the `&lt;version&gt;` header.
</span><span id="line2751" class="codeline "> * We don&#39;t use that as including `&lt;utility&gt;` in `extern &#34;C&#34;` blocks
</span><span id="line2752" class="codeline "> * doesn&#39;t work on GCC12
</span><span id="line2753" class="codeline "> */
</span><span id="line2754" class="codeline ">
</span><span id="line2755" class="codeline ">#if XXH_HAS_BUILTIN(__builtin_unreachable)
</span><span id="line2756" class="codeline ">#  define XXH_UNREACHABLE() __builtin_unreachable()
</span><span id="line2757" class="codeline ">
</span><span id="line2758" class="codeline ">#elif defined(_MSC_VER)
</span><span id="line2759" class="codeline ">#  define XXH_UNREACHABLE() __assume(0)
</span><span id="line2760" class="codeline ">
</span><span id="line2761" class="codeline ">#else
</span><span id="line2762" class="codeline ">#  define XXH_UNREACHABLE()
</span><span id="line2763" class="codeline ">#endif
</span><span id="line2764" class="codeline ">
</span><span id="line2765" class="codeline ">#if XXH_HAS_BUILTIN(__builtin_assume)
</span><span id="line2766" class="codeline ">#  define XXH_ASSUME(c) __builtin_assume(c)
</span><span id="line2767" class="codeline ">#else
</span><span id="line2768" class="codeline ">#  define XXH_ASSUME(c) if (!(c)) { XXH_UNREACHABLE(); }
</span><span id="line2769" class="codeline ">#endif
</span><span id="line2770" class="codeline ">
</span><span id="line2771" class="codeline ">/*!
</span><span id="line2772" class="codeline "> * @internal
</span><span id="line2773" class="codeline "> * @def XXH_rotl32(x,r)
</span><span id="line2774" class="codeline "> * @brief 32-bit rotate left.
</span><span id="line2775" class="codeline "> *
</span><span id="line2776" class="codeline "> * @param x The 32-bit integer to be rotated.
</span><span id="line2777" class="codeline "> * @param r The number of bits to rotate.
</span><span id="line2778" class="codeline "> * @pre
</span><span id="line2779" class="codeline "> *   @p r &gt; 0 &amp;&amp; @p r &lt; 32
</span><span id="line2780" class="codeline "> * @note
</span><span id="line2781" class="codeline "> *   @p x and @p r may be evaluated multiple times.
</span><span id="line2782" class="codeline "> * @return The rotated result.
</span><span id="line2783" class="codeline "> */
</span><span id="line2784" class="codeline ">#if !defined(NO_CLANG_BUILTIN) &amp;&amp; XXH_HAS_BUILTIN(__builtin_rotateleft32) \
</span><span id="line2785" class="codeline ">                               &amp;&amp; XXH_HAS_BUILTIN(__builtin_rotateleft64)
</span><span id="line2786" class="codeline ">#  define XXH_rotl32 __builtin_rotateleft32
</span><span id="line2787" class="codeline ">#  define XXH_rotl64 __builtin_rotateleft64
</span><span id="line2788" class="codeline ">#elif XXH_HAS_BUILTIN(__builtin_stdc_rotate_left)
</span><span id="line2789" class="codeline ">#  define XXH_rotl32 __builtin_stdc_rotate_left
</span><span id="line2790" class="codeline ">#  define XXH_rotl64 __builtin_stdc_rotate_left
</span><span id="line2791" class="codeline ">/* Note: although _rotl exists for minGW (GCC under windows), performance seems poor */
</span><span id="line2792" class="codeline ">#elif defined(_MSC_VER)
</span><span id="line2793" class="codeline ">#  define XXH_rotl32(x,r) _rotl(x,r)
</span><span id="line2794" class="codeline ">#  define XXH_rotl64(x,r) _rotl64(x,r)
</span><span id="line2795" class="codeline ">#else
</span><span id="line2796" class="codeline ">#  define XXH_rotl32(x,r) (((x) &lt;&lt; (r)) | ((x) &gt;&gt; (32 - (r))))
</span><span id="line2797" class="codeline ">#  define XXH_rotl64(x,r) (((x) &lt;&lt; (r)) | ((x) &gt;&gt; (64 - (r))))
</span><span id="line2798" class="codeline ">#endif
</span><span id="line2799" class="codeline ">
</span><span id="line2800" class="codeline ">/*!
</span><span id="line2801" class="codeline "> * @internal
</span><span id="line2802" class="codeline "> * @fn xxh_u32 XXH_swap32(xxh_u32 x)
</span><span id="line2803" class="codeline "> * @brief A 32-bit byteswap.
</span><span id="line2804" class="codeline "> *
</span><span id="line2805" class="codeline "> * @param x The 32-bit integer to byteswap.
</span><span id="line2806" class="codeline "> * @return @p x, byteswapped.
</span><span id="line2807" class="codeline "> */
</span><span id="line2808" class="codeline ">#if defined(_MSC_VER)     /* Visual Studio */
</span><span id="line2809" class="codeline ">#  define XXH_swap32 _byteswap_ulong
</span><span id="line2810" class="codeline ">#elif XXH_GCC_VERSION &gt;= 403
</span><span id="line2811" class="codeline ">#  define XXH_swap32 __builtin_bswap32
</span><span id="line2812" class="codeline ">#else
</span><span id="line2813" class="codeline ">static xxh_u32 XXH_swap32 (xxh_u32 x)
</span><span id="line2814" class="codeline ">{
</span><span id="line2815" class="codeline ">    return  ((x &lt;&lt; 24) &amp; 0xff000000 ) |
</span><span id="line2816" class="codeline ">            ((x &lt;&lt;  8) &amp; 0x00ff0000 ) |
</span><span id="line2817" class="codeline ">            ((x &gt;&gt;  8) &amp; 0x0000ff00 ) |
</span><span id="line2818" class="codeline ">            ((x &gt;&gt; 24) &amp; 0x000000ff );
</span><span id="line2819" class="codeline ">}
</span><span id="line2820" class="codeline ">#endif
</span><span id="line2821" class="codeline ">
</span><span id="line2822" class="codeline ">
</span><span id="line2823" class="codeline ">/* ***************************
</span><span id="line2824" class="codeline ">*  Memory reads
</span><span id="line2825" class="codeline ">*****************************/
</span><span id="line2826" class="codeline ">
</span><span id="line2827" class="codeline ">/*!
</span><span id="line2828" class="codeline "> * @internal
</span><span id="line2829" class="codeline "> * @brief Enum to indicate whether a pointer is aligned.
</span><span id="line2830" class="codeline "> */
</span><span id="line2831" class="codeline ">typedef enum {
</span><span id="line2832" class="codeline ">    XXH_aligned,  /*!&lt; Aligned */
</span><span id="line2833" class="codeline ">    XXH_unaligned /*!&lt; Possibly unaligned */
</span><span id="line2834" class="codeline ">} XXH_alignment;
</span><span id="line2835" class="codeline ">
</span><span id="line2836" class="codeline ">/*
</span><span id="line2837" class="codeline "> * XXH_FORCE_MEMORY_ACCESS==3 is an endian-independent byteshift load.
</span><span id="line2838" class="codeline "> *
</span><span id="line2839" class="codeline "> * This is ideal for older compilers which don&#39;t inline memcpy.
</span><span id="line2840" class="codeline "> */
</span><span id="line2841" class="codeline ">#if (defined(XXH_FORCE_MEMORY_ACCESS) &amp;&amp; (XXH_FORCE_MEMORY_ACCESS==3))
</span><span id="line2842" class="codeline ">
</span><span id="line2843" class="codeline ">XXH_FORCE_INLINE xxh_u32 XXH_readLE32(const void* memPtr)
</span><span id="line2844" class="codeline ">{
</span><span id="line2845" class="codeline ">    const xxh_u8* bytePtr = (const xxh_u8 *)memPtr;
</span><span id="line2846" class="codeline ">    return bytePtr[0]
</span><span id="line2847" class="codeline ">         | ((xxh_u32)bytePtr[1] &lt;&lt; 8)
</span><span id="line2848" class="codeline ">         | ((xxh_u32)bytePtr[2] &lt;&lt; 16)
</span><span id="line2849" class="codeline ">         | ((xxh_u32)bytePtr[3] &lt;&lt; 24);
</span><span id="line2850" class="codeline ">}
</span><span id="line2851" class="codeline ">
</span><span id="line2852" class="codeline ">XXH_FORCE_INLINE xxh_u32 XXH_readBE32(const void* memPtr)
</span><span id="line2853" class="codeline ">{
</span><span id="line2854" class="codeline ">    const xxh_u8* bytePtr = (const xxh_u8 *)memPtr;
</span><span id="line2855" class="codeline ">    return bytePtr[3]
</span><span id="line2856" class="codeline ">         | ((xxh_u32)bytePtr[2] &lt;&lt; 8)
</span><span id="line2857" class="codeline ">         | ((xxh_u32)bytePtr[1] &lt;&lt; 16)
</span><span id="line2858" class="codeline ">         | ((xxh_u32)bytePtr[0] &lt;&lt; 24);
</span><span id="line2859" class="codeline ">}
</span><span id="line2860" class="codeline ">
</span><span id="line2861" class="codeline ">#else
</span><span id="line2862" class="codeline ">XXH_FORCE_INLINE xxh_u32 XXH_readLE32(const void* ptr)
</span><span id="line2863" class="codeline ">{
</span><span id="line2864" class="codeline ">    return XXH_CPU_LITTLE_ENDIAN ? XXH_read32(ptr) : XXH_swap32(XXH_read32(ptr));
</span><span id="line2865" class="codeline ">}
</span><span id="line2866" class="codeline ">
</span><span id="line2867" class="codeline ">static xxh_u32 XXH_readBE32(const void* ptr)
</span><span id="line2868" class="codeline ">{
</span><span id="line2869" class="codeline ">    return XXH_CPU_LITTLE_ENDIAN ? XXH_swap32(XXH_read32(ptr)) : XXH_read32(ptr);
</span><span id="line2870" class="codeline ">}
</span><span id="line2871" class="codeline ">#endif
</span><span id="line2872" class="codeline ">
</span><span id="line2873" class="codeline ">XXH_FORCE_INLINE xxh_u32
</span><span id="line2874" class="codeline ">XXH_readLE32_align(const void* ptr, XXH_alignment align)
</span><span id="line2875" class="codeline ">{
</span><span id="line2876" class="codeline ">    if (align==XXH_unaligned) {
</span><span id="line2877" class="codeline ">        return XXH_readLE32(ptr);
</span><span id="line2878" class="codeline ">    } else {
</span><span id="line2879" class="codeline ">        return XXH_CPU_LITTLE_ENDIAN ? *(const xxh_u32*)ptr : XXH_swap32(*(const xxh_u32*)ptr);
</span><span id="line2880" class="codeline ">    }
</span><span id="line2881" class="codeline ">}
</span><span id="line2882" class="codeline ">
</span><span id="line2883" class="codeline ">
</span><span id="line2884" class="codeline ">/* *************************************
</span><span id="line2885" class="codeline ">*  Misc
</span><span id="line2886" class="codeline ">***************************************/
</span><span id="line2887" class="codeline ">/*! @ingroup public */
</span><span id="line2888" class="codeline ">XXH_PUBLIC_API unsigned XXH_versionNumber (void) { return XXH_VERSION_NUMBER; }
</span><span id="line2889" class="codeline ">
</span><span id="line2890" class="codeline ">
</span><span id="line2891" class="codeline ">/* *******************************************************************
</span><span id="line2892" class="codeline ">*  32-bit hash functions
</span><span id="line2893" class="codeline ">*********************************************************************/
</span><span id="line2894" class="codeline ">/*!
</span><span id="line2895" class="codeline "> * @}
</span><span id="line2896" class="codeline "> * @defgroup XXH32_impl XXH32 implementation
</span><span id="line2897" class="codeline "> * @ingroup impl
</span><span id="line2898" class="codeline "> *
</span><span id="line2899" class="codeline "> * Details on the XXH32 implementation.
</span><span id="line2900" class="codeline "> * @{
</span><span id="line2901" class="codeline "> */
</span><span id="line2902" class="codeline "> /* #define instead of static const, to be used as initializers */
</span><span id="line2903" class="codeline ">#define XXH_PRIME32_1  0x9E3779B1U  /*!&lt; 0b10011110001101110111100110110001 */
</span><span id="line2904" class="codeline ">#define XXH_PRIME32_2  0x85EBCA77U  /*!&lt; 0b10000101111010111100101001110111 */
</span><span id="line2905" class="codeline ">#define XXH_PRIME32_3  0xC2B2AE3DU  /*!&lt; 0b11000010101100101010111000111101 */
</span><span id="line2906" class="codeline ">#define XXH_PRIME32_4  0x27D4EB2FU  /*!&lt; 0b00100111110101001110101100101111 */
</span><span id="line2907" class="codeline ">#define XXH_PRIME32_5  0x165667B1U  /*!&lt; 0b00010110010101100110011110110001 */
</span><span id="line2908" class="codeline ">
</span><span id="line2909" class="codeline ">#ifdef XXH_OLD_NAMES
</span><span id="line2910" class="codeline ">#  define PRIME32_1 XXH_PRIME32_1
</span><span id="line2911" class="codeline ">#  define PRIME32_2 XXH_PRIME32_2
</span><span id="line2912" class="codeline ">#  define PRIME32_3 XXH_PRIME32_3
</span><span id="line2913" class="codeline ">#  define PRIME32_4 XXH_PRIME32_4
</span><span id="line2914" class="codeline ">#  define PRIME32_5 XXH_PRIME32_5
</span><span id="line2915" class="codeline ">#endif
</span><span id="line2916" class="codeline ">
</span><span id="line2917" class="codeline ">/*!
</span><span id="line2918" class="codeline "> * @internal
</span><span id="line2919" class="codeline "> * @brief Normal stripe processing routine.
</span><span id="line2920" class="codeline "> *
</span><span id="line2921" class="codeline "> * This shuffles the bits so that any bit from @p input impacts several bits in
</span><span id="line2922" class="codeline "> * @p acc.
</span><span id="line2923" class="codeline "> *
</span><span id="line2924" class="codeline "> * @param acc The accumulator lane.
</span><span id="line2925" class="codeline "> * @param input The stripe of input to mix.
</span><span id="line2926" class="codeline "> * @return The mixed accumulator lane.
</span><span id="line2927" class="codeline "> */
</span><span id="line2928" class="codeline ">static xxh_u32 XXH32_round(xxh_u32 acc, xxh_u32 input)
</span><span id="line2929" class="codeline ">{
</span><span id="line2930" class="codeline ">    acc += input * XXH_PRIME32_2;
</span><span id="line2931" class="codeline ">    acc  = XXH_rotl32(acc, 13);
</span><span id="line2932" class="codeline ">    acc *= XXH_PRIME32_1;
</span><span id="line2933" class="codeline ">#if (defined(__SSE4_1__) || defined(__aarch64__) || defined(__wasm_simd128__)) &amp;&amp; !defined(XXH_ENABLE_AUTOVECTORIZE)
</span><span id="line2934" class="codeline ">    /*
</span><span id="line2935" class="codeline ">     * UGLY HACK:
</span><span id="line2936" class="codeline ">     * A compiler fence is used to prevent GCC and Clang from
</span><span id="line2937" class="codeline ">     * autovectorizing the XXH32 loop (pragmas and attributes don&#39;t work for some
</span><span id="line2938" class="codeline ">     * reason) without globally disabling SSE4.1.
</span><span id="line2939" class="codeline ">     *
</span><span id="line2940" class="codeline ">     * The reason we want to avoid vectorization is because despite working on
</span><span id="line2941" class="codeline ">     * 4 integers at a time, there are multiple factors slowing XXH32 down on
</span><span id="line2942" class="codeline ">     * SSE4:
</span><span id="line2943" class="codeline ">     * - There&#39;s a ridiculous amount of lag from pmulld (10 cycles of latency on
</span><span id="line2944" class="codeline ">     *   newer chips!) making it slightly slower to multiply four integers at
</span><span id="line2945" class="codeline ">     *   once compared to four integers independently. Even when pmulld was
</span><span id="line2946" class="codeline ">     *   fastest, Sandy/Ivy Bridge, it is still not worth it to go into SSE
</span><span id="line2947" class="codeline ">     *   just to multiply unless doing a long operation.
</span><span id="line2948" class="codeline ">     *
</span><span id="line2949" class="codeline ">     * - Four instructions are required to rotate,
</span><span id="line2950" class="codeline ">     *      movqda tmp,  v // not required with VEX encoding
</span><span id="line2951" class="codeline ">     *      pslld  tmp, 13 // tmp &lt;&lt;= 13
</span><span id="line2952" class="codeline ">     *      psrld  v,   19 // x &gt;&gt;= 19
</span><span id="line2953" class="codeline ">     *      por    v,  tmp // x |= tmp
</span><span id="line2954" class="codeline ">     *   compared to one for scalar:
</span><span id="line2955" class="codeline ">     *      roll   v, 13    // reliably fast across the board
</span><span id="line2956" class="codeline ">     *      shldl  v, v, 13 // Sandy Bridge and later prefer this for some reason
</span><span id="line2957" class="codeline ">     *
</span><span id="line2958" class="codeline ">     * - Instruction level parallelism is actually more beneficial here because
</span><span id="line2959" class="codeline ">     *   the SIMD actually serializes this operation: While v1 is rotating, v2
</span><span id="line2960" class="codeline ">     *   can load data, while v3 can multiply. SSE forces them to operate
</span><span id="line2961" class="codeline ">     *   together.
</span><span id="line2962" class="codeline ">     *
</span><span id="line2963" class="codeline ">     * This is also enabled on AArch64, as Clang is *very aggressive* in vectorizing
</span><span id="line2964" class="codeline ">     * the loop. NEON is only faster on the A53, and with the newer cores, it is less
</span><span id="line2965" class="codeline ">     * than half the speed.
</span><span id="line2966" class="codeline ">     *
</span><span id="line2967" class="codeline ">     * Additionally, this is used on WASM SIMD128 because it JITs to the same
</span><span id="line2968" class="codeline ">     * SIMD instructions and has the same issue.
</span><span id="line2969" class="codeline ">     */
</span><span id="line2970" class="codeline ">    XXH_COMPILER_GUARD(acc);
</span><span id="line2971" class="codeline ">#endif
</span><span id="line2972" class="codeline ">    return acc;
</span><span id="line2973" class="codeline ">}
</span><span id="line2974" class="codeline ">
</span><span id="line2975" class="codeline ">/*!
</span><span id="line2976" class="codeline "> * @internal
</span><span id="line2977" class="codeline "> * @brief Mixes all bits to finalize the hash.
</span><span id="line2978" class="codeline "> *
</span><span id="line2979" class="codeline "> * The final mix ensures that all input bits have a chance to impact any bit in
</span><span id="line2980" class="codeline "> * the output digest, resulting in an unbiased distribution.
</span><span id="line2981" class="codeline "> *
</span><span id="line2982" class="codeline "> * @param hash The hash to avalanche.
</span><span id="line2983" class="codeline "> * @return The avalanched hash.
</span><span id="line2984" class="codeline "> */
</span><span id="line2985" class="codeline ">static xxh_u32 XXH32_avalanche(xxh_u32 hash)
</span><span id="line2986" class="codeline ">{
</span><span id="line2987" class="codeline ">    hash ^= hash &gt;&gt; 15;
</span><span id="line2988" class="codeline ">    hash *= XXH_PRIME32_2;
</span><span id="line2989" class="codeline ">    hash ^= hash &gt;&gt; 13;
</span><span id="line2990" class="codeline ">    hash *= XXH_PRIME32_3;
</span><span id="line2991" class="codeline ">    hash ^= hash &gt;&gt; 16;
</span><span id="line2992" class="codeline ">    return hash;
</span><span id="line2993" class="codeline ">}
</span><span id="line2994" class="codeline ">
</span><span id="line2995" class="codeline ">#define XXH_get32bits(p) XXH_readLE32_align(p, align)
</span><span id="line2996" class="codeline ">
</span><span id="line2997" class="codeline ">/*!
</span><span id="line2998" class="codeline "> * @internal
</span><span id="line2999" class="codeline "> * @brief Sets up the initial accumulator state for XXH32().
</span><span id="line3000" class="codeline "> */
</span><span id="line3001" class="codeline ">XXH_FORCE_INLINE void
</span><span id="line3002" class="codeline ">XXH32_initAccs(xxh_u32 *acc, xxh_u32 seed)
</span><span id="line3003" class="codeline ">{
</span><span id="line3004" class="codeline ">    XXH_ASSERT(acc != NULL);
</span><span id="line3005" class="codeline ">    acc[0] = seed + XXH_PRIME32_1 + XXH_PRIME32_2;
</span><span id="line3006" class="codeline ">    acc[1] = seed + XXH_PRIME32_2;
</span><span id="line3007" class="codeline ">    acc[2] = seed + 0;
</span><span id="line3008" class="codeline ">    acc[3] = seed - XXH_PRIME32_1;
</span><span id="line3009" class="codeline ">}
</span><span id="line3010" class="codeline ">
</span><span id="line3011" class="codeline ">/*!
</span><span id="line3012" class="codeline "> * @internal
</span><span id="line3013" class="codeline "> * @brief Consumes a block of data for XXH32().
</span><span id="line3014" class="codeline "> *
</span><span id="line3015" class="codeline "> * @return the end input pointer.
</span><span id="line3016" class="codeline "> */
</span><span id="line3017" class="codeline ">XXH_FORCE_INLINE const xxh_u8 *
</span><span id="line3018" class="codeline ">XXH32_consumeLong(
</span><span id="line3019" class="codeline ">    xxh_u32 *XXH_RESTRICT acc,
</span><span id="line3020" class="codeline ">    xxh_u8 const *XXH_RESTRICT input,
</span><span id="line3021" class="codeline ">    size_t len,
</span><span id="line3022" class="codeline ">    XXH_alignment align
</span><span id="line3023" class="codeline ">)
</span><span id="line3024" class="codeline ">{
</span><span id="line3025" class="codeline ">    const xxh_u8* const bEnd = input + len;
</span><span id="line3026" class="codeline ">    const xxh_u8* const limit = bEnd - 15;
</span><span id="line3027" class="codeline ">    XXH_ASSERT(acc != NULL);
</span><span id="line3028" class="codeline ">    XXH_ASSERT(input != NULL);
</span><span id="line3029" class="codeline ">    XXH_ASSERT(len &gt;= 16);
</span><span id="line3030" class="codeline ">    do {
</span><span id="line3031" class="codeline ">        acc[0] = XXH32_round(acc[0], XXH_get32bits(input)); input += 4;
</span><span id="line3032" class="codeline ">        acc[1] = XXH32_round(acc[1], XXH_get32bits(input)); input += 4;
</span><span id="line3033" class="codeline ">        acc[2] = XXH32_round(acc[2], XXH_get32bits(input)); input += 4;
</span><span id="line3034" class="codeline ">        acc[3] = XXH32_round(acc[3], XXH_get32bits(input)); input += 4;
</span><span id="line3035" class="codeline ">    } while (input &lt; limit);
</span><span id="line3036" class="codeline ">
</span><span id="line3037" class="codeline ">    return input;
</span><span id="line3038" class="codeline ">}
</span><span id="line3039" class="codeline ">
</span><span id="line3040" class="codeline ">/*!
</span><span id="line3041" class="codeline "> * @internal
</span><span id="line3042" class="codeline "> * @brief Merges the accumulator lanes together for XXH32()
</span><span id="line3043" class="codeline "> */
</span><span id="line3044" class="codeline ">XXH_FORCE_INLINE XXH_PUREF xxh_u32
</span><span id="line3045" class="codeline ">XXH32_mergeAccs(const xxh_u32 *acc)
</span><span id="line3046" class="codeline ">{
</span><span id="line3047" class="codeline ">    XXH_ASSERT(acc != NULL);
</span><span id="line3048" class="codeline ">    return XXH_rotl32(acc[0], 1)  + XXH_rotl32(acc[1], 7)
</span><span id="line3049" class="codeline ">         + XXH_rotl32(acc[2], 12) + XXH_rotl32(acc[3], 18);
</span><span id="line3050" class="codeline ">}
</span><span id="line3051" class="codeline ">
</span><span id="line3052" class="codeline ">/*!
</span><span id="line3053" class="codeline "> * @internal
</span><span id="line3054" class="codeline "> * @brief Processes the last 0-15 bytes of @p ptr.
</span><span id="line3055" class="codeline "> *
</span><span id="line3056" class="codeline "> * There may be up to 15 bytes remaining to consume from the input.
</span><span id="line3057" class="codeline "> * This final stage will digest them to ensure that all input bytes are present
</span><span id="line3058" class="codeline "> * in the final mix.
</span><span id="line3059" class="codeline "> *
</span><span id="line3060" class="codeline "> * @param hash The hash to finalize.
</span><span id="line3061" class="codeline "> * @param ptr The pointer to the remaining input.
</span><span id="line3062" class="codeline "> * @param len The remaining length, modulo 16.
</span><span id="line3063" class="codeline "> * @param align Whether @p ptr is aligned.
</span><span id="line3064" class="codeline "> * @return The finalized hash.
</span><span id="line3065" class="codeline "> * @see XXH64_finalize().
</span><span id="line3066" class="codeline "> */
</span><span id="line3067" class="codeline ">static XXH_PUREF xxh_u32
</span><span id="line3068" class="codeline ">XXH32_finalize(xxh_u32 hash, const xxh_u8* ptr, size_t len, XXH_alignment align)
</span><span id="line3069" class="codeline ">{
</span><span id="line3070" class="codeline ">#define XXH_PROCESS1 do {                             \
</span><span id="line3071" class="codeline ">    hash += (*ptr++) * XXH_PRIME32_5;                 \
</span><span id="line3072" class="codeline ">    hash = XXH_rotl32(hash, 11) * XXH_PRIME32_1;      \
</span><span id="line3073" class="codeline ">} while (0)
</span><span id="line3074" class="codeline ">
</span><span id="line3075" class="codeline ">#define XXH_PROCESS4 do {                             \
</span><span id="line3076" class="codeline ">    hash += XXH_get32bits(ptr) * XXH_PRIME32_3;       \
</span><span id="line3077" class="codeline ">    ptr += 4;                                         \
</span><span id="line3078" class="codeline ">    hash  = XXH_rotl32(hash, 17) * XXH_PRIME32_4;     \
</span><span id="line3079" class="codeline ">} while (0)
</span><span id="line3080" class="codeline ">
</span><span id="line3081" class="codeline ">    if (ptr==NULL) XXH_ASSERT(len == 0);
</span><span id="line3082" class="codeline ">
</span><span id="line3083" class="codeline ">    /* Compact rerolled version; generally faster */
</span><span id="line3084" class="codeline ">    if (!XXH32_ENDJMP) {
</span><span id="line3085" class="codeline ">        len &amp;= 15;
</span><span id="line3086" class="codeline ">        while (len &gt;= 4) {
</span><span id="line3087" class="codeline ">            XXH_PROCESS4;
</span><span id="line3088" class="codeline ">            len -= 4;
</span><span id="line3089" class="codeline ">        }
</span><span id="line3090" class="codeline ">        while (len &gt; 0) {
</span><span id="line3091" class="codeline ">            XXH_PROCESS1;
</span><span id="line3092" class="codeline ">            --len;
</span><span id="line3093" class="codeline ">        }
</span><span id="line3094" class="codeline ">        return XXH32_avalanche(hash);
</span><span id="line3095" class="codeline ">    } else {
</span><span id="line3096" class="codeline ">         switch(len&amp;15) /* or switch(bEnd - p) */ {
</span><span id="line3097" class="codeline ">           case 12:      XXH_PROCESS4;
</span><span id="line3098" class="codeline ">                         XXH_FALLTHROUGH;  /* fallthrough */
</span><span id="line3099" class="codeline ">           case 8:       XXH_PROCESS4;
</span><span id="line3100" class="codeline ">                         XXH_FALLTHROUGH;  /* fallthrough */
</span><span id="line3101" class="codeline ">           case 4:       XXH_PROCESS4;
</span><span id="line3102" class="codeline ">                         return XXH32_avalanche(hash);
</span><span id="line3103" class="codeline ">
</span><span id="line3104" class="codeline ">           case 13:      XXH_PROCESS4;
</span><span id="line3105" class="codeline ">                         XXH_FALLTHROUGH;  /* fallthrough */
</span><span id="line3106" class="codeline ">           case 9:       XXH_PROCESS4;
</span><span id="line3107" class="codeline ">                         XXH_FALLTHROUGH;  /* fallthrough */
</span><span id="line3108" class="codeline ">           case 5:       XXH_PROCESS4;
</span><span id="line3109" class="codeline ">                         XXH_PROCESS1;
</span><span id="line3110" class="codeline ">                         return XXH32_avalanche(hash);
</span><span id="line3111" class="codeline ">
</span><span id="line3112" class="codeline ">           case 14:      XXH_PROCESS4;
</span><span id="line3113" class="codeline ">                         XXH_FALLTHROUGH;  /* fallthrough */
</span><span id="line3114" class="codeline ">           case 10:      XXH_PROCESS4;
</span><span id="line3115" class="codeline ">                         XXH_FALLTHROUGH;  /* fallthrough */
</span><span id="line3116" class="codeline ">           case 6:       XXH_PROCESS4;
</span><span id="line3117" class="codeline ">                         XXH_PROCESS1;
</span><span id="line3118" class="codeline ">                         XXH_PROCESS1;
</span><span id="line3119" class="codeline ">                         return XXH32_avalanche(hash);
</span><span id="line3120" class="codeline ">
</span><span id="line3121" class="codeline ">           case 15:      XXH_PROCESS4;
</span><span id="line3122" class="codeline ">                         XXH_FALLTHROUGH;  /* fallthrough */
</span><span id="line3123" class="codeline ">           case 11:      XXH_PROCESS4;
</span><span id="line3124" class="codeline ">                         XXH_FALLTHROUGH;  /* fallthrough */
</span><span id="line3125" class="codeline ">           case 7:       XXH_PROCESS4;
</span><span id="line3126" class="codeline ">                         XXH_FALLTHROUGH;  /* fallthrough */
</span><span id="line3127" class="codeline ">           case 3:       XXH_PROCESS1;
</span><span id="line3128" class="codeline ">                         XXH_FALLTHROUGH;  /* fallthrough */
</span><span id="line3129" class="codeline ">           case 2:       XXH_PROCESS1;
</span><span id="line3130" class="codeline ">                         XXH_FALLTHROUGH;  /* fallthrough */
</span><span id="line3131" class="codeline ">           case 1:       XXH_PROCESS1;
</span><span id="line3132" class="codeline ">                         XXH_FALLTHROUGH;  /* fallthrough */
</span><span id="line3133" class="codeline ">           case 0:       return XXH32_avalanche(hash);
</span><span id="line3134" class="codeline ">        }
</span><span id="line3135" class="codeline ">        XXH_ASSERT(0);
</span><span id="line3136" class="codeline ">        return hash;   /* reaching this point is deemed impossible */
</span><span id="line3137" class="codeline ">    }
</span><span id="line3138" class="codeline ">}
</span><span id="line3139" class="codeline ">
</span><span id="line3140" class="codeline ">#ifdef XXH_OLD_NAMES
</span><span id="line3141" class="codeline ">#  define PROCESS1 XXH_PROCESS1
</span><span id="line3142" class="codeline ">#  define PROCESS4 XXH_PROCESS4
</span><span id="line3143" class="codeline ">#else
</span><span id="line3144" class="codeline ">#  undef XXH_PROCESS1
</span><span id="line3145" class="codeline ">#  undef XXH_PROCESS4
</span><span id="line3146" class="codeline ">#endif
</span><span id="line3147" class="codeline ">
</span><span id="line3148" class="codeline ">/*!
</span><span id="line3149" class="codeline "> * @internal
</span><span id="line3150" class="codeline "> * @brief The implementation for @ref XXH32().
</span><span id="line3151" class="codeline "> *
</span><span id="line3152" class="codeline "> * @param input , len , seed Directly passed from @ref XXH32().
</span><span id="line3153" class="codeline "> * @param align Whether @p input is aligned.
</span><span id="line3154" class="codeline "> * @return The calculated hash.
</span><span id="line3155" class="codeline "> */
</span><span id="line3156" class="codeline ">XXH_FORCE_INLINE XXH_PUREF xxh_u32
</span><span id="line3157" class="codeline ">XXH32_endian_align(const xxh_u8* input, size_t len, xxh_u32 seed, XXH_alignment align)
</span><span id="line3158" class="codeline ">{
</span><span id="line3159" class="codeline ">    xxh_u32 h32;
</span><span id="line3160" class="codeline ">
</span><span id="line3161" class="codeline ">    if (input==NULL) XXH_ASSERT(len == 0);
</span><span id="line3162" class="codeline ">
</span><span id="line3163" class="codeline ">    if (len&gt;=16) {
</span><span id="line3164" class="codeline ">        xxh_u32 acc[4];
</span><span id="line3165" class="codeline ">        XXH32_initAccs(acc, seed);
</span><span id="line3166" class="codeline ">
</span><span id="line3167" class="codeline ">        input = XXH32_consumeLong(acc, input, len, align);
</span><span id="line3168" class="codeline ">
</span><span id="line3169" class="codeline ">        h32 = XXH32_mergeAccs(acc);
</span><span id="line3170" class="codeline ">    } else {
</span><span id="line3171" class="codeline ">        h32  = seed + XXH_PRIME32_5;
</span><span id="line3172" class="codeline ">    }
</span><span id="line3173" class="codeline ">
</span><span id="line3174" class="codeline ">    h32 += (xxh_u32)len;
</span><span id="line3175" class="codeline ">
</span><span id="line3176" class="codeline ">    return XXH32_finalize(h32, input, len&amp;15, align);
</span><span id="line3177" class="codeline ">}
</span><span id="line3178" class="codeline ">
</span><span id="line3179" class="codeline ">/*! @ingroup XXH32_family */
</span><span id="line3180" class="codeline ">XXH_PUBLIC_API XXH32_hash_t XXH32 (const void* input, size_t len, XXH32_hash_t seed)
</span><span id="line3181" class="codeline ">{
</span><span id="line3182" class="codeline ">#if !defined(XXH_NO_STREAM) &amp;&amp; XXH_SIZE_OPT &gt;= 2
</span><span id="line3183" class="codeline ">    /* Simple version, good for code maintenance, but unfortunately slow for small inputs */
</span><span id="line3184" class="codeline ">    XXH32_state_t state;
</span><span id="line3185" class="codeline ">    XXH32_reset(&amp;state, seed);
</span><span id="line3186" class="codeline ">    XXH32_update(&amp;state, (const xxh_u8*)input, len);
</span><span id="line3187" class="codeline ">    return XXH32_digest(&amp;state);
</span><span id="line3188" class="codeline ">#else
</span><span id="line3189" class="codeline ">    if (XXH_FORCE_ALIGN_CHECK) {
</span><span id="line3190" class="codeline ">        if ((((size_t)input) &amp; 3) == 0) {   /* Input is 4-bytes aligned, leverage the speed benefit */
</span><span id="line3191" class="codeline ">            return XXH32_endian_align((const xxh_u8*)input, len, seed, XXH_aligned);
</span><span id="line3192" class="codeline ">    }   }
</span><span id="line3193" class="codeline ">
</span><span id="line3194" class="codeline ">    return XXH32_endian_align((const xxh_u8*)input, len, seed, XXH_unaligned);
</span><span id="line3195" class="codeline ">#endif
</span><span id="line3196" class="codeline ">}
</span><span id="line3197" class="codeline ">
</span><span id="line3198" class="codeline ">
</span><span id="line3199" class="codeline ">
</span><span id="line3200" class="codeline ">/*******   Hash streaming   *******/
</span><span id="line3201" class="codeline ">#ifndef XXH_NO_STREAM
</span><span id="line3202" class="codeline ">/*! @ingroup XXH32_family */
</span><span id="line3203" class="codeline ">XXH_PUBLIC_API XXH32_state_t* XXH32_createState(void)
</span><span id="line3204" class="codeline ">{
</span><span id="line3205" class="codeline ">    return (XXH32_state_t*)XXH_malloc(sizeof(XXH32_state_t));
</span><span id="line3206" class="codeline ">}
</span><span id="line3207" class="codeline ">/*! @ingroup XXH32_family */
</span><span id="line3208" class="codeline ">XXH_PUBLIC_API XXH_errorcode XXH32_freeState(XXH32_state_t* statePtr)
</span><span id="line3209" class="codeline ">{
</span><span id="line3210" class="codeline ">    XXH_free(statePtr);
</span><span id="line3211" class="codeline ">    return XXH_OK;
</span><span id="line3212" class="codeline ">}
</span><span id="line3213" class="codeline ">
</span><span id="line3214" class="codeline ">/*! @ingroup XXH32_family */
</span><span id="line3215" class="codeline ">XXH_PUBLIC_API void XXH32_copyState(XXH32_state_t* dstState, const XXH32_state_t* srcState)
</span><span id="line3216" class="codeline ">{
</span><span id="line3217" class="codeline ">    XXH_memcpy(dstState, srcState, sizeof(*dstState));
</span><span id="line3218" class="codeline ">}
</span><span id="line3219" class="codeline ">
</span><span id="line3220" class="codeline ">/*! @ingroup XXH32_family */
</span><span id="line3221" class="codeline ">XXH_PUBLIC_API XXH_errorcode XXH32_reset(XXH32_state_t* statePtr, XXH32_hash_t seed)
</span><span id="line3222" class="codeline ">{
</span><span id="line3223" class="codeline ">    XXH_ASSERT(statePtr != NULL);
</span><span id="line3224" class="codeline ">    memset(statePtr, 0, sizeof(*statePtr));
</span><span id="line3225" class="codeline ">    XXH32_initAccs(statePtr-&gt;acc, seed);
</span><span id="line3226" class="codeline ">    return XXH_OK;
</span><span id="line3227" class="codeline ">}
</span><span id="line3228" class="codeline ">
</span><span id="line3229" class="codeline ">
</span><span id="line3230" class="codeline ">/*! @ingroup XXH32_family */
</span><span id="line3231" class="codeline ">XXH_PUBLIC_API XXH_errorcode
</span><span id="line3232" class="codeline ">XXH32_update(XXH32_state_t* state, const void* input, size_t len)
</span><span id="line3233" class="codeline ">{
</span><span id="line3234" class="codeline ">    if (input==NULL) {
</span><span id="line3235" class="codeline ">        XXH_ASSERT(len == 0);
</span><span id="line3236" class="codeline ">        return XXH_OK;
</span><span id="line3237" class="codeline ">    }
</span><span id="line3238" class="codeline ">
</span><span id="line3239" class="codeline ">    state-&gt;total_len_32 += (XXH32_hash_t)len;
</span><span id="line3240" class="codeline ">    state-&gt;large_len |= (XXH32_hash_t)((len&gt;=16) | (state-&gt;total_len_32&gt;=16));
</span><span id="line3241" class="codeline ">
</span><span id="line3242" class="codeline ">    XXH_ASSERT(state-&gt;bufferedSize &lt; sizeof(state-&gt;buffer));
</span><span id="line3243" class="codeline ">    if (len &lt; sizeof(state-&gt;buffer) - state-&gt;bufferedSize)  {   /* fill in tmp buffer */
</span><span id="line3244" class="codeline ">        XXH_memcpy(state-&gt;buffer + state-&gt;bufferedSize, input, len);
</span><span id="line3245" class="codeline ">        state-&gt;bufferedSize += (XXH32_hash_t)len;
</span><span id="line3246" class="codeline ">        return XXH_OK;
</span><span id="line3247" class="codeline ">    }
</span><span id="line3248" class="codeline ">
</span><span id="line3249" class="codeline ">    {   const xxh_u8* xinput = (const xxh_u8*)input;
</span><span id="line3250" class="codeline ">        const xxh_u8* const bEnd = xinput + len;
</span><span id="line3251" class="codeline ">
</span><span id="line3252" class="codeline ">        if (state-&gt;bufferedSize) {   /* non-empty buffer: complete first */
</span><span id="line3253" class="codeline ">            XXH_memcpy(state-&gt;buffer + state-&gt;bufferedSize, xinput, sizeof(state-&gt;buffer) - state-&gt;bufferedSize);
</span><span id="line3254" class="codeline ">            xinput += sizeof(state-&gt;buffer) - state-&gt;bufferedSize;
</span><span id="line3255" class="codeline ">            /* then process one round */
</span><span id="line3256" class="codeline ">            (void)XXH32_consumeLong(state-&gt;acc, state-&gt;buffer, sizeof(state-&gt;buffer), XXH_aligned);
</span><span id="line3257" class="codeline ">            state-&gt;bufferedSize = 0;
</span><span id="line3258" class="codeline ">        }
</span><span id="line3259" class="codeline ">
</span><span id="line3260" class="codeline ">        XXH_ASSERT(xinput &lt;= bEnd);
</span><span id="line3261" class="codeline ">        if ((size_t)(bEnd - xinput) &gt;= sizeof(state-&gt;buffer)) {
</span><span id="line3262" class="codeline ">            /* Process the remaining data */
</span><span id="line3263" class="codeline ">            xinput = XXH32_consumeLong(state-&gt;acc, xinput, (size_t)(bEnd - xinput), XXH_unaligned);
</span><span id="line3264" class="codeline ">        }
</span><span id="line3265" class="codeline ">
</span><span id="line3266" class="codeline ">        if (xinput &lt; bEnd) {
</span><span id="line3267" class="codeline ">            /* Copy the leftover to the tmp buffer */
</span><span id="line3268" class="codeline ">            XXH_memcpy(state-&gt;buffer, xinput, (size_t)(bEnd-xinput));
</span><span id="line3269" class="codeline ">            state-&gt;bufferedSize = (unsigned)(bEnd-xinput);
</span><span id="line3270" class="codeline ">        }
</span><span id="line3271" class="codeline ">    }
</span><span id="line3272" class="codeline ">
</span><span id="line3273" class="codeline ">    return XXH_OK;
</span><span id="line3274" class="codeline ">}
</span><span id="line3275" class="codeline ">
</span><span id="line3276" class="codeline ">
</span><span id="line3277" class="codeline ">/*! @ingroup XXH32_family */
</span><span id="line3278" class="codeline ">XXH_PUBLIC_API XXH32_hash_t XXH32_digest(const XXH32_state_t* state)
</span><span id="line3279" class="codeline ">{
</span><span id="line3280" class="codeline ">    xxh_u32 h32;
</span><span id="line3281" class="codeline ">
</span><span id="line3282" class="codeline ">    if (state-&gt;large_len) {
</span><span id="line3283" class="codeline ">        h32 = XXH32_mergeAccs(state-&gt;acc);
</span><span id="line3284" class="codeline ">    } else {
</span><span id="line3285" class="codeline ">        h32 = state-&gt;acc[2] /* == seed */ + XXH_PRIME32_5;
</span><span id="line3286" class="codeline ">    }
</span><span id="line3287" class="codeline ">
</span><span id="line3288" class="codeline ">    h32 += state-&gt;total_len_32;
</span><span id="line3289" class="codeline ">
</span><span id="line3290" class="codeline ">    return XXH32_finalize(h32, state-&gt;buffer, state-&gt;bufferedSize, XXH_aligned);
</span><span id="line3291" class="codeline ">}
</span><span id="line3292" class="codeline ">#endif /* !XXH_NO_STREAM */
</span><span id="line3293" class="codeline ">
</span><span id="line3294" class="codeline ">/*******   Canonical representation   *******/
</span><span id="line3295" class="codeline ">
</span><span id="line3296" class="codeline ">/*! @ingroup XXH32_family */
</span><span id="line3297" class="codeline ">XXH_PUBLIC_API void XXH32_canonicalFromHash(XXH32_canonical_t* dst, XXH32_hash_t hash)
</span><span id="line3298" class="codeline ">{
</span><span id="line3299" class="codeline ">    XXH_STATIC_ASSERT(sizeof(XXH32_canonical_t) == sizeof(XXH32_hash_t));
</span><span id="line3300" class="codeline ">    if (XXH_CPU_LITTLE_ENDIAN) hash = XXH_swap32(hash);
</span><span id="line3301" class="codeline ">    XXH_memcpy(dst, &amp;hash, sizeof(*dst));
</span><span id="line3302" class="codeline ">}
</span><span id="line3303" class="codeline ">/*! @ingroup XXH32_family */
</span><span id="line3304" class="codeline ">XXH_PUBLIC_API XXH32_hash_t XXH32_hashFromCanonical(const XXH32_canonical_t* src)
</span><span id="line3305" class="codeline ">{
</span><span id="line3306" class="codeline ">    return XXH_readBE32(src);
</span><span id="line3307" class="codeline ">}
</span><span id="line3308" class="codeline ">
</span><span id="line3309" class="codeline ">
</span><span id="line3310" class="codeline ">#ifndef XXH_NO_LONG_LONG
</span><span id="line3311" class="codeline ">
</span><span id="line3312" class="codeline ">/* *******************************************************************
</span><span id="line3313" class="codeline ">*  64-bit hash functions
</span><span id="line3314" class="codeline ">*********************************************************************/
</span><span id="line3315" class="codeline ">/*!
</span><span id="line3316" class="codeline "> * @}
</span><span id="line3317" class="codeline "> * @ingroup impl
</span><span id="line3318" class="codeline "> * @{
</span><span id="line3319" class="codeline "> */
</span><span id="line3320" class="codeline ">/*******   Memory access   *******/
</span><span id="line3321" class="codeline ">
</span><span id="line3322" class="codeline ">typedef XXH64_hash_t xxh_u64;
</span><span id="line3323" class="codeline ">
</span><span id="line3324" class="codeline ">#ifdef XXH_OLD_NAMES
</span><span id="line3325" class="codeline ">#  define U64 xxh_u64
</span><span id="line3326" class="codeline ">#endif
</span><span id="line3327" class="codeline ">
</span><span id="line3328" class="codeline ">#if (defined(XXH_FORCE_MEMORY_ACCESS) &amp;&amp; (XXH_FORCE_MEMORY_ACCESS==3))
</span><span id="line3329" class="codeline ">/*
</span><span id="line3330" class="codeline "> * Manual byteshift. Best for old compilers which don&#39;t inline memcpy.
</span><span id="line3331" class="codeline "> * We actually directly use XXH_readLE64 and XXH_readBE64.
</span><span id="line3332" class="codeline "> */
</span><span id="line3333" class="codeline ">#elif (defined(XXH_FORCE_MEMORY_ACCESS) &amp;&amp; (XXH_FORCE_MEMORY_ACCESS==2))
</span><span id="line3334" class="codeline ">
</span><span id="line3335" class="codeline ">/* Force direct memory access. Only works on CPU which support unaligned memory access in hardware */
</span><span id="line3336" class="codeline ">static xxh_u64 XXH_read64(const void* memPtr)
</span><span id="line3337" class="codeline ">{
</span><span id="line3338" class="codeline ">    return *(const xxh_u64*) memPtr;
</span><span id="line3339" class="codeline ">}
</span><span id="line3340" class="codeline ">
</span><span id="line3341" class="codeline ">#elif (defined(XXH_FORCE_MEMORY_ACCESS) &amp;&amp; (XXH_FORCE_MEMORY_ACCESS==1))
</span><span id="line3342" class="codeline ">
</span><span id="line3343" class="codeline ">/*
</span><span id="line3344" class="codeline "> * __attribute__((aligned(1))) is supported by gcc and clang. Originally the
</span><span id="line3345" class="codeline "> * documentation claimed that it only increased the alignment, but actually it
</span><span id="line3346" class="codeline "> * can decrease it on gcc, clang, and icc:
</span><span id="line3347" class="codeline "> * https://gcc.gnu.org/bugzilla/show_bug.cgi?id=69502,
</span><span id="line3348" class="codeline "> * https://gcc.godbolt.org/z/xYez1j67Y.
</span><span id="line3349" class="codeline "> */
</span><span id="line3350" class="codeline ">#ifdef XXH_OLD_NAMES
</span><span id="line3351" class="codeline ">typedef union { xxh_u32 u32; xxh_u64 u64; } __attribute__((__packed__)) unalign64;
</span><span id="line3352" class="codeline ">#endif
</span><span id="line3353" class="codeline ">static xxh_u64 XXH_read64(const void* ptr)
</span><span id="line3354" class="codeline ">{
</span><span id="line3355" class="codeline ">    typedef __attribute__((__aligned__(1))) xxh_u64 xxh_unalign64;
</span><span id="line3356" class="codeline ">    return *((const xxh_unalign64*)ptr);
</span><span id="line3357" class="codeline ">}
</span><span id="line3358" class="codeline ">
</span><span id="line3359" class="codeline ">#else
</span><span id="line3360" class="codeline ">
</span><span id="line3361" class="codeline ">/*
</span><span id="line3362" class="codeline "> * Portable and safe solution. Generally efficient.
</span><span id="line3363" class="codeline "> * see: https://fastcompression.blogspot.com/2015/08/accessing-unaligned-memory.html
</span><span id="line3364" class="codeline "> */
</span><span id="line3365" class="codeline ">static xxh_u64 XXH_read64(const void* memPtr)
</span><span id="line3366" class="codeline ">{
</span><span id="line3367" class="codeline ">    xxh_u64 val;
</span><span id="line3368" class="codeline ">    XXH_memcpy(&amp;val, memPtr, sizeof(val));
</span><span id="line3369" class="codeline ">    return val;
</span><span id="line3370" class="codeline ">}
</span><span id="line3371" class="codeline ">
</span><span id="line3372" class="codeline ">#endif   /* XXH_FORCE_DIRECT_MEMORY_ACCESS */
</span><span id="line3373" class="codeline ">
</span><span id="line3374" class="codeline ">#if defined(_MSC_VER)     /* Visual Studio */
</span><span id="line3375" class="codeline ">#  define XXH_swap64 _byteswap_uint64
</span><span id="line3376" class="codeline ">#elif XXH_GCC_VERSION &gt;= 403
</span><span id="line3377" class="codeline ">#  define XXH_swap64 __builtin_bswap64
</span><span id="line3378" class="codeline ">#else
</span><span id="line3379" class="codeline ">static xxh_u64 XXH_swap64(xxh_u64 x)
</span><span id="line3380" class="codeline ">{
</span><span id="line3381" class="codeline ">    return  ((x &lt;&lt; 56) &amp; 0xff00000000000000ULL) |
</span><span id="line3382" class="codeline ">            ((x &lt;&lt; 40) &amp; 0x00ff000000000000ULL) |
</span><span id="line3383" class="codeline ">            ((x &lt;&lt; 24) &amp; 0x0000ff0000000000ULL) |
</span><span id="line3384" class="codeline ">            ((x &lt;&lt; 8)  &amp; 0x000000ff00000000ULL) |
</span><span id="line3385" class="codeline ">            ((x &gt;&gt; 8)  &amp; 0x00000000ff000000ULL) |
</span><span id="line3386" class="codeline ">            ((x &gt;&gt; 24) &amp; 0x0000000000ff0000ULL) |
</span><span id="line3387" class="codeline ">            ((x &gt;&gt; 40) &amp; 0x000000000000ff00ULL) |
</span><span id="line3388" class="codeline ">            ((x &gt;&gt; 56) &amp; 0x00000000000000ffULL);
</span><span id="line3389" class="codeline ">}
</span><span id="line3390" class="codeline ">#endif
</span><span id="line3391" class="codeline ">
</span><span id="line3392" class="codeline ">
</span><span id="line3393" class="codeline ">/* XXH_FORCE_MEMORY_ACCESS==3 is an endian-independent byteshift load. */
</span><span id="line3394" class="codeline ">#if (defined(XXH_FORCE_MEMORY_ACCESS) &amp;&amp; (XXH_FORCE_MEMORY_ACCESS==3))
</span><span id="line3395" class="codeline ">
</span><span id="line3396" class="codeline ">XXH_FORCE_INLINE xxh_u64 XXH_readLE64(const void* memPtr)
</span><span id="line3397" class="codeline ">{
</span><span id="line3398" class="codeline ">    const xxh_u8* bytePtr = (const xxh_u8 *)memPtr;
</span><span id="line3399" class="codeline ">    return bytePtr[0]
</span><span id="line3400" class="codeline ">         | ((xxh_u64)bytePtr[1] &lt;&lt; 8)
</span><span id="line3401" class="codeline ">         | ((xxh_u64)bytePtr[2] &lt;&lt; 16)
</span><span id="line3402" class="codeline ">         | ((xxh_u64)bytePtr[3] &lt;&lt; 24)
</span><span id="line3403" class="codeline ">         | ((xxh_u64)bytePtr[4] &lt;&lt; 32)
</span><span id="line3404" class="codeline ">         | ((xxh_u64)bytePtr[5] &lt;&lt; 40)
</span><span id="line3405" class="codeline ">         | ((xxh_u64)bytePtr[6] &lt;&lt; 48)
</span><span id="line3406" class="codeline ">         | ((xxh_u64)bytePtr[7] &lt;&lt; 56);
</span><span id="line3407" class="codeline ">}
</span><span id="line3408" class="codeline ">
</span><span id="line3409" class="codeline ">XXH_FORCE_INLINE xxh_u64 XXH_readBE64(const void* memPtr)
</span><span id="line3410" class="codeline ">{
</span><span id="line3411" class="codeline ">    const xxh_u8* bytePtr = (const xxh_u8 *)memPtr;
</span><span id="line3412" class="codeline ">    return bytePtr[7]
</span><span id="line3413" class="codeline ">         | ((xxh_u64)bytePtr[6] &lt;&lt; 8)
</span><span id="line3414" class="codeline ">         | ((xxh_u64)bytePtr[5] &lt;&lt; 16)
</span><span id="line3415" class="codeline ">         | ((xxh_u64)bytePtr[4] &lt;&lt; 24)
</span><span id="line3416" class="codeline ">         | ((xxh_u64)bytePtr[3] &lt;&lt; 32)
</span><span id="line3417" class="codeline ">         | ((xxh_u64)bytePtr[2] &lt;&lt; 40)
</span><span id="line3418" class="codeline ">         | ((xxh_u64)bytePtr[1] &lt;&lt; 48)
</span><span id="line3419" class="codeline ">         | ((xxh_u64)bytePtr[0] &lt;&lt; 56);
</span><span id="line3420" class="codeline ">}
</span><span id="line3421" class="codeline ">
</span><span id="line3422" class="codeline ">#else
</span><span id="line3423" class="codeline ">XXH_FORCE_INLINE xxh_u64 XXH_readLE64(const void* ptr)
</span><span id="line3424" class="codeline ">{
</span><span id="line3425" class="codeline ">    return XXH_CPU_LITTLE_ENDIAN ? XXH_read64(ptr) : XXH_swap64(XXH_read64(ptr));
</span><span id="line3426" class="codeline ">}
</span><span id="line3427" class="codeline ">
</span><span id="line3428" class="codeline ">static xxh_u64 XXH_readBE64(const void* ptr)
</span><span id="line3429" class="codeline ">{
</span><span id="line3430" class="codeline ">    return XXH_CPU_LITTLE_ENDIAN ? XXH_swap64(XXH_read64(ptr)) : XXH_read64(ptr);
</span><span id="line3431" class="codeline ">}
</span><span id="line3432" class="codeline ">#endif
</span><span id="line3433" class="codeline ">
</span><span id="line3434" class="codeline ">XXH_FORCE_INLINE xxh_u64
</span><span id="line3435" class="codeline ">XXH_readLE64_align(const void* ptr, XXH_alignment align)
</span><span id="line3436" class="codeline ">{
</span><span id="line3437" class="codeline ">    if (align==XXH_unaligned)
</span><span id="line3438" class="codeline ">        return XXH_readLE64(ptr);
</span><span id="line3439" class="codeline ">    else
</span><span id="line3440" class="codeline ">        return XXH_CPU_LITTLE_ENDIAN ? *(const xxh_u64*)ptr : XXH_swap64(*(const xxh_u64*)ptr);
</span><span id="line3441" class="codeline ">}
</span><span id="line3442" class="codeline ">
</span><span id="line3443" class="codeline ">
</span><span id="line3444" class="codeline ">/*******   xxh64   *******/
</span><span id="line3445" class="codeline ">/*!
</span><span id="line3446" class="codeline "> * @}
</span><span id="line3447" class="codeline "> * @defgroup XXH64_impl XXH64 implementation
</span><span id="line3448" class="codeline "> * @ingroup impl
</span><span id="line3449" class="codeline "> *
</span><span id="line3450" class="codeline "> * Details on the XXH64 implementation.
</span><span id="line3451" class="codeline "> * @{
</span><span id="line3452" class="codeline "> */
</span><span id="line3453" class="codeline ">/* #define rather that static const, to be used as initializers */
</span><span id="line3454" class="codeline ">#define XXH_PRIME64_1  0x9E3779B185EBCA87ULL  /*!&lt; 0b1001111000110111011110011011000110000101111010111100101010000111 */
</span><span id="line3455" class="codeline ">#define XXH_PRIME64_2  0xC2B2AE3D27D4EB4FULL  /*!&lt; 0b1100001010110010101011100011110100100111110101001110101101001111 */
</span><span id="line3456" class="codeline ">#define XXH_PRIME64_3  0x165667B19E3779F9ULL  /*!&lt; 0b0001011001010110011001111011000110011110001101110111100111111001 */
</span><span id="line3457" class="codeline ">#define XXH_PRIME64_4  0x85EBCA77C2B2AE63ULL  /*!&lt; 0b1000010111101011110010100111011111000010101100101010111001100011 */
</span><span id="line3458" class="codeline ">#define XXH_PRIME64_5  0x27D4EB2F165667C5ULL  /*!&lt; 0b0010011111010100111010110010111100010110010101100110011111000101 */
</span><span id="line3459" class="codeline ">
</span><span id="line3460" class="codeline ">#ifdef XXH_OLD_NAMES
</span><span id="line3461" class="codeline ">#  define PRIME64_1 XXH_PRIME64_1
</span><span id="line3462" class="codeline ">#  define PRIME64_2 XXH_PRIME64_2
</span><span id="line3463" class="codeline ">#  define PRIME64_3 XXH_PRIME64_3
</span><span id="line3464" class="codeline ">#  define PRIME64_4 XXH_PRIME64_4
</span><span id="line3465" class="codeline ">#  define PRIME64_5 XXH_PRIME64_5
</span><span id="line3466" class="codeline ">#endif
</span><span id="line3467" class="codeline ">
</span><span id="line3468" class="codeline ">/*! @copydoc XXH32_round */
</span><span id="line3469" class="codeline ">static xxh_u64 XXH64_round(xxh_u64 acc, xxh_u64 input)
</span><span id="line3470" class="codeline ">{
</span><span id="line3471" class="codeline ">    acc += input * XXH_PRIME64_2;
</span><span id="line3472" class="codeline ">    acc  = XXH_rotl64(acc, 31);
</span><span id="line3473" class="codeline ">    acc *= XXH_PRIME64_1;
</span><span id="line3474" class="codeline ">#if (defined(__AVX512F__)) &amp;&amp; !defined(XXH_ENABLE_AUTOVECTORIZE)
</span><span id="line3475" class="codeline ">    /*
</span><span id="line3476" class="codeline ">     * DISABLE AUTOVECTORIZATION:
</span><span id="line3477" class="codeline ">     * A compiler fence is used to prevent GCC and Clang from
</span><span id="line3478" class="codeline ">     * autovectorizing the XXH64 loop (pragmas and attributes don&#39;t work for some
</span><span id="line3479" class="codeline ">     * reason) without globally disabling AVX512.
</span><span id="line3480" class="codeline ">     *
</span><span id="line3481" class="codeline ">     * Autovectorization of XXH64 tends to be detrimental,
</span><span id="line3482" class="codeline ">     * though the exact outcome may change depending on exact cpu and compiler version.
</span><span id="line3483" class="codeline ">     * For information, it has been reported as detrimental for Skylake-X,
</span><span id="line3484" class="codeline ">     * but possibly beneficial for Zen4.
</span><span id="line3485" class="codeline ">     *
</span><span id="line3486" class="codeline ">     * The default is to disable auto-vectorization,
</span><span id="line3487" class="codeline ">     * but you can select to enable it instead using `XXH_ENABLE_AUTOVECTORIZE` build variable.
</span><span id="line3488" class="codeline ">     */
</span><span id="line3489" class="codeline ">    XXH_COMPILER_GUARD(acc);
</span><span id="line3490" class="codeline ">#endif
</span><span id="line3491" class="codeline ">    return acc;
</span><span id="line3492" class="codeline ">}
</span><span id="line3493" class="codeline ">
</span><span id="line3494" class="codeline ">static xxh_u64 XXH64_mergeRound(xxh_u64 acc, xxh_u64 val)
</span><span id="line3495" class="codeline ">{
</span><span id="line3496" class="codeline ">    val  = XXH64_round(0, val);
</span><span id="line3497" class="codeline ">    acc ^= val;
</span><span id="line3498" class="codeline ">    acc  = acc * XXH_PRIME64_1 + XXH_PRIME64_4;
</span><span id="line3499" class="codeline ">    return acc;
</span><span id="line3500" class="codeline ">}
</span><span id="line3501" class="codeline ">
</span><span id="line3502" class="codeline ">/*! @copydoc XXH32_avalanche */
</span><span id="line3503" class="codeline ">static xxh_u64 XXH64_avalanche(xxh_u64 hash)
</span><span id="line3504" class="codeline ">{
</span><span id="line3505" class="codeline ">    hash ^= hash &gt;&gt; 33;
</span><span id="line3506" class="codeline ">    hash *= XXH_PRIME64_2;
</span><span id="line3507" class="codeline ">    hash ^= hash &gt;&gt; 29;
</span><span id="line3508" class="codeline ">    hash *= XXH_PRIME64_3;
</span><span id="line3509" class="codeline ">    hash ^= hash &gt;&gt; 32;
</span><span id="line3510" class="codeline ">    return hash;
</span><span id="line3511" class="codeline ">}
</span><span id="line3512" class="codeline ">
</span><span id="line3513" class="codeline ">
</span><span id="line3514" class="codeline ">#define XXH_get64bits(p) XXH_readLE64_align(p, align)
</span><span id="line3515" class="codeline ">
</span><span id="line3516" class="codeline ">/*!
</span><span id="line3517" class="codeline "> * @internal
</span><span id="line3518" class="codeline "> * @brief Sets up the initial accumulator state for XXH64().
</span><span id="line3519" class="codeline "> */
</span><span id="line3520" class="codeline ">XXH_FORCE_INLINE void
</span><span id="line3521" class="codeline ">XXH64_initAccs(xxh_u64 *acc, xxh_u64 seed)
</span><span id="line3522" class="codeline ">{
</span><span id="line3523" class="codeline ">    XXH_ASSERT(acc != NULL);
</span><span id="line3524" class="codeline ">    acc[0] = seed + XXH_PRIME64_1 + XXH_PRIME64_2;
</span><span id="line3525" class="codeline ">    acc[1] = seed + XXH_PRIME64_2;
</span><span id="line3526" class="codeline ">    acc[2] = seed + 0;
</span><span id="line3527" class="codeline ">    acc[3] = seed - XXH_PRIME64_1;
</span><span id="line3528" class="codeline ">}
</span><span id="line3529" class="codeline ">
</span><span id="line3530" class="codeline ">/*!
</span><span id="line3531" class="codeline "> * @internal
</span><span id="line3532" class="codeline "> * @brief Consumes a block of data for XXH64().
</span><span id="line3533" class="codeline "> *
</span><span id="line3534" class="codeline "> * @return the end input pointer.
</span><span id="line3535" class="codeline "> */
</span><span id="line3536" class="codeline ">XXH_FORCE_INLINE const xxh_u8 *
</span><span id="line3537" class="codeline ">XXH64_consumeLong(
</span><span id="line3538" class="codeline ">    xxh_u64 *XXH_RESTRICT acc,
</span><span id="line3539" class="codeline ">    xxh_u8 const *XXH_RESTRICT input,
</span><span id="line3540" class="codeline ">    size_t len,
</span><span id="line3541" class="codeline ">    XXH_alignment align
</span><span id="line3542" class="codeline ">)
</span><span id="line3543" class="codeline ">{
</span><span id="line3544" class="codeline ">    const xxh_u8* const bEnd = input + len;
</span><span id="line3545" class="codeline ">    const xxh_u8* const limit = bEnd - 31;
</span><span id="line3546" class="codeline ">    XXH_ASSERT(acc != NULL);
</span><span id="line3547" class="codeline ">    XXH_ASSERT(input != NULL);
</span><span id="line3548" class="codeline ">    XXH_ASSERT(len &gt;= 32);
</span><span id="line3549" class="codeline ">    do {
</span><span id="line3550" class="codeline ">        /* reroll on 32-bit */
</span><span id="line3551" class="codeline ">        if (sizeof(void *) &lt; sizeof(xxh_u64)) {
</span><span id="line3552" class="codeline ">            size_t i;
</span><span id="line3553" class="codeline ">            for (i = 0; i &lt; 4; i++) {
</span><span id="line3554" class="codeline ">                acc[i] = XXH64_round(acc[i], XXH_get64bits(input));
</span><span id="line3555" class="codeline ">                input += 8;
</span><span id="line3556" class="codeline ">            }
</span><span id="line3557" class="codeline ">        } else {
</span><span id="line3558" class="codeline ">            acc[0] = XXH64_round(acc[0], XXH_get64bits(input)); input += 8;
</span><span id="line3559" class="codeline ">            acc[1] = XXH64_round(acc[1], XXH_get64bits(input)); input += 8;
</span><span id="line3560" class="codeline ">            acc[2] = XXH64_round(acc[2], XXH_get64bits(input)); input += 8;
</span><span id="line3561" class="codeline ">            acc[3] = XXH64_round(acc[3], XXH_get64bits(input)); input += 8;
</span><span id="line3562" class="codeline ">        }
</span><span id="line3563" class="codeline ">    } while (input &lt; limit);
</span><span id="line3564" class="codeline ">
</span><span id="line3565" class="codeline ">    return input;
</span><span id="line3566" class="codeline ">}
</span><span id="line3567" class="codeline ">
</span><span id="line3568" class="codeline ">/*!
</span><span id="line3569" class="codeline "> * @internal
</span><span id="line3570" class="codeline "> * @brief Merges the accumulator lanes together for XXH64()
</span><span id="line3571" class="codeline "> */
</span><span id="line3572" class="codeline ">XXH_FORCE_INLINE XXH_PUREF xxh_u64
</span><span id="line3573" class="codeline ">XXH64_mergeAccs(const xxh_u64 *acc)
</span><span id="line3574" class="codeline ">{
</span><span id="line3575" class="codeline ">    XXH_ASSERT(acc != NULL);
</span><span id="line3576" class="codeline ">    {
</span><span id="line3577" class="codeline ">        xxh_u64 h64 = XXH_rotl64(acc[0], 1) + XXH_rotl64(acc[1], 7)
</span><span id="line3578" class="codeline ">                    + XXH_rotl64(acc[2], 12) + XXH_rotl64(acc[3], 18);
</span><span id="line3579" class="codeline ">        /* reroll on 32-bit */
</span><span id="line3580" class="codeline ">        if (sizeof(void *) &lt; sizeof(xxh_u64)) {
</span><span id="line3581" class="codeline ">            size_t i;
</span><span id="line3582" class="codeline ">            for (i = 0; i &lt; 4; i++) {
</span><span id="line3583" class="codeline ">                h64 = XXH64_mergeRound(h64, acc[i]);
</span><span id="line3584" class="codeline ">            }
</span><span id="line3585" class="codeline ">        } else {
</span><span id="line3586" class="codeline ">            h64 = XXH64_mergeRound(h64, acc[0]);
</span><span id="line3587" class="codeline ">            h64 = XXH64_mergeRound(h64, acc[1]);
</span><span id="line3588" class="codeline ">            h64 = XXH64_mergeRound(h64, acc[2]);
</span><span id="line3589" class="codeline ">            h64 = XXH64_mergeRound(h64, acc[3]);
</span><span id="line3590" class="codeline ">        }
</span><span id="line3591" class="codeline ">        return h64;
</span><span id="line3592" class="codeline ">    }
</span><span id="line3593" class="codeline ">}
</span><span id="line3594" class="codeline ">
</span><span id="line3595" class="codeline ">/*!
</span><span id="line3596" class="codeline "> * @internal
</span><span id="line3597" class="codeline "> * @brief Processes the last 0-31 bytes of @p ptr.
</span><span id="line3598" class="codeline "> *
</span><span id="line3599" class="codeline "> * There may be up to 31 bytes remaining to consume from the input.
</span><span id="line3600" class="codeline "> * This final stage will digest them to ensure that all input bytes are present
</span><span id="line3601" class="codeline "> * in the final mix.
</span><span id="line3602" class="codeline "> *
</span><span id="line3603" class="codeline "> * @param hash The hash to finalize.
</span><span id="line3604" class="codeline "> * @param ptr The pointer to the remaining input.
</span><span id="line3605" class="codeline "> * @param len The remaining length, modulo 32.
</span><span id="line3606" class="codeline "> * @param align Whether @p ptr is aligned.
</span><span id="line3607" class="codeline "> * @return The finalized hash
</span><span id="line3608" class="codeline "> * @see XXH32_finalize().
</span><span id="line3609" class="codeline "> */
</span><span id="line3610" class="codeline ">XXH_STATIC XXH_PUREF xxh_u64
</span><span id="line3611" class="codeline ">XXH64_finalize(xxh_u64 hash, const xxh_u8* ptr, size_t len, XXH_alignment align)
</span><span id="line3612" class="codeline ">{
</span><span id="line3613" class="codeline ">    if (ptr==NULL) XXH_ASSERT(len == 0);
</span><span id="line3614" class="codeline ">    len &amp;= 31;
</span><span id="line3615" class="codeline ">    while (len &gt;= 8) {
</span><span id="line3616" class="codeline ">        xxh_u64 const k1 = XXH64_round(0, XXH_get64bits(ptr));
</span><span id="line3617" class="codeline ">        ptr += 8;
</span><span id="line3618" class="codeline ">        hash ^= k1;
</span><span id="line3619" class="codeline ">        hash  = XXH_rotl64(hash,27) * XXH_PRIME64_1 + XXH_PRIME64_4;
</span><span id="line3620" class="codeline ">        len -= 8;
</span><span id="line3621" class="codeline ">    }
</span><span id="line3622" class="codeline ">    if (len &gt;= 4) {
</span><span id="line3623" class="codeline ">        hash ^= (xxh_u64)(XXH_get32bits(ptr)) * XXH_PRIME64_1;
</span><span id="line3624" class="codeline ">        ptr += 4;
</span><span id="line3625" class="codeline ">        hash = XXH_rotl64(hash, 23) * XXH_PRIME64_2 + XXH_PRIME64_3;
</span><span id="line3626" class="codeline ">        len -= 4;
</span><span id="line3627" class="codeline ">    }
</span><span id="line3628" class="codeline ">    while (len &gt; 0) {
</span><span id="line3629" class="codeline ">        hash ^= (*ptr++) * XXH_PRIME64_5;
</span><span id="line3630" class="codeline ">        hash = XXH_rotl64(hash, 11) * XXH_PRIME64_1;
</span><span id="line3631" class="codeline ">        --len;
</span><span id="line3632" class="codeline ">    }
</span><span id="line3633" class="codeline ">    return  XXH64_avalanche(hash);
</span><span id="line3634" class="codeline ">}
</span><span id="line3635" class="codeline ">
</span><span id="line3636" class="codeline ">#ifdef XXH_OLD_NAMES
</span><span id="line3637" class="codeline ">#  define PROCESS1_64 XXH_PROCESS1_64
</span><span id="line3638" class="codeline ">#  define PROCESS4_64 XXH_PROCESS4_64
</span><span id="line3639" class="codeline ">#  define PROCESS8_64 XXH_PROCESS8_64
</span><span id="line3640" class="codeline ">#else
</span><span id="line3641" class="codeline ">#  undef XXH_PROCESS1_64
</span><span id="line3642" class="codeline ">#  undef XXH_PROCESS4_64
</span><span id="line3643" class="codeline ">#  undef XXH_PROCESS8_64
</span><span id="line3644" class="codeline ">#endif
</span><span id="line3645" class="codeline ">
</span><span id="line3646" class="codeline ">/*!
</span><span id="line3647" class="codeline "> * @internal
</span><span id="line3648" class="codeline "> * @brief The implementation for @ref XXH64().
</span><span id="line3649" class="codeline "> *
</span><span id="line3650" class="codeline "> * @param input , len , seed Directly passed from @ref XXH64().
</span><span id="line3651" class="codeline "> * @param align Whether @p input is aligned.
</span><span id="line3652" class="codeline "> * @return The calculated hash.
</span><span id="line3653" class="codeline "> */
</span><span id="line3654" class="codeline ">XXH_FORCE_INLINE XXH_PUREF xxh_u64
</span><span id="line3655" class="codeline ">XXH64_endian_align(const xxh_u8* input, size_t len, xxh_u64 seed, XXH_alignment align)
</span><span id="line3656" class="codeline ">{
</span><span id="line3657" class="codeline ">    xxh_u64 h64;
</span><span id="line3658" class="codeline ">    if (input==NULL) XXH_ASSERT(len == 0);
</span><span id="line3659" class="codeline ">
</span><span id="line3660" class="codeline ">    if (len&gt;=32) {  /* Process a large block of data */
</span><span id="line3661" class="codeline ">        xxh_u64 acc[4];
</span><span id="line3662" class="codeline ">        XXH64_initAccs(acc, seed);
</span><span id="line3663" class="codeline ">
</span><span id="line3664" class="codeline ">        input = XXH64_consumeLong(acc, input, len, align);
</span><span id="line3665" class="codeline ">
</span><span id="line3666" class="codeline ">        h64 = XXH64_mergeAccs(acc);
</span><span id="line3667" class="codeline ">    } else {
</span><span id="line3668" class="codeline ">        h64  = seed + XXH_PRIME64_5;
</span><span id="line3669" class="codeline ">    }
</span><span id="line3670" class="codeline ">
</span><span id="line3671" class="codeline ">    h64 += (xxh_u64) len;
</span><span id="line3672" class="codeline ">
</span><span id="line3673" class="codeline ">    return XXH64_finalize(h64, input, len, align);
</span><span id="line3674" class="codeline ">}
</span><span id="line3675" class="codeline ">
</span><span id="line3676" class="codeline ">
</span><span id="line3677" class="codeline ">/*! @ingroup XXH64_family */
</span><span id="line3678" class="codeline ">XXH_PUBLIC_API XXH64_hash_t XXH64 (XXH_NOESCAPE const void* input, size_t len, XXH64_hash_t seed)
</span><span id="line3679" class="codeline ">{
</span><span id="line3680" class="codeline ">#if !defined(XXH_NO_STREAM) &amp;&amp; XXH_SIZE_OPT &gt;= 2
</span><span id="line3681" class="codeline ">    /* Simple version, good for code maintenance, but unfortunately slow for small inputs */
</span><span id="line3682" class="codeline ">    XXH64_state_t state;
</span><span id="line3683" class="codeline ">    XXH64_reset(&amp;state, seed);
</span><span id="line3684" class="codeline ">    XXH64_update(&amp;state, (const xxh_u8*)input, len);
</span><span id="line3685" class="codeline ">    return XXH64_digest(&amp;state);
</span><span id="line3686" class="codeline ">#else
</span><span id="line3687" class="codeline ">    if (XXH_FORCE_ALIGN_CHECK) {
</span><span id="line3688" class="codeline ">        if ((((size_t)input) &amp; 7)==0) {  /* Input is aligned, let&#39;s leverage the speed advantage */
</span><span id="line3689" class="codeline ">            return XXH64_endian_align((const xxh_u8*)input, len, seed, XXH_aligned);
</span><span id="line3690" class="codeline ">    }   }
</span><span id="line3691" class="codeline ">
</span><span id="line3692" class="codeline ">    return XXH64_endian_align((const xxh_u8*)input, len, seed, XXH_unaligned);
</span><span id="line3693" class="codeline ">
</span><span id="line3694" class="codeline ">#endif
</span><span id="line3695" class="codeline ">}
</span><span id="line3696" class="codeline ">
</span><span id="line3697" class="codeline ">/*******   Hash Streaming   *******/
</span><span id="line3698" class="codeline ">#ifndef XXH_NO_STREAM
</span><span id="line3699" class="codeline ">/*! @ingroup XXH64_family*/
</span><span id="line3700" class="codeline ">XXH_PUBLIC_API XXH64_state_t* XXH64_createState(void)
</span><span id="line3701" class="codeline ">{
</span><span id="line3702" class="codeline ">    return (XXH64_state_t*)XXH_malloc(sizeof(XXH64_state_t));
</span><span id="line3703" class="codeline ">}
</span><span id="line3704" class="codeline ">/*! @ingroup XXH64_family */
</span><span id="line3705" class="codeline ">XXH_PUBLIC_API XXH_errorcode XXH64_freeState(XXH64_state_t* statePtr)
</span><span id="line3706" class="codeline ">{
</span><span id="line3707" class="codeline ">    XXH_free(statePtr);
</span><span id="line3708" class="codeline ">    return XXH_OK;
</span><span id="line3709" class="codeline ">}
</span><span id="line3710" class="codeline ">
</span><span id="line3711" class="codeline ">/*! @ingroup XXH64_family */
</span><span id="line3712" class="codeline ">XXH_PUBLIC_API void XXH64_copyState(XXH_NOESCAPE XXH64_state_t* dstState, const XXH64_state_t* srcState)
</span><span id="line3713" class="codeline ">{
</span><span id="line3714" class="codeline ">    XXH_memcpy(dstState, srcState, sizeof(*dstState));
</span><span id="line3715" class="codeline ">}
</span><span id="line3716" class="codeline ">
</span><span id="line3717" class="codeline ">/*! @ingroup XXH64_family */
</span><span id="line3718" class="codeline ">XXH_PUBLIC_API XXH_errorcode XXH64_reset(XXH_NOESCAPE XXH64_state_t* statePtr, XXH64_hash_t seed)
</span><span id="line3719" class="codeline ">{
</span><span id="line3720" class="codeline ">    XXH_ASSERT(statePtr != NULL);
</span><span id="line3721" class="codeline ">    memset(statePtr, 0, sizeof(*statePtr));
</span><span id="line3722" class="codeline ">    XXH64_initAccs(statePtr-&gt;acc, seed);
</span><span id="line3723" class="codeline ">    return XXH_OK;
</span><span id="line3724" class="codeline ">}
</span><span id="line3725" class="codeline ">
</span><span id="line3726" class="codeline ">/*! @ingroup XXH64_family */
</span><span id="line3727" class="codeline ">XXH_PUBLIC_API XXH_errorcode
</span><span id="line3728" class="codeline ">XXH64_update (XXH_NOESCAPE XXH64_state_t* state, XXH_NOESCAPE const void* input, size_t len)
</span><span id="line3729" class="codeline ">{
</span><span id="line3730" class="codeline ">    if (input==NULL) {
</span><span id="line3731" class="codeline ">        XXH_ASSERT(len == 0);
</span><span id="line3732" class="codeline ">        return XXH_OK;
</span><span id="line3733" class="codeline ">    }
</span><span id="line3734" class="codeline ">
</span><span id="line3735" class="codeline ">    state-&gt;total_len += len;
</span><span id="line3736" class="codeline ">
</span><span id="line3737" class="codeline ">    XXH_ASSERT(state-&gt;bufferedSize &lt;= sizeof(state-&gt;buffer));
</span><span id="line3738" class="codeline ">    if (len &lt; sizeof(state-&gt;buffer) - state-&gt;bufferedSize)  {   /* fill in tmp buffer */
</span><span id="line3739" class="codeline ">        XXH_memcpy(state-&gt;buffer + state-&gt;bufferedSize, input, len);
</span><span id="line3740" class="codeline ">        state-&gt;bufferedSize += (XXH32_hash_t)len;
</span><span id="line3741" class="codeline ">        return XXH_OK;
</span><span id="line3742" class="codeline ">    }
</span><span id="line3743" class="codeline ">
</span><span id="line3744" class="codeline ">    {   const xxh_u8* xinput = (const xxh_u8*)input;
</span><span id="line3745" class="codeline ">        const xxh_u8* const bEnd = xinput + len;
</span><span id="line3746" class="codeline ">
</span><span id="line3747" class="codeline ">        if (state-&gt;bufferedSize) {   /* non-empty buffer =&gt; complete first */
</span><span id="line3748" class="codeline ">            XXH_memcpy(state-&gt;buffer + state-&gt;bufferedSize, xinput, sizeof(state-&gt;buffer) - state-&gt;bufferedSize);
</span><span id="line3749" class="codeline ">            xinput += sizeof(state-&gt;buffer) - state-&gt;bufferedSize;
</span><span id="line3750" class="codeline ">            /* and process one round */
</span><span id="line3751" class="codeline ">            (void)XXH64_consumeLong(state-&gt;acc, state-&gt;buffer, sizeof(state-&gt;buffer), XXH_aligned);
</span><span id="line3752" class="codeline ">            state-&gt;bufferedSize = 0;
</span><span id="line3753" class="codeline ">        }
</span><span id="line3754" class="codeline ">
</span><span id="line3755" class="codeline ">        XXH_ASSERT(xinput &lt;= bEnd);
</span><span id="line3756" class="codeline ">        if ((size_t)(bEnd - xinput) &gt;= sizeof(state-&gt;buffer)) {
</span><span id="line3757" class="codeline ">            /* Process the remaining data */
</span><span id="line3758" class="codeline ">            xinput = XXH64_consumeLong(state-&gt;acc, xinput, (size_t)(bEnd - xinput), XXH_unaligned);
</span><span id="line3759" class="codeline ">        }
</span><span id="line3760" class="codeline ">
</span><span id="line3761" class="codeline ">        if (xinput &lt; bEnd) {
</span><span id="line3762" class="codeline ">            /* Copy the leftover to the tmp buffer */
</span><span id="line3763" class="codeline ">            XXH_memcpy(state-&gt;buffer, xinput, (size_t)(bEnd-xinput));
</span><span id="line3764" class="codeline ">            state-&gt;bufferedSize = (unsigned)(bEnd-xinput);
</span><span id="line3765" class="codeline ">        }
</span><span id="line3766" class="codeline ">    }
</span><span id="line3767" class="codeline ">
</span><span id="line3768" class="codeline ">    return XXH_OK;
</span><span id="line3769" class="codeline ">}
</span><span id="line3770" class="codeline ">
</span><span id="line3771" class="codeline ">
</span><span id="line3772" class="codeline ">/*! @ingroup XXH64_family */
</span><span id="line3773" class="codeline ">XXH_PUBLIC_API XXH64_hash_t XXH64_digest(XXH_NOESCAPE const XXH64_state_t* state)
</span><span id="line3774" class="codeline ">{
</span><span id="line3775" class="codeline ">    xxh_u64 h64;
</span><span id="line3776" class="codeline ">
</span><span id="line3777" class="codeline ">    if (state-&gt;total_len &gt;= 32) {
</span><span id="line3778" class="codeline ">        h64 = XXH64_mergeAccs(state-&gt;acc);
</span><span id="line3779" class="codeline ">    } else {
</span><span id="line3780" class="codeline ">        h64  = state-&gt;acc[2] /*seed*/ + XXH_PRIME64_5;
</span><span id="line3781" class="codeline ">    }
</span><span id="line3782" class="codeline ">
</span><span id="line3783" class="codeline ">    h64 += (xxh_u64) state-&gt;total_len;
</span><span id="line3784" class="codeline ">
</span><span id="line3785" class="codeline ">    return XXH64_finalize(h64, state-&gt;buffer, (size_t)state-&gt;total_len, XXH_aligned);
</span><span id="line3786" class="codeline ">}
</span><span id="line3787" class="codeline ">#endif /* !XXH_NO_STREAM */
</span><span id="line3788" class="codeline ">
</span><span id="line3789" class="codeline ">/******* Canonical representation   *******/
</span><span id="line3790" class="codeline ">
</span><span id="line3791" class="codeline ">/*! @ingroup XXH64_family */
</span><span id="line3792" class="codeline ">XXH_PUBLIC_API void XXH64_canonicalFromHash(XXH_NOESCAPE XXH64_canonical_t* dst, XXH64_hash_t hash)
</span><span id="line3793" class="codeline ">{
</span><span id="line3794" class="codeline ">    XXH_STATIC_ASSERT(sizeof(XXH64_canonical_t) == sizeof(XXH64_hash_t));
</span><span id="line3795" class="codeline ">    if (XXH_CPU_LITTLE_ENDIAN) hash = XXH_swap64(hash);
</span><span id="line3796" class="codeline ">    XXH_memcpy(dst, &amp;hash, sizeof(*dst));
</span><span id="line3797" class="codeline ">}
</span><span id="line3798" class="codeline ">
</span><span id="line3799" class="codeline ">/*! @ingroup XXH64_family */
</span><span id="line3800" class="codeline ">XXH_PUBLIC_API XXH64_hash_t XXH64_hashFromCanonical(XXH_NOESCAPE const XXH64_canonical_t* src)
</span><span id="line3801" class="codeline ">{
</span><span id="line3802" class="codeline ">    return XXH_readBE64(src);
</span><span id="line3803" class="codeline ">}
</span><span id="line3804" class="codeline ">
</span><span id="line3805" class="codeline ">#ifndef XXH_NO_XXH3
</span><span id="line3806" class="codeline ">
</span><span id="line3807" class="codeline ">/* *********************************************************************
</span><span id="line3808" class="codeline ">*  XXH3
</span><span id="line3809" class="codeline ">*  New generation hash designed for speed on small keys and vectorization
</span><span id="line3810" class="codeline ">************************************************************************ */
</span><span id="line3811" class="codeline ">/*!
</span><span id="line3812" class="codeline "> * @}
</span><span id="line3813" class="codeline "> * @defgroup XXH3_impl XXH3 implementation
</span><span id="line3814" class="codeline "> * @ingroup impl
</span><span id="line3815" class="codeline "> * @{
</span><span id="line3816" class="codeline "> */
</span><span id="line3817" class="codeline ">
</span><span id="line3818" class="codeline ">/* ===   Compiler specifics   === */
</span><span id="line3819" class="codeline ">
</span><span id="line3820" class="codeline ">
</span><span id="line3821" class="codeline ">#if (defined(__GNUC__) &amp;&amp; (__GNUC__ &gt;= 3))  \
</span><span id="line3822" class="codeline ">  || (defined(__INTEL_COMPILER) &amp;&amp; (__INTEL_COMPILER &gt;= 800)) \
</span><span id="line3823" class="codeline ">  || defined(__clang__)
</span><span id="line3824" class="codeline ">#    define XXH_likely(x) __builtin_expect(x, 1)
</span><span id="line3825" class="codeline ">#    define XXH_unlikely(x) __builtin_expect(x, 0)
</span><span id="line3826" class="codeline ">#else
</span><span id="line3827" class="codeline ">#    define XXH_likely(x) (x)
</span><span id="line3828" class="codeline ">#    define XXH_unlikely(x) (x)
</span><span id="line3829" class="codeline ">#endif
</span><span id="line3830" class="codeline ">
</span><span id="line3831" class="codeline ">#ifndef XXH_HAS_INCLUDE
</span><span id="line3832" class="codeline ">#  ifdef __has_include
</span><span id="line3833" class="codeline ">/*
</span><span id="line3834" class="codeline "> * Not defined as XXH_HAS_INCLUDE(x) (function-like) because
</span><span id="line3835" class="codeline "> * this causes segfaults in Apple Clang 4.2 (on Mac OS X 10.7 Lion)
</span><span id="line3836" class="codeline "> */
</span><span id="line3837" class="codeline ">#    define XXH_HAS_INCLUDE __has_include
</span><span id="line3838" class="codeline ">#  else
</span><span id="line3839" class="codeline ">#    define XXH_HAS_INCLUDE(x) 0
</span><span id="line3840" class="codeline ">#  endif
</span><span id="line3841" class="codeline ">#endif
</span><span id="line3842" class="codeline ">
</span><span id="line3843" class="codeline ">#if defined(__GNUC__) || defined(__clang__)
</span><span id="line3844" class="codeline ">#  if defined(__ARM_FEATURE_SVE)
</span><span id="line3845" class="codeline ">#    include &lt;arm_sve.h&gt;
</span><span id="line3846" class="codeline ">#  endif
</span><span id="line3847" class="codeline ">#  if defined(__ARM_NEON__) || defined(__ARM_NEON) \
</span><span id="line3848" class="codeline ">   || (defined(_M_ARM) &amp;&amp; _M_ARM &gt;= 7) \
</span><span id="line3849" class="codeline ">   || defined(_M_ARM64) || defined(_M_ARM64EC) \
</span><span id="line3850" class="codeline ">   || (defined(__wasm_simd128__) &amp;&amp; XXH_HAS_INCLUDE(&lt;arm_neon.h&gt;)) /* WASM SIMD128 via SIMDe */
</span><span id="line3851" class="codeline ">#    define inline __inline__  /* circumvent a clang bug */
</span><span id="line3852" class="codeline ">#    include &lt;arm_neon.h&gt;
</span><span id="line3853" class="codeline ">#    undef inline
</span><span id="line3854" class="codeline ">#  elif defined(__AVX2__)
</span><span id="line3855" class="codeline ">#    include &lt;immintrin.h&gt;
</span><span id="line3856" class="codeline ">#  elif defined(__SSE2__)
</span><span id="line3857" class="codeline ">#    include &lt;emmintrin.h&gt;
</span><span id="line3858" class="codeline ">#  elif defined(__loongarch_sx)
</span><span id="line3859" class="codeline ">#    include &lt;lsxintrin.h&gt;
</span><span id="line3860" class="codeline ">#  endif
</span><span id="line3861" class="codeline ">#endif
</span><span id="line3862" class="codeline ">
</span><span id="line3863" class="codeline ">#if defined(_MSC_VER)
</span><span id="line3864" class="codeline ">#  include &lt;intrin.h&gt;
</span><span id="line3865" class="codeline ">#endif
</span><span id="line3866" class="codeline ">
</span><span id="line3867" class="codeline ">/*
</span><span id="line3868" class="codeline "> * One goal of XXH3 is to make it fast on both 32-bit and 64-bit, while
</span><span id="line3869" class="codeline "> * remaining a true 64-bit/128-bit hash function.
</span><span id="line3870" class="codeline "> *
</span><span id="line3871" class="codeline "> * This is done by prioritizing a subset of 64-bit operations that can be
</span><span id="line3872" class="codeline "> * emulated without too many steps on the average 32-bit machine.
</span><span id="line3873" class="codeline "> *
</span><span id="line3874" class="codeline "> * For example, these two lines seem similar, and run equally fast on 64-bit:
</span><span id="line3875" class="codeline "> *
</span><span id="line3876" class="codeline "> *   xxh_u64 x;
</span><span id="line3877" class="codeline "> *   x ^= (x &gt;&gt; 47); // good
</span><span id="line3878" class="codeline "> *   x ^= (x &gt;&gt; 13); // bad
</span><span id="line3879" class="codeline "> *
</span><span id="line3880" class="codeline "> * However, to a 32-bit machine, there is a major difference.
</span><span id="line3881" class="codeline "> *
</span><span id="line3882" class="codeline "> * x ^= (x &gt;&gt; 47) looks like this:
</span><span id="line3883" class="codeline "> *
</span><span id="line3884" class="codeline "> *   x.lo ^= (x.hi &gt;&gt; (47 - 32));
</span><span id="line3885" class="codeline "> *
</span><span id="line3886" class="codeline "> * while x ^= (x &gt;&gt; 13) looks like this:
</span><span id="line3887" class="codeline "> *
</span><span id="line3888" class="codeline "> *   // note: funnel shifts are not usually cheap.
</span><span id="line3889" class="codeline "> *   x.lo ^= (x.lo &gt;&gt; 13) | (x.hi &lt;&lt; (32 - 13));
</span><span id="line3890" class="codeline "> *   x.hi ^= (x.hi &gt;&gt; 13);
</span><span id="line3891" class="codeline "> *
</span><span id="line3892" class="codeline "> * The first one is significantly faster than the second, simply because the
</span><span id="line3893" class="codeline "> * shift is larger than 32. This means:
</span><span id="line3894" class="codeline "> *  - All the bits we need are in the upper 32 bits, so we can ignore the lower
</span><span id="line3895" class="codeline "> *    32 bits in the shift.
</span><span id="line3896" class="codeline "> *  - The shift result will always fit in the lower 32 bits, and therefore,
</span><span id="line3897" class="codeline "> *    we can ignore the upper 32 bits in the xor.
</span><span id="line3898" class="codeline "> *
</span><span id="line3899" class="codeline "> * Thanks to this optimization, XXH3 only requires these features to be efficient:
</span><span id="line3900" class="codeline "> *
</span><span id="line3901" class="codeline "> *  - Usable unaligned access
</span><span id="line3902" class="codeline "> *  - A 32-bit or 64-bit ALU
</span><span id="line3903" class="codeline "> *      - If 32-bit, a decent ADC instruction
</span><span id="line3904" class="codeline "> *  - A 32 or 64-bit multiply with a 64-bit result
</span><span id="line3905" class="codeline "> *  - For the 128-bit variant, a decent byteswap helps short inputs.
</span><span id="line3906" class="codeline "> *
</span><span id="line3907" class="codeline "> * The first two are already required by XXH32, and almost all 32-bit and 64-bit
</span><span id="line3908" class="codeline "> * platforms which can run XXH32 can run XXH3 efficiently.
</span><span id="line3909" class="codeline "> *
</span><span id="line3910" class="codeline "> * Thumb-1, the classic 16-bit only subset of ARM&#39;s instruction set, is one
</span><span id="line3911" class="codeline "> * notable exception.
</span><span id="line3912" class="codeline "> *
</span><span id="line3913" class="codeline "> * First of all, Thumb-1 lacks support for the UMULL instruction which
</span><span id="line3914" class="codeline "> * performs the important long multiply. This means numerous __aeabi_lmul
</span><span id="line3915" class="codeline "> * calls.
</span><span id="line3916" class="codeline "> *
</span><span id="line3917" class="codeline "> * Second of all, the 8 functional registers are just not enough.
</span><span id="line3918" class="codeline "> * Setup for __aeabi_lmul, byteshift loads, pointers, and all arithmetic need
</span><span id="line3919" class="codeline "> * Lo registers, and this shuffling results in thousands more MOVs than A32.
</span><span id="line3920" class="codeline "> *
</span><span id="line3921" class="codeline "> * A32 and T32 don&#39;t have this limitation. They can access all 14 registers,
</span><span id="line3922" class="codeline "> * do a 32-&gt;64 multiply with UMULL, and the flexible operand allowing free
</span><span id="line3923" class="codeline "> * shifts is helpful, too.
</span><span id="line3924" class="codeline "> *
</span><span id="line3925" class="codeline "> * Therefore, we do a quick sanity check.
</span><span id="line3926" class="codeline "> *
</span><span id="line3927" class="codeline "> * If compiling Thumb-1 for a target which supports ARM instructions, we will
</span><span id="line3928" class="codeline "> * emit a warning, as it is not a &#34;sane&#34; platform to compile for.
</span><span id="line3929" class="codeline "> *
</span><span id="line3930" class="codeline "> * Usually, if this happens, it is because of an accident and you probably need
</span><span id="line3931" class="codeline "> * to specify -march, as you likely meant to compile for a newer architecture.
</span><span id="line3932" class="codeline "> *
</span><span id="line3933" class="codeline "> * Credit: large sections of the vectorial and asm source code paths
</span><span id="line3934" class="codeline "> *         have been contributed by @easyaspi314
</span><span id="line3935" class="codeline "> */
</span><span id="line3936" class="codeline ">#if defined(__thumb__) &amp;&amp; !defined(__thumb2__) &amp;&amp; defined(__ARM_ARCH_ISA_ARM)
</span><span id="line3937" class="codeline ">#   warning &#34;XXH3 is highly inefficient without ARM or Thumb-2.&#34;
</span><span id="line3938" class="codeline ">#endif
</span><span id="line3939" class="codeline ">
</span><span id="line3940" class="codeline ">/* ==========================================
</span><span id="line3941" class="codeline "> * Vectorization detection
</span><span id="line3942" class="codeline "> * ========================================== */
</span><span id="line3943" class="codeline ">
</span><span id="line3944" class="codeline ">#ifdef XXH_DOXYGEN
</span><span id="line3945" class="codeline ">/*!
</span><span id="line3946" class="codeline "> * @ingroup tuning
</span><span id="line3947" class="codeline "> * @brief Overrides the vectorization implementation chosen for XXH3.
</span><span id="line3948" class="codeline "> *
</span><span id="line3949" class="codeline "> * Can be defined to 0 to disable SIMD or any of the values mentioned in
</span><span id="line3950" class="codeline "> * @ref XXH_VECTOR_TYPE.
</span><span id="line3951" class="codeline "> *
</span><span id="line3952" class="codeline "> * If this is not defined, it uses predefined macros to determine the best
</span><span id="line3953" class="codeline "> * implementation.
</span><span id="line3954" class="codeline "> */
</span><span id="line3955" class="codeline ">#  define XXH_VECTOR XXH_SCALAR
</span><span id="line3956" class="codeline ">/*!
</span><span id="line3957" class="codeline "> * @ingroup tuning
</span><span id="line3958" class="codeline "> * @brief Selects the minimum alignment for XXH3&#39;s accumulators.
</span><span id="line3959" class="codeline "> *
</span><span id="line3960" class="codeline "> * When using SIMD, this should match the alignment required for said vector
</span><span id="line3961" class="codeline "> * type, so, for example, 32 for AVX2.
</span><span id="line3962" class="codeline "> *
</span><span id="line3963" class="codeline "> * Default: Auto detected.
</span><span id="line3964" class="codeline "> */
</span><span id="line3965" class="codeline ">#  define XXH_ACC_ALIGN 8
</span><span id="line3966" class="codeline ">#endif
</span><span id="line3967" class="codeline ">
</span><span id="line3968" class="codeline ">/* Actual definition */
</span><span id="line3969" class="codeline ">#ifndef XXH_DOXYGEN
</span><span id="line3970" class="codeline ">#endif
</span><span id="line3971" class="codeline ">
</span><span id="line3972" class="codeline ">#ifndef XXH_VECTOR    /* can be defined on command line */
</span><span id="line3973" class="codeline ">#  if defined(__ARM_FEATURE_SVE)
</span><span id="line3974" class="codeline ">#    define XXH_VECTOR XXH_SVE
</span><span id="line3975" class="codeline ">#  elif ( \
</span><span id="line3976" class="codeline ">        defined(__ARM_NEON__) || defined(__ARM_NEON) /* gcc */ \
</span><span id="line3977" class="codeline ">     || defined(_M_ARM) || defined(_M_ARM64) || defined(_M_ARM64EC) /* msvc */ \
</span><span id="line3978" class="codeline ">     || (defined(__wasm_simd128__) &amp;&amp; XXH_HAS_INCLUDE(&lt;arm_neon.h&gt;)) /* wasm simd128 via SIMDe */ \
</span><span id="line3979" class="codeline ">   ) &amp;&amp; ( \
</span><span id="line3980" class="codeline ">        defined(_WIN32) || defined(__LITTLE_ENDIAN__) /* little endian only */ \
</span><span id="line3981" class="codeline ">    || (defined(__BYTE_ORDER__) &amp;&amp; __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__) \
</span><span id="line3982" class="codeline ">   )
</span><span id="line3983" class="codeline ">#    define XXH_VECTOR XXH_NEON
</span><span id="line3984" class="codeline ">#  elif defined(__AVX512F__)
</span><span id="line3985" class="codeline ">#    define XXH_VECTOR XXH_AVX512
</span><span id="line3986" class="codeline ">#  elif defined(__AVX2__)
</span><span id="line3987" class="codeline ">#    define XXH_VECTOR XXH_AVX2
</span><span id="line3988" class="codeline ">#  elif defined(__SSE2__) || defined(_M_AMD64) || defined(_M_X64) || (defined(_M_IX86_FP) &amp;&amp; (_M_IX86_FP == 2))
</span><span id="line3989" class="codeline ">#    define XXH_VECTOR XXH_SSE2
</span><span id="line3990" class="codeline ">#  elif (defined(__PPC64__) &amp;&amp; defined(__POWER8_VECTOR__)) \
</span><span id="line3991" class="codeline ">     || (defined(__s390x__) &amp;&amp; defined(__VEC__)) \
</span><span id="line3992" class="codeline ">     &amp;&amp; defined(__GNUC__) /* TODO: IBM XL */
</span><span id="line3993" class="codeline ">#    define XXH_VECTOR XXH_VSX
</span><span id="line3994" class="codeline ">#  elif defined(__loongarch_sx)
</span><span id="line3995" class="codeline ">#    define XXH_VECTOR XXH_LSX
</span><span id="line3996" class="codeline ">#  else
</span><span id="line3997" class="codeline ">#    define XXH_VECTOR XXH_SCALAR
</span><span id="line3998" class="codeline ">#  endif
</span><span id="line3999" class="codeline ">#endif
</span><span id="line4000" class="codeline ">
</span><span id="line4001" class="codeline ">/* __ARM_FEATURE_SVE is only supported by GCC &amp; Clang. */
</span><span id="line4002" class="codeline ">#if (XXH_VECTOR == XXH_SVE) &amp;&amp; !defined(__ARM_FEATURE_SVE)
</span><span id="line4003" class="codeline ">#  ifdef _MSC_VER
</span><span id="line4004" class="codeline ">#    pragma warning(once : 4606)
</span><span id="line4005" class="codeline ">#  else
</span><span id="line4006" class="codeline ">#    warning &#34;__ARM_FEATURE_SVE isn&#39;t supported. Use SCALAR instead.&#34;
</span><span id="line4007" class="codeline ">#  endif
</span><span id="line4008" class="codeline ">#  undef XXH_VECTOR
</span><span id="line4009" class="codeline ">#  define XXH_VECTOR XXH_SCALAR
</span><span id="line4010" class="codeline ">#endif
</span><span id="line4011" class="codeline ">
</span><span id="line4012" class="codeline ">/*
</span><span id="line4013" class="codeline "> * Controls the alignment of the accumulator,
</span><span id="line4014" class="codeline "> * for compatibility with aligned vector loads, which are usually faster.
</span><span id="line4015" class="codeline "> */
</span><span id="line4016" class="codeline ">#ifndef XXH_ACC_ALIGN
</span><span id="line4017" class="codeline ">#  if defined(XXH_X86DISPATCH)
</span><span id="line4018" class="codeline ">#     define XXH_ACC_ALIGN 64  /* for compatibility with avx512 */
</span><span id="line4019" class="codeline ">#  elif XXH_VECTOR == XXH_SCALAR  /* scalar */
</span><span id="line4020" class="codeline ">#     define XXH_ACC_ALIGN 8
</span><span id="line4021" class="codeline ">#  elif XXH_VECTOR == XXH_SSE2  /* sse2 */
</span><span id="line4022" class="codeline ">#     define XXH_ACC_ALIGN 16
</span><span id="line4023" class="codeline ">#  elif XXH_VECTOR == XXH_AVX2  /* avx2 */
</span><span id="line4024" class="codeline ">#     define XXH_ACC_ALIGN 32
</span><span id="line4025" class="codeline ">#  elif XXH_VECTOR == XXH_NEON  /* neon */
</span><span id="line4026" class="codeline ">#     define XXH_ACC_ALIGN 16
</span><span id="line4027" class="codeline ">#  elif XXH_VECTOR == XXH_VSX   /* vsx */
</span><span id="line4028" class="codeline ">#     define XXH_ACC_ALIGN 16
</span><span id="line4029" class="codeline ">#  elif XXH_VECTOR == XXH_AVX512  /* avx512 */
</span><span id="line4030" class="codeline ">#     define XXH_ACC_ALIGN 64
</span><span id="line4031" class="codeline ">#  elif XXH_VECTOR == XXH_SVE   /* sve */
</span><span id="line4032" class="codeline ">#     define XXH_ACC_ALIGN 64
</span><span id="line4033" class="codeline ">#  elif XXH_VECTOR == XXH_LSX   /* lsx */
</span><span id="line4034" class="codeline ">#     define XXH_ACC_ALIGN 64
</span><span id="line4035" class="codeline ">#  endif
</span><span id="line4036" class="codeline ">#endif
</span><span id="line4037" class="codeline ">
</span><span id="line4038" class="codeline ">#if defined(XXH_X86DISPATCH) || XXH_VECTOR == XXH_SSE2 \
</span><span id="line4039" class="codeline ">    || XXH_VECTOR == XXH_AVX2 || XXH_VECTOR == XXH_AVX512
</span><span id="line4040" class="codeline ">#  define XXH_SEC_ALIGN XXH_ACC_ALIGN
</span><span id="line4041" class="codeline ">#elif XXH_VECTOR == XXH_SVE
</span><span id="line4042" class="codeline ">#  define XXH_SEC_ALIGN XXH_ACC_ALIGN
</span><span id="line4043" class="codeline ">#else
</span><span id="line4044" class="codeline ">#  define XXH_SEC_ALIGN 8
</span><span id="line4045" class="codeline ">#endif
</span><span id="line4046" class="codeline ">
</span><span id="line4047" class="codeline ">#if defined(__GNUC__) || defined(__clang__)
</span><span id="line4048" class="codeline ">#  define XXH_ALIASING __attribute__((__may_alias__))
</span><span id="line4049" class="codeline ">#else
</span><span id="line4050" class="codeline ">#  define XXH_ALIASING /* nothing */
</span><span id="line4051" class="codeline ">#endif
</span><span id="line4052" class="codeline ">
</span><span id="line4053" class="codeline ">/*
</span><span id="line4054" class="codeline "> * UGLY HACK:
</span><span id="line4055" class="codeline "> * GCC usually generates the best code with -O3 for xxHash.
</span><span id="line4056" class="codeline "> *
</span><span id="line4057" class="codeline "> * However, when targeting AVX2, it is overzealous in its unrolling resulting
</span><span id="line4058" class="codeline "> * in code roughly 3/4 the speed of Clang.
</span><span id="line4059" class="codeline "> *
</span><span id="line4060" class="codeline "> * There are other issues, such as GCC splitting _mm256_loadu_si256 into
</span><span id="line4061" class="codeline "> * _mm_loadu_si128 + _mm256_inserti128_si256. This is an optimization which
</span><span id="line4062" class="codeline "> * only applies to Sandy and Ivy Bridge... which don&#39;t even support AVX2.
</span><span id="line4063" class="codeline "> *
</span><span id="line4064" class="codeline "> * That is why when compiling the AVX2 version, it is recommended to use either
</span><span id="line4065" class="codeline "> *   -O2 -mavx2 -march=haswell
</span><span id="line4066" class="codeline "> * or
</span><span id="line4067" class="codeline "> *   -O2 -mavx2 -mno-avx256-split-unaligned-load
</span><span id="line4068" class="codeline "> * for decent performance, or to use Clang instead.
</span><span id="line4069" class="codeline "> *
</span><span id="line4070" class="codeline "> * Fortunately, we can control the first one with a pragma that forces GCC into
</span><span id="line4071" class="codeline "> * -O2, but the other one we can&#39;t control without &#34;failed to inline always
</span><span id="line4072" class="codeline "> * inline function due to target mismatch&#34; warnings.
</span><span id="line4073" class="codeline "> */
</span><span id="line4074" class="codeline ">#if XXH_VECTOR == XXH_AVX2 /* AVX2 */ \
</span><span id="line4075" class="codeline ">  &amp;&amp; defined(__GNUC__) &amp;&amp; !defined(__clang__) /* GCC, not Clang */ \
</span><span id="line4076" class="codeline ">  &amp;&amp; defined(__OPTIMIZE__) &amp;&amp; XXH_SIZE_OPT &lt;= 0 /* respect -O0 and -Os */
</span><span id="line4077" class="codeline ">#  pragma GCC push_options
</span><span id="line4078" class="codeline ">#  pragma GCC optimize(&#34;-O2&#34;)
</span><span id="line4079" class="codeline ">#endif
</span><span id="line4080" class="codeline ">
</span><span id="line4081" class="codeline ">#if XXH_VECTOR == XXH_NEON
</span><span id="line4082" class="codeline ">
</span><span id="line4083" class="codeline ">/*
</span><span id="line4084" class="codeline "> * UGLY HACK: While AArch64 GCC on Linux does not seem to care, on macOS, GCC -O3
</span><span id="line4085" class="codeline "> * optimizes out the entire hashLong loop because of the aliasing violation.
</span><span id="line4086" class="codeline "> *
</span><span id="line4087" class="codeline "> * However, GCC is also inefficient at load-store optimization with vld1q/vst1q,
</span><span id="line4088" class="codeline "> * so the only option is to mark it as aliasing.
</span><span id="line4089" class="codeline "> */
</span><span id="line4090" class="codeline ">typedef uint64x2_t xxh_aliasing_uint64x2_t XXH_ALIASING;
</span><span id="line4091" class="codeline ">
</span><span id="line4092" class="codeline ">/*!
</span><span id="line4093" class="codeline "> * @internal
</span><span id="line4094" class="codeline "> * @brief `vld1q_u64` but faster and alignment-safe.
</span><span id="line4095" class="codeline "> *
</span><span id="line4096" class="codeline "> * On AArch64, unaligned access is always safe, but on ARMv7-a, it is only
</span><span id="line4097" class="codeline "> * *conditionally* safe (`vld1` has an alignment bit like `movdq[ua]` in x86).
</span><span id="line4098" class="codeline "> *
</span><span id="line4099" class="codeline "> * GCC for AArch64 sees `vld1q_u8` as an intrinsic instead of a load, so it
</span><span id="line4100" class="codeline "> * prohibits load-store optimizations. Therefore, a direct dereference is used.
</span><span id="line4101" class="codeline "> *
</span><span id="line4102" class="codeline "> * Otherwise, `vld1q_u8` is used with `vreinterpretq_u8_u64` to do a safe
</span><span id="line4103" class="codeline "> * unaligned load.
</span><span id="line4104" class="codeline "> */
</span><span id="line4105" class="codeline ">#if defined(__aarch64__) &amp;&amp; defined(__GNUC__) &amp;&amp; !defined(__clang__)
</span><span id="line4106" class="codeline ">XXH_FORCE_INLINE uint64x2_t XXH_vld1q_u64(void const* ptr) /* silence -Wcast-align */
</span><span id="line4107" class="codeline ">{
</span><span id="line4108" class="codeline ">    return *(xxh_aliasing_uint64x2_t const *)ptr;
</span><span id="line4109" class="codeline ">}
</span><span id="line4110" class="codeline ">#else
</span><span id="line4111" class="codeline ">XXH_FORCE_INLINE uint64x2_t XXH_vld1q_u64(void const* ptr)
</span><span id="line4112" class="codeline ">{
</span><span id="line4113" class="codeline ">    return vreinterpretq_u64_u8(vld1q_u8((uint8_t const*)ptr));
</span><span id="line4114" class="codeline ">}
</span><span id="line4115" class="codeline ">#endif
</span><span id="line4116" class="codeline ">
</span><span id="line4117" class="codeline ">/*!
</span><span id="line4118" class="codeline "> * @internal
</span><span id="line4119" class="codeline "> * @brief `vmlal_u32` on low and high halves of a vector.
</span><span id="line4120" class="codeline "> *
</span><span id="line4121" class="codeline "> * This is a workaround for AArch64 GCC &lt; 11 which implemented arm_neon.h with
</span><span id="line4122" class="codeline "> * inline assembly and were therefore incapable of merging the `vget_{low, high}_u32`
</span><span id="line4123" class="codeline "> * with `vmlal_u32`.
</span><span id="line4124" class="codeline "> */
</span><span id="line4125" class="codeline ">#if defined(__aarch64__) &amp;&amp; defined(__GNUC__) &amp;&amp; !defined(__clang__) &amp;&amp; __GNUC__ &lt; 11
</span><span id="line4126" class="codeline ">XXH_FORCE_INLINE uint64x2_t
</span><span id="line4127" class="codeline ">XXH_vmlal_low_u32(uint64x2_t acc, uint32x4_t lhs, uint32x4_t rhs)
</span><span id="line4128" class="codeline ">{
</span><span id="line4129" class="codeline ">    /* Inline assembly is the only way */
</span><span id="line4130" class="codeline ">    __asm__(&#34;umlal   %0.2d, %1.2s, %2.2s&#34; : &#34;+w&#34; (acc) : &#34;w&#34; (lhs), &#34;w&#34; (rhs));
</span><span id="line4131" class="codeline ">    return acc;
</span><span id="line4132" class="codeline ">}
</span><span id="line4133" class="codeline ">XXH_FORCE_INLINE uint64x2_t
</span><span id="line4134" class="codeline ">XXH_vmlal_high_u32(uint64x2_t acc, uint32x4_t lhs, uint32x4_t rhs)
</span><span id="line4135" class="codeline ">{
</span><span id="line4136" class="codeline ">    /* This intrinsic works as expected */
</span><span id="line4137" class="codeline ">    return vmlal_high_u32(acc, lhs, rhs);
</span><span id="line4138" class="codeline ">}
</span><span id="line4139" class="codeline ">#else
</span><span id="line4140" class="codeline ">/* Portable intrinsic versions */
</span><span id="line4141" class="codeline ">XXH_FORCE_INLINE uint64x2_t
</span><span id="line4142" class="codeline ">XXH_vmlal_low_u32(uint64x2_t acc, uint32x4_t lhs, uint32x4_t rhs)
</span><span id="line4143" class="codeline ">{
</span><span id="line4144" class="codeline ">    return vmlal_u32(acc, vget_low_u32(lhs), vget_low_u32(rhs));
</span><span id="line4145" class="codeline ">}
</span><span id="line4146" class="codeline ">/*! @copydoc XXH_vmlal_low_u32
</span><span id="line4147" class="codeline "> * Assume the compiler converts this to vmlal_high_u32 on aarch64 */
</span><span id="line4148" class="codeline ">XXH_FORCE_INLINE uint64x2_t
</span><span id="line4149" class="codeline ">XXH_vmlal_high_u32(uint64x2_t acc, uint32x4_t lhs, uint32x4_t rhs)
</span><span id="line4150" class="codeline ">{
</span><span id="line4151" class="codeline ">    return vmlal_u32(acc, vget_high_u32(lhs), vget_high_u32(rhs));
</span><span id="line4152" class="codeline ">}
</span><span id="line4153" class="codeline ">#endif
</span><span id="line4154" class="codeline ">
</span><span id="line4155" class="codeline ">/*!
</span><span id="line4156" class="codeline "> * @ingroup tuning
</span><span id="line4157" class="codeline "> * @brief Controls the NEON to scalar ratio for XXH3
</span><span id="line4158" class="codeline "> *
</span><span id="line4159" class="codeline "> * This can be set to 2, 4, 6, or 8.
</span><span id="line4160" class="codeline "> *
</span><span id="line4161" class="codeline "> * ARM Cortex CPUs are _very_ sensitive to how their pipelines are used.
</span><span id="line4162" class="codeline "> *
</span><span id="line4163" class="codeline "> * For example, the Cortex-A73 can dispatch 3 micro-ops per cycle, but only 2 of those
</span><span id="line4164" class="codeline "> * can be NEON. If you are only using NEON instructions, you are only using 2/3 of the CPU
</span><span id="line4165" class="codeline "> * bandwidth.
</span><span id="line4166" class="codeline "> *
</span><span id="line4167" class="codeline "> * This is even more noticeable on the more advanced cores like the Cortex-A76 which
</span><span id="line4168" class="codeline "> * can dispatch 8 micro-ops per cycle, but still only 2 NEON micro-ops at once.
</span><span id="line4169" class="codeline "> *
</span><span id="line4170" class="codeline "> * Therefore, to make the most out of the pipeline, it is beneficial to run 6 NEON lanes
</span><span id="line4171" class="codeline "> * and 2 scalar lanes, which is chosen by default.
</span><span id="line4172" class="codeline "> *
</span><span id="line4173" class="codeline "> * This does not apply to Apple processors or 32-bit processors, which run better with
</span><span id="line4174" class="codeline "> * full NEON. These will default to 8. Additionally, size-optimized builds run 8 lanes.
</span><span id="line4175" class="codeline "> *
</span><span id="line4176" class="codeline "> * This change benefits CPUs with large micro-op buffers without negatively affecting
</span><span id="line4177" class="codeline "> * most other CPUs:
</span><span id="line4178" class="codeline "> *
</span><span id="line4179" class="codeline "> *  | Chipset               | Dispatch type       | NEON only | 6:2 hybrid | Diff. |
</span><span id="line4180" class="codeline "> *  |:----------------------|:--------------------|----------:|-----------:|------:|
</span><span id="line4181" class="codeline "> *  | Snapdragon 730 (A76)  | 2 NEON/8 micro-ops  |  8.8 GB/s |  10.1 GB/s |  ~16% |
</span><span id="line4182" class="codeline "> *  | Snapdragon 835 (A73)  | 2 NEON/3 micro-ops  |  5.1 GB/s |   5.3 GB/s |   ~5% |
</span><span id="line4183" class="codeline "> *  | Marvell PXA1928 (A53) | In-order dual-issue |  1.9 GB/s |   1.9 GB/s |    0% |
</span><span id="line4184" class="codeline "> *  | Apple M1              | 4 NEON/8 micro-ops  | 37.3 GB/s |  36.1 GB/s |  ~-3% |
</span><span id="line4185" class="codeline "> *
</span><span id="line4186" class="codeline "> * It also seems to fix some bad codegen on GCC, making it almost as fast as clang.
</span><span id="line4187" class="codeline "> *
</span><span id="line4188" class="codeline "> * When using WASM SIMD128, if this is 2 or 6, SIMDe will scalarize 2 of the lanes meaning
</span><span id="line4189" class="codeline "> * it effectively becomes worse 4.
</span><span id="line4190" class="codeline "> *
</span><span id="line4191" class="codeline "> * @see XXH3_accumulate_512_neon()
</span><span id="line4192" class="codeline "> */
</span><span id="line4193" class="codeline "># ifndef XXH3_NEON_LANES
</span><span id="line4194" class="codeline ">#  if (defined(__aarch64__) || defined(__arm64__) || defined(_M_ARM64) || defined(_M_ARM64EC)) \
</span><span id="line4195" class="codeline ">   &amp;&amp; !defined(__APPLE__) &amp;&amp; XXH_SIZE_OPT &lt;= 0
</span><span id="line4196" class="codeline ">#   define XXH3_NEON_LANES 6
</span><span id="line4197" class="codeline ">#  else
</span><span id="line4198" class="codeline ">#   define XXH3_NEON_LANES XXH_ACC_NB
</span><span id="line4199" class="codeline ">#  endif
</span><span id="line4200" class="codeline "># endif
</span><span id="line4201" class="codeline ">#endif  /* XXH_VECTOR == XXH_NEON */
</span><span id="line4202" class="codeline ">
</span><span id="line4203" class="codeline ">/*
</span><span id="line4204" class="codeline "> * VSX and Z Vector helpers.
</span><span id="line4205" class="codeline "> *
</span><span id="line4206" class="codeline "> * This is very messy, and any pull requests to clean this up are welcome.
</span><span id="line4207" class="codeline "> *
</span><span id="line4208" class="codeline "> * There are a lot of problems with supporting VSX and s390x, due to
</span><span id="line4209" class="codeline "> * inconsistent intrinsics, spotty coverage, and multiple endiannesses.
</span><span id="line4210" class="codeline "> */
</span><span id="line4211" class="codeline ">#if XXH_VECTOR == XXH_VSX
</span><span id="line4212" class="codeline ">/* Annoyingly, these headers _may_ define three macros: `bool`, `vector`,
</span><span id="line4213" class="codeline "> * and `pixel`. This is a problem for obvious reasons.
</span><span id="line4214" class="codeline "> *
</span><span id="line4215" class="codeline "> * These keywords are unnecessary; the spec literally says they are
</span><span id="line4216" class="codeline "> * equivalent to `__bool`, `__vector`, and `__pixel` and may be undef&#39;d
</span><span id="line4217" class="codeline "> * after including the header.
</span><span id="line4218" class="codeline "> *
</span><span id="line4219" class="codeline "> * We use pragma push_macro/pop_macro to keep the namespace clean. */
</span><span id="line4220" class="codeline ">#  pragma push_macro(&#34;bool&#34;)
</span><span id="line4221" class="codeline ">#  pragma push_macro(&#34;vector&#34;)
</span><span id="line4222" class="codeline ">#  pragma push_macro(&#34;pixel&#34;)
</span><span id="line4223" class="codeline ">/* silence potential macro redefined warnings */
</span><span id="line4224" class="codeline ">#  undef bool
</span><span id="line4225" class="codeline ">#  undef vector
</span><span id="line4226" class="codeline ">#  undef pixel
</span><span id="line4227" class="codeline ">
</span><span id="line4228" class="codeline ">#  if defined(__s390x__)
</span><span id="line4229" class="codeline ">#    include &lt;s390intrin.h&gt;
</span><span id="line4230" class="codeline ">#  else
</span><span id="line4231" class="codeline ">#    include &lt;altivec.h&gt;
</span><span id="line4232" class="codeline ">#  endif
</span><span id="line4233" class="codeline ">
</span><span id="line4234" class="codeline ">/* Restore the original macro values, if applicable. */
</span><span id="line4235" class="codeline ">#  pragma pop_macro(&#34;pixel&#34;)
</span><span id="line4236" class="codeline ">#  pragma pop_macro(&#34;vector&#34;)
</span><span id="line4237" class="codeline ">#  pragma pop_macro(&#34;bool&#34;)
</span><span id="line4238" class="codeline ">
</span><span id="line4239" class="codeline ">typedef __vector unsigned long long xxh_u64x2;
</span><span id="line4240" class="codeline ">typedef __vector unsigned char xxh_u8x16;
</span><span id="line4241" class="codeline ">typedef __vector unsigned xxh_u32x4;
</span><span id="line4242" class="codeline ">
</span><span id="line4243" class="codeline ">/*
</span><span id="line4244" class="codeline "> * UGLY HACK: Similar to aarch64 macOS GCC, s390x GCC has the same aliasing issue.
</span><span id="line4245" class="codeline "> */
</span><span id="line4246" class="codeline ">typedef xxh_u64x2 xxh_aliasing_u64x2 XXH_ALIASING;
</span><span id="line4247" class="codeline ">
</span><span id="line4248" class="codeline "># ifndef XXH_VSX_BE
</span><span id="line4249" class="codeline ">#  if defined(__BIG_ENDIAN__) \
</span><span id="line4250" class="codeline ">  || (defined(__BYTE_ORDER__) &amp;&amp; __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__)
</span><span id="line4251" class="codeline ">#    define XXH_VSX_BE 1
</span><span id="line4252" class="codeline ">#  elif defined(__VEC_ELEMENT_REG_ORDER__) &amp;&amp; __VEC_ELEMENT_REG_ORDER__ == __ORDER_BIG_ENDIAN__
</span><span id="line4253" class="codeline ">#    warning &#34;-maltivec=be is not recommended. Please use native endianness.&#34;
</span><span id="line4254" class="codeline ">#    define XXH_VSX_BE 1
</span><span id="line4255" class="codeline ">#  else
</span><span id="line4256" class="codeline ">#    define XXH_VSX_BE 0
</span><span id="line4257" class="codeline ">#  endif
</span><span id="line4258" class="codeline "># endif /* !defined(XXH_VSX_BE) */
</span><span id="line4259" class="codeline ">
</span><span id="line4260" class="codeline "># if XXH_VSX_BE
</span><span id="line4261" class="codeline ">#  if defined(__POWER9_VECTOR__) || (defined(__clang__) &amp;&amp; defined(__s390x__))
</span><span id="line4262" class="codeline ">#    define XXH_vec_revb vec_revb
</span><span id="line4263" class="codeline ">#  else
</span><span id="line4264" class="codeline ">/*!
</span><span id="line4265" class="codeline "> * A polyfill for POWER9&#39;s vec_revb().
</span><span id="line4266" class="codeline "> */
</span><span id="line4267" class="codeline ">XXH_FORCE_INLINE xxh_u64x2 XXH_vec_revb(xxh_u64x2 val)
</span><span id="line4268" class="codeline ">{
</span><span id="line4269" class="codeline ">    xxh_u8x16 const vByteSwap = { 0x07, 0x06, 0x05, 0x04, 0x03, 0x02, 0x01, 0x00,
</span><span id="line4270" class="codeline ">                                  0x0F, 0x0E, 0x0D, 0x0C, 0x0B, 0x0A, 0x09, 0x08 };
</span><span id="line4271" class="codeline ">    return vec_perm(val, val, vByteSwap);
</span><span id="line4272" class="codeline ">}
</span><span id="line4273" class="codeline ">#  endif
</span><span id="line4274" class="codeline "># endif /* XXH_VSX_BE */
</span><span id="line4275" class="codeline ">
</span><span id="line4276" class="codeline ">/*!
</span><span id="line4277" class="codeline "> * Performs an unaligned vector load and byte swaps it on big endian.
</span><span id="line4278" class="codeline "> */
</span><span id="line4279" class="codeline ">XXH_FORCE_INLINE xxh_u64x2 XXH_vec_loadu(const void *ptr)
</span><span id="line4280" class="codeline ">{
</span><span id="line4281" class="codeline ">    xxh_u64x2 ret;
</span><span id="line4282" class="codeline ">    XXH_memcpy(&amp;ret, ptr, sizeof(xxh_u64x2));
</span><span id="line4283" class="codeline "># if XXH_VSX_BE
</span><span id="line4284" class="codeline ">    ret = XXH_vec_revb(ret);
</span><span id="line4285" class="codeline "># endif
</span><span id="line4286" class="codeline ">    return ret;
</span><span id="line4287" class="codeline ">}
</span><span id="line4288" class="codeline ">
</span><span id="line4289" class="codeline ">/*
</span><span id="line4290" class="codeline "> * vec_mulo and vec_mule are very problematic intrinsics on PowerPC
</span><span id="line4291" class="codeline "> *
</span><span id="line4292" class="codeline "> * These intrinsics weren&#39;t added until GCC 8, despite existing for a while,
</span><span id="line4293" class="codeline "> * and they are endian dependent. Also, their meaning swap depending on version.
</span><span id="line4294" class="codeline "> * */
</span><span id="line4295" class="codeline "># if defined(__s390x__)
</span><span id="line4296" class="codeline "> /* s390x is always big endian, no issue on this platform */
</span><span id="line4297" class="codeline ">#  define XXH_vec_mulo vec_mulo
</span><span id="line4298" class="codeline ">#  define XXH_vec_mule vec_mule
</span><span id="line4299" class="codeline "># elif defined(__clang__) &amp;&amp; XXH_HAS_BUILTIN(__builtin_altivec_vmuleuw) &amp;&amp; !defined(__ibmxl__)
</span><span id="line4300" class="codeline ">/* Clang has a better way to control this, we can just use the builtin which doesn&#39;t swap. */
</span><span id="line4301" class="codeline "> /* The IBM XL Compiler (which defined __clang__) only implements the vec_* operations */
</span><span id="line4302" class="codeline ">#  define XXH_vec_mulo __builtin_altivec_vmulouw
</span><span id="line4303" class="codeline ">#  define XXH_vec_mule __builtin_altivec_vmuleuw
</span><span id="line4304" class="codeline "># else
</span><span id="line4305" class="codeline ">/* gcc needs inline assembly */
</span><span id="line4306" class="codeline ">/* Adapted from https://github.com/google/highwayhash/blob/master/highwayhash/hh_vsx.h. */
</span><span id="line4307" class="codeline ">XXH_FORCE_INLINE xxh_u64x2 XXH_vec_mulo(xxh_u32x4 a, xxh_u32x4 b)
</span><span id="line4308" class="codeline ">{
</span><span id="line4309" class="codeline ">    xxh_u64x2 result;
</span><span id="line4310" class="codeline ">    __asm__(&#34;vmulouw %0, %1, %2&#34; : &#34;=v&#34; (result) : &#34;v&#34; (a), &#34;v&#34; (b));
</span><span id="line4311" class="codeline ">    return result;
</span><span id="line4312" class="codeline ">}
</span><span id="line4313" class="codeline ">XXH_FORCE_INLINE xxh_u64x2 XXH_vec_mule(xxh_u32x4 a, xxh_u32x4 b)
</span><span id="line4314" class="codeline ">{
</span><span id="line4315" class="codeline ">    xxh_u64x2 result;
</span><span id="line4316" class="codeline ">    __asm__(&#34;vmuleuw %0, %1, %2&#34; : &#34;=v&#34; (result) : &#34;v&#34; (a), &#34;v&#34; (b));
</span><span id="line4317" class="codeline ">    return result;
</span><span id="line4318" class="codeline ">}
</span><span id="line4319" class="codeline "># endif /* XXH_vec_mulo, XXH_vec_mule */
</span><span id="line4320" class="codeline ">#endif /* XXH_VECTOR == XXH_VSX */
</span><span id="line4321" class="codeline ">
</span><span id="line4322" class="codeline ">#if XXH_VECTOR == XXH_SVE
</span><span id="line4323" class="codeline ">#define ACCRND(acc, offset) \
</span><span id="line4324" class="codeline ">do { \
</span><span id="line4325" class="codeline ">    svuint64_t input_vec = svld1_u64(mask, xinput + offset);         \
</span><span id="line4326" class="codeline ">    svuint64_t secret_vec = svld1_u64(mask, xsecret + offset);       \
</span><span id="line4327" class="codeline ">    svuint64_t mixed = sveor_u64_x(mask, secret_vec, input_vec);     \
</span><span id="line4328" class="codeline ">    svuint64_t swapped = svtbl_u64(input_vec, kSwap);                \
</span><span id="line4329" class="codeline ">    svuint64_t mixed_lo = svextw_u64_x(mask, mixed);                 \
</span><span id="line4330" class="codeline ">    svuint64_t mixed_hi = svlsr_n_u64_x(mask, mixed, 32);            \
</span><span id="line4331" class="codeline ">    svuint64_t mul = svmad_u64_x(mask, mixed_lo, mixed_hi, swapped); \
</span><span id="line4332" class="codeline ">    acc = svadd_u64_x(mask, acc, mul);                               \
</span><span id="line4333" class="codeline ">} while (0)
</span><span id="line4334" class="codeline ">#endif /* XXH_VECTOR == XXH_SVE */
</span><span id="line4335" class="codeline ">
</span><span id="line4336" class="codeline ">/* prefetch
</span><span id="line4337" class="codeline "> * can be disabled, by declaring XXH_NO_PREFETCH build macro */
</span><span id="line4338" class="codeline ">#if defined(XXH_NO_PREFETCH)
</span><span id="line4339" class="codeline ">#  define XXH_PREFETCH(ptr)  (void)(ptr)  /* disabled */
</span><span id="line4340" class="codeline ">#else
</span><span id="line4341" class="codeline ">#  if XXH_SIZE_OPT &gt;= 1
</span><span id="line4342" class="codeline ">#    define XXH_PREFETCH(ptr) (void)(ptr)
</span><span id="line4343" class="codeline ">#  elif defined(_MSC_VER) &amp;&amp; (defined(_M_X64) || defined(_M_IX86))  /* _mm_prefetch() not defined outside of x86/x64 */
</span><span id="line4344" class="codeline ">#    include &lt;mmintrin.h&gt;   /* https://msdn.microsoft.com/fr-fr/library/84szxsww(v=vs.90).aspx */
</span><span id="line4345" class="codeline ">#    define XXH_PREFETCH(ptr)  _mm_prefetch((const char*)(ptr), _MM_HINT_T0)
</span><span id="line4346" class="codeline ">#  elif defined(__GNUC__) &amp;&amp; ( (__GNUC__ &gt;= 4) || ( (__GNUC__ == 3) &amp;&amp; (__GNUC_MINOR__ &gt;= 1) ) )
</span><span id="line4347" class="codeline ">#    define XXH_PREFETCH(ptr)  __builtin_prefetch((ptr), 0 /* rw==read */, 3 /* locality */)
</span><span id="line4348" class="codeline ">#  else
</span><span id="line4349" class="codeline ">#    define XXH_PREFETCH(ptr) (void)(ptr)  /* disabled */
</span><span id="line4350" class="codeline ">#  endif
</span><span id="line4351" class="codeline ">#endif  /* XXH_NO_PREFETCH */
</span><span id="line4352" class="codeline ">
</span><span id="line4353" class="codeline ">
</span><span id="line4354" class="codeline ">/* ==========================================
</span><span id="line4355" class="codeline "> * XXH3 default settings
</span><span id="line4356" class="codeline "> * ========================================== */
</span><span id="line4357" class="codeline ">
</span><span id="line4358" class="codeline ">#define XXH_SECRET_DEFAULT_SIZE 192   /* minimum XXH3_SECRET_SIZE_MIN */
</span><span id="line4359" class="codeline ">
</span><span id="line4360" class="codeline ">#if (XXH_SECRET_DEFAULT_SIZE &lt; XXH3_SECRET_SIZE_MIN)
</span><span id="line4361" class="codeline ">#  error &#34;default keyset is not large enough&#34;
</span><span id="line4362" class="codeline ">#endif
</span><span id="line4363" class="codeline ">
</span><span id="line4364" class="codeline ">/*! Pseudorandom secret taken directly from FARSH. */
</span><span id="line4365" class="codeline ">XXH_ALIGN(64) static const xxh_u8 XXH3_kSecret[XXH_SECRET_DEFAULT_SIZE] = {
</span><span id="line4366" class="codeline ">    0xb8, 0xfe, 0x6c, 0x39, 0x23, 0xa4, 0x4b, 0xbe, 0x7c, 0x01, 0x81, 0x2c, 0xf7, 0x21, 0xad, 0x1c,
</span><span id="line4367" class="codeline ">    0xde, 0xd4, 0x6d, 0xe9, 0x83, 0x90, 0x97, 0xdb, 0x72, 0x40, 0xa4, 0xa4, 0xb7, 0xb3, 0x67, 0x1f,
</span><span id="line4368" class="codeline ">    0xcb, 0x79, 0xe6, 0x4e, 0xcc, 0xc0, 0xe5, 0x78, 0x82, 0x5a, 0xd0, 0x7d, 0xcc, 0xff, 0x72, 0x21,
</span><span id="line4369" class="codeline ">    0xb8, 0x08, 0x46, 0x74, 0xf7, 0x43, 0x24, 0x8e, 0xe0, 0x35, 0x90, 0xe6, 0x81, 0x3a, 0x26, 0x4c,
</span><span id="line4370" class="codeline ">    0x3c, 0x28, 0x52, 0xbb, 0x91, 0xc3, 0x00, 0xcb, 0x88, 0xd0, 0x65, 0x8b, 0x1b, 0x53, 0x2e, 0xa3,
</span><span id="line4371" class="codeline ">    0x71, 0x64, 0x48, 0x97, 0xa2, 0x0d, 0xf9, 0x4e, 0x38, 0x19, 0xef, 0x46, 0xa9, 0xde, 0xac, 0xd8,
</span><span id="line4372" class="codeline ">    0xa8, 0xfa, 0x76, 0x3f, 0xe3, 0x9c, 0x34, 0x3f, 0xf9, 0xdc, 0xbb, 0xc7, 0xc7, 0x0b, 0x4f, 0x1d,
</span><span id="line4373" class="codeline ">    0x8a, 0x51, 0xe0, 0x4b, 0xcd, 0xb4, 0x59, 0x31, 0xc8, 0x9f, 0x7e, 0xc9, 0xd9, 0x78, 0x73, 0x64,
</span><span id="line4374" class="codeline ">    0xea, 0xc5, 0xac, 0x83, 0x34, 0xd3, 0xeb, 0xc3, 0xc5, 0x81, 0xa0, 0xff, 0xfa, 0x13, 0x63, 0xeb,
</span><span id="line4375" class="codeline ">    0x17, 0x0d, 0xdd, 0x51, 0xb7, 0xf0, 0xda, 0x49, 0xd3, 0x16, 0x55, 0x26, 0x29, 0xd4, 0x68, 0x9e,
</span><span id="line4376" class="codeline ">    0x2b, 0x16, 0xbe, 0x58, 0x7d, 0x47, 0xa1, 0xfc, 0x8f, 0xf8, 0xb8, 0xd1, 0x7a, 0xd0, 0x31, 0xce,
</span><span id="line4377" class="codeline ">    0x45, 0xcb, 0x3a, 0x8f, 0x95, 0x16, 0x04, 0x28, 0xaf, 0xd7, 0xfb, 0xca, 0xbb, 0x4b, 0x40, 0x7e,
</span><span id="line4378" class="codeline ">};
</span><span id="line4379" class="codeline ">
</span><span id="line4380" class="codeline ">static const xxh_u64 PRIME_MX1 = 0x165667919E3779F9ULL;  /*!&lt; 0b0001011001010110011001111001000110011110001101110111100111111001 */
</span><span id="line4381" class="codeline ">static const xxh_u64 PRIME_MX2 = 0x9FB21C651E98DF25ULL;  /*!&lt; 0b1001111110110010000111000110010100011110100110001101111100100101 */
</span><span id="line4382" class="codeline ">
</span><span id="line4383" class="codeline ">#ifdef XXH_OLD_NAMES
</span><span id="line4384" class="codeline ">#  define kSecret XXH3_kSecret
</span><span id="line4385" class="codeline ">#endif
</span><span id="line4386" class="codeline ">
</span><span id="line4387" class="codeline ">#ifdef XXH_DOXYGEN
</span><span id="line4388" class="codeline ">/*!
</span><span id="line4389" class="codeline "> * @brief Calculates a 32-bit to 64-bit long multiply.
</span><span id="line4390" class="codeline "> *
</span><span id="line4391" class="codeline "> * Implemented as a macro.
</span><span id="line4392" class="codeline "> *
</span><span id="line4393" class="codeline "> * Wraps `__emulu` on MSVC x86 because it tends to call `__allmul` when it doesn&#39;t
</span><span id="line4394" class="codeline "> * need to (but it shouldn&#39;t need to anyways, it is about 7 instructions to do
</span><span id="line4395" class="codeline "> * a 64x64 multiply...). Since we know that this will _always_ emit `MULL`, we
</span><span id="line4396" class="codeline "> * use that instead of the normal method.
</span><span id="line4397" class="codeline "> *
</span><span id="line4398" class="codeline "> * If you are compiling for platforms like Thumb-1 and don&#39;t have a better option,
</span><span id="line4399" class="codeline "> * you may also want to write your own long multiply routine here.
</span><span id="line4400" class="codeline "> *
</span><span id="line4401" class="codeline "> * @param x, y Numbers to be multiplied
</span><span id="line4402" class="codeline "> * @return 64-bit product of the low 32 bits of @p x and @p y.
</span><span id="line4403" class="codeline "> */
</span><span id="line4404" class="codeline ">XXH_FORCE_INLINE xxh_u64
</span><span id="line4405" class="codeline ">XXH_mult32to64(xxh_u64 x, xxh_u64 y)
</span><span id="line4406" class="codeline ">{
</span><span id="line4407" class="codeline ">   return (x &amp; 0xFFFFFFFF) * (y &amp; 0xFFFFFFFF);
</span><span id="line4408" class="codeline ">}
</span><span id="line4409" class="codeline ">#elif defined(_MSC_VER) &amp;&amp; defined(_M_IX86)
</span><span id="line4410" class="codeline ">#    define XXH_mult32to64(x, y) __emulu((unsigned)(x), (unsigned)(y))
</span><span id="line4411" class="codeline ">#else
</span><span id="line4412" class="codeline ">/*
</span><span id="line4413" class="codeline "> * Downcast + upcast is usually better than masking on older compilers like
</span><span id="line4414" class="codeline "> * GCC 4.2 (especially 32-bit ones), all without affecting newer compilers.
</span><span id="line4415" class="codeline "> *
</span><span id="line4416" class="codeline "> * The other method, (x &amp; 0xFFFFFFFF) * (y &amp; 0xFFFFFFFF), will AND both operands
</span><span id="line4417" class="codeline "> * and perform a full 64x64 multiply -- entirely redundant on 32-bit.
</span><span id="line4418" class="codeline "> */
</span><span id="line4419" class="codeline ">#    define XXH_mult32to64(x, y) ((xxh_u64)(xxh_u32)(x) * (xxh_u64)(xxh_u32)(y))
</span><span id="line4420" class="codeline ">#endif
</span><span id="line4421" class="codeline ">
</span><span id="line4422" class="codeline ">/*!
</span><span id="line4423" class="codeline "> * @brief Calculates a 64-&gt;128-bit long multiply.
</span><span id="line4424" class="codeline "> *
</span><span id="line4425" class="codeline "> * Uses `__uint128_t` and `_umul128` if available, otherwise uses a scalar
</span><span id="line4426" class="codeline "> * version.
</span><span id="line4427" class="codeline "> *
</span><span id="line4428" class="codeline "> * @param lhs , rhs The 64-bit integers to be multiplied
</span><span id="line4429" class="codeline "> * @return The 128-bit result represented in an @ref XXH128_hash_t.
</span><span id="line4430" class="codeline "> */
</span><span id="line4431" class="codeline ">static XXH128_hash_t
</span><span id="line4432" class="codeline ">XXH_mult64to128(xxh_u64 lhs, xxh_u64 rhs)
</span><span id="line4433" class="codeline ">{
</span><span id="line4434" class="codeline ">    /*
</span><span id="line4435" class="codeline ">     * GCC/Clang __uint128_t method.
</span><span id="line4436" class="codeline ">     *
</span><span id="line4437" class="codeline ">     * On most 64-bit targets, GCC and Clang define a __uint128_t type.
</span><span id="line4438" class="codeline ">     * This is usually the best way as it usually uses a native long 64-bit
</span><span id="line4439" class="codeline ">     * multiply, such as MULQ on x86_64 or MUL + UMULH on aarch64.
</span><span id="line4440" class="codeline ">     *
</span><span id="line4441" class="codeline ">     * Usually.
</span><span id="line4442" class="codeline ">     *
</span><span id="line4443" class="codeline ">     * Despite being a 32-bit platform, Clang (and emscripten) define this type
</span><span id="line4444" class="codeline ">     * despite not having the arithmetic for it. This results in a laggy
</span><span id="line4445" class="codeline ">     * compiler builtin call which calculates a full 128-bit multiply.
</span><span id="line4446" class="codeline ">     * In that case it is best to use the portable one.
</span><span id="line4447" class="codeline ">     * https://github.com/Cyan4973/xxHash/issues/211#issuecomment-515575677
</span><span id="line4448" class="codeline ">     */
</span><span id="line4449" class="codeline ">#if (defined(__GNUC__) || defined(__clang__)) &amp;&amp; !defined(__wasm__) \
</span><span id="line4450" class="codeline ">    &amp;&amp; defined(__SIZEOF_INT128__) \
</span><span id="line4451" class="codeline ">    || (defined(_INTEGRAL_MAX_BITS) &amp;&amp; _INTEGRAL_MAX_BITS &gt;= 128)
</span><span id="line4452" class="codeline ">
</span><span id="line4453" class="codeline ">    __uint128_t const product = (__uint128_t)lhs * (__uint128_t)rhs;
</span><span id="line4454" class="codeline ">    XXH128_hash_t r128;
</span><span id="line4455" class="codeline ">    r128.low64  = (xxh_u64)(product);
</span><span id="line4456" class="codeline ">    r128.high64 = (xxh_u64)(product &gt;&gt; 64);
</span><span id="line4457" class="codeline ">    return r128;
</span><span id="line4458" class="codeline ">
</span><span id="line4459" class="codeline ">    /*
</span><span id="line4460" class="codeline ">     * MSVC for x64&#39;s _umul128 method.
</span><span id="line4461" class="codeline ">     *
</span><span id="line4462" class="codeline ">     * xxh_u64 _umul128(xxh_u64 Multiplier, xxh_u64 Multiplicand, xxh_u64 *HighProduct);
</span><span id="line4463" class="codeline ">     *
</span><span id="line4464" class="codeline ">     * This compiles to single operand MUL on x64.
</span><span id="line4465" class="codeline ">     */
</span><span id="line4466" class="codeline ">#elif (defined(_M_X64) || defined(_M_IA64)) &amp;&amp; !defined(_M_ARM64EC)
</span><span id="line4467" class="codeline ">
</span><span id="line4468" class="codeline ">#ifndef _MSC_VER
</span><span id="line4469" class="codeline ">#   pragma intrinsic(_umul128)
</span><span id="line4470" class="codeline ">#endif
</span><span id="line4471" class="codeline ">    xxh_u64 product_high;
</span><span id="line4472" class="codeline ">    xxh_u64 const product_low = _umul128(lhs, rhs, &amp;product_high);
</span><span id="line4473" class="codeline ">    XXH128_hash_t r128;
</span><span id="line4474" class="codeline ">    r128.low64  = product_low;
</span><span id="line4475" class="codeline ">    r128.high64 = product_high;
</span><span id="line4476" class="codeline ">    return r128;
</span><span id="line4477" class="codeline ">
</span><span id="line4478" class="codeline ">    /*
</span><span id="line4479" class="codeline ">     * MSVC for ARM64&#39;s __umulh method.
</span><span id="line4480" class="codeline ">     *
</span><span id="line4481" class="codeline ">     * This compiles to the same MUL + UMULH as GCC/Clang&#39;s __uint128_t method.
</span><span id="line4482" class="codeline ">     */
</span><span id="line4483" class="codeline ">#elif defined(_M_ARM64) || defined(_M_ARM64EC)
</span><span id="line4484" class="codeline ">
</span><span id="line4485" class="codeline ">#ifndef _MSC_VER
</span><span id="line4486" class="codeline ">#   pragma intrinsic(__umulh)
</span><span id="line4487" class="codeline ">#endif
</span><span id="line4488" class="codeline ">    XXH128_hash_t r128;
</span><span id="line4489" class="codeline ">    r128.low64  = lhs * rhs;
</span><span id="line4490" class="codeline ">    r128.high64 = __umulh(lhs, rhs);
</span><span id="line4491" class="codeline ">    return r128;
</span><span id="line4492" class="codeline ">
</span><span id="line4493" class="codeline ">#else
</span><span id="line4494" class="codeline ">    /*
</span><span id="line4495" class="codeline ">     * Portable scalar method. Optimized for 32-bit and 64-bit ALUs.
</span><span id="line4496" class="codeline ">     *
</span><span id="line4497" class="codeline ">     * This is a fast and simple grade school multiply, which is shown below
</span><span id="line4498" class="codeline ">     * with base 10 arithmetic instead of base 0x100000000.
</span><span id="line4499" class="codeline ">     *
</span><span id="line4500" class="codeline ">     *           9 3 // D2 lhs = 93
</span><span id="line4501" class="codeline ">     *         x 7 5 // D2 rhs = 75
</span><span id="line4502" class="codeline ">     *     ----------
</span><span id="line4503" class="codeline ">     *           1 5 // D2 lo_lo = (93 % 10) * (75 % 10) = 15
</span><span id="line4504" class="codeline ">     *         4 5 | // D2 hi_lo = (93 / 10) * (75 % 10) = 45
</span><span id="line4505" class="codeline ">     *         2 1 | // D2 lo_hi = (93 % 10) * (75 / 10) = 21
</span><span id="line4506" class="codeline ">     *     + 6 3 | | // D2 hi_hi = (93 / 10) * (75 / 10) = 63
</span><span id="line4507" class="codeline ">     *     ---------
</span><span id="line4508" class="codeline ">     *         2 7 | // D2 cross = (15 / 10) + (45 % 10) + 21 = 27
</span><span id="line4509" class="codeline ">     *     + 6 7 | | // D2 upper = (27 / 10) + (45 / 10) + 63 = 67
</span><span id="line4510" class="codeline ">     *     ---------
</span><span id="line4511" class="codeline ">     *       6 9 7 5 // D4 res = (27 * 10) + (15 % 10) + (67 * 100) = 6975
</span><span id="line4512" class="codeline ">     *
</span><span id="line4513" class="codeline ">     * The reasons for adding the products like this are:
</span><span id="line4514" class="codeline ">     *  1. It avoids manual carry tracking. Just like how
</span><span id="line4515" class="codeline ">     *     (9 * 9) + 9 + 9 = 99, the same applies with this for UINT64_MAX.
</span><span id="line4516" class="codeline ">     *     This avoids a lot of complexity.
</span><span id="line4517" class="codeline ">     *
</span><span id="line4518" class="codeline ">     *  2. It hints for, and on Clang, compiles to, the powerful UMAAL
</span><span id="line4519" class="codeline ">     *     instruction available in ARM&#39;s Digital Signal Processing extension
</span><span id="line4520" class="codeline ">     *     in 32-bit ARMv6 and later, which is shown below:
</span><span id="line4521" class="codeline ">     *
</span><span id="line4522" class="codeline ">     *         void UMAAL(xxh_u32 *RdLo, xxh_u32 *RdHi, xxh_u32 Rn, xxh_u32 Rm)
</span><span id="line4523" class="codeline ">     *         {
</span><span id="line4524" class="codeline ">     *             xxh_u64 product = (xxh_u64)*RdLo * (xxh_u64)*RdHi + Rn + Rm;
</span><span id="line4525" class="codeline ">     *             *RdLo = (xxh_u32)(product &amp; 0xFFFFFFFF);
</span><span id="line4526" class="codeline ">     *             *RdHi = (xxh_u32)(product &gt;&gt; 32);
</span><span id="line4527" class="codeline ">     *         }
</span><span id="line4528" class="codeline ">     *
</span><span id="line4529" class="codeline ">     *     This instruction was designed for efficient long multiplication, and
</span><span id="line4530" class="codeline ">     *     allows this to be calculated in only 4 instructions at speeds
</span><span id="line4531" class="codeline ">     *     comparable to some 64-bit ALUs.
</span><span id="line4532" class="codeline ">     *
</span><span id="line4533" class="codeline ">     *  3. It isn&#39;t terrible on other platforms. Usually this will be a couple
</span><span id="line4534" class="codeline ">     *     of 32-bit ADD/ADCs.
</span><span id="line4535" class="codeline ">     */
</span><span id="line4536" class="codeline ">
</span><span id="line4537" class="codeline ">    /* First calculate all of the cross products. */
</span><span id="line4538" class="codeline ">    xxh_u64 const lo_lo = XXH_mult32to64(lhs &amp; 0xFFFFFFFF, rhs &amp; 0xFFFFFFFF);
</span><span id="line4539" class="codeline ">    xxh_u64 const hi_lo = XXH_mult32to64(lhs &gt;&gt; 32,        rhs &amp; 0xFFFFFFFF);
</span><span id="line4540" class="codeline ">    xxh_u64 const lo_hi = XXH_mult32to64(lhs &amp; 0xFFFFFFFF, rhs &gt;&gt; 32);
</span><span id="line4541" class="codeline ">    xxh_u64 const hi_hi = XXH_mult32to64(lhs &gt;&gt; 32,        rhs &gt;&gt; 32);
</span><span id="line4542" class="codeline ">
</span><span id="line4543" class="codeline ">    /* Now add the products together. These will never overflow. */
</span><span id="line4544" class="codeline ">    xxh_u64 const cross = (lo_lo &gt;&gt; 32) + (hi_lo &amp; 0xFFFFFFFF) + lo_hi;
</span><span id="line4545" class="codeline ">    xxh_u64 const upper = (hi_lo &gt;&gt; 32) + (cross &gt;&gt; 32)        + hi_hi;
</span><span id="line4546" class="codeline ">    xxh_u64 const lower = (cross &lt;&lt; 32) | (lo_lo &amp; 0xFFFFFFFF);
</span><span id="line4547" class="codeline ">
</span><span id="line4548" class="codeline ">    XXH128_hash_t r128;
</span><span id="line4549" class="codeline ">    r128.low64  = lower;
</span><span id="line4550" class="codeline ">    r128.high64 = upper;
</span><span id="line4551" class="codeline ">    return r128;
</span><span id="line4552" class="codeline ">#endif
</span><span id="line4553" class="codeline ">}
</span><span id="line4554" class="codeline ">
</span><span id="line4555" class="codeline ">/*!
</span><span id="line4556" class="codeline "> * @brief Calculates a 64-bit to 128-bit multiply, then XOR folds it.
</span><span id="line4557" class="codeline "> *
</span><span id="line4558" class="codeline "> * The reason for the separate function is to prevent passing too many structs
</span><span id="line4559" class="codeline "> * around by value. This will hopefully inline the multiply, but we don&#39;t force it.
</span><span id="line4560" class="codeline "> *
</span><span id="line4561" class="codeline "> * @param lhs , rhs The 64-bit integers to multiply
</span><span id="line4562" class="codeline "> * @return The low 64 bits of the product XOR&#39;d by the high 64 bits.
</span><span id="line4563" class="codeline "> * @see XXH_mult64to128()
</span><span id="line4564" class="codeline "> */
</span><span id="line4565" class="codeline ">static xxh_u64
</span><span id="line4566" class="codeline ">XXH3_mul128_fold64(xxh_u64 lhs, xxh_u64 rhs)
</span><span id="line4567" class="codeline ">{
</span><span id="line4568" class="codeline ">    XXH128_hash_t product = XXH_mult64to128(lhs, rhs);
</span><span id="line4569" class="codeline ">    return product.low64 ^ product.high64;
</span><span id="line4570" class="codeline ">}
</span><span id="line4571" class="codeline ">
</span><span id="line4572" class="codeline ">/*! Seems to produce slightly better code on GCC for some reason. */
</span><span id="line4573" class="codeline ">XXH_FORCE_INLINE XXH_CONSTF xxh_u64 XXH_xorshift64(xxh_u64 v64, int shift)
</span><span id="line4574" class="codeline ">{
</span><span id="line4575" class="codeline ">    XXH_ASSERT(0 &lt;= shift &amp;&amp; shift &lt; 64);
</span><span id="line4576" class="codeline ">    return v64 ^ (v64 &gt;&gt; shift);
</span><span id="line4577" class="codeline ">}
</span><span id="line4578" class="codeline ">
</span><span id="line4579" class="codeline ">/*
</span><span id="line4580" class="codeline "> * This is a fast avalanche stage,
</span><span id="line4581" class="codeline "> * suitable when input bits are already partially mixed
</span><span id="line4582" class="codeline "> */
</span><span id="line4583" class="codeline ">static XXH64_hash_t XXH3_avalanche(xxh_u64 h64)
</span><span id="line4584" class="codeline ">{
</span><span id="line4585" class="codeline ">    h64 = XXH_xorshift64(h64, 37);
</span><span id="line4586" class="codeline ">    h64 *= PRIME_MX1;
</span><span id="line4587" class="codeline ">    h64 = XXH_xorshift64(h64, 32);
</span><span id="line4588" class="codeline ">    return h64;
</span><span id="line4589" class="codeline ">}
</span><span id="line4590" class="codeline ">
</span><span id="line4591" class="codeline ">/*
</span><span id="line4592" class="codeline "> * This is a stronger avalanche,
</span><span id="line4593" class="codeline "> * inspired by Pelle Evensen&#39;s rrmxmx
</span><span id="line4594" class="codeline "> * preferable when input has not been previously mixed
</span><span id="line4595" class="codeline "> */
</span><span id="line4596" class="codeline ">static XXH64_hash_t XXH3_rrmxmx(xxh_u64 h64, xxh_u64 len)
</span><span id="line4597" class="codeline ">{
</span><span id="line4598" class="codeline ">    /* this mix is inspired by Pelle Evensen&#39;s rrmxmx */
</span><span id="line4599" class="codeline ">    h64 ^= XXH_rotl64(h64, 49) ^ XXH_rotl64(h64, 24);
</span><span id="line4600" class="codeline ">    h64 *= PRIME_MX2;
</span><span id="line4601" class="codeline ">    h64 ^= (h64 &gt;&gt; 35) + len ;
</span><span id="line4602" class="codeline ">    h64 *= PRIME_MX2;
</span><span id="line4603" class="codeline ">    return XXH_xorshift64(h64, 28);
</span><span id="line4604" class="codeline ">}
</span><span id="line4605" class="codeline ">
</span><span id="line4606" class="codeline ">
</span><span id="line4607" class="codeline ">/* ==========================================
</span><span id="line4608" class="codeline "> * Short keys
</span><span id="line4609" class="codeline "> * ==========================================
</span><span id="line4610" class="codeline "> * One of the shortcomings of XXH32 and XXH64 was that their performance was
</span><span id="line4611" class="codeline "> * sub-optimal on short lengths. It used an iterative algorithm which strongly
</span><span id="line4612" class="codeline "> * favored lengths that were a multiple of 4 or 8.
</span><span id="line4613" class="codeline "> *
</span><span id="line4614" class="codeline "> * Instead of iterating over individual inputs, we use a set of single shot
</span><span id="line4615" class="codeline "> * functions which piece together a range of lengths and operate in constant time.
</span><span id="line4616" class="codeline "> *
</span><span id="line4617" class="codeline "> * Additionally, the number of multiplies has been significantly reduced. This
</span><span id="line4618" class="codeline "> * reduces latency, especially when emulating 64-bit multiplies on 32-bit.
</span><span id="line4619" class="codeline "> *
</span><span id="line4620" class="codeline "> * Depending on the platform, this may or may not be faster than XXH32, but it
</span><span id="line4621" class="codeline "> * is almost guaranteed to be faster than XXH64.
</span><span id="line4622" class="codeline "> */
</span><span id="line4623" class="codeline ">
</span><span id="line4624" class="codeline ">/*
</span><span id="line4625" class="codeline "> * At very short lengths, there isn&#39;t enough input to fully hide secrets, or use
</span><span id="line4626" class="codeline "> * the entire secret.
</span><span id="line4627" class="codeline "> *
</span><span id="line4628" class="codeline "> * There is also only a limited amount of mixing we can do before significantly
</span><span id="line4629" class="codeline "> * impacting performance.
</span><span id="line4630" class="codeline "> *
</span><span id="line4631" class="codeline "> * Therefore, we use different sections of the secret and always mix two secret
</span><span id="line4632" class="codeline "> * samples with an XOR. This should have no effect on performance on the
</span><span id="line4633" class="codeline "> * seedless or withSeed variants because everything _should_ be constant folded
</span><span id="line4634" class="codeline "> * by modern compilers.
</span><span id="line4635" class="codeline "> *
</span><span id="line4636" class="codeline "> * The XOR mixing hides individual parts of the secret and increases entropy.
</span><span id="line4637" class="codeline "> *
</span><span id="line4638" class="codeline "> * This adds an extra layer of strength for custom secrets.
</span><span id="line4639" class="codeline "> */
</span><span id="line4640" class="codeline ">XXH_FORCE_INLINE XXH_PUREF XXH64_hash_t
</span><span id="line4641" class="codeline ">XXH3_len_1to3_64b(const xxh_u8* input, size_t len, const xxh_u8* secret, XXH64_hash_t seed)
</span><span id="line4642" class="codeline ">{
</span><span id="line4643" class="codeline ">    XXH_ASSERT(input != NULL);
</span><span id="line4644" class="codeline ">    XXH_ASSERT(1 &lt;= len &amp;&amp; len &lt;= 3);
</span><span id="line4645" class="codeline ">    XXH_ASSERT(secret != NULL);
</span><span id="line4646" class="codeline ">    /*
</span><span id="line4647" class="codeline ">     * len = 1: combined = { input[0], 0x01, input[0], input[0] }
</span><span id="line4648" class="codeline ">     * len = 2: combined = { input[1], 0x02, input[0], input[1] }
</span><span id="line4649" class="codeline ">     * len = 3: combined = { input[2], 0x03, input[0], input[1] }
</span><span id="line4650" class="codeline ">     */
</span><span id="line4651" class="codeline ">    {   xxh_u8  const c1 = input[0];
</span><span id="line4652" class="codeline ">        xxh_u8  const c2 = input[len &gt;&gt; 1];
</span><span id="line4653" class="codeline ">        xxh_u8  const c3 = input[len - 1];
</span><span id="line4654" class="codeline ">        xxh_u32 const combined = ((xxh_u32)c1 &lt;&lt; 16) | ((xxh_u32)c2  &lt;&lt; 24)
</span><span id="line4655" class="codeline ">                               | ((xxh_u32)c3 &lt;&lt;  0) | ((xxh_u32)len &lt;&lt; 8);
</span><span id="line4656" class="codeline ">        xxh_u64 const bitflip = (XXH_readLE32(secret) ^ XXH_readLE32(secret+4)) + seed;
</span><span id="line4657" class="codeline ">        xxh_u64 const keyed = (xxh_u64)combined ^ bitflip;
</span><span id="line4658" class="codeline ">        return XXH64_avalanche(keyed);
</span><span id="line4659" class="codeline ">    }
</span><span id="line4660" class="codeline ">}
</span><span id="line4661" class="codeline ">
</span><span id="line4662" class="codeline ">XXH_FORCE_INLINE XXH_PUREF XXH64_hash_t
</span><span id="line4663" class="codeline ">XXH3_len_4to8_64b(const xxh_u8* input, size_t len, const xxh_u8* secret, XXH64_hash_t seed)
</span><span id="line4664" class="codeline ">{
</span><span id="line4665" class="codeline ">    XXH_ASSERT(input != NULL);
</span><span id="line4666" class="codeline ">    XXH_ASSERT(secret != NULL);
</span><span id="line4667" class="codeline ">    XXH_ASSERT(4 &lt;= len &amp;&amp; len &lt;= 8);
</span><span id="line4668" class="codeline ">    seed ^= (xxh_u64)XXH_swap32((xxh_u32)seed) &lt;&lt; 32;
</span><span id="line4669" class="codeline ">    {   xxh_u32 const input1 = XXH_readLE32(input);
</span><span id="line4670" class="codeline ">        xxh_u32 const input2 = XXH_readLE32(input + len - 4);
</span><span id="line4671" class="codeline ">        xxh_u64 const bitflip = (XXH_readLE64(secret+8) ^ XXH_readLE64(secret+16)) - seed;
</span><span id="line4672" class="codeline ">        xxh_u64 const input64 = input2 + (((xxh_u64)input1) &lt;&lt; 32);
</span><span id="line4673" class="codeline ">        xxh_u64 const keyed = input64 ^ bitflip;
</span><span id="line4674" class="codeline ">        return XXH3_rrmxmx(keyed, len);
</span><span id="line4675" class="codeline ">    }
</span><span id="line4676" class="codeline ">}
</span><span id="line4677" class="codeline ">
</span><span id="line4678" class="codeline ">XXH_FORCE_INLINE XXH_PUREF XXH64_hash_t
</span><span id="line4679" class="codeline ">XXH3_len_9to16_64b(const xxh_u8* input, size_t len, const xxh_u8* secret, XXH64_hash_t seed)
</span><span id="line4680" class="codeline ">{
</span><span id="line4681" class="codeline ">    XXH_ASSERT(input != NULL);
</span><span id="line4682" class="codeline ">    XXH_ASSERT(secret != NULL);
</span><span id="line4683" class="codeline ">    XXH_ASSERT(9 &lt;= len &amp;&amp; len &lt;= 16);
</span><span id="line4684" class="codeline ">    {   xxh_u64 const bitflip1 = (XXH_readLE64(secret+24) ^ XXH_readLE64(secret+32)) + seed;
</span><span id="line4685" class="codeline ">        xxh_u64 const bitflip2 = (XXH_readLE64(secret+40) ^ XXH_readLE64(secret+48)) - seed;
</span><span id="line4686" class="codeline ">        xxh_u64 const input_lo = XXH_readLE64(input)           ^ bitflip1;
</span><span id="line4687" class="codeline ">        xxh_u64 const input_hi = XXH_readLE64(input + len - 8) ^ bitflip2;
</span><span id="line4688" class="codeline ">        xxh_u64 const acc = len
</span><span id="line4689" class="codeline ">                          + XXH_swap64(input_lo) + input_hi
</span><span id="line4690" class="codeline ">                          + XXH3_mul128_fold64(input_lo, input_hi);
</span><span id="line4691" class="codeline ">        return XXH3_avalanche(acc);
</span><span id="line4692" class="codeline ">    }
</span><span id="line4693" class="codeline ">}
</span><span id="line4694" class="codeline ">
</span><span id="line4695" class="codeline ">XXH_FORCE_INLINE XXH_PUREF XXH64_hash_t
</span><span id="line4696" class="codeline ">XXH3_len_0to16_64b(const xxh_u8* input, size_t len, const xxh_u8* secret, XXH64_hash_t seed)
</span><span id="line4697" class="codeline ">{
</span><span id="line4698" class="codeline ">    XXH_ASSERT(len &lt;= 16);
</span><span id="line4699" class="codeline ">    {   if (XXH_likely(len &gt;  8)) return XXH3_len_9to16_64b(input, len, secret, seed);
</span><span id="line4700" class="codeline ">        if (XXH_likely(len &gt;= 4)) return XXH3_len_4to8_64b(input, len, secret, seed);
</span><span id="line4701" class="codeline ">        if (len) return XXH3_len_1to3_64b(input, len, secret, seed);
</span><span id="line4702" class="codeline ">        return XXH64_avalanche(seed ^ (XXH_readLE64(secret+56) ^ XXH_readLE64(secret+64)));
</span><span id="line4703" class="codeline ">    }
</span><span id="line4704" class="codeline ">}
</span><span id="line4705" class="codeline ">
</span><span id="line4706" class="codeline ">/*
</span><span id="line4707" class="codeline "> * DISCLAIMER: There are known *seed-dependent* multicollisions here due to
</span><span id="line4708" class="codeline "> * multiplication by zero, affecting hashes of lengths 17 to 240.
</span><span id="line4709" class="codeline "> *
</span><span id="line4710" class="codeline "> * However, they are very unlikely.
</span><span id="line4711" class="codeline "> *
</span><span id="line4712" class="codeline "> * Keep this in mind when using the unseeded XXH3_64bits() variant: As with all
</span><span id="line4713" class="codeline "> * unseeded non-cryptographic hashes, it does not attempt to defend itself
</span><span id="line4714" class="codeline "> * against specially crafted inputs, only random inputs.
</span><span id="line4715" class="codeline "> *
</span><span id="line4716" class="codeline "> * Compared to classic UMAC where a 1 in 2^31 chance of 4 consecutive bytes
</span><span id="line4717" class="codeline "> * cancelling out the secret is taken an arbitrary number of times (addressed
</span><span id="line4718" class="codeline "> * in XXH3_accumulate_512), this collision is very unlikely with random inputs
</span><span id="line4719" class="codeline "> * and/or proper seeding:
</span><span id="line4720" class="codeline "> *
</span><span id="line4721" class="codeline "> * This only has a 1 in 2^63 chance of 8 consecutive bytes cancelling out, in a
</span><span id="line4722" class="codeline "> * function that is only called up to 16 times per hash with up to 240 bytes of
</span><span id="line4723" class="codeline "> * input.
</span><span id="line4724" class="codeline "> *
</span><span id="line4725" class="codeline "> * This is not too bad for a non-cryptographic hash function, especially with
</span><span id="line4726" class="codeline "> * only 64 bit outputs.
</span><span id="line4727" class="codeline "> *
</span><span id="line4728" class="codeline "> * The 128-bit variant (which trades some speed for strength) is NOT affected
</span><span id="line4729" class="codeline "> * by this, although it is always a good idea to use a proper seed if you care
</span><span id="line4730" class="codeline "> * about strength.
</span><span id="line4731" class="codeline "> */
</span><span id="line4732" class="codeline ">XXH_FORCE_INLINE xxh_u64 XXH3_mix16B(const xxh_u8* XXH_RESTRICT input,
</span><span id="line4733" class="codeline ">                                     const xxh_u8* XXH_RESTRICT secret, xxh_u64 seed64)
</span><span id="line4734" class="codeline ">{
</span><span id="line4735" class="codeline ">#if defined(__GNUC__) &amp;&amp; !defined(__clang__) /* GCC, not Clang */ \
</span><span id="line4736" class="codeline ">  &amp;&amp; defined(__i386__) &amp;&amp; defined(__SSE2__)  /* x86 + SSE2 */ \
</span><span id="line4737" class="codeline ">  &amp;&amp; !defined(XXH_ENABLE_AUTOVECTORIZE)      /* Define to disable like XXH32 hack */
</span><span id="line4738" class="codeline ">    /*
</span><span id="line4739" class="codeline ">     * UGLY HACK:
</span><span id="line4740" class="codeline ">     * GCC for x86 tends to autovectorize the 128-bit multiply, resulting in
</span><span id="line4741" class="codeline ">     * slower code.
</span><span id="line4742" class="codeline ">     *
</span><span id="line4743" class="codeline ">     * By forcing seed64 into a register, we disrupt the cost model and
</span><span id="line4744" class="codeline ">     * cause it to scalarize. See `XXH32_round()`
</span><span id="line4745" class="codeline ">     *
</span><span id="line4746" class="codeline ">     * FIXME: Clang&#39;s output is still _much_ faster -- On an AMD Ryzen 3600,
</span><span id="line4747" class="codeline ">     * XXH3_64bits @ len=240 runs at 4.6 GB/s with Clang 9, but 3.3 GB/s on
</span><span id="line4748" class="codeline ">     * GCC 9.2, despite both emitting scalar code.
</span><span id="line4749" class="codeline ">     *
</span><span id="line4750" class="codeline ">     * GCC generates much better scalar code than Clang for the rest of XXH3,
</span><span id="line4751" class="codeline ">     * which is why finding a more optimal codepath is an interest.
</span><span id="line4752" class="codeline ">     */
</span><span id="line4753" class="codeline ">    XXH_COMPILER_GUARD(seed64);
</span><span id="line4754" class="codeline ">#endif
</span><span id="line4755" class="codeline ">    {   xxh_u64 const input_lo = XXH_readLE64(input);
</span><span id="line4756" class="codeline ">        xxh_u64 const input_hi = XXH_readLE64(input+8);
</span><span id="line4757" class="codeline ">        return XXH3_mul128_fold64(
</span><span id="line4758" class="codeline ">            input_lo ^ (XXH_readLE64(secret)   + seed64),
</span><span id="line4759" class="codeline ">            input_hi ^ (XXH_readLE64(secret+8) - seed64)
</span><span id="line4760" class="codeline ">        );
</span><span id="line4761" class="codeline ">    }
</span><span id="line4762" class="codeline ">}
</span><span id="line4763" class="codeline ">
</span><span id="line4764" class="codeline ">/* For mid range keys, XXH3 uses a Mum-hash variant. */
</span><span id="line4765" class="codeline ">XXH_FORCE_INLINE XXH_PUREF XXH64_hash_t
</span><span id="line4766" class="codeline ">XXH3_len_17to128_64b(const xxh_u8* XXH_RESTRICT input, size_t len,
</span><span id="line4767" class="codeline ">                     const xxh_u8* XXH_RESTRICT secret, size_t secretSize,
</span><span id="line4768" class="codeline ">                     XXH64_hash_t seed)
</span><span id="line4769" class="codeline ">{
</span><span id="line4770" class="codeline ">    XXH_ASSERT(secretSize &gt;= XXH3_SECRET_SIZE_MIN); (void)secretSize;
</span><span id="line4771" class="codeline ">    XXH_ASSERT(16 &lt; len &amp;&amp; len &lt;= 128);
</span><span id="line4772" class="codeline ">
</span><span id="line4773" class="codeline ">    {   xxh_u64 acc = len * XXH_PRIME64_1;
</span><span id="line4774" class="codeline ">#if XXH_SIZE_OPT &gt;= 1
</span><span id="line4775" class="codeline ">        /* Smaller and cleaner, but slightly slower. */
</span><span id="line4776" class="codeline ">        unsigned int i = (unsigned int)(len - 1) / 32;
</span><span id="line4777" class="codeline ">        do {
</span><span id="line4778" class="codeline ">            acc += XXH3_mix16B(input+16 * i, secret+32*i, seed);
</span><span id="line4779" class="codeline ">            acc += XXH3_mix16B(input+len-16*(i+1), secret+32*i+16, seed);
</span><span id="line4780" class="codeline ">        } while (i-- != 0);
</span><span id="line4781" class="codeline ">#else
</span><span id="line4782" class="codeline ">        if (len &gt; 32) {
</span><span id="line4783" class="codeline ">            if (len &gt; 64) {
</span><span id="line4784" class="codeline ">                if (len &gt; 96) {
</span><span id="line4785" class="codeline ">                    acc += XXH3_mix16B(input+48, secret+96, seed);
</span><span id="line4786" class="codeline ">                    acc += XXH3_mix16B(input+len-64, secret+112, seed);
</span><span id="line4787" class="codeline ">                }
</span><span id="line4788" class="codeline ">                acc += XXH3_mix16B(input+32, secret+64, seed);
</span><span id="line4789" class="codeline ">                acc += XXH3_mix16B(input+len-48, secret+80, seed);
</span><span id="line4790" class="codeline ">            }
</span><span id="line4791" class="codeline ">            acc += XXH3_mix16B(input+16, secret+32, seed);
</span><span id="line4792" class="codeline ">            acc += XXH3_mix16B(input+len-32, secret+48, seed);
</span><span id="line4793" class="codeline ">        }
</span><span id="line4794" class="codeline ">        acc += XXH3_mix16B(input+0, secret+0, seed);
</span><span id="line4795" class="codeline ">        acc += XXH3_mix16B(input+len-16, secret+16, seed);
</span><span id="line4796" class="codeline ">#endif
</span><span id="line4797" class="codeline ">        return XXH3_avalanche(acc);
</span><span id="line4798" class="codeline ">    }
</span><span id="line4799" class="codeline ">}
</span><span id="line4800" class="codeline ">
</span><span id="line4801" class="codeline ">XXH_NO_INLINE XXH_PUREF XXH64_hash_t
</span><span id="line4802" class="codeline ">XXH3_len_129to240_64b(const xxh_u8* XXH_RESTRICT input, size_t len,
</span><span id="line4803" class="codeline ">                      const xxh_u8* XXH_RESTRICT secret, size_t secretSize,
</span><span id="line4804" class="codeline ">                      XXH64_hash_t seed)
</span><span id="line4805" class="codeline ">{
</span><span id="line4806" class="codeline ">    XXH_ASSERT(secretSize &gt;= XXH3_SECRET_SIZE_MIN); (void)secretSize;
</span><span id="line4807" class="codeline ">    XXH_ASSERT(128 &lt; len &amp;&amp; len &lt;= XXH3_MIDSIZE_MAX);
</span><span id="line4808" class="codeline ">
</span><span id="line4809" class="codeline ">    #define XXH3_MIDSIZE_STARTOFFSET 3
</span><span id="line4810" class="codeline ">    #define XXH3_MIDSIZE_LASTOFFSET  17
</span><span id="line4811" class="codeline ">
</span><span id="line4812" class="codeline ">    {   xxh_u64 acc = len * XXH_PRIME64_1;
</span><span id="line4813" class="codeline ">        xxh_u64 acc_end;
</span><span id="line4814" class="codeline ">        unsigned int const nbRounds = (unsigned int)len / 16;
</span><span id="line4815" class="codeline ">        unsigned int i;
</span><span id="line4816" class="codeline ">        XXH_ASSERT(128 &lt; len &amp;&amp; len &lt;= XXH3_MIDSIZE_MAX);
</span><span id="line4817" class="codeline ">        for (i=0; i&lt;8; i++) {
</span><span id="line4818" class="codeline ">            acc += XXH3_mix16B(input+(16*i), secret+(16*i), seed);
</span><span id="line4819" class="codeline ">        }
</span><span id="line4820" class="codeline ">        /* last bytes */
</span><span id="line4821" class="codeline ">        acc_end = XXH3_mix16B(input + len - 16, secret + XXH3_SECRET_SIZE_MIN - XXH3_MIDSIZE_LASTOFFSET, seed);
</span><span id="line4822" class="codeline ">        XXH_ASSERT(nbRounds &gt;= 8);
</span><span id="line4823" class="codeline ">        acc = XXH3_avalanche(acc);
</span><span id="line4824" class="codeline ">#if defined(__clang__)                                /* Clang */ \
</span><span id="line4825" class="codeline ">    &amp;&amp; (defined(__ARM_NEON) || defined(__ARM_NEON__)) /* NEON */ \
</span><span id="line4826" class="codeline ">    &amp;&amp; !defined(XXH_ENABLE_AUTOVECTORIZE)             /* Define to disable */
</span><span id="line4827" class="codeline ">        /*
</span><span id="line4828" class="codeline ">         * UGLY HACK:
</span><span id="line4829" class="codeline ">         * Clang for ARMv7-A tries to vectorize this loop, similar to GCC x86.
</span><span id="line4830" class="codeline ">         * In everywhere else, it uses scalar code.
</span><span id="line4831" class="codeline ">         *
</span><span id="line4832" class="codeline ">         * For 64-&gt;128-bit multiplies, even if the NEON was 100% optimal, it
</span><span id="line4833" class="codeline ">         * would still be slower than UMAAL (see XXH_mult64to128).
</span><span id="line4834" class="codeline ">         *
</span><span id="line4835" class="codeline ">         * Unfortunately, Clang doesn&#39;t handle the long multiplies properly and
</span><span id="line4836" class="codeline ">         * converts them to the nonexistent &#34;vmulq_u64&#34; intrinsic, which is then
</span><span id="line4837" class="codeline ">         * scalarized into an ugly mess of VMOV.32 instructions.
</span><span id="line4838" class="codeline ">         *
</span><span id="line4839" class="codeline ">         * This mess is difficult to avoid without turning autovectorization
</span><span id="line4840" class="codeline ">         * off completely, but they are usually relatively minor and/or not
</span><span id="line4841" class="codeline ">         * worth it to fix.
</span><span id="line4842" class="codeline ">         *
</span><span id="line4843" class="codeline ">         * This loop is the easiest to fix, as unlike XXH32, this pragma
</span><span id="line4844" class="codeline ">         * _actually works_ because it is a loop vectorization instead of an
</span><span id="line4845" class="codeline ">         * SLP vectorization.
</span><span id="line4846" class="codeline ">         */
</span><span id="line4847" class="codeline ">        #pragma clang loop vectorize(disable)
</span><span id="line4848" class="codeline ">#endif
</span><span id="line4849" class="codeline ">        for (i=8 ; i &lt; nbRounds; i++) {
</span><span id="line4850" class="codeline ">            /*
</span><span id="line4851" class="codeline ">             * Prevents clang for unrolling the acc loop and interleaving with this one.
</span><span id="line4852" class="codeline ">             */
</span><span id="line4853" class="codeline ">            XXH_COMPILER_GUARD(acc);
</span><span id="line4854" class="codeline ">            acc_end += XXH3_mix16B(input+(16*i), secret+(16*(i-8)) + XXH3_MIDSIZE_STARTOFFSET, seed);
</span><span id="line4855" class="codeline ">        }
</span><span id="line4856" class="codeline ">        return XXH3_avalanche(acc + acc_end);
</span><span id="line4857" class="codeline ">    }
</span><span id="line4858" class="codeline ">}
</span><span id="line4859" class="codeline ">
</span><span id="line4860" class="codeline ">
</span><span id="line4861" class="codeline ">/* =======     Long Keys     ======= */
</span><span id="line4862" class="codeline ">
</span><span id="line4863" class="codeline ">#define XXH_STRIPE_LEN 64
</span><span id="line4864" class="codeline ">#define XXH_SECRET_CONSUME_RATE 8   /* nb of secret bytes consumed at each accumulation */
</span><span id="line4865" class="codeline ">#define XXH_ACC_NB (XXH_STRIPE_LEN / sizeof(xxh_u64))
</span><span id="line4866" class="codeline ">
</span><span id="line4867" class="codeline ">#ifdef XXH_OLD_NAMES
</span><span id="line4868" class="codeline ">#  define STRIPE_LEN XXH_STRIPE_LEN
</span><span id="line4869" class="codeline ">#  define ACC_NB XXH_ACC_NB
</span><span id="line4870" class="codeline ">#endif
</span><span id="line4871" class="codeline ">
</span><span id="line4872" class="codeline ">#ifndef XXH_PREFETCH_DIST
</span><span id="line4873" class="codeline ">#  ifdef __clang__
</span><span id="line4874" class="codeline ">#    define XXH_PREFETCH_DIST 320
</span><span id="line4875" class="codeline ">#  else
</span><span id="line4876" class="codeline ">#    if (XXH_VECTOR == XXH_AVX512)
</span><span id="line4877" class="codeline ">#      define XXH_PREFETCH_DIST 512
</span><span id="line4878" class="codeline ">#    else
</span><span id="line4879" class="codeline ">#      define XXH_PREFETCH_DIST 384
</span><span id="line4880" class="codeline ">#    endif
</span><span id="line4881" class="codeline ">#  endif  /* __clang__ */
</span><span id="line4882" class="codeline ">#endif  /* XXH_PREFETCH_DIST */
</span><span id="line4883" class="codeline ">
</span><span id="line4884" class="codeline ">/*
</span><span id="line4885" class="codeline "> * These macros are to generate an XXH3_accumulate() function.
</span><span id="line4886" class="codeline "> * The two arguments select the name suffix and target attribute.
</span><span id="line4887" class="codeline "> *
</span><span id="line4888" class="codeline "> * The name of this symbol is XXH3_accumulate_&lt;name&gt;() and it calls
</span><span id="line4889" class="codeline "> * XXH3_accumulate_512_&lt;name&gt;().
</span><span id="line4890" class="codeline "> *
</span><span id="line4891" class="codeline "> * It may be useful to hand implement this function if the compiler fails to
</span><span id="line4892" class="codeline "> * optimize the inline function.
</span><span id="line4893" class="codeline "> */
</span><span id="line4894" class="codeline ">#define XXH3_ACCUMULATE_TEMPLATE(name)                      \
</span><span id="line4895" class="codeline ">void                                                        \
</span><span id="line4896" class="codeline ">XXH3_accumulate_##name(xxh_u64* XXH_RESTRICT acc,           \
</span><span id="line4897" class="codeline ">                       const xxh_u8* XXH_RESTRICT input,    \
</span><span id="line4898" class="codeline ">                       const xxh_u8* XXH_RESTRICT secret,   \
</span><span id="line4899" class="codeline ">                       size_t nbStripes)                    \
</span><span id="line4900" class="codeline ">{                                                           \
</span><span id="line4901" class="codeline ">    size_t n;                                               \
</span><span id="line4902" class="codeline ">    for (n = 0; n &lt; nbStripes; n++ ) {                      \
</span><span id="line4903" class="codeline ">        const xxh_u8* const in = input + n*XXH_STRIPE_LEN;  \
</span><span id="line4904" class="codeline ">        XXH_PREFETCH(in + XXH_PREFETCH_DIST);               \
</span><span id="line4905" class="codeline ">        XXH3_accumulate_512_##name(                         \
</span><span id="line4906" class="codeline ">                 acc,                                       \
</span><span id="line4907" class="codeline ">                 in,                                        \
</span><span id="line4908" class="codeline ">                 secret + n*XXH_SECRET_CONSUME_RATE);       \
</span><span id="line4909" class="codeline ">    }                                                       \
</span><span id="line4910" class="codeline ">}
</span><span id="line4911" class="codeline ">
</span><span id="line4912" class="codeline ">
</span><span id="line4913" class="codeline ">XXH_FORCE_INLINE void XXH_writeLE64(void* dst, xxh_u64 v64)
</span><span id="line4914" class="codeline ">{
</span><span id="line4915" class="codeline ">    if (!XXH_CPU_LITTLE_ENDIAN) v64 = XXH_swap64(v64);
</span><span id="line4916" class="codeline ">    XXH_memcpy(dst, &amp;v64, sizeof(v64));
</span><span id="line4917" class="codeline ">}
</span><span id="line4918" class="codeline ">
</span><span id="line4919" class="codeline ">/* Several intrinsic functions below are supposed to accept __int64 as argument,
</span><span id="line4920" class="codeline "> * as documented in https://software.intel.com/sites/landingpage/IntrinsicsGuide/ .
</span><span id="line4921" class="codeline "> * However, several environments do not define __int64 type,
</span><span id="line4922" class="codeline "> * requiring a workaround.
</span><span id="line4923" class="codeline "> */
</span><span id="line4924" class="codeline ">#if !defined (__VMS) \
</span><span id="line4925" class="codeline ">  &amp;&amp; (defined (__cplusplus) \
</span><span id="line4926" class="codeline ">  || (defined (__STDC_VERSION__) &amp;&amp; (__STDC_VERSION__ &gt;= 199901L) /* C99 */) )
</span><span id="line4927" class="codeline ">    typedef int64_t xxh_i64;
</span><span id="line4928" class="codeline ">#else
</span><span id="line4929" class="codeline ">    /* the following type must have a width of 64-bit */
</span><span id="line4930" class="codeline ">    typedef long long xxh_i64;
</span><span id="line4931" class="codeline ">#endif
</span><span id="line4932" class="codeline ">
</span><span id="line4933" class="codeline ">
</span><span id="line4934" class="codeline ">/*
</span><span id="line4935" class="codeline "> * XXH3_accumulate_512 is the tightest loop for long inputs, and it is the most optimized.
</span><span id="line4936" class="codeline "> *
</span><span id="line4937" class="codeline "> * It is a hardened version of UMAC, based off of FARSH&#39;s implementation.
</span><span id="line4938" class="codeline "> *
</span><span id="line4939" class="codeline "> * This was chosen because it adapts quite well to 32-bit, 64-bit, and SIMD
</span><span id="line4940" class="codeline "> * implementations, and it is ridiculously fast.
</span><span id="line4941" class="codeline "> *
</span><span id="line4942" class="codeline "> * We harden it by mixing the original input to the accumulators as well as the product.
</span><span id="line4943" class="codeline "> *
</span><span id="line4944" class="codeline "> * This means that in the (relatively likely) case of a multiply by zero, the
</span><span id="line4945" class="codeline "> * original input is preserved.
</span><span id="line4946" class="codeline "> *
</span><span id="line4947" class="codeline "> * On 128-bit inputs, we swap 64-bit pairs when we add the input to improve
</span><span id="line4948" class="codeline "> * cross-pollination, as otherwise the upper and lower halves would be
</span><span id="line4949" class="codeline "> * essentially independent.
</span><span id="line4950" class="codeline "> *
</span><span id="line4951" class="codeline "> * This doesn&#39;t matter on 64-bit hashes since they all get merged together in
</span><span id="line4952" class="codeline "> * the end, so we skip the extra step.
</span><span id="line4953" class="codeline "> *
</span><span id="line4954" class="codeline "> * Both XXH3_64bits and XXH3_128bits use this subroutine.
</span><span id="line4955" class="codeline "> */
</span><span id="line4956" class="codeline ">
</span><span id="line4957" class="codeline ">#if (XXH_VECTOR == XXH_AVX512) \
</span><span id="line4958" class="codeline ">     || (defined(XXH_DISPATCH_AVX512) &amp;&amp; XXH_DISPATCH_AVX512 != 0)
</span><span id="line4959" class="codeline ">
</span><span id="line4960" class="codeline ">#ifndef XXH_TARGET_AVX512
</span><span id="line4961" class="codeline "># define XXH_TARGET_AVX512  /* disable attribute target */
</span><span id="line4962" class="codeline ">#endif
</span><span id="line4963" class="codeline ">
</span><span id="line4964" class="codeline ">XXH_FORCE_INLINE XXH_TARGET_AVX512 void
</span><span id="line4965" class="codeline ">XXH3_accumulate_512_avx512(void* XXH_RESTRICT acc,
</span><span id="line4966" class="codeline ">                     const void* XXH_RESTRICT input,
</span><span id="line4967" class="codeline ">                     const void* XXH_RESTRICT secret)
</span><span id="line4968" class="codeline ">{
</span><span id="line4969" class="codeline ">    __m512i* const xacc = (__m512i *) acc;
</span><span id="line4970" class="codeline ">    XXH_ASSERT((((size_t)acc) &amp; 63) == 0);
</span><span id="line4971" class="codeline ">    XXH_STATIC_ASSERT(XXH_STRIPE_LEN == sizeof(__m512i));
</span><span id="line4972" class="codeline ">
</span><span id="line4973" class="codeline ">    {
</span><span id="line4974" class="codeline ">        /* data_vec    = input[0]; */
</span><span id="line4975" class="codeline ">        __m512i const data_vec    = _mm512_loadu_si512   (input);
</span><span id="line4976" class="codeline ">        /* key_vec     = secret[0]; */
</span><span id="line4977" class="codeline ">        __m512i const key_vec     = _mm512_loadu_si512   (secret);
</span><span id="line4978" class="codeline ">        /* data_key    = data_vec ^ key_vec; */
</span><span id="line4979" class="codeline ">        __m512i const data_key    = _mm512_xor_si512     (data_vec, key_vec);
</span><span id="line4980" class="codeline ">        /* data_key_lo = data_key &gt;&gt; 32; */
</span><span id="line4981" class="codeline ">        __m512i const data_key_lo = _mm512_srli_epi64 (data_key, 32);
</span><span id="line4982" class="codeline ">        /* product     = (data_key &amp; 0xffffffff) * (data_key_lo &amp; 0xffffffff); */
</span><span id="line4983" class="codeline ">        __m512i const product     = _mm512_mul_epu32     (data_key, data_key_lo);
</span><span id="line4984" class="codeline ">        /* xacc[0] += swap(data_vec); */
</span><span id="line4985" class="codeline ">        __m512i const data_swap = _mm512_shuffle_epi32(data_vec, (_MM_PERM_ENUM)_MM_SHUFFLE(1, 0, 3, 2));
</span><span id="line4986" class="codeline ">        __m512i const sum       = _mm512_add_epi64(*xacc, data_swap);
</span><span id="line4987" class="codeline ">        /* xacc[0] += product; */
</span><span id="line4988" class="codeline ">        *xacc = _mm512_add_epi64(product, sum);
</span><span id="line4989" class="codeline ">    }
</span><span id="line4990" class="codeline ">}
</span><span id="line4991" class="codeline ">XXH_FORCE_INLINE XXH_TARGET_AVX512 XXH3_ACCUMULATE_TEMPLATE(avx512)
</span><span id="line4992" class="codeline ">
</span><span id="line4993" class="codeline ">/*
</span><span id="line4994" class="codeline "> * XXH3_scrambleAcc: Scrambles the accumulators to improve mixing.
</span><span id="line4995" class="codeline "> *
</span><span id="line4996" class="codeline "> * Multiplication isn&#39;t perfect, as explained by Google in HighwayHash:
</span><span id="line4997" class="codeline "> *
</span><span id="line4998" class="codeline "> *  // Multiplication mixes/scrambles bytes 0-7 of the 64-bit result to
</span><span id="line4999" class="codeline "> *  // varying degrees. In descending order of goodness, bytes
</span><span id="line5000" class="codeline "> *  // 3 4 2 5 1 6 0 7 have quality 228 224 164 160 100 96 36 32.
</span><span id="line5001" class="codeline "> *  // As expected, the upper and lower bytes are much worse.
</span><span id="line5002" class="codeline "> *
</span><span id="line5003" class="codeline "> * Source: https://github.com/google/highwayhash/blob/0aaf66b/highwayhash/hh_avx2.h#L291
</span><span id="line5004" class="codeline "> *
</span><span id="line5005" class="codeline "> * Since our algorithm uses a pseudorandom secret to add some variance into the
</span><span id="line5006" class="codeline "> * mix, we don&#39;t need to (or want to) mix as often or as much as HighwayHash does.
</span><span id="line5007" class="codeline "> *
</span><span id="line5008" class="codeline "> * This isn&#39;t as tight as XXH3_accumulate, but still written in SIMD to avoid
</span><span id="line5009" class="codeline "> * extraction.
</span><span id="line5010" class="codeline "> *
</span><span id="line5011" class="codeline "> * Both XXH3_64bits and XXH3_128bits use this subroutine.
</span><span id="line5012" class="codeline "> */
</span><span id="line5013" class="codeline ">
</span><span id="line5014" class="codeline ">XXH_FORCE_INLINE XXH_TARGET_AVX512 void
</span><span id="line5015" class="codeline ">XXH3_scrambleAcc_avx512(void* XXH_RESTRICT acc, const void* XXH_RESTRICT secret)
</span><span id="line5016" class="codeline ">{
</span><span id="line5017" class="codeline ">    XXH_ASSERT((((size_t)acc) &amp; 63) == 0);
</span><span id="line5018" class="codeline ">    XXH_STATIC_ASSERT(XXH_STRIPE_LEN == sizeof(__m512i));
</span><span id="line5019" class="codeline ">    {   __m512i* const xacc = (__m512i*) acc;
</span><span id="line5020" class="codeline ">        const __m512i prime32 = _mm512_set1_epi32((int)XXH_PRIME32_1);
</span><span id="line5021" class="codeline ">
</span><span id="line5022" class="codeline ">        /* xacc[0] ^= (xacc[0] &gt;&gt; 47) */
</span><span id="line5023" class="codeline ">        __m512i const acc_vec     = *xacc;
</span><span id="line5024" class="codeline ">        __m512i const shifted     = _mm512_srli_epi64    (acc_vec, 47);
</span><span id="line5025" class="codeline ">        /* xacc[0] ^= secret; */
</span><span id="line5026" class="codeline ">        __m512i const key_vec     = _mm512_loadu_si512   (secret);
</span><span id="line5027" class="codeline ">        __m512i const data_key    = _mm512_ternarylogic_epi32(key_vec, acc_vec, shifted, 0x96 /* key_vec ^ acc_vec ^ shifted */);
</span><span id="line5028" class="codeline ">
</span><span id="line5029" class="codeline ">        /* xacc[0] *= XXH_PRIME32_1; */
</span><span id="line5030" class="codeline ">        __m512i const data_key_hi = _mm512_srli_epi64 (data_key, 32);
</span><span id="line5031" class="codeline ">        __m512i const prod_lo     = _mm512_mul_epu32     (data_key, prime32);
</span><span id="line5032" class="codeline ">        __m512i const prod_hi     = _mm512_mul_epu32     (data_key_hi, prime32);
</span><span id="line5033" class="codeline ">        *xacc = _mm512_add_epi64(prod_lo, _mm512_slli_epi64(prod_hi, 32));
</span><span id="line5034" class="codeline ">    }
</span><span id="line5035" class="codeline ">}
</span><span id="line5036" class="codeline ">
</span><span id="line5037" class="codeline ">XXH_FORCE_INLINE XXH_TARGET_AVX512 void
</span><span id="line5038" class="codeline ">XXH3_initCustomSecret_avx512(void* XXH_RESTRICT customSecret, xxh_u64 seed64)
</span><span id="line5039" class="codeline ">{
</span><span id="line5040" class="codeline ">    XXH_STATIC_ASSERT((XXH_SECRET_DEFAULT_SIZE &amp; 63) == 0);
</span><span id="line5041" class="codeline ">    XXH_STATIC_ASSERT(XXH_SEC_ALIGN == 64);
</span><span id="line5042" class="codeline ">    XXH_ASSERT(((size_t)customSecret &amp; 63) == 0);
</span><span id="line5043" class="codeline ">    (void)(&amp;XXH_writeLE64);
</span><span id="line5044" class="codeline ">    {   int const nbRounds = XXH_SECRET_DEFAULT_SIZE / sizeof(__m512i);
</span><span id="line5045" class="codeline ">        __m512i const seed_pos = _mm512_set1_epi64((xxh_i64)seed64);
</span><span id="line5046" class="codeline ">        __m512i const seed     = _mm512_mask_sub_epi64(seed_pos, 0xAA, _mm512_set1_epi8(0), seed_pos);
</span><span id="line5047" class="codeline ">
</span><span id="line5048" class="codeline ">        const __m512i* const src  = (const __m512i*) ((const void*) XXH3_kSecret);
</span><span id="line5049" class="codeline ">              __m512i* const dest = (      __m512i*) customSecret;
</span><span id="line5050" class="codeline ">        int i;
</span><span id="line5051" class="codeline ">        XXH_ASSERT(((size_t)src &amp; 63) == 0); /* control alignment */
</span><span id="line5052" class="codeline ">        XXH_ASSERT(((size_t)dest &amp; 63) == 0);
</span><span id="line5053" class="codeline ">        for (i=0; i &lt; nbRounds; ++i) {
</span><span id="line5054" class="codeline ">            dest[i] = _mm512_add_epi64(_mm512_load_si512(src + i), seed);
</span><span id="line5055" class="codeline ">    }   }
</span><span id="line5056" class="codeline ">}
</span><span id="line5057" class="codeline ">
</span><span id="line5058" class="codeline ">#endif
</span><span id="line5059" class="codeline ">
</span><span id="line5060" class="codeline ">#if (XXH_VECTOR == XXH_AVX2) \
</span><span id="line5061" class="codeline ">    || (defined(XXH_DISPATCH_AVX2) &amp;&amp; XXH_DISPATCH_AVX2 != 0)
</span><span id="line5062" class="codeline ">
</span><span id="line5063" class="codeline ">#ifndef XXH_TARGET_AVX2
</span><span id="line5064" class="codeline "># define XXH_TARGET_AVX2  /* disable attribute target */
</span><span id="line5065" class="codeline ">#endif
</span><span id="line5066" class="codeline ">
</span><span id="line5067" class="codeline ">XXH_FORCE_INLINE XXH_TARGET_AVX2 void
</span><span id="line5068" class="codeline ">XXH3_accumulate_512_avx2( void* XXH_RESTRICT acc,
</span><span id="line5069" class="codeline ">                    const void* XXH_RESTRICT input,
</span><span id="line5070" class="codeline ">                    const void* XXH_RESTRICT secret)
</span><span id="line5071" class="codeline ">{
</span><span id="line5072" class="codeline ">    XXH_ASSERT((((size_t)acc) &amp; 31) == 0);
</span><span id="line5073" class="codeline ">    {   __m256i* const xacc    =       (__m256i *) acc;
</span><span id="line5074" class="codeline ">        /* Unaligned. This is mainly for pointer arithmetic, and because
</span><span id="line5075" class="codeline ">         * _mm256_loadu_si256 requires  a const __m256i * pointer for some reason. */
</span><span id="line5076" class="codeline ">        const         __m256i* const xinput  = (const __m256i *) input;
</span><span id="line5077" class="codeline ">        /* Unaligned. This is mainly for pointer arithmetic, and because
</span><span id="line5078" class="codeline ">         * _mm256_loadu_si256 requires a const __m256i * pointer for some reason. */
</span><span id="line5079" class="codeline ">        const         __m256i* const xsecret = (const __m256i *) secret;
</span><span id="line5080" class="codeline ">
</span><span id="line5081" class="codeline ">        size_t i;
</span><span id="line5082" class="codeline ">        for (i=0; i &lt; XXH_STRIPE_LEN/sizeof(__m256i); i++) {
</span><span id="line5083" class="codeline ">            /* data_vec    = xinput[i]; */
</span><span id="line5084" class="codeline ">            __m256i const data_vec    = _mm256_loadu_si256    (xinput+i);
</span><span id="line5085" class="codeline ">            /* key_vec     = xsecret[i]; */
</span><span id="line5086" class="codeline ">            __m256i const key_vec     = _mm256_loadu_si256   (xsecret+i);
</span><span id="line5087" class="codeline ">            /* data_key    = data_vec ^ key_vec; */
</span><span id="line5088" class="codeline ">            __m256i const data_key    = _mm256_xor_si256     (data_vec, key_vec);
</span><span id="line5089" class="codeline ">            /* data_key_lo = data_key &gt;&gt; 32; */
</span><span id="line5090" class="codeline ">            __m256i const data_key_lo = _mm256_srli_epi64 (data_key, 32);
</span><span id="line5091" class="codeline ">            /* product     = (data_key &amp; 0xffffffff) * (data_key_lo &amp; 0xffffffff); */
</span><span id="line5092" class="codeline ">            __m256i const product     = _mm256_mul_epu32     (data_key, data_key_lo);
</span><span id="line5093" class="codeline ">            /* xacc[i] += swap(data_vec); */
</span><span id="line5094" class="codeline ">            __m256i const data_swap = _mm256_shuffle_epi32(data_vec, _MM_SHUFFLE(1, 0, 3, 2));
</span><span id="line5095" class="codeline ">            __m256i const sum       = _mm256_add_epi64(xacc[i], data_swap);
</span><span id="line5096" class="codeline ">            /* xacc[i] += product; */
</span><span id="line5097" class="codeline ">            xacc[i] = _mm256_add_epi64(product, sum);
</span><span id="line5098" class="codeline ">    }   }
</span><span id="line5099" class="codeline ">}
</span><span id="line5100" class="codeline ">XXH_FORCE_INLINE XXH_TARGET_AVX2 XXH3_ACCUMULATE_TEMPLATE(avx2)
</span><span id="line5101" class="codeline ">
</span><span id="line5102" class="codeline ">XXH_FORCE_INLINE XXH_TARGET_AVX2 void
</span><span id="line5103" class="codeline ">XXH3_scrambleAcc_avx2(void* XXH_RESTRICT acc, const void* XXH_RESTRICT secret)
</span><span id="line5104" class="codeline ">{
</span><span id="line5105" class="codeline ">    XXH_ASSERT((((size_t)acc) &amp; 31) == 0);
</span><span id="line5106" class="codeline ">    {   __m256i* const xacc = (__m256i*) acc;
</span><span id="line5107" class="codeline ">        /* Unaligned. This is mainly for pointer arithmetic, and because
</span><span id="line5108" class="codeline ">         * _mm256_loadu_si256 requires a const __m256i * pointer for some reason. */
</span><span id="line5109" class="codeline ">        const         __m256i* const xsecret = (const __m256i *) secret;
</span><span id="line5110" class="codeline ">        const __m256i prime32 = _mm256_set1_epi32((int)XXH_PRIME32_1);
</span><span id="line5111" class="codeline ">
</span><span id="line5112" class="codeline ">        size_t i;
</span><span id="line5113" class="codeline ">        for (i=0; i &lt; XXH_STRIPE_LEN/sizeof(__m256i); i++) {
</span><span id="line5114" class="codeline ">            /* xacc[i] ^= (xacc[i] &gt;&gt; 47) */
</span><span id="line5115" class="codeline ">            __m256i const acc_vec     = xacc[i];
</span><span id="line5116" class="codeline ">            __m256i const shifted     = _mm256_srli_epi64    (acc_vec, 47);
</span><span id="line5117" class="codeline ">            __m256i const data_vec    = _mm256_xor_si256     (acc_vec, shifted);
</span><span id="line5118" class="codeline ">            /* xacc[i] ^= xsecret; */
</span><span id="line5119" class="codeline ">            __m256i const key_vec     = _mm256_loadu_si256   (xsecret+i);
</span><span id="line5120" class="codeline ">            __m256i const data_key    = _mm256_xor_si256     (data_vec, key_vec);
</span><span id="line5121" class="codeline ">
</span><span id="line5122" class="codeline ">            /* xacc[i] *= XXH_PRIME32_1; */
</span><span id="line5123" class="codeline ">            __m256i const data_key_hi = _mm256_srli_epi64 (data_key, 32);
</span><span id="line5124" class="codeline ">            __m256i const prod_lo     = _mm256_mul_epu32     (data_key, prime32);
</span><span id="line5125" class="codeline ">            __m256i const prod_hi     = _mm256_mul_epu32     (data_key_hi, prime32);
</span><span id="line5126" class="codeline ">            xacc[i] = _mm256_add_epi64(prod_lo, _mm256_slli_epi64(prod_hi, 32));
</span><span id="line5127" class="codeline ">        }
</span><span id="line5128" class="codeline ">    }
</span><span id="line5129" class="codeline ">}
</span><span id="line5130" class="codeline ">
</span><span id="line5131" class="codeline ">XXH_FORCE_INLINE XXH_TARGET_AVX2 void XXH3_initCustomSecret_avx2(void* XXH_RESTRICT customSecret, xxh_u64 seed64)
</span><span id="line5132" class="codeline ">{
</span><span id="line5133" class="codeline ">    XXH_STATIC_ASSERT((XXH_SECRET_DEFAULT_SIZE &amp; 31) == 0);
</span><span id="line5134" class="codeline ">    XXH_STATIC_ASSERT((XXH_SECRET_DEFAULT_SIZE / sizeof(__m256i)) == 6);
</span><span id="line5135" class="codeline ">    XXH_STATIC_ASSERT(XXH_SEC_ALIGN &lt;= 64);
</span><span id="line5136" class="codeline ">    (void)(&amp;XXH_writeLE64);
</span><span id="line5137" class="codeline ">    XXH_PREFETCH(customSecret);
</span><span id="line5138" class="codeline ">    {   __m256i const seed = _mm256_set_epi64x((xxh_i64)(0U - seed64), (xxh_i64)seed64, (xxh_i64)(0U - seed64), (xxh_i64)seed64);
</span><span id="line5139" class="codeline ">
</span><span id="line5140" class="codeline ">        const __m256i* const src  = (const __m256i*) ((const void*) XXH3_kSecret);
</span><span id="line5141" class="codeline ">              __m256i*       dest = (      __m256i*) customSecret;
</span><span id="line5142" class="codeline ">
</span><span id="line5143" class="codeline ">#       if defined(__GNUC__) || defined(__clang__)
</span><span id="line5144" class="codeline ">        /*
</span><span id="line5145" class="codeline ">         * On GCC &amp; Clang, marking &#39;dest&#39; as modified will cause the compiler:
</span><span id="line5146" class="codeline ">         *   - do not extract the secret from sse registers in the internal loop
</span><span id="line5147" class="codeline ">         *   - use less common registers, and avoid pushing these reg into stack
</span><span id="line5148" class="codeline ">         */
</span><span id="line5149" class="codeline ">        XXH_COMPILER_GUARD(dest);
</span><span id="line5150" class="codeline ">#       endif
</span><span id="line5151" class="codeline ">        XXH_ASSERT(((size_t)src &amp; 31) == 0); /* control alignment */
</span><span id="line5152" class="codeline ">        XXH_ASSERT(((size_t)dest &amp; 31) == 0);
</span><span id="line5153" class="codeline ">
</span><span id="line5154" class="codeline ">        /* GCC -O2 need unroll loop manually */
</span><span id="line5155" class="codeline ">        dest[0] = _mm256_add_epi64(_mm256_load_si256(src+0), seed);
</span><span id="line5156" class="codeline ">        dest[1] = _mm256_add_epi64(_mm256_load_si256(src+1), seed);
</span><span id="line5157" class="codeline ">        dest[2] = _mm256_add_epi64(_mm256_load_si256(src+2), seed);
</span><span id="line5158" class="codeline ">        dest[3] = _mm256_add_epi64(_mm256_load_si256(src+3), seed);
</span><span id="line5159" class="codeline ">        dest[4] = _mm256_add_epi64(_mm256_load_si256(src+4), seed);
</span><span id="line5160" class="codeline ">        dest[5] = _mm256_add_epi64(_mm256_load_si256(src+5), seed);
</span><span id="line5161" class="codeline ">    }
</span><span id="line5162" class="codeline ">}
</span><span id="line5163" class="codeline ">
</span><span id="line5164" class="codeline ">#endif
</span><span id="line5165" class="codeline ">
</span><span id="line5166" class="codeline ">/* x86dispatch always generates SSE2 */
</span><span id="line5167" class="codeline ">#if (XXH_VECTOR == XXH_SSE2) || defined(XXH_X86DISPATCH)
</span><span id="line5168" class="codeline ">
</span><span id="line5169" class="codeline ">#ifndef XXH_TARGET_SSE2
</span><span id="line5170" class="codeline "># define XXH_TARGET_SSE2  /* disable attribute target */
</span><span id="line5171" class="codeline ">#endif
</span><span id="line5172" class="codeline ">
</span><span id="line5173" class="codeline ">XXH_FORCE_INLINE XXH_TARGET_SSE2 void
</span><span id="line5174" class="codeline ">XXH3_accumulate_512_sse2( void* XXH_RESTRICT acc,
</span><span id="line5175" class="codeline ">                    const void* XXH_RESTRICT input,
</span><span id="line5176" class="codeline ">                    const void* XXH_RESTRICT secret)
</span><span id="line5177" class="codeline ">{
</span><span id="line5178" class="codeline ">    /* SSE2 is just a half-scale version of the AVX2 version. */
</span><span id="line5179" class="codeline ">    XXH_ASSERT((((size_t)acc) &amp; 15) == 0);
</span><span id="line5180" class="codeline ">    {   __m128i* const xacc    =       (__m128i *) acc;
</span><span id="line5181" class="codeline ">        /* Unaligned. This is mainly for pointer arithmetic, and because
</span><span id="line5182" class="codeline ">         * _mm_loadu_si128 requires a const __m128i * pointer for some reason. */
</span><span id="line5183" class="codeline ">        const         __m128i* const xinput  = (const __m128i *) input;
</span><span id="line5184" class="codeline ">        /* Unaligned. This is mainly for pointer arithmetic, and because
</span><span id="line5185" class="codeline ">         * _mm_loadu_si128 requires a const __m128i * pointer for some reason. */
</span><span id="line5186" class="codeline ">        const         __m128i* const xsecret = (const __m128i *) secret;
</span><span id="line5187" class="codeline ">
</span><span id="line5188" class="codeline ">        size_t i;
</span><span id="line5189" class="codeline ">        for (i=0; i &lt; XXH_STRIPE_LEN/sizeof(__m128i); i++) {
</span><span id="line5190" class="codeline ">            /* data_vec    = xinput[i]; */
</span><span id="line5191" class="codeline ">            __m128i const data_vec    = _mm_loadu_si128   (xinput+i);
</span><span id="line5192" class="codeline ">            /* key_vec     = xsecret[i]; */
</span><span id="line5193" class="codeline ">            __m128i const key_vec     = _mm_loadu_si128   (xsecret+i);
</span><span id="line5194" class="codeline ">            /* data_key    = data_vec ^ key_vec; */
</span><span id="line5195" class="codeline ">            __m128i const data_key    = _mm_xor_si128     (data_vec, key_vec);
</span><span id="line5196" class="codeline ">            /* data_key_lo = data_key &gt;&gt; 32; */
</span><span id="line5197" class="codeline ">            __m128i const data_key_lo = _mm_shuffle_epi32 (data_key, _MM_SHUFFLE(0, 3, 0, 1));
</span><span id="line5198" class="codeline ">            /* product     = (data_key &amp; 0xffffffff) * (data_key_lo &amp; 0xffffffff); */
</span><span id="line5199" class="codeline ">            __m128i const product     = _mm_mul_epu32     (data_key, data_key_lo);
</span><span id="line5200" class="codeline ">            /* xacc[i] += swap(data_vec); */
</span><span id="line5201" class="codeline ">            __m128i const data_swap = _mm_shuffle_epi32(data_vec, _MM_SHUFFLE(1,0,3,2));
</span><span id="line5202" class="codeline ">            __m128i const sum       = _mm_add_epi64(xacc[i], data_swap);
</span><span id="line5203" class="codeline ">            /* xacc[i] += product; */
</span><span id="line5204" class="codeline ">            xacc[i] = _mm_add_epi64(product, sum);
</span><span id="line5205" class="codeline ">    }   }
</span><span id="line5206" class="codeline ">}
</span><span id="line5207" class="codeline ">XXH_FORCE_INLINE XXH_TARGET_SSE2 XXH3_ACCUMULATE_TEMPLATE(sse2)
</span><span id="line5208" class="codeline ">
</span><span id="line5209" class="codeline ">XXH_FORCE_INLINE XXH_TARGET_SSE2 void
</span><span id="line5210" class="codeline ">XXH3_scrambleAcc_sse2(void* XXH_RESTRICT acc, const void* XXH_RESTRICT secret)
</span><span id="line5211" class="codeline ">{
</span><span id="line5212" class="codeline ">    XXH_ASSERT((((size_t)acc) &amp; 15) == 0);
</span><span id="line5213" class="codeline ">    {   __m128i* const xacc = (__m128i*) acc;
</span><span id="line5214" class="codeline ">        /* Unaligned. This is mainly for pointer arithmetic, and because
</span><span id="line5215" class="codeline ">         * _mm_loadu_si128 requires a const __m128i * pointer for some reason. */
</span><span id="line5216" class="codeline ">        const         __m128i* const xsecret = (const __m128i *) secret;
</span><span id="line5217" class="codeline ">        const __m128i prime32 = _mm_set1_epi32((int)XXH_PRIME32_1);
</span><span id="line5218" class="codeline ">
</span><span id="line5219" class="codeline ">        size_t i;
</span><span id="line5220" class="codeline ">        for (i=0; i &lt; XXH_STRIPE_LEN/sizeof(__m128i); i++) {
</span><span id="line5221" class="codeline ">            /* xacc[i] ^= (xacc[i] &gt;&gt; 47) */
</span><span id="line5222" class="codeline ">            __m128i const acc_vec     = xacc[i];
</span><span id="line5223" class="codeline ">            __m128i const shifted     = _mm_srli_epi64    (acc_vec, 47);
</span><span id="line5224" class="codeline ">            __m128i const data_vec    = _mm_xor_si128     (acc_vec, shifted);
</span><span id="line5225" class="codeline ">            /* xacc[i] ^= xsecret[i]; */
</span><span id="line5226" class="codeline ">            __m128i const key_vec     = _mm_loadu_si128   (xsecret+i);
</span><span id="line5227" class="codeline ">            __m128i const data_key    = _mm_xor_si128     (data_vec, key_vec);
</span><span id="line5228" class="codeline ">
</span><span id="line5229" class="codeline ">            /* xacc[i] *= XXH_PRIME32_1; */
</span><span id="line5230" class="codeline ">            __m128i const data_key_hi = _mm_shuffle_epi32 (data_key, _MM_SHUFFLE(0, 3, 0, 1));
</span><span id="line5231" class="codeline ">            __m128i const prod_lo     = _mm_mul_epu32     (data_key, prime32);
</span><span id="line5232" class="codeline ">            __m128i const prod_hi     = _mm_mul_epu32     (data_key_hi, prime32);
</span><span id="line5233" class="codeline ">            xacc[i] = _mm_add_epi64(prod_lo, _mm_slli_epi64(prod_hi, 32));
</span><span id="line5234" class="codeline ">        }
</span><span id="line5235" class="codeline ">    }
</span><span id="line5236" class="codeline ">}
</span><span id="line5237" class="codeline ">
</span><span id="line5238" class="codeline ">XXH_FORCE_INLINE XXH_TARGET_SSE2 void XXH3_initCustomSecret_sse2(void* XXH_RESTRICT customSecret, xxh_u64 seed64)
</span><span id="line5239" class="codeline ">{
</span><span id="line5240" class="codeline ">    XXH_STATIC_ASSERT((XXH_SECRET_DEFAULT_SIZE &amp; 15) == 0);
</span><span id="line5241" class="codeline ">    (void)(&amp;XXH_writeLE64);
</span><span id="line5242" class="codeline ">    {   int const nbRounds = XXH_SECRET_DEFAULT_SIZE / sizeof(__m128i);
</span><span id="line5243" class="codeline ">
</span><span id="line5244" class="codeline ">#       if defined(_MSC_VER) &amp;&amp; defined(_M_IX86) &amp;&amp; _MSC_VER &lt; 1900
</span><span id="line5245" class="codeline ">        /* MSVC 32bit mode does not support _mm_set_epi64x before 2015 */
</span><span id="line5246" class="codeline ">        XXH_ALIGN(16) const xxh_i64 seed64x2[2] = { (xxh_i64)seed64, (xxh_i64)(0U - seed64) };
</span><span id="line5247" class="codeline ">        __m128i const seed = _mm_load_si128((__m128i const*)seed64x2);
</span><span id="line5248" class="codeline ">#       else
</span><span id="line5249" class="codeline ">        __m128i const seed = _mm_set_epi64x((xxh_i64)(0U - seed64), (xxh_i64)seed64);
</span><span id="line5250" class="codeline ">#       endif
</span><span id="line5251" class="codeline ">        int i;
</span><span id="line5252" class="codeline ">
</span><span id="line5253" class="codeline ">        const void* const src16 = XXH3_kSecret;
</span><span id="line5254" class="codeline ">        __m128i* dst16 = (__m128i*) customSecret;
</span><span id="line5255" class="codeline ">#       if defined(__GNUC__) || defined(__clang__)
</span><span id="line5256" class="codeline ">        /*
</span><span id="line5257" class="codeline ">         * On GCC &amp; Clang, marking &#39;dest&#39; as modified will cause the compiler:
</span><span id="line5258" class="codeline ">         *   - do not extract the secret from sse registers in the internal loop
</span><span id="line5259" class="codeline ">         *   - use less common registers, and avoid pushing these reg into stack
</span><span id="line5260" class="codeline ">         */
</span><span id="line5261" class="codeline ">        XXH_COMPILER_GUARD(dst16);
</span><span id="line5262" class="codeline ">#       endif
</span><span id="line5263" class="codeline ">        XXH_ASSERT(((size_t)src16 &amp; 15) == 0); /* control alignment */
</span><span id="line5264" class="codeline ">        XXH_ASSERT(((size_t)dst16 &amp; 15) == 0);
</span><span id="line5265" class="codeline ">
</span><span id="line5266" class="codeline ">        for (i=0; i &lt; nbRounds; ++i) {
</span><span id="line5267" class="codeline ">            dst16[i] = _mm_add_epi64(_mm_load_si128((const __m128i *)src16+i), seed);
</span><span id="line5268" class="codeline ">    }   }
</span><span id="line5269" class="codeline ">}
</span><span id="line5270" class="codeline ">
</span><span id="line5271" class="codeline ">#endif
</span><span id="line5272" class="codeline ">
</span><span id="line5273" class="codeline ">#if (XXH_VECTOR == XXH_NEON)
</span><span id="line5274" class="codeline ">
</span><span id="line5275" class="codeline ">/* forward declarations for the scalar routines */
</span><span id="line5276" class="codeline ">XXH_FORCE_INLINE void
</span><span id="line5277" class="codeline ">XXH3_scalarRound(void* XXH_RESTRICT acc, void const* XXH_RESTRICT input,
</span><span id="line5278" class="codeline ">                 void const* XXH_RESTRICT secret, size_t lane);
</span><span id="line5279" class="codeline ">
</span><span id="line5280" class="codeline ">XXH_FORCE_INLINE void
</span><span id="line5281" class="codeline ">XXH3_scalarScrambleRound(void* XXH_RESTRICT acc,
</span><span id="line5282" class="codeline ">                         void const* XXH_RESTRICT secret, size_t lane);
</span><span id="line5283" class="codeline ">
</span><span id="line5284" class="codeline ">/*!
</span><span id="line5285" class="codeline "> * @internal
</span><span id="line5286" class="codeline "> * @brief The bulk processing loop for NEON and WASM SIMD128.
</span><span id="line5287" class="codeline "> *
</span><span id="line5288" class="codeline "> * The NEON code path is actually partially scalar when running on AArch64. This
</span><span id="line5289" class="codeline "> * is to optimize the pipelining and can have up to 15% speedup depending on the
</span><span id="line5290" class="codeline "> * CPU, and it also mitigates some GCC codegen issues.
</span><span id="line5291" class="codeline "> *
</span><span id="line5292" class="codeline "> * @see XXH3_NEON_LANES for configuring this and details about this optimization.
</span><span id="line5293" class="codeline "> *
</span><span id="line5294" class="codeline "> * NEON&#39;s 32-bit to 64-bit long multiply takes a half vector of 32-bit
</span><span id="line5295" class="codeline "> * integers instead of the other platforms which mask full 64-bit vectors,
</span><span id="line5296" class="codeline "> * so the setup is more complicated than just shifting right.
</span><span id="line5297" class="codeline "> *
</span><span id="line5298" class="codeline "> * Additionally, there is an optimization for 4 lanes at once noted below.
</span><span id="line5299" class="codeline "> *
</span><span id="line5300" class="codeline "> * Since, as stated, the most optimal amount of lanes for Cortexes is 6,
</span><span id="line5301" class="codeline "> * there needs to be *three* versions of the accumulate operation used
</span><span id="line5302" class="codeline "> * for the remaining 2 lanes.
</span><span id="line5303" class="codeline "> *
</span><span id="line5304" class="codeline "> * WASM&#39;s SIMD128 uses SIMDe&#39;s arm_neon.h polyfill because the intrinsics overlap
</span><span id="line5305" class="codeline "> * nearly perfectly.
</span><span id="line5306" class="codeline "> */
</span><span id="line5307" class="codeline ">
</span><span id="line5308" class="codeline ">XXH_FORCE_INLINE void
</span><span id="line5309" class="codeline ">XXH3_accumulate_512_neon( void* XXH_RESTRICT acc,
</span><span id="line5310" class="codeline ">                    const void* XXH_RESTRICT input,
</span><span id="line5311" class="codeline ">                    const void* XXH_RESTRICT secret)
</span><span id="line5312" class="codeline ">{
</span><span id="line5313" class="codeline ">    XXH_ASSERT((((size_t)acc) &amp; 15) == 0);
</span><span id="line5314" class="codeline ">    XXH_STATIC_ASSERT(XXH3_NEON_LANES &gt; 0 &amp;&amp; XXH3_NEON_LANES &lt;= XXH_ACC_NB &amp;&amp; XXH3_NEON_LANES % 2 == 0);
</span><span id="line5315" class="codeline ">    {   /* GCC for darwin arm64 does not like aliasing here */
</span><span id="line5316" class="codeline ">        xxh_aliasing_uint64x2_t* const xacc = (xxh_aliasing_uint64x2_t*) acc;
</span><span id="line5317" class="codeline ">        /* We don&#39;t use a uint32x4_t pointer because it causes bus errors on ARMv7. */
</span><span id="line5318" class="codeline ">        uint8_t const* xinput = (const uint8_t *) input;
</span><span id="line5319" class="codeline ">        uint8_t const* xsecret  = (const uint8_t *) secret;
</span><span id="line5320" class="codeline ">
</span><span id="line5321" class="codeline ">        size_t i;
</span><span id="line5322" class="codeline ">#ifdef __wasm_simd128__
</span><span id="line5323" class="codeline ">        /*
</span><span id="line5324" class="codeline ">         * On WASM SIMD128, Clang emits direct address loads when XXH3_kSecret
</span><span id="line5325" class="codeline ">         * is constant propagated, which results in it converting it to this
</span><span id="line5326" class="codeline ">         * inside the loop:
</span><span id="line5327" class="codeline ">         *
</span><span id="line5328" class="codeline ">         *    a = v128.load(XXH3_kSecret +  0 + $secret_offset, offset = 0)
</span><span id="line5329" class="codeline ">         *    b = v128.load(XXH3_kSecret + 16 + $secret_offset, offset = 0)
</span><span id="line5330" class="codeline ">         *    ...
</span><span id="line5331" class="codeline ">         *
</span><span id="line5332" class="codeline ">         * This requires a full 32-bit address immediate (and therefore a 6 byte
</span><span id="line5333" class="codeline ">         * instruction) as well as an add for each offset.
</span><span id="line5334" class="codeline ">         *
</span><span id="line5335" class="codeline ">         * Putting an asm guard prevents it from folding (at the cost of losing
</span><span id="line5336" class="codeline ">         * the alignment hint), and uses the free offset in `v128.load` instead
</span><span id="line5337" class="codeline ">         * of adding secret_offset each time which overall reduces code size by
</span><span id="line5338" class="codeline ">         * about a kilobyte and improves performance.
</span><span id="line5339" class="codeline ">         */
</span><span id="line5340" class="codeline ">        XXH_COMPILER_GUARD(xsecret);
</span><span id="line5341" class="codeline ">#endif
</span><span id="line5342" class="codeline ">        /* Scalar lanes use the normal scalarRound routine */
</span><span id="line5343" class="codeline ">        for (i = XXH3_NEON_LANES; i &lt; XXH_ACC_NB; i++) {
</span><span id="line5344" class="codeline ">            XXH3_scalarRound(acc, input, secret, i);
</span><span id="line5345" class="codeline ">        }
</span><span id="line5346" class="codeline ">        i = 0;
</span><span id="line5347" class="codeline ">        /* 4 NEON lanes at a time. */
</span><span id="line5348" class="codeline ">        for (; i+1 &lt; XXH3_NEON_LANES / 2; i+=2) {
</span><span id="line5349" class="codeline ">            /* data_vec = xinput[i]; */
</span><span id="line5350" class="codeline ">            uint64x2_t data_vec_1 = XXH_vld1q_u64(xinput  + (i * 16));
</span><span id="line5351" class="codeline ">            uint64x2_t data_vec_2 = XXH_vld1q_u64(xinput  + ((i+1) * 16));
</span><span id="line5352" class="codeline ">            /* key_vec  = xsecret[i];  */
</span><span id="line5353" class="codeline ">            uint64x2_t key_vec_1  = XXH_vld1q_u64(xsecret + (i * 16));
</span><span id="line5354" class="codeline ">            uint64x2_t key_vec_2  = XXH_vld1q_u64(xsecret + ((i+1) * 16));
</span><span id="line5355" class="codeline ">            /* data_swap = swap(data_vec) */
</span><span id="line5356" class="codeline ">            uint64x2_t data_swap_1 = vextq_u64(data_vec_1, data_vec_1, 1);
</span><span id="line5357" class="codeline ">            uint64x2_t data_swap_2 = vextq_u64(data_vec_2, data_vec_2, 1);
</span><span id="line5358" class="codeline ">            /* data_key = data_vec ^ key_vec; */
</span><span id="line5359" class="codeline ">            uint64x2_t data_key_1 = veorq_u64(data_vec_1, key_vec_1);
</span><span id="line5360" class="codeline ">            uint64x2_t data_key_2 = veorq_u64(data_vec_2, key_vec_2);
</span><span id="line5361" class="codeline ">
</span><span id="line5362" class="codeline ">            /*
</span><span id="line5363" class="codeline ">             * If we reinterpret the 64x2 vectors as 32x4 vectors, we can use a
</span><span id="line5364" class="codeline ">             * de-interleave operation for 4 lanes in 1 step with `vuzpq_u32` to
</span><span id="line5365" class="codeline ">             * get one vector with the low 32 bits of each lane, and one vector
</span><span id="line5366" class="codeline ">             * with the high 32 bits of each lane.
</span><span id="line5367" class="codeline ">             *
</span><span id="line5368" class="codeline ">             * The intrinsic returns a double vector because the original ARMv7-a
</span><span id="line5369" class="codeline ">             * instruction modified both arguments in place. AArch64 and SIMD128 emit
</span><span id="line5370" class="codeline ">             * two instructions from this intrinsic.
</span><span id="line5371" class="codeline ">             *
</span><span id="line5372" class="codeline ">             *  [ dk11L | dk11H | dk12L | dk12H ] -&gt; [ dk11L | dk12L | dk21L | dk22L ]
</span><span id="line5373" class="codeline ">             *  [ dk21L | dk21H | dk22L | dk22H ] -&gt; [ dk11H | dk12H | dk21H | dk22H ]
</span><span id="line5374" class="codeline ">             */
</span><span id="line5375" class="codeline ">            uint32x4x2_t unzipped = vuzpq_u32(
</span><span id="line5376" class="codeline ">                vreinterpretq_u32_u64(data_key_1),
</span><span id="line5377" class="codeline ">                vreinterpretq_u32_u64(data_key_2)
</span><span id="line5378" class="codeline ">            );
</span><span id="line5379" class="codeline ">            /* data_key_lo = data_key &amp; 0xFFFFFFFF */
</span><span id="line5380" class="codeline ">            uint32x4_t data_key_lo = unzipped.val[0];
</span><span id="line5381" class="codeline ">            /* data_key_hi = data_key &gt;&gt; 32 */
</span><span id="line5382" class="codeline ">            uint32x4_t data_key_hi = unzipped.val[1];
</span><span id="line5383" class="codeline ">            /*
</span><span id="line5384" class="codeline ">             * Then, we can split the vectors horizontally and multiply which, as for most
</span><span id="line5385" class="codeline ">             * widening intrinsics, have a variant that works on both high half vectors
</span><span id="line5386" class="codeline ">             * for free on AArch64. A similar instruction is available on SIMD128.
</span><span id="line5387" class="codeline ">             *
</span><span id="line5388" class="codeline ">             * sum = data_swap + (u64x2) data_key_lo * (u64x2) data_key_hi
</span><span id="line5389" class="codeline ">             */
</span><span id="line5390" class="codeline ">            uint64x2_t sum_1 = XXH_vmlal_low_u32(data_swap_1, data_key_lo, data_key_hi);
</span><span id="line5391" class="codeline ">            uint64x2_t sum_2 = XXH_vmlal_high_u32(data_swap_2, data_key_lo, data_key_hi);
</span><span id="line5392" class="codeline ">            /*
</span><span id="line5393" class="codeline ">             * Clang reorders
</span><span id="line5394" class="codeline ">             *    a += b * c;     // umlal   swap.2d, dkl.2s, dkh.2s
</span><span id="line5395" class="codeline ">             *    c += a;         // add     acc.2d, acc.2d, swap.2d
</span><span id="line5396" class="codeline ">             * to
</span><span id="line5397" class="codeline ">             *    c += a;         // add     acc.2d, acc.2d, swap.2d
</span><span id="line5398" class="codeline ">             *    c += b * c;     // umlal   acc.2d, dkl.2s, dkh.2s
</span><span id="line5399" class="codeline ">             *
</span><span id="line5400" class="codeline ">             * While it would make sense in theory since the addition is faster,
</span><span id="line5401" class="codeline ">             * for reasons likely related to umlal being limited to certain NEON
</span><span id="line5402" class="codeline ">             * pipelines, this is worse. A compiler guard fixes this.
</span><span id="line5403" class="codeline ">             */
</span><span id="line5404" class="codeline ">            XXH_COMPILER_GUARD_CLANG_NEON(sum_1);
</span><span id="line5405" class="codeline ">            XXH_COMPILER_GUARD_CLANG_NEON(sum_2);
</span><span id="line5406" class="codeline ">            /* xacc[i] = acc_vec + sum; */
</span><span id="line5407" class="codeline ">            xacc[i]   = vaddq_u64(xacc[i], sum_1);
</span><span id="line5408" class="codeline ">            xacc[i+1] = vaddq_u64(xacc[i+1], sum_2);
</span><span id="line5409" class="codeline ">        }
</span><span id="line5410" class="codeline ">        /* Operate on the remaining NEON lanes 2 at a time. */
</span><span id="line5411" class="codeline ">        for (; i &lt; XXH3_NEON_LANES / 2; i++) {
</span><span id="line5412" class="codeline ">            /* data_vec = xinput[i]; */
</span><span id="line5413" class="codeline ">            uint64x2_t data_vec = XXH_vld1q_u64(xinput  + (i * 16));
</span><span id="line5414" class="codeline ">            /* key_vec  = xsecret[i];  */
</span><span id="line5415" class="codeline ">            uint64x2_t key_vec  = XXH_vld1q_u64(xsecret + (i * 16));
</span><span id="line5416" class="codeline ">            /* acc_vec_2 = swap(data_vec) */
</span><span id="line5417" class="codeline ">            uint64x2_t data_swap = vextq_u64(data_vec, data_vec, 1);
</span><span id="line5418" class="codeline ">            /* data_key = data_vec ^ key_vec; */
</span><span id="line5419" class="codeline ">            uint64x2_t data_key = veorq_u64(data_vec, key_vec);
</span><span id="line5420" class="codeline ">            /* For two lanes, just use VMOVN and VSHRN. */
</span><span id="line5421" class="codeline ">            /* data_key_lo = data_key &amp; 0xFFFFFFFF; */
</span><span id="line5422" class="codeline ">            uint32x2_t data_key_lo = vmovn_u64(data_key);
</span><span id="line5423" class="codeline ">            /* data_key_hi = data_key &gt;&gt; 32; */
</span><span id="line5424" class="codeline ">            uint32x2_t data_key_hi = vshrn_n_u64(data_key, 32);
</span><span id="line5425" class="codeline ">            /* sum = data_swap + (u64x2) data_key_lo * (u64x2) data_key_hi; */
</span><span id="line5426" class="codeline ">            uint64x2_t sum = vmlal_u32(data_swap, data_key_lo, data_key_hi);
</span><span id="line5427" class="codeline ">            /* Same Clang workaround as before */
</span><span id="line5428" class="codeline ">            XXH_COMPILER_GUARD_CLANG_NEON(sum);
</span><span id="line5429" class="codeline ">            /* xacc[i] = acc_vec + sum; */
</span><span id="line5430" class="codeline ">            xacc[i] = vaddq_u64 (xacc[i], sum);
</span><span id="line5431" class="codeline ">        }
</span><span id="line5432" class="codeline ">    }
</span><span id="line5433" class="codeline ">}
</span><span id="line5434" class="codeline ">XXH_FORCE_INLINE XXH3_ACCUMULATE_TEMPLATE(neon)
</span><span id="line5435" class="codeline ">
</span><span id="line5436" class="codeline ">XXH_FORCE_INLINE void
</span><span id="line5437" class="codeline ">XXH3_scrambleAcc_neon(void* XXH_RESTRICT acc, const void* XXH_RESTRICT secret)
</span><span id="line5438" class="codeline ">{
</span><span id="line5439" class="codeline ">    XXH_ASSERT((((size_t)acc) &amp; 15) == 0);
</span><span id="line5440" class="codeline ">
</span><span id="line5441" class="codeline ">    {   xxh_aliasing_uint64x2_t* xacc       = (xxh_aliasing_uint64x2_t*) acc;
</span><span id="line5442" class="codeline ">        uint8_t const* xsecret = (uint8_t const*) secret;
</span><span id="line5443" class="codeline ">
</span><span id="line5444" class="codeline ">        size_t i;
</span><span id="line5445" class="codeline ">        /* WASM uses operator overloads and doesn&#39;t need these. */
</span><span id="line5446" class="codeline ">#ifndef __wasm_simd128__
</span><span id="line5447" class="codeline ">        /* { prime32_1, prime32_1 } */
</span><span id="line5448" class="codeline ">        uint32x2_t const kPrimeLo = vdup_n_u32(XXH_PRIME32_1);
</span><span id="line5449" class="codeline ">        /* { 0, prime32_1, 0, prime32_1 } */
</span><span id="line5450" class="codeline ">        uint32x4_t const kPrimeHi = vreinterpretq_u32_u64(vdupq_n_u64((xxh_u64)XXH_PRIME32_1 &lt;&lt; 32));
</span><span id="line5451" class="codeline ">#endif
</span><span id="line5452" class="codeline ">
</span><span id="line5453" class="codeline ">        /* AArch64 uses both scalar and neon at the same time */
</span><span id="line5454" class="codeline ">        for (i = XXH3_NEON_LANES; i &lt; XXH_ACC_NB; i++) {
</span><span id="line5455" class="codeline ">            XXH3_scalarScrambleRound(acc, secret, i);
</span><span id="line5456" class="codeline ">        }
</span><span id="line5457" class="codeline ">        for (i=0; i &lt; XXH3_NEON_LANES / 2; i++) {
</span><span id="line5458" class="codeline ">            /* xacc[i] ^= (xacc[i] &gt;&gt; 47); */
</span><span id="line5459" class="codeline ">            uint64x2_t acc_vec  = xacc[i];
</span><span id="line5460" class="codeline ">            uint64x2_t shifted  = vshrq_n_u64(acc_vec, 47);
</span><span id="line5461" class="codeline ">            uint64x2_t data_vec = veorq_u64(acc_vec, shifted);
</span><span id="line5462" class="codeline ">
</span><span id="line5463" class="codeline ">            /* xacc[i] ^= xsecret[i]; */
</span><span id="line5464" class="codeline ">            uint64x2_t key_vec  = XXH_vld1q_u64(xsecret + (i * 16));
</span><span id="line5465" class="codeline ">            uint64x2_t data_key = veorq_u64(data_vec, key_vec);
</span><span id="line5466" class="codeline ">            /* xacc[i] *= XXH_PRIME32_1 */
</span><span id="line5467" class="codeline ">#ifdef __wasm_simd128__
</span><span id="line5468" class="codeline ">            /* SIMD128 has multiply by u64x2, use it instead of expanding and scalarizing */
</span><span id="line5469" class="codeline ">            xacc[i] = data_key * XXH_PRIME32_1;
</span><span id="line5470" class="codeline ">#else
</span><span id="line5471" class="codeline ">            /*
</span><span id="line5472" class="codeline ">             * Expanded version with portable NEON intrinsics
</span><span id="line5473" class="codeline ">             *
</span><span id="line5474" class="codeline ">             *    lo(x) * lo(y) + (hi(x) * lo(y) &lt;&lt; 32)
</span><span id="line5475" class="codeline ">             *
</span><span id="line5476" class="codeline ">             * prod_hi = hi(data_key) * lo(prime) &lt;&lt; 32
</span><span id="line5477" class="codeline ">             *
</span><span id="line5478" class="codeline ">             * Since we only need 32 bits of this multiply a trick can be used, reinterpreting the vector
</span><span id="line5479" class="codeline ">             * as a uint32x4_t and multiplying by { 0, prime, 0, prime } to cancel out the unwanted bits
</span><span id="line5480" class="codeline ">             * and avoid the shift.
</span><span id="line5481" class="codeline ">             */
</span><span id="line5482" class="codeline ">            uint32x4_t prod_hi = vmulq_u32 (vreinterpretq_u32_u64(data_key), kPrimeHi);
</span><span id="line5483" class="codeline ">            /* Extract low bits for vmlal_u32  */
</span><span id="line5484" class="codeline ">            uint32x2_t data_key_lo = vmovn_u64(data_key);
</span><span id="line5485" class="codeline ">            /* xacc[i] = prod_hi + lo(data_key) * XXH_PRIME32_1; */
</span><span id="line5486" class="codeline ">            xacc[i] = vmlal_u32(vreinterpretq_u64_u32(prod_hi), data_key_lo, kPrimeLo);
</span><span id="line5487" class="codeline ">#endif
</span><span id="line5488" class="codeline ">        }
</span><span id="line5489" class="codeline ">    }
</span><span id="line5490" class="codeline ">}
</span><span id="line5491" class="codeline ">#endif
</span><span id="line5492" class="codeline ">
</span><span id="line5493" class="codeline ">#if (XXH_VECTOR == XXH_VSX)
</span><span id="line5494" class="codeline ">
</span><span id="line5495" class="codeline ">XXH_FORCE_INLINE void
</span><span id="line5496" class="codeline ">XXH3_accumulate_512_vsx(  void* XXH_RESTRICT acc,
</span><span id="line5497" class="codeline ">                    const void* XXH_RESTRICT input,
</span><span id="line5498" class="codeline ">                    const void* XXH_RESTRICT secret)
</span><span id="line5499" class="codeline ">{
</span><span id="line5500" class="codeline ">    /* presumed aligned */
</span><span id="line5501" class="codeline ">    xxh_aliasing_u64x2* const xacc = (xxh_aliasing_u64x2*) acc;
</span><span id="line5502" class="codeline ">    xxh_u8 const* const xinput   = (xxh_u8 const*) input;   /* no alignment restriction */
</span><span id="line5503" class="codeline ">    xxh_u8 const* const xsecret  = (xxh_u8 const*) secret;    /* no alignment restriction */
</span><span id="line5504" class="codeline ">    xxh_u64x2 const v32 = { 32, 32 };
</span><span id="line5505" class="codeline ">    size_t i;
</span><span id="line5506" class="codeline ">    for (i = 0; i &lt; XXH_STRIPE_LEN / sizeof(xxh_u64x2); i++) {
</span><span id="line5507" class="codeline ">        /* data_vec = xinput[i]; */
</span><span id="line5508" class="codeline ">        xxh_u64x2 const data_vec = XXH_vec_loadu(xinput + 16*i);
</span><span id="line5509" class="codeline ">        /* key_vec = xsecret[i]; */
</span><span id="line5510" class="codeline ">        xxh_u64x2 const key_vec  = XXH_vec_loadu(xsecret + 16*i);
</span><span id="line5511" class="codeline ">        xxh_u64x2 const data_key = data_vec ^ key_vec;
</span><span id="line5512" class="codeline ">        /* shuffled = (data_key &lt;&lt; 32) | (data_key &gt;&gt; 32); */
</span><span id="line5513" class="codeline ">        xxh_u32x4 const shuffled = (xxh_u32x4)vec_rl(data_key, v32);
</span><span id="line5514" class="codeline ">        /* product = ((xxh_u64x2)data_key &amp; 0xFFFFFFFF) * ((xxh_u64x2)shuffled &amp; 0xFFFFFFFF); */
</span><span id="line5515" class="codeline ">        xxh_u64x2 const product  = XXH_vec_mulo((xxh_u32x4)data_key, shuffled);
</span><span id="line5516" class="codeline ">        /* acc_vec = xacc[i]; */
</span><span id="line5517" class="codeline ">        xxh_u64x2 acc_vec        = xacc[i];
</span><span id="line5518" class="codeline ">        acc_vec += product;
</span><span id="line5519" class="codeline ">
</span><span id="line5520" class="codeline ">        /* swap high and low halves */
</span><span id="line5521" class="codeline ">#ifdef __s390x__
</span><span id="line5522" class="codeline ">        acc_vec += vec_permi(data_vec, data_vec, 2);
</span><span id="line5523" class="codeline ">#else
</span><span id="line5524" class="codeline ">        acc_vec += vec_xxpermdi(data_vec, data_vec, 2);
</span><span id="line5525" class="codeline ">#endif
</span><span id="line5526" class="codeline ">        xacc[i] = acc_vec;
</span><span id="line5527" class="codeline ">    }
</span><span id="line5528" class="codeline ">}
</span><span id="line5529" class="codeline ">XXH_FORCE_INLINE XXH3_ACCUMULATE_TEMPLATE(vsx)
</span><span id="line5530" class="codeline ">
</span><span id="line5531" class="codeline ">XXH_FORCE_INLINE void
</span><span id="line5532" class="codeline ">XXH3_scrambleAcc_vsx(void* XXH_RESTRICT acc, const void* XXH_RESTRICT secret)
</span><span id="line5533" class="codeline ">{
</span><span id="line5534" class="codeline ">    XXH_ASSERT((((size_t)acc) &amp; 15) == 0);
</span><span id="line5535" class="codeline ">
</span><span id="line5536" class="codeline ">    {   xxh_aliasing_u64x2* const xacc = (xxh_aliasing_u64x2*) acc;
</span><span id="line5537" class="codeline ">        const xxh_u8* const xsecret = (const xxh_u8*) secret;
</span><span id="line5538" class="codeline ">        /* constants */
</span><span id="line5539" class="codeline ">        xxh_u64x2 const v32  = { 32, 32 };
</span><span id="line5540" class="codeline ">        xxh_u64x2 const v47 = { 47, 47 };
</span><span id="line5541" class="codeline ">        xxh_u32x4 const prime = { XXH_PRIME32_1, XXH_PRIME32_1, XXH_PRIME32_1, XXH_PRIME32_1 };
</span><span id="line5542" class="codeline ">        size_t i;
</span><span id="line5543" class="codeline ">        for (i = 0; i &lt; XXH_STRIPE_LEN / sizeof(xxh_u64x2); i++) {
</span><span id="line5544" class="codeline ">            /* xacc[i] ^= (xacc[i] &gt;&gt; 47); */
</span><span id="line5545" class="codeline ">            xxh_u64x2 const acc_vec  = xacc[i];
</span><span id="line5546" class="codeline ">            xxh_u64x2 const data_vec = acc_vec ^ (acc_vec &gt;&gt; v47);
</span><span id="line5547" class="codeline ">
</span><span id="line5548" class="codeline ">            /* xacc[i] ^= xsecret[i]; */
</span><span id="line5549" class="codeline ">            xxh_u64x2 const key_vec  = XXH_vec_loadu(xsecret + 16*i);
</span><span id="line5550" class="codeline ">            xxh_u64x2 const data_key = data_vec ^ key_vec;
</span><span id="line5551" class="codeline ">
</span><span id="line5552" class="codeline ">            /* xacc[i] *= XXH_PRIME32_1 */
</span><span id="line5553" class="codeline ">            /* prod_lo = ((xxh_u64x2)data_key &amp; 0xFFFFFFFF) * ((xxh_u64x2)prime &amp; 0xFFFFFFFF);  */
</span><span id="line5554" class="codeline ">            xxh_u64x2 const prod_even  = XXH_vec_mule((xxh_u32x4)data_key, prime);
</span><span id="line5555" class="codeline ">            /* prod_hi = ((xxh_u64x2)data_key &gt;&gt; 32) * ((xxh_u64x2)prime &gt;&gt; 32);  */
</span><span id="line5556" class="codeline ">            xxh_u64x2 const prod_odd  = XXH_vec_mulo((xxh_u32x4)data_key, prime);
</span><span id="line5557" class="codeline ">            xacc[i] = prod_odd + (prod_even &lt;&lt; v32);
</span><span id="line5558" class="codeline ">    }   }
</span><span id="line5559" class="codeline ">}
</span><span id="line5560" class="codeline ">
</span><span id="line5561" class="codeline ">#endif
</span><span id="line5562" class="codeline ">
</span><span id="line5563" class="codeline ">#if (XXH_VECTOR == XXH_SVE)
</span><span id="line5564" class="codeline ">
</span><span id="line5565" class="codeline ">XXH_FORCE_INLINE void
</span><span id="line5566" class="codeline ">XXH3_accumulate_512_sve( void* XXH_RESTRICT acc,
</span><span id="line5567" class="codeline ">                   const void* XXH_RESTRICT input,
</span><span id="line5568" class="codeline ">                   const void* XXH_RESTRICT secret)
</span><span id="line5569" class="codeline ">{
</span><span id="line5570" class="codeline ">    uint64_t *xacc = (uint64_t *)acc;
</span><span id="line5571" class="codeline ">    const uint64_t *xinput = (const uint64_t *)(const void *)input;
</span><span id="line5572" class="codeline ">    const uint64_t *xsecret = (const uint64_t *)(const void *)secret;
</span><span id="line5573" class="codeline ">    svuint64_t kSwap = sveor_n_u64_z(svptrue_b64(), svindex_u64(0, 1), 1);
</span><span id="line5574" class="codeline ">    uint64_t element_count = svcntd();
</span><span id="line5575" class="codeline ">    if (element_count &gt;= 8) {
</span><span id="line5576" class="codeline ">        svbool_t mask = svptrue_pat_b64(SV_VL8);
</span><span id="line5577" class="codeline ">        svuint64_t vacc = svld1_u64(mask, xacc);
</span><span id="line5578" class="codeline ">        ACCRND(vacc, 0);
</span><span id="line5579" class="codeline ">        svst1_u64(mask, xacc, vacc);
</span><span id="line5580" class="codeline ">    } else if (element_count == 2) {   /* sve128 */
</span><span id="line5581" class="codeline ">        svbool_t mask = svptrue_pat_b64(SV_VL2);
</span><span id="line5582" class="codeline ">        svuint64_t acc0 = svld1_u64(mask, xacc + 0);
</span><span id="line5583" class="codeline ">        svuint64_t acc1 = svld1_u64(mask, xacc + 2);
</span><span id="line5584" class="codeline ">        svuint64_t acc2 = svld1_u64(mask, xacc + 4);
</span><span id="line5585" class="codeline ">        svuint64_t acc3 = svld1_u64(mask, xacc + 6);
</span><span id="line5586" class="codeline ">        ACCRND(acc0, 0);
</span><span id="line5587" class="codeline ">        ACCRND(acc1, 2);
</span><span id="line5588" class="codeline ">        ACCRND(acc2, 4);
</span><span id="line5589" class="codeline ">        ACCRND(acc3, 6);
</span><span id="line5590" class="codeline ">        svst1_u64(mask, xacc + 0, acc0);
</span><span id="line5591" class="codeline ">        svst1_u64(mask, xacc + 2, acc1);
</span><span id="line5592" class="codeline ">        svst1_u64(mask, xacc + 4, acc2);
</span><span id="line5593" class="codeline ">        svst1_u64(mask, xacc + 6, acc3);
</span><span id="line5594" class="codeline ">    } else {
</span><span id="line5595" class="codeline ">        svbool_t mask = svptrue_pat_b64(SV_VL4);
</span><span id="line5596" class="codeline ">        svuint64_t acc0 = svld1_u64(mask, xacc + 0);
</span><span id="line5597" class="codeline ">        svuint64_t acc1 = svld1_u64(mask, xacc + 4);
</span><span id="line5598" class="codeline ">        ACCRND(acc0, 0);
</span><span id="line5599" class="codeline ">        ACCRND(acc1, 4);
</span><span id="line5600" class="codeline ">        svst1_u64(mask, xacc + 0, acc0);
</span><span id="line5601" class="codeline ">        svst1_u64(mask, xacc + 4, acc1);
</span><span id="line5602" class="codeline ">    }
</span><span id="line5603" class="codeline ">}
</span><span id="line5604" class="codeline ">
</span><span id="line5605" class="codeline ">XXH_FORCE_INLINE void
</span><span id="line5606" class="codeline ">XXH3_accumulate_sve(xxh_u64* XXH_RESTRICT acc,
</span><span id="line5607" class="codeline ">               const xxh_u8* XXH_RESTRICT input,
</span><span id="line5608" class="codeline ">               const xxh_u8* XXH_RESTRICT secret,
</span><span id="line5609" class="codeline ">               size_t nbStripes)
</span><span id="line5610" class="codeline ">{
</span><span id="line5611" class="codeline ">    if (nbStripes != 0) {
</span><span id="line5612" class="codeline ">        uint64_t *xacc = (uint64_t *)acc;
</span><span id="line5613" class="codeline ">        const uint64_t *xinput = (const uint64_t *)(const void *)input;
</span><span id="line5614" class="codeline ">        const uint64_t *xsecret = (const uint64_t *)(const void *)secret;
</span><span id="line5615" class="codeline ">        svuint64_t kSwap = sveor_n_u64_z(svptrue_b64(), svindex_u64(0, 1), 1);
</span><span id="line5616" class="codeline ">        uint64_t element_count = svcntd();
</span><span id="line5617" class="codeline ">        if (element_count &gt;= 8) {
</span><span id="line5618" class="codeline ">            svbool_t mask = svptrue_pat_b64(SV_VL8);
</span><span id="line5619" class="codeline ">            svuint64_t vacc = svld1_u64(mask, xacc + 0);
</span><span id="line5620" class="codeline ">            do {
</span><span id="line5621" class="codeline ">                /* svprfd(svbool_t, void *, enum svfprop); */
</span><span id="line5622" class="codeline ">                svprfd(mask, xinput + 128, SV_PLDL1STRM);
</span><span id="line5623" class="codeline ">                ACCRND(vacc, 0);
</span><span id="line5624" class="codeline ">                xinput += 8;
</span><span id="line5625" class="codeline ">                xsecret += 1;
</span><span id="line5626" class="codeline ">                nbStripes--;
</span><span id="line5627" class="codeline ">           } while (nbStripes != 0);
</span><span id="line5628" class="codeline ">
</span><span id="line5629" class="codeline ">           svst1_u64(mask, xacc + 0, vacc);
</span><span id="line5630" class="codeline ">        } else if (element_count == 2) { /* sve128 */
</span><span id="line5631" class="codeline ">            svbool_t mask = svptrue_pat_b64(SV_VL2);
</span><span id="line5632" class="codeline ">            svuint64_t acc0 = svld1_u64(mask, xacc + 0);
</span><span id="line5633" class="codeline ">            svuint64_t acc1 = svld1_u64(mask, xacc + 2);
</span><span id="line5634" class="codeline ">            svuint64_t acc2 = svld1_u64(mask, xacc + 4);
</span><span id="line5635" class="codeline ">            svuint64_t acc3 = svld1_u64(mask, xacc + 6);
</span><span id="line5636" class="codeline ">            do {
</span><span id="line5637" class="codeline ">                svprfd(mask, xinput + 128, SV_PLDL1STRM);
</span><span id="line5638" class="codeline ">                ACCRND(acc0, 0);
</span><span id="line5639" class="codeline ">                ACCRND(acc1, 2);
</span><span id="line5640" class="codeline ">                ACCRND(acc2, 4);
</span><span id="line5641" class="codeline ">                ACCRND(acc3, 6);
</span><span id="line5642" class="codeline ">                xinput += 8;
</span><span id="line5643" class="codeline ">                xsecret += 1;
</span><span id="line5644" class="codeline ">                nbStripes--;
</span><span id="line5645" class="codeline ">           } while (nbStripes != 0);
</span><span id="line5646" class="codeline ">
</span><span id="line5647" class="codeline ">           svst1_u64(mask, xacc + 0, acc0);
</span><span id="line5648" class="codeline ">           svst1_u64(mask, xacc + 2, acc1);
</span><span id="line5649" class="codeline ">           svst1_u64(mask, xacc + 4, acc2);
</span><span id="line5650" class="codeline ">           svst1_u64(mask, xacc + 6, acc3);
</span><span id="line5651" class="codeline ">        } else {
</span><span id="line5652" class="codeline ">            svbool_t mask = svptrue_pat_b64(SV_VL4);
</span><span id="line5653" class="codeline ">            svuint64_t acc0 = svld1_u64(mask, xacc + 0);
</span><span id="line5654" class="codeline ">            svuint64_t acc1 = svld1_u64(mask, xacc + 4);
</span><span id="line5655" class="codeline ">            do {
</span><span id="line5656" class="codeline ">                svprfd(mask, xinput + 128, SV_PLDL1STRM);
</span><span id="line5657" class="codeline ">                ACCRND(acc0, 0);
</span><span id="line5658" class="codeline ">                ACCRND(acc1, 4);
</span><span id="line5659" class="codeline ">                xinput += 8;
</span><span id="line5660" class="codeline ">                xsecret += 1;
</span><span id="line5661" class="codeline ">                nbStripes--;
</span><span id="line5662" class="codeline ">           } while (nbStripes != 0);
</span><span id="line5663" class="codeline ">
</span><span id="line5664" class="codeline ">           svst1_u64(mask, xacc + 0, acc0);
</span><span id="line5665" class="codeline ">           svst1_u64(mask, xacc + 4, acc1);
</span><span id="line5666" class="codeline ">       }
</span><span id="line5667" class="codeline ">    }
</span><span id="line5668" class="codeline ">}
</span><span id="line5669" class="codeline ">
</span><span id="line5670" class="codeline ">#endif
</span><span id="line5671" class="codeline ">
</span><span id="line5672" class="codeline ">#if (XXH_VECTOR == XXH_LSX)
</span><span id="line5673" class="codeline ">#define _LSX_SHUFFLE(z, y, x, w) (((z) &lt;&lt; 6) | ((y) &lt;&lt; 4) | ((x) &lt;&lt; 2) | (w))
</span><span id="line5674" class="codeline ">
</span><span id="line5675" class="codeline ">XXH_FORCE_INLINE void
</span><span id="line5676" class="codeline ">XXH3_accumulate_512_lsx( void* XXH_RESTRICT acc,
</span><span id="line5677" class="codeline ">                    const void* XXH_RESTRICT input,
</span><span id="line5678" class="codeline ">                    const void* XXH_RESTRICT secret)
</span><span id="line5679" class="codeline ">{
</span><span id="line5680" class="codeline ">    XXH_ASSERT((((size_t)acc) &amp; 15) == 0);
</span><span id="line5681" class="codeline ">    {
</span><span id="line5682" class="codeline ">        __m128i* const xacc    =       (__m128i *) acc;
</span><span id="line5683" class="codeline ">        const __m128i* const xinput  = (const __m128i *) input;
</span><span id="line5684" class="codeline ">        const __m128i* const xsecret = (const __m128i *) secret;
</span><span id="line5685" class="codeline ">
</span><span id="line5686" class="codeline ">        for (size_t i = 0; i &lt; XXH_STRIPE_LEN / sizeof(__m128i); i++) {
</span><span id="line5687" class="codeline ">            /* data_vec = xinput[i]; */
</span><span id="line5688" class="codeline ">            __m128i const data_vec = __lsx_vld(xinput + i, 0);
</span><span id="line5689" class="codeline ">            /* key_vec = xsecret[i]; */
</span><span id="line5690" class="codeline ">            __m128i const key_vec = __lsx_vld(xsecret + i, 0);
</span><span id="line5691" class="codeline ">            /* data_key = data_vec ^ key_vec; */
</span><span id="line5692" class="codeline ">            __m128i const data_key = __lsx_vxor_v(data_vec, key_vec);
</span><span id="line5693" class="codeline ">            /* data_key_lo = data_key &gt;&gt; 32; */
</span><span id="line5694" class="codeline ">            __m128i const data_key_lo = __lsx_vsrli_d(data_key, 32);
</span><span id="line5695" class="codeline ">            // __m128i const data_key_lo = __lsx_vsrli_d(data_key, 32);
</span><span id="line5696" class="codeline ">            /* product = (data_key &amp; 0xffffffff) * (data_key_lo &amp; 0xffffffff); */
</span><span id="line5697" class="codeline ">            __m128i const product = __lsx_vmulwev_d_wu(data_key, data_key_lo);
</span><span id="line5698" class="codeline ">            /* xacc[i] += swap(data_vec); */
</span><span id="line5699" class="codeline ">            __m128i const data_swap = __lsx_vshuf4i_w(data_vec, _LSX_SHUFFLE(1, 0, 3, 2));
</span><span id="line5700" class="codeline ">            __m128i const sum = __lsx_vadd_d(xacc[i], data_swap);
</span><span id="line5701" class="codeline ">            /* xacc[i] += product; */
</span><span id="line5702" class="codeline ">            xacc[i] = __lsx_vadd_d(product, sum);
</span><span id="line5703" class="codeline ">        }
</span><span id="line5704" class="codeline ">    }
</span><span id="line5705" class="codeline ">}
</span><span id="line5706" class="codeline ">XXH_FORCE_INLINE XXH3_ACCUMULATE_TEMPLATE(lsx)
</span><span id="line5707" class="codeline ">
</span><span id="line5708" class="codeline ">XXH_FORCE_INLINE void
</span><span id="line5709" class="codeline ">XXH3_scrambleAcc_lsx(void* XXH_RESTRICT acc, const void* XXH_RESTRICT secret)
</span><span id="line5710" class="codeline ">{
</span><span id="line5711" class="codeline ">    XXH_ASSERT((((size_t)acc) &amp; 15) == 0);
</span><span id="line5712" class="codeline ">    {
</span><span id="line5713" class="codeline ">        __m128i* const xacc = (__m128i*) acc;
</span><span id="line5714" class="codeline ">        const __m128i* const xsecret = (const __m128i *) secret;
</span><span id="line5715" class="codeline ">        const __m128i prime32 = __lsx_vreplgr2vr_w((int)XXH_PRIME32_1);
</span><span id="line5716" class="codeline ">
</span><span id="line5717" class="codeline ">        for (size_t i = 0; i &lt; XXH_STRIPE_LEN / sizeof(__m128i); i++) {
</span><span id="line5718" class="codeline ">            /* xacc[i] ^= (xacc[i] &gt;&gt; 47) */
</span><span id="line5719" class="codeline ">            __m128i const acc_vec = xacc[i];
</span><span id="line5720" class="codeline ">            __m128i const shifted = __lsx_vsrli_d(acc_vec, 47);
</span><span id="line5721" class="codeline ">            __m128i const data_vec = __lsx_vxor_v(acc_vec, shifted);
</span><span id="line5722" class="codeline ">            /* xacc[i] ^= xsecret[i]; */
</span><span id="line5723" class="codeline ">            __m128i const key_vec = __lsx_vld(xsecret + i, 0);
</span><span id="line5724" class="codeline ">            __m128i const data_key = __lsx_vxor_v(data_vec, key_vec);
</span><span id="line5725" class="codeline ">
</span><span id="line5726" class="codeline ">            /* xacc[i] *= XXH_PRIME32_1; */
</span><span id="line5727" class="codeline ">            __m128i const data_key_hi = __lsx_vsrli_d(data_key, 32);
</span><span id="line5728" class="codeline ">            __m128i const prod_lo = __lsx_vmulwev_d_wu(data_key, prime32);
</span><span id="line5729" class="codeline ">            __m128i const prod_hi = __lsx_vmulwev_d_wu(data_key_hi, prime32);
</span><span id="line5730" class="codeline ">            xacc[i] = __lsx_vadd_d(prod_lo, __lsx_vslli_d(prod_hi, 32));
</span><span id="line5731" class="codeline ">        }
</span><span id="line5732" class="codeline ">    }
</span><span id="line5733" class="codeline ">}
</span><span id="line5734" class="codeline ">
</span><span id="line5735" class="codeline ">#endif
</span><span id="line5736" class="codeline ">
</span><span id="line5737" class="codeline ">/* scalar variants - universal */
</span><span id="line5738" class="codeline ">
</span><span id="line5739" class="codeline ">#if defined(__aarch64__) &amp;&amp; (defined(__GNUC__) || defined(__clang__))
</span><span id="line5740" class="codeline ">/*
</span><span id="line5741" class="codeline "> * In XXH3_scalarRound(), GCC and Clang have a similar codegen issue, where they
</span><span id="line5742" class="codeline "> * emit an excess mask and a full 64-bit multiply-add (MADD X-form).
</span><span id="line5743" class="codeline "> *
</span><span id="line5744" class="codeline "> * While this might not seem like much, as AArch64 is a 64-bit architecture, only
</span><span id="line5745" class="codeline "> * big Cortex designs have a full 64-bit multiplier.
</span><span id="line5746" class="codeline "> *
</span><span id="line5747" class="codeline "> * On the little cores, the smaller 32-bit multiplier is used, and full 64-bit
</span><span id="line5748" class="codeline "> * multiplies expand to 2-3 multiplies in microcode. This has a major penalty
</span><span id="line5749" class="codeline "> * of up to 4 latency cycles and 2 stall cycles in the multiply pipeline.
</span><span id="line5750" class="codeline "> *
</span><span id="line5751" class="codeline "> * Thankfully, AArch64 still provides the 32-bit long multiply-add (UMADDL) which does
</span><span id="line5752" class="codeline "> * not have this penalty and does the mask automatically.
</span><span id="line5753" class="codeline "> */
</span><span id="line5754" class="codeline ">XXH_FORCE_INLINE xxh_u64
</span><span id="line5755" class="codeline ">XXH_mult32to64_add64(xxh_u64 lhs, xxh_u64 rhs, xxh_u64 acc)
</span><span id="line5756" class="codeline ">{
</span><span id="line5757" class="codeline ">    xxh_u64 ret;
</span><span id="line5758" class="codeline ">    /* note: %x = 64-bit register, %w = 32-bit register */
</span><span id="line5759" class="codeline ">    __asm__(&#34;umaddl %x0, %w1, %w2, %x3&#34; : &#34;=r&#34; (ret) : &#34;r&#34; (lhs), &#34;r&#34; (rhs), &#34;r&#34; (acc));
</span><span id="line5760" class="codeline ">    return ret;
</span><span id="line5761" class="codeline ">}
</span><span id="line5762" class="codeline ">#else
</span><span id="line5763" class="codeline ">XXH_FORCE_INLINE xxh_u64
</span><span id="line5764" class="codeline ">XXH_mult32to64_add64(xxh_u64 lhs, xxh_u64 rhs, xxh_u64 acc)
</span><span id="line5765" class="codeline ">{
</span><span id="line5766" class="codeline ">    return XXH_mult32to64((xxh_u32)lhs, (xxh_u32)rhs) + acc;
</span><span id="line5767" class="codeline ">}
</span><span id="line5768" class="codeline ">#endif
</span><span id="line5769" class="codeline ">
</span><span id="line5770" class="codeline ">/*!
</span><span id="line5771" class="codeline "> * @internal
</span><span id="line5772" class="codeline "> * @brief Scalar round for @ref XXH3_accumulate_512_scalar().
</span><span id="line5773" class="codeline "> *
</span><span id="line5774" class="codeline "> * This is extracted to its own function because the NEON path uses a combination
</span><span id="line5775" class="codeline "> * of NEON and scalar.
</span><span id="line5776" class="codeline "> */
</span><span id="line5777" class="codeline ">XXH_FORCE_INLINE void
</span><span id="line5778" class="codeline ">XXH3_scalarRound(void* XXH_RESTRICT acc,
</span><span id="line5779" class="codeline ">                 void const* XXH_RESTRICT input,
</span><span id="line5780" class="codeline ">                 void const* XXH_RESTRICT secret,
</span><span id="line5781" class="codeline ">                 size_t lane)
</span><span id="line5782" class="codeline ">{
</span><span id="line5783" class="codeline ">    xxh_u64* xacc = (xxh_u64*) acc;
</span><span id="line5784" class="codeline ">    xxh_u8 const* xinput  = (xxh_u8 const*) input;
</span><span id="line5785" class="codeline ">    xxh_u8 const* xsecret = (xxh_u8 const*) secret;
</span><span id="line5786" class="codeline ">    XXH_ASSERT(lane &lt; XXH_ACC_NB);
</span><span id="line5787" class="codeline ">    XXH_ASSERT(((size_t)acc &amp; (XXH_ACC_ALIGN-1)) == 0);
</span><span id="line5788" class="codeline ">    {
</span><span id="line5789" class="codeline ">        xxh_u64 const data_val = XXH_readLE64(xinput + lane * 8);
</span><span id="line5790" class="codeline ">        xxh_u64 const data_key = data_val ^ XXH_readLE64(xsecret + lane * 8);
</span><span id="line5791" class="codeline ">        xacc[lane ^ 1] += data_val; /* swap adjacent lanes */
</span><span id="line5792" class="codeline ">        xacc[lane] = XXH_mult32to64_add64(data_key /* &amp; 0xFFFFFFFF */, data_key &gt;&gt; 32, xacc[lane]);
</span><span id="line5793" class="codeline ">    }
</span><span id="line5794" class="codeline ">}
</span><span id="line5795" class="codeline ">
</span><span id="line5796" class="codeline ">/*!
</span><span id="line5797" class="codeline "> * @internal
</span><span id="line5798" class="codeline "> * @brief Processes a 64 byte block of data using the scalar path.
</span><span id="line5799" class="codeline "> */
</span><span id="line5800" class="codeline ">XXH_FORCE_INLINE void
</span><span id="line5801" class="codeline ">XXH3_accumulate_512_scalar(void* XXH_RESTRICT acc,
</span><span id="line5802" class="codeline ">                     const void* XXH_RESTRICT input,
</span><span id="line5803" class="codeline ">                     const void* XXH_RESTRICT secret)
</span><span id="line5804" class="codeline ">{
</span><span id="line5805" class="codeline ">    size_t i;
</span><span id="line5806" class="codeline ">    /* ARM GCC refuses to unroll this loop, resulting in a 24% slowdown on ARMv6. */
</span><span id="line5807" class="codeline ">#if defined(__GNUC__) &amp;&amp; !defined(__clang__) \
</span><span id="line5808" class="codeline ">  &amp;&amp; (defined(__arm__) || defined(__thumb2__)) \
</span><span id="line5809" class="codeline ">  &amp;&amp; defined(__ARM_FEATURE_UNALIGNED) /* no unaligned access just wastes bytes */ \
</span><span id="line5810" class="codeline ">  &amp;&amp; XXH_SIZE_OPT &lt;= 0
</span><span id="line5811" class="codeline ">#  pragma GCC unroll 8
</span><span id="line5812" class="codeline ">#endif
</span><span id="line5813" class="codeline ">    for (i=0; i &lt; XXH_ACC_NB; i++) {
</span><span id="line5814" class="codeline ">        XXH3_scalarRound(acc, input, secret, i);
</span><span id="line5815" class="codeline ">    }
</span><span id="line5816" class="codeline ">}
</span><span id="line5817" class="codeline ">XXH_FORCE_INLINE XXH3_ACCUMULATE_TEMPLATE(scalar)
</span><span id="line5818" class="codeline ">
</span><span id="line5819" class="codeline ">/*!
</span><span id="line5820" class="codeline "> * @internal
</span><span id="line5821" class="codeline "> * @brief Scalar scramble step for @ref XXH3_scrambleAcc_scalar().
</span><span id="line5822" class="codeline "> *
</span><span id="line5823" class="codeline "> * This is extracted to its own function because the NEON path uses a combination
</span><span id="line5824" class="codeline "> * of NEON and scalar.
</span><span id="line5825" class="codeline "> */
</span><span id="line5826" class="codeline ">XXH_FORCE_INLINE void
</span><span id="line5827" class="codeline ">XXH3_scalarScrambleRound(void* XXH_RESTRICT acc,
</span><span id="line5828" class="codeline ">                         void const* XXH_RESTRICT secret,
</span><span id="line5829" class="codeline ">                         size_t lane)
</span><span id="line5830" class="codeline ">{
</span><span id="line5831" class="codeline ">    xxh_u64* const xacc = (xxh_u64*) acc;   /* presumed aligned */
</span><span id="line5832" class="codeline ">    const xxh_u8* const xsecret = (const xxh_u8*) secret;   /* no alignment restriction */
</span><span id="line5833" class="codeline ">    XXH_ASSERT((((size_t)acc) &amp; (XXH_ACC_ALIGN-1)) == 0);
</span><span id="line5834" class="codeline ">    XXH_ASSERT(lane &lt; XXH_ACC_NB);
</span><span id="line5835" class="codeline ">    {
</span><span id="line5836" class="codeline ">        xxh_u64 const key64 = XXH_readLE64(xsecret + lane * 8);
</span><span id="line5837" class="codeline ">        xxh_u64 acc64 = xacc[lane];
</span><span id="line5838" class="codeline ">        acc64 = XXH_xorshift64(acc64, 47);
</span><span id="line5839" class="codeline ">        acc64 ^= key64;
</span><span id="line5840" class="codeline ">        acc64 *= XXH_PRIME32_1;
</span><span id="line5841" class="codeline ">        xacc[lane] = acc64;
</span><span id="line5842" class="codeline ">    }
</span><span id="line5843" class="codeline ">}
</span><span id="line5844" class="codeline ">
</span><span id="line5845" class="codeline ">/*!
</span><span id="line5846" class="codeline "> * @internal
</span><span id="line5847" class="codeline "> * @brief Scrambles the accumulators after a large chunk has been read
</span><span id="line5848" class="codeline "> */
</span><span id="line5849" class="codeline ">XXH_FORCE_INLINE void
</span><span id="line5850" class="codeline ">XXH3_scrambleAcc_scalar(void* XXH_RESTRICT acc, const void* XXH_RESTRICT secret)
</span><span id="line5851" class="codeline ">{
</span><span id="line5852" class="codeline ">    size_t i;
</span><span id="line5853" class="codeline ">    for (i=0; i &lt; XXH_ACC_NB; i++) {
</span><span id="line5854" class="codeline ">        XXH3_scalarScrambleRound(acc, secret, i);
</span><span id="line5855" class="codeline ">    }
</span><span id="line5856" class="codeline ">}
</span><span id="line5857" class="codeline ">
</span><span id="line5858" class="codeline ">XXH_FORCE_INLINE void
</span><span id="line5859" class="codeline ">XXH3_initCustomSecret_scalar(void* XXH_RESTRICT customSecret, xxh_u64 seed64)
</span><span id="line5860" class="codeline ">{
</span><span id="line5861" class="codeline ">    /*
</span><span id="line5862" class="codeline ">     * We need a separate pointer for the hack below,
</span><span id="line5863" class="codeline ">     * which requires a non-const pointer.
</span><span id="line5864" class="codeline ">     * Any decent compiler will optimize this out otherwise.
</span><span id="line5865" class="codeline ">     */
</span><span id="line5866" class="codeline ">    const xxh_u8* kSecretPtr = XXH3_kSecret;
</span><span id="line5867" class="codeline ">    XXH_STATIC_ASSERT((XXH_SECRET_DEFAULT_SIZE &amp; 15) == 0);
</span><span id="line5868" class="codeline ">
</span><span id="line5869" class="codeline ">#if defined(__GNUC__) &amp;&amp; defined(__aarch64__)
</span><span id="line5870" class="codeline ">    /*
</span><span id="line5871" class="codeline ">     * UGLY HACK:
</span><span id="line5872" class="codeline ">     * GCC and Clang generate a bunch of MOV/MOVK pairs for aarch64, and they are
</span><span id="line5873" class="codeline ">     * placed sequentially, in order, at the top of the unrolled loop.
</span><span id="line5874" class="codeline ">     *
</span><span id="line5875" class="codeline ">     * While MOVK is great for generating constants (2 cycles for a 64-bit
</span><span id="line5876" class="codeline ">     * constant compared to 4 cycles for LDR), it fights for bandwidth with
</span><span id="line5877" class="codeline ">     * the arithmetic instructions.
</span><span id="line5878" class="codeline ">     *
</span><span id="line5879" class="codeline ">     *   I   L   S
</span><span id="line5880" class="codeline ">     * MOVK
</span><span id="line5881" class="codeline ">     * MOVK
</span><span id="line5882" class="codeline ">     * MOVK
</span><span id="line5883" class="codeline ">     * MOVK
</span><span id="line5884" class="codeline ">     * ADD
</span><span id="line5885" class="codeline ">     * SUB      STR
</span><span id="line5886" class="codeline ">     *          STR
</span><span id="line5887" class="codeline ">     * By forcing loads from memory (as the asm line causes the compiler to assume
</span><span id="line5888" class="codeline ">     * that XXH3_kSecretPtr has been changed), the pipelines are used more
</span><span id="line5889" class="codeline ">     * efficiently:
</span><span id="line5890" class="codeline ">     *   I   L   S
</span><span id="line5891" class="codeline ">     *      LDR
</span><span id="line5892" class="codeline ">     *  ADD LDR
</span><span id="line5893" class="codeline ">     *  SUB     STR
</span><span id="line5894" class="codeline ">     *          STR
</span><span id="line5895" class="codeline ">     *
</span><span id="line5896" class="codeline ">     * See XXH3_NEON_LANES for details on the pipsline.
</span><span id="line5897" class="codeline ">     *
</span><span id="line5898" class="codeline ">     * XXH3_64bits_withSeed, len == 256, Snapdragon 835
</span><span id="line5899" class="codeline ">     *   without hack: 2654.4 MB/s
</span><span id="line5900" class="codeline ">     *   with hack:    3202.9 MB/s
</span><span id="line5901" class="codeline ">     */
</span><span id="line5902" class="codeline ">    XXH_COMPILER_GUARD(kSecretPtr);
</span><span id="line5903" class="codeline ">#endif
</span><span id="line5904" class="codeline ">    {   int const nbRounds = XXH_SECRET_DEFAULT_SIZE / 16;
</span><span id="line5905" class="codeline ">        int i;
</span><span id="line5906" class="codeline ">        for (i=0; i &lt; nbRounds; i++) {
</span><span id="line5907" class="codeline ">            /*
</span><span id="line5908" class="codeline ">             * The asm hack causes the compiler to assume that kSecretPtr aliases with
</span><span id="line5909" class="codeline ">             * customSecret, and on aarch64, this prevented LDP from merging two
</span><span id="line5910" class="codeline ">             * loads together for free. Putting the loads together before the stores
</span><span id="line5911" class="codeline ">             * properly generates LDP.
</span><span id="line5912" class="codeline ">             */
</span><span id="line5913" class="codeline ">            xxh_u64 lo = XXH_readLE64(kSecretPtr + 16*i)     + seed64;
</span><span id="line5914" class="codeline ">            xxh_u64 hi = XXH_readLE64(kSecretPtr + 16*i + 8) - seed64;
</span><span id="line5915" class="codeline ">            XXH_writeLE64((xxh_u8*)customSecret + 16*i,     lo);
</span><span id="line5916" class="codeline ">            XXH_writeLE64((xxh_u8*)customSecret + 16*i + 8, hi);
</span><span id="line5917" class="codeline ">    }   }
</span><span id="line5918" class="codeline ">}
</span><span id="line5919" class="codeline ">
</span><span id="line5920" class="codeline ">
</span><span id="line5921" class="codeline ">typedef void (*XXH3_f_accumulate)(xxh_u64* XXH_RESTRICT, const xxh_u8* XXH_RESTRICT, const xxh_u8* XXH_RESTRICT, size_t);
</span><span id="line5922" class="codeline ">typedef void (*XXH3_f_scrambleAcc)(void* XXH_RESTRICT, const void*);
</span><span id="line5923" class="codeline ">typedef void (*XXH3_f_initCustomSecret)(void* XXH_RESTRICT, xxh_u64);
</span><span id="line5924" class="codeline ">
</span><span id="line5925" class="codeline ">
</span><span id="line5926" class="codeline ">#if (XXH_VECTOR == XXH_AVX512)
</span><span id="line5927" class="codeline ">
</span><span id="line5928" class="codeline ">#define XXH3_accumulate_512 XXH3_accumulate_512_avx512
</span><span id="line5929" class="codeline ">#define XXH3_accumulate     XXH3_accumulate_avx512
</span><span id="line5930" class="codeline ">#define XXH3_scrambleAcc    XXH3_scrambleAcc_avx512
</span><span id="line5931" class="codeline ">#define XXH3_initCustomSecret XXH3_initCustomSecret_avx512
</span><span id="line5932" class="codeline ">
</span><span id="line5933" class="codeline ">#elif (XXH_VECTOR == XXH_AVX2)
</span><span id="line5934" class="codeline ">
</span><span id="line5935" class="codeline ">#define XXH3_accumulate_512 XXH3_accumulate_512_avx2
</span><span id="line5936" class="codeline ">#define XXH3_accumulate     XXH3_accumulate_avx2
</span><span id="line5937" class="codeline ">#define XXH3_scrambleAcc    XXH3_scrambleAcc_avx2
</span><span id="line5938" class="codeline ">#define XXH3_initCustomSecret XXH3_initCustomSecret_avx2
</span><span id="line5939" class="codeline ">
</span><span id="line5940" class="codeline ">#elif (XXH_VECTOR == XXH_SSE2)
</span><span id="line5941" class="codeline ">
</span><span id="line5942" class="codeline ">#define XXH3_accumulate_512 XXH3_accumulate_512_sse2
</span><span id="line5943" class="codeline ">#define XXH3_accumulate     XXH3_accumulate_sse2
</span><span id="line5944" class="codeline ">#define XXH3_scrambleAcc    XXH3_scrambleAcc_sse2
</span><span id="line5945" class="codeline ">#define XXH3_initCustomSecret XXH3_initCustomSecret_sse2
</span><span id="line5946" class="codeline ">
</span><span id="line5947" class="codeline ">#elif (XXH_VECTOR == XXH_NEON)
</span><span id="line5948" class="codeline ">
</span><span id="line5949" class="codeline ">#define XXH3_accumulate_512 XXH3_accumulate_512_neon
</span><span id="line5950" class="codeline ">#define XXH3_accumulate     XXH3_accumulate_neon
</span><span id="line5951" class="codeline ">#define XXH3_scrambleAcc    XXH3_scrambleAcc_neon
</span><span id="line5952" class="codeline ">#define XXH3_initCustomSecret XXH3_initCustomSecret_scalar
</span><span id="line5953" class="codeline ">
</span><span id="line5954" class="codeline ">#elif (XXH_VECTOR == XXH_VSX)
</span><span id="line5955" class="codeline ">
</span><span id="line5956" class="codeline ">#define XXH3_accumulate_512 XXH3_accumulate_512_vsx
</span><span id="line5957" class="codeline ">#define XXH3_accumulate     XXH3_accumulate_vsx
</span><span id="line5958" class="codeline ">#define XXH3_scrambleAcc    XXH3_scrambleAcc_vsx
</span><span id="line5959" class="codeline ">#define XXH3_initCustomSecret XXH3_initCustomSecret_scalar
</span><span id="line5960" class="codeline ">
</span><span id="line5961" class="codeline ">#elif (XXH_VECTOR == XXH_SVE)
</span><span id="line5962" class="codeline ">#define XXH3_accumulate_512 XXH3_accumulate_512_sve
</span><span id="line5963" class="codeline ">#define XXH3_accumulate     XXH3_accumulate_sve
</span><span id="line5964" class="codeline ">#define XXH3_scrambleAcc    XXH3_scrambleAcc_scalar
</span><span id="line5965" class="codeline ">#define XXH3_initCustomSecret XXH3_initCustomSecret_scalar
</span><span id="line5966" class="codeline ">
</span><span id="line5967" class="codeline ">#elif (XXH_VECTOR == XXH_LSX)
</span><span id="line5968" class="codeline ">#define XXH3_accumulate_512 XXH3_accumulate_512_lsx
</span><span id="line5969" class="codeline ">#define XXH3_accumulate     XXH3_accumulate_lsx
</span><span id="line5970" class="codeline ">#define XXH3_scrambleAcc    XXH3_scrambleAcc_lsx
</span><span id="line5971" class="codeline ">#define XXH3_initCustomSecret XXH3_initCustomSecret_scalar
</span><span id="line5972" class="codeline ">
</span><span id="line5973" class="codeline ">#else /* scalar */
</span><span id="line5974" class="codeline ">
</span><span id="line5975" class="codeline ">#define XXH3_accumulate_512 XXH3_accumulate_512_scalar
</span><span id="line5976" class="codeline ">#define XXH3_accumulate     XXH3_accumulate_scalar
</span><span id="line5977" class="codeline ">#define XXH3_scrambleAcc    XXH3_scrambleAcc_scalar
</span><span id="line5978" class="codeline ">#define XXH3_initCustomSecret XXH3_initCustomSecret_scalar
</span><span id="line5979" class="codeline ">
</span><span id="line5980" class="codeline ">#endif
</span><span id="line5981" class="codeline ">
</span><span id="line5982" class="codeline ">#if XXH_SIZE_OPT &gt;= 1 /* don&#39;t do SIMD for initialization */
</span><span id="line5983" class="codeline ">#  undef XXH3_initCustomSecret
</span><span id="line5984" class="codeline ">#  define XXH3_initCustomSecret XXH3_initCustomSecret_scalar
</span><span id="line5985" class="codeline ">#endif
</span><span id="line5986" class="codeline ">
</span><span id="line5987" class="codeline ">XXH_FORCE_INLINE void
</span><span id="line5988" class="codeline ">XXH3_hashLong_internal_loop(xxh_u64* XXH_RESTRICT acc,
</span><span id="line5989" class="codeline ">                      const xxh_u8* XXH_RESTRICT input, size_t len,
</span><span id="line5990" class="codeline ">                      const xxh_u8* XXH_RESTRICT secret, size_t secretSize,
</span><span id="line5991" class="codeline ">                            XXH3_f_accumulate f_acc,
</span><span id="line5992" class="codeline ">                            XXH3_f_scrambleAcc f_scramble)
</span><span id="line5993" class="codeline ">{
</span><span id="line5994" class="codeline ">    size_t const nbStripesPerBlock = (secretSize - XXH_STRIPE_LEN) / XXH_SECRET_CONSUME_RATE;
</span><span id="line5995" class="codeline ">    size_t const block_len = XXH_STRIPE_LEN * nbStripesPerBlock;
</span><span id="line5996" class="codeline ">    size_t const nb_blocks = (len - 1) / block_len;
</span><span id="line5997" class="codeline ">
</span><span id="line5998" class="codeline ">    size_t n;
</span><span id="line5999" class="codeline ">
</span><span id="line6000" class="codeline ">    XXH_ASSERT(secretSize &gt;= XXH3_SECRET_SIZE_MIN);
</span><span id="line6001" class="codeline ">
</span><span id="line6002" class="codeline ">    for (n = 0; n &lt; nb_blocks; n++) {
</span><span id="line6003" class="codeline ">        f_acc(acc, input + n*block_len, secret, nbStripesPerBlock);
</span><span id="line6004" class="codeline ">        f_scramble(acc, secret + secretSize - XXH_STRIPE_LEN);
</span><span id="line6005" class="codeline ">    }
</span><span id="line6006" class="codeline ">
</span><span id="line6007" class="codeline ">    /* last partial block */
</span><span id="line6008" class="codeline ">    XXH_ASSERT(len &gt; XXH_STRIPE_LEN);
</span><span id="line6009" class="codeline ">    {   size_t const nbStripes = ((len - 1) - (block_len * nb_blocks)) / XXH_STRIPE_LEN;
</span><span id="line6010" class="codeline ">        XXH_ASSERT(nbStripes &lt;= (secretSize / XXH_SECRET_CONSUME_RATE));
</span><span id="line6011" class="codeline ">        f_acc(acc, input + nb_blocks*block_len, secret, nbStripes);
</span><span id="line6012" class="codeline ">
</span><span id="line6013" class="codeline ">        /* last stripe */
</span><span id="line6014" class="codeline ">        {   const xxh_u8* const p = input + len - XXH_STRIPE_LEN;
</span><span id="line6015" class="codeline ">#define XXH_SECRET_LASTACC_START 7  /* not aligned on 8, last secret is different from acc &amp; scrambler */
</span><span id="line6016" class="codeline ">            XXH3_accumulate_512(acc, p, secret + secretSize - XXH_STRIPE_LEN - XXH_SECRET_LASTACC_START);
</span><span id="line6017" class="codeline ">    }   }
</span><span id="line6018" class="codeline ">}
</span><span id="line6019" class="codeline ">
</span><span id="line6020" class="codeline ">XXH_FORCE_INLINE xxh_u64
</span><span id="line6021" class="codeline ">XXH3_mix2Accs(const xxh_u64* XXH_RESTRICT acc, const xxh_u8* XXH_RESTRICT secret)
</span><span id="line6022" class="codeline ">{
</span><span id="line6023" class="codeline ">    return XXH3_mul128_fold64(
</span><span id="line6024" class="codeline ">               acc[0] ^ XXH_readLE64(secret),
</span><span id="line6025" class="codeline ">               acc[1] ^ XXH_readLE64(secret+8) );
</span><span id="line6026" class="codeline ">}
</span><span id="line6027" class="codeline ">
</span><span id="line6028" class="codeline ">static XXH_PUREF XXH64_hash_t
</span><span id="line6029" class="codeline ">XXH3_mergeAccs(const xxh_u64* XXH_RESTRICT acc, const xxh_u8* XXH_RESTRICT secret, xxh_u64 start)
</span><span id="line6030" class="codeline ">{
</span><span id="line6031" class="codeline ">    xxh_u64 result64 = start;
</span><span id="line6032" class="codeline ">    size_t i = 0;
</span><span id="line6033" class="codeline ">
</span><span id="line6034" class="codeline ">    for (i = 0; i &lt; 4; i++) {
</span><span id="line6035" class="codeline ">        result64 += XXH3_mix2Accs(acc+2*i, secret + 16*i);
</span><span id="line6036" class="codeline ">#if defined(__clang__)                                /* Clang */ \
</span><span id="line6037" class="codeline ">    &amp;&amp; (defined(__arm__) || defined(__thumb__))       /* ARMv7 */ \
</span><span id="line6038" class="codeline ">    &amp;&amp; (defined(__ARM_NEON) || defined(__ARM_NEON__)) /* NEON */  \
</span><span id="line6039" class="codeline ">    &amp;&amp; !defined(XXH_ENABLE_AUTOVECTORIZE)             /* Define to disable */
</span><span id="line6040" class="codeline ">        /*
</span><span id="line6041" class="codeline ">         * UGLY HACK:
</span><span id="line6042" class="codeline ">         * Prevent autovectorization on Clang ARMv7-a. Exact same problem as
</span><span id="line6043" class="codeline ">         * the one in XXH3_len_129to240_64b. Speeds up shorter keys &gt; 240b.
</span><span id="line6044" class="codeline ">         * XXH3_64bits, len == 256, Snapdragon 835:
</span><span id="line6045" class="codeline ">         *   without hack: 2063.7 MB/s
</span><span id="line6046" class="codeline ">         *   with hack:    2560.7 MB/s
</span><span id="line6047" class="codeline ">         */
</span><span id="line6048" class="codeline ">        XXH_COMPILER_GUARD(result64);
</span><span id="line6049" class="codeline ">#endif
</span><span id="line6050" class="codeline ">    }
</span><span id="line6051" class="codeline ">
</span><span id="line6052" class="codeline ">    return XXH3_avalanche(result64);
</span><span id="line6053" class="codeline ">}
</span><span id="line6054" class="codeline ">
</span><span id="line6055" class="codeline ">/* do not align on 8, so that the secret is different from the accumulator */
</span><span id="line6056" class="codeline ">#define XXH_SECRET_MERGEACCS_START 11
</span><span id="line6057" class="codeline ">
</span><span id="line6058" class="codeline ">static XXH_PUREF XXH64_hash_t
</span><span id="line6059" class="codeline ">XXH3_finalizeLong_64b(const xxh_u64* XXH_RESTRICT acc, const xxh_u8* XXH_RESTRICT secret, xxh_u64 len)
</span><span id="line6060" class="codeline ">{
</span><span id="line6061" class="codeline ">    return XXH3_mergeAccs(acc, secret + XXH_SECRET_MERGEACCS_START, len * XXH_PRIME64_1);
</span><span id="line6062" class="codeline ">}
</span><span id="line6063" class="codeline ">
</span><span id="line6064" class="codeline ">#define XXH3_INIT_ACC { XXH_PRIME32_3, XXH_PRIME64_1, XXH_PRIME64_2, XXH_PRIME64_3, \
</span><span id="line6065" class="codeline ">                        XXH_PRIME64_4, XXH_PRIME32_2, XXH_PRIME64_5, XXH_PRIME32_1 }
</span><span id="line6066" class="codeline ">
</span><span id="line6067" class="codeline ">XXH_FORCE_INLINE XXH64_hash_t
</span><span id="line6068" class="codeline ">XXH3_hashLong_64b_internal(const void* XXH_RESTRICT input, size_t len,
</span><span id="line6069" class="codeline ">                           const void* XXH_RESTRICT secret, size_t secretSize,
</span><span id="line6070" class="codeline ">                           XXH3_f_accumulate f_acc,
</span><span id="line6071" class="codeline ">                           XXH3_f_scrambleAcc f_scramble)
</span><span id="line6072" class="codeline ">{
</span><span id="line6073" class="codeline ">    XXH_ALIGN(XXH_ACC_ALIGN) xxh_u64 acc[XXH_ACC_NB] = XXH3_INIT_ACC;
</span><span id="line6074" class="codeline ">
</span><span id="line6075" class="codeline ">    XXH3_hashLong_internal_loop(acc, (const xxh_u8*)input, len, (const xxh_u8*)secret, secretSize, f_acc, f_scramble);
</span><span id="line6076" class="codeline ">
</span><span id="line6077" class="codeline ">    /* converge into final hash */
</span><span id="line6078" class="codeline ">    XXH_STATIC_ASSERT(sizeof(acc) == 64);
</span><span id="line6079" class="codeline ">    XXH_ASSERT(secretSize &gt;= sizeof(acc) + XXH_SECRET_MERGEACCS_START);
</span><span id="line6080" class="codeline ">    return XXH3_finalizeLong_64b(acc, (const xxh_u8*)secret, (xxh_u64)len);
</span><span id="line6081" class="codeline ">}
</span><span id="line6082" class="codeline ">
</span><span id="line6083" class="codeline ">/*
</span><span id="line6084" class="codeline "> * It&#39;s important for performance to transmit secret&#39;s size (when it&#39;s static)
</span><span id="line6085" class="codeline "> * so that the compiler can properly optimize the vectorized loop.
</span><span id="line6086" class="codeline "> * This makes a big performance difference for &#34;medium&#34; keys (&lt;1 KB) when using AVX instruction set.
</span><span id="line6087" class="codeline "> * When the secret size is unknown, or on GCC 12 where the mix of NO_INLINE and FORCE_INLINE
</span><span id="line6088" class="codeline "> * breaks -Og, this is XXH_NO_INLINE.
</span><span id="line6089" class="codeline "> */
</span><span id="line6090" class="codeline ">XXH3_WITH_SECRET_INLINE XXH64_hash_t
</span><span id="line6091" class="codeline ">XXH3_hashLong_64b_withSecret(const void* XXH_RESTRICT input, size_t len,
</span><span id="line6092" class="codeline ">                             XXH64_hash_t seed64, const xxh_u8* XXH_RESTRICT secret, size_t secretLen)
</span><span id="line6093" class="codeline ">{
</span><span id="line6094" class="codeline ">    (void)seed64;
</span><span id="line6095" class="codeline ">    return XXH3_hashLong_64b_internal(input, len, secret, secretLen, XXH3_accumulate, XXH3_scrambleAcc);
</span><span id="line6096" class="codeline ">}
</span><span id="line6097" class="codeline ">
</span><span id="line6098" class="codeline ">/*
</span><span id="line6099" class="codeline "> * It&#39;s preferable for performance that XXH3_hashLong is not inlined,
</span><span id="line6100" class="codeline "> * as it results in a smaller function for small data, easier to the instruction cache.
</span><span id="line6101" class="codeline "> * Note that inside this no_inline function, we do inline the internal loop,
</span><span id="line6102" class="codeline "> * and provide a statically defined secret size to allow optimization of vector loop.
</span><span id="line6103" class="codeline "> */
</span><span id="line6104" class="codeline ">XXH_NO_INLINE XXH_PUREF XXH64_hash_t
</span><span id="line6105" class="codeline ">XXH3_hashLong_64b_default(const void* XXH_RESTRICT input, size_t len,
</span><span id="line6106" class="codeline ">                          XXH64_hash_t seed64, const xxh_u8* XXH_RESTRICT secret, size_t secretLen)
</span><span id="line6107" class="codeline ">{
</span><span id="line6108" class="codeline ">    (void)seed64; (void)secret; (void)secretLen;
</span><span id="line6109" class="codeline ">    return XXH3_hashLong_64b_internal(input, len, XXH3_kSecret, sizeof(XXH3_kSecret), XXH3_accumulate, XXH3_scrambleAcc);
</span><span id="line6110" class="codeline ">}
</span><span id="line6111" class="codeline ">
</span><span id="line6112" class="codeline ">/*
</span><span id="line6113" class="codeline "> * XXH3_hashLong_64b_withSeed():
</span><span id="line6114" class="codeline "> * Generate a custom key based on alteration of default XXH3_kSecret with the seed,
</span><span id="line6115" class="codeline "> * and then use this key for long mode hashing.
</span><span id="line6116" class="codeline "> *
</span><span id="line6117" class="codeline "> * This operation is decently fast but nonetheless costs a little bit of time.
</span><span id="line6118" class="codeline "> * Try to avoid it whenever possible (typically when seed==0).
</span><span id="line6119" class="codeline "> *
</span><span id="line6120" class="codeline "> * It&#39;s important for performance that XXH3_hashLong is not inlined. Not sure
</span><span id="line6121" class="codeline "> * why (uop cache maybe?), but the difference is large and easily measurable.
</span><span id="line6122" class="codeline "> */
</span><span id="line6123" class="codeline ">XXH_FORCE_INLINE XXH64_hash_t
</span><span id="line6124" class="codeline ">XXH3_hashLong_64b_withSeed_internal(const void* input, size_t len,
</span><span id="line6125" class="codeline ">                                    XXH64_hash_t seed,
</span><span id="line6126" class="codeline ">                                    XXH3_f_accumulate f_acc,
</span><span id="line6127" class="codeline ">                                    XXH3_f_scrambleAcc f_scramble,
</span><span id="line6128" class="codeline ">                                    XXH3_f_initCustomSecret f_initSec)
</span><span id="line6129" class="codeline ">{
</span><span id="line6130" class="codeline ">#if XXH_SIZE_OPT &lt;= 0
</span><span id="line6131" class="codeline ">    if (seed == 0)
</span><span id="line6132" class="codeline ">        return XXH3_hashLong_64b_internal(input, len,
</span><span id="line6133" class="codeline ">                                          XXH3_kSecret, sizeof(XXH3_kSecret),
</span><span id="line6134" class="codeline ">                                          f_acc, f_scramble);
</span><span id="line6135" class="codeline ">#endif
</span><span id="line6136" class="codeline ">    {   XXH_ALIGN(XXH_SEC_ALIGN) xxh_u8 secret[XXH_SECRET_DEFAULT_SIZE];
</span><span id="line6137" class="codeline ">        f_initSec(secret, seed);
</span><span id="line6138" class="codeline ">        return XXH3_hashLong_64b_internal(input, len, secret, sizeof(secret),
</span><span id="line6139" class="codeline ">                                          f_acc, f_scramble);
</span><span id="line6140" class="codeline ">    }
</span><span id="line6141" class="codeline ">}
</span><span id="line6142" class="codeline ">
</span><span id="line6143" class="codeline ">/*
</span><span id="line6144" class="codeline "> * It&#39;s important for performance that XXH3_hashLong is not inlined.
</span><span id="line6145" class="codeline "> */
</span><span id="line6146" class="codeline ">XXH_NO_INLINE XXH64_hash_t
</span><span id="line6147" class="codeline ">XXH3_hashLong_64b_withSeed(const void* XXH_RESTRICT input, size_t len,
</span><span id="line6148" class="codeline ">                           XXH64_hash_t seed, const xxh_u8* XXH_RESTRICT secret, size_t secretLen)
</span><span id="line6149" class="codeline ">{
</span><span id="line6150" class="codeline ">    (void)secret; (void)secretLen;
</span><span id="line6151" class="codeline ">    return XXH3_hashLong_64b_withSeed_internal(input, len, seed,
</span><span id="line6152" class="codeline ">                XXH3_accumulate, XXH3_scrambleAcc, XXH3_initCustomSecret);
</span><span id="line6153" class="codeline ">}
</span><span id="line6154" class="codeline ">
</span><span id="line6155" class="codeline ">
</span><span id="line6156" class="codeline ">typedef XXH64_hash_t (*XXH3_hashLong64_f)(const void* XXH_RESTRICT, size_t,
</span><span id="line6157" class="codeline ">                                          XXH64_hash_t, const xxh_u8* XXH_RESTRICT, size_t);
</span><span id="line6158" class="codeline ">
</span><span id="line6159" class="codeline ">XXH_FORCE_INLINE XXH64_hash_t
</span><span id="line6160" class="codeline ">XXH3_64bits_internal(const void* XXH_RESTRICT input, size_t len,
</span><span id="line6161" class="codeline ">                     XXH64_hash_t seed64, const void* XXH_RESTRICT secret, size_t secretLen,
</span><span id="line6162" class="codeline ">                     XXH3_hashLong64_f f_hashLong)
</span><span id="line6163" class="codeline ">{
</span><span id="line6164" class="codeline ">    XXH_ASSERT(secretLen &gt;= XXH3_SECRET_SIZE_MIN);
</span><span id="line6165" class="codeline ">    /*
</span><span id="line6166" class="codeline ">     * If an action is to be taken if `secretLen` condition is not respected,
</span><span id="line6167" class="codeline ">     * it should be done here.
</span><span id="line6168" class="codeline ">     * For now, it&#39;s a contract pre-condition.
</span><span id="line6169" class="codeline ">     * Adding a check and a branch here would cost performance at every hash.
</span><span id="line6170" class="codeline ">     * Also, note that function signature doesn&#39;t offer room to return an error.
</span><span id="line6171" class="codeline ">     */
</span><span id="line6172" class="codeline ">    if (len &lt;= 16)
</span><span id="line6173" class="codeline ">        return XXH3_len_0to16_64b((const xxh_u8*)input, len, (const xxh_u8*)secret, seed64);
</span><span id="line6174" class="codeline ">    if (len &lt;= 128)
</span><span id="line6175" class="codeline ">        return XXH3_len_17to128_64b((const xxh_u8*)input, len, (const xxh_u8*)secret, secretLen, seed64);
</span><span id="line6176" class="codeline ">    if (len &lt;= XXH3_MIDSIZE_MAX)
</span><span id="line6177" class="codeline ">        return XXH3_len_129to240_64b((const xxh_u8*)input, len, (const xxh_u8*)secret, secretLen, seed64);
</span><span id="line6178" class="codeline ">    return f_hashLong(input, len, seed64, (const xxh_u8*)secret, secretLen);
</span><span id="line6179" class="codeline ">}
</span><span id="line6180" class="codeline ">
</span><span id="line6181" class="codeline ">
</span><span id="line6182" class="codeline ">/* ===   Public entry point   === */
</span><span id="line6183" class="codeline ">
</span><span id="line6184" class="codeline ">/*! @ingroup XXH3_family */
</span><span id="line6185" class="codeline ">XXH_PUBLIC_API XXH64_hash_t XXH3_64bits(XXH_NOESCAPE const void* input, size_t length)
</span><span id="line6186" class="codeline ">{
</span><span id="line6187" class="codeline ">    return XXH3_64bits_internal(input, length, 0, XXH3_kSecret, sizeof(XXH3_kSecret), XXH3_hashLong_64b_default);
</span><span id="line6188" class="codeline ">}
</span><span id="line6189" class="codeline ">
</span><span id="line6190" class="codeline ">/*! @ingroup XXH3_family */
</span><span id="line6191" class="codeline ">XXH_PUBLIC_API XXH64_hash_t
</span><span id="line6192" class="codeline ">XXH3_64bits_withSecret(XXH_NOESCAPE const void* input, size_t length, XXH_NOESCAPE const void* secret, size_t secretSize)
</span><span id="line6193" class="codeline ">{
</span><span id="line6194" class="codeline ">    return XXH3_64bits_internal(input, length, 0, secret, secretSize, XXH3_hashLong_64b_withSecret);
</span><span id="line6195" class="codeline ">}
</span><span id="line6196" class="codeline ">
</span><span id="line6197" class="codeline ">/*! @ingroup XXH3_family */
</span><span id="line6198" class="codeline ">XXH_PUBLIC_API XXH64_hash_t
</span><span id="line6199" class="codeline ">XXH3_64bits_withSeed(XXH_NOESCAPE const void* input, size_t length, XXH64_hash_t seed)
</span><span id="line6200" class="codeline ">{
</span><span id="line6201" class="codeline ">    return XXH3_64bits_internal(input, length, seed, XXH3_kSecret, sizeof(XXH3_kSecret), XXH3_hashLong_64b_withSeed);
</span><span id="line6202" class="codeline ">}
</span><span id="line6203" class="codeline ">
</span><span id="line6204" class="codeline ">XXH_PUBLIC_API XXH64_hash_t
</span><span id="line6205" class="codeline ">XXH3_64bits_withSecretandSeed(XXH_NOESCAPE const void* input, size_t length, XXH_NOESCAPE const void* secret, size_t secretSize, XXH64_hash_t seed)
</span><span id="line6206" class="codeline ">{
</span><span id="line6207" class="codeline ">    if (length &lt;= XXH3_MIDSIZE_MAX)
</span><span id="line6208" class="codeline ">        return XXH3_64bits_internal(input, length, seed, XXH3_kSecret, sizeof(XXH3_kSecret), NULL);
</span><span id="line6209" class="codeline ">    return XXH3_hashLong_64b_withSecret(input, length, seed, (const xxh_u8*)secret, secretSize);
</span><span id="line6210" class="codeline ">}
</span><span id="line6211" class="codeline ">
</span><span id="line6212" class="codeline ">
</span><span id="line6213" class="codeline ">/* ===   XXH3 streaming   === */
</span><span id="line6214" class="codeline ">#ifndef XXH_NO_STREAM
</span><span id="line6215" class="codeline ">/*
</span><span id="line6216" class="codeline "> * Malloc&#39;s a pointer that is always aligned to @align.
</span><span id="line6217" class="codeline "> *
</span><span id="line6218" class="codeline "> * This must be freed with `XXH_alignedFree()`.
</span><span id="line6219" class="codeline "> *
</span><span id="line6220" class="codeline "> * malloc typically guarantees 16 byte alignment on 64-bit systems and 8 byte
</span><span id="line6221" class="codeline "> * alignment on 32-bit. This isn&#39;t enough for the 32 byte aligned loads in AVX2
</span><span id="line6222" class="codeline "> * or on 32-bit, the 16 byte aligned loads in SSE2 and NEON.
</span><span id="line6223" class="codeline "> *
</span><span id="line6224" class="codeline "> * This underalignment previously caused a rather obvious crash which went
</span><span id="line6225" class="codeline "> * completely unnoticed due to XXH3_createState() not actually being tested.
</span><span id="line6226" class="codeline "> * Credit to RedSpah for noticing this bug.
</span><span id="line6227" class="codeline "> *
</span><span id="line6228" class="codeline "> * The alignment is done manually: Functions like posix_memalign or _mm_malloc
</span><span id="line6229" class="codeline "> * are avoided: To maintain portability, we would have to write a fallback
</span><span id="line6230" class="codeline "> * like this anyways, and besides, testing for the existence of library
</span><span id="line6231" class="codeline "> * functions without relying on external build tools is impossible.
</span><span id="line6232" class="codeline "> *
</span><span id="line6233" class="codeline "> * The method is simple: Overallocate, manually align, and store the offset
</span><span id="line6234" class="codeline "> * to the original behind the returned pointer.
</span><span id="line6235" class="codeline "> *
</span><span id="line6236" class="codeline "> * Align must be a power of 2 and 8 &lt;= align &lt;= 128.
</span><span id="line6237" class="codeline "> */
</span><span id="line6238" class="codeline ">static XXH_MALLOCF void* XXH_alignedMalloc(size_t s, size_t align)
</span><span id="line6239" class="codeline ">{
</span><span id="line6240" class="codeline ">    XXH_ASSERT(align &lt;= 128 &amp;&amp; align &gt;= 8); /* range check */
</span><span id="line6241" class="codeline ">    XXH_ASSERT((align &amp; (align-1)) == 0);   /* power of 2 */
</span><span id="line6242" class="codeline ">    XXH_ASSERT(s != 0 &amp;&amp; s &lt; (s + align));  /* empty/overflow */
</span><span id="line6243" class="codeline ">    {   /* Overallocate to make room for manual realignment and an offset byte */
</span><span id="line6244" class="codeline ">        xxh_u8* base = (xxh_u8*)XXH_malloc(s + align);
</span><span id="line6245" class="codeline ">        if (base != NULL) {
</span><span id="line6246" class="codeline ">            /*
</span><span id="line6247" class="codeline ">             * Get the offset needed to align this pointer.
</span><span id="line6248" class="codeline ">             *
</span><span id="line6249" class="codeline ">             * Even if the returned pointer is aligned, there will always be
</span><span id="line6250" class="codeline ">             * at least one byte to store the offset to the original pointer.
</span><span id="line6251" class="codeline ">             */
</span><span id="line6252" class="codeline ">            size_t offset = align - ((size_t)base &amp; (align - 1)); /* base % align */
</span><span id="line6253" class="codeline ">            /* Add the offset for the now-aligned pointer */
</span><span id="line6254" class="codeline ">            xxh_u8* ptr = base + offset;
</span><span id="line6255" class="codeline ">
</span><span id="line6256" class="codeline ">            XXH_ASSERT((size_t)ptr % align == 0);
</span><span id="line6257" class="codeline ">
</span><span id="line6258" class="codeline ">            /* Store the offset immediately before the returned pointer. */
</span><span id="line6259" class="codeline ">            ptr[-1] = (xxh_u8)offset;
</span><span id="line6260" class="codeline ">            return ptr;
</span><span id="line6261" class="codeline ">        }
</span><span id="line6262" class="codeline ">        return NULL;
</span><span id="line6263" class="codeline ">    }
</span><span id="line6264" class="codeline ">}
</span><span id="line6265" class="codeline ">/*
</span><span id="line6266" class="codeline "> * Frees an aligned pointer allocated by XXH_alignedMalloc(). Don&#39;t pass
</span><span id="line6267" class="codeline "> * normal malloc&#39;d pointers, XXH_alignedMalloc has a specific data layout.
</span><span id="line6268" class="codeline "> */
</span><span id="line6269" class="codeline ">static void XXH_alignedFree(void* p)
</span><span id="line6270" class="codeline ">{
</span><span id="line6271" class="codeline ">    if (p != NULL) {
</span><span id="line6272" class="codeline ">        xxh_u8* ptr = (xxh_u8*)p;
</span><span id="line6273" class="codeline ">        /* Get the offset byte we added in XXH_malloc. */
</span><span id="line6274" class="codeline ">        xxh_u8 offset = ptr[-1];
</span><span id="line6275" class="codeline ">        /* Free the original malloc&#39;d pointer */
</span><span id="line6276" class="codeline ">        xxh_u8* base = ptr - offset;
</span><span id="line6277" class="codeline ">        XXH_free(base);
</span><span id="line6278" class="codeline ">    }
</span><span id="line6279" class="codeline ">}
</span><span id="line6280" class="codeline ">/*! @ingroup XXH3_family */
</span><span id="line6281" class="codeline ">/*!
</span><span id="line6282" class="codeline "> * @brief Allocate an @ref XXH3_state_t.
</span><span id="line6283" class="codeline "> *
</span><span id="line6284" class="codeline "> * @return An allocated pointer of @ref XXH3_state_t on success.
</span><span id="line6285" class="codeline "> * @return `NULL` on failure.
</span><span id="line6286" class="codeline "> *
</span><span id="line6287" class="codeline "> * @note Must be freed with XXH3_freeState().
</span><span id="line6288" class="codeline "> *
</span><span id="line6289" class="codeline "> * @see @ref streaming_example &#34;Streaming Example&#34;
</span><span id="line6290" class="codeline "> */
</span><span id="line6291" class="codeline ">XXH_PUBLIC_API XXH3_state_t* XXH3_createState(void)
</span><span id="line6292" class="codeline ">{
</span><span id="line6293" class="codeline ">    XXH3_state_t* const state = (XXH3_state_t*)XXH_alignedMalloc(sizeof(XXH3_state_t), 64);
</span><span id="line6294" class="codeline ">    if (state==NULL) return NULL;
</span><span id="line6295" class="codeline ">    XXH3_INITSTATE(state);
</span><span id="line6296" class="codeline ">    return state;
</span><span id="line6297" class="codeline ">}
</span><span id="line6298" class="codeline ">
</span><span id="line6299" class="codeline ">/*! @ingroup XXH3_family */
</span><span id="line6300" class="codeline ">/*!
</span><span id="line6301" class="codeline "> * @brief Frees an @ref XXH3_state_t.
</span><span id="line6302" class="codeline "> *
</span><span id="line6303" class="codeline "> * @param statePtr A pointer to an @ref XXH3_state_t allocated with @ref XXH3_createState().
</span><span id="line6304" class="codeline "> *
</span><span id="line6305" class="codeline "> * @return @ref XXH_OK.
</span><span id="line6306" class="codeline "> *
</span><span id="line6307" class="codeline "> * @note Must be allocated with XXH3_createState().
</span><span id="line6308" class="codeline "> *
</span><span id="line6309" class="codeline "> * @see @ref streaming_example &#34;Streaming Example&#34;
</span><span id="line6310" class="codeline "> */
</span><span id="line6311" class="codeline ">XXH_PUBLIC_API XXH_errorcode XXH3_freeState(XXH3_state_t* statePtr)
</span><span id="line6312" class="codeline ">{
</span><span id="line6313" class="codeline ">    XXH_alignedFree(statePtr);
</span><span id="line6314" class="codeline ">    return XXH_OK;
</span><span id="line6315" class="codeline ">}
</span><span id="line6316" class="codeline ">
</span><span id="line6317" class="codeline ">/*! @ingroup XXH3_family */
</span><span id="line6318" class="codeline ">XXH_PUBLIC_API void
</span><span id="line6319" class="codeline ">XXH3_copyState(XXH_NOESCAPE XXH3_state_t* dst_state, XXH_NOESCAPE const XXH3_state_t* src_state)
</span><span id="line6320" class="codeline ">{
</span><span id="line6321" class="codeline ">    XXH_memcpy(dst_state, src_state, sizeof(*dst_state));
</span><span id="line6322" class="codeline ">}
</span><span id="line6323" class="codeline ">
</span><span id="line6324" class="codeline ">static void
</span><span id="line6325" class="codeline ">XXH3_reset_internal(XXH3_state_t* statePtr,
</span><span id="line6326" class="codeline ">                    XXH64_hash_t seed,
</span><span id="line6327" class="codeline ">                    const void* secret, size_t secretSize)
</span><span id="line6328" class="codeline ">{
</span><span id="line6329" class="codeline ">    size_t const initStart = offsetof(XXH3_state_t, bufferedSize);
</span><span id="line6330" class="codeline ">    size_t const initLength = offsetof(XXH3_state_t, nbStripesPerBlock) - initStart;
</span><span id="line6331" class="codeline ">    XXH_ASSERT(offsetof(XXH3_state_t, nbStripesPerBlock) &gt; initStart);
</span><span id="line6332" class="codeline ">    XXH_ASSERT(statePtr != NULL);
</span><span id="line6333" class="codeline ">    /* set members from bufferedSize to nbStripesPerBlock (excluded) to 0 */
</span><span id="line6334" class="codeline ">    memset((char*)statePtr + initStart, 0, initLength);
</span><span id="line6335" class="codeline ">    statePtr-&gt;acc[0] = XXH_PRIME32_3;
</span><span id="line6336" class="codeline ">    statePtr-&gt;acc[1] = XXH_PRIME64_1;
</span><span id="line6337" class="codeline ">    statePtr-&gt;acc[2] = XXH_PRIME64_2;
</span><span id="line6338" class="codeline ">    statePtr-&gt;acc[3] = XXH_PRIME64_3;
</span><span id="line6339" class="codeline ">    statePtr-&gt;acc[4] = XXH_PRIME64_4;
</span><span id="line6340" class="codeline ">    statePtr-&gt;acc[5] = XXH_PRIME32_2;
</span><span id="line6341" class="codeline ">    statePtr-&gt;acc[6] = XXH_PRIME64_5;
</span><span id="line6342" class="codeline ">    statePtr-&gt;acc[7] = XXH_PRIME32_1;
</span><span id="line6343" class="codeline ">    statePtr-&gt;seed = seed;
</span><span id="line6344" class="codeline ">    statePtr-&gt;useSeed = (seed != 0);
</span><span id="line6345" class="codeline ">    statePtr-&gt;extSecret = (const unsigned char*)secret;
</span><span id="line6346" class="codeline ">    XXH_ASSERT(secretSize &gt;= XXH3_SECRET_SIZE_MIN);
</span><span id="line6347" class="codeline ">    statePtr-&gt;secretLimit = secretSize - XXH_STRIPE_LEN;
</span><span id="line6348" class="codeline ">    statePtr-&gt;nbStripesPerBlock = statePtr-&gt;secretLimit / XXH_SECRET_CONSUME_RATE;
</span><span id="line6349" class="codeline ">}
</span><span id="line6350" class="codeline ">
</span><span id="line6351" class="codeline ">/*! @ingroup XXH3_family */
</span><span id="line6352" class="codeline ">XXH_PUBLIC_API XXH_errorcode
</span><span id="line6353" class="codeline ">XXH3_64bits_reset(XXH_NOESCAPE XXH3_state_t* statePtr)
</span><span id="line6354" class="codeline ">{
</span><span id="line6355" class="codeline ">    if (statePtr == NULL) return XXH_ERROR;
</span><span id="line6356" class="codeline ">    XXH3_reset_internal(statePtr, 0, XXH3_kSecret, XXH_SECRET_DEFAULT_SIZE);
</span><span id="line6357" class="codeline ">    return XXH_OK;
</span><span id="line6358" class="codeline ">}
</span><span id="line6359" class="codeline ">
</span><span id="line6360" class="codeline ">/*! @ingroup XXH3_family */
</span><span id="line6361" class="codeline ">XXH_PUBLIC_API XXH_errorcode
</span><span id="line6362" class="codeline ">XXH3_64bits_reset_withSecret(XXH_NOESCAPE XXH3_state_t* statePtr, XXH_NOESCAPE const void* secret, size_t secretSize)
</span><span id="line6363" class="codeline ">{
</span><span id="line6364" class="codeline ">    if (statePtr == NULL) return XXH_ERROR;
</span><span id="line6365" class="codeline ">    XXH3_reset_internal(statePtr, 0, secret, secretSize);
</span><span id="line6366" class="codeline ">    if (secret == NULL) return XXH_ERROR;
</span><span id="line6367" class="codeline ">    if (secretSize &lt; XXH3_SECRET_SIZE_MIN) return XXH_ERROR;
</span><span id="line6368" class="codeline ">    return XXH_OK;
</span><span id="line6369" class="codeline ">}
</span><span id="line6370" class="codeline ">
</span><span id="line6371" class="codeline ">/*! @ingroup XXH3_family */
</span><span id="line6372" class="codeline ">XXH_PUBLIC_API XXH_errorcode
</span><span id="line6373" class="codeline ">XXH3_64bits_reset_withSeed(XXH_NOESCAPE XXH3_state_t* statePtr, XXH64_hash_t seed)
</span><span id="line6374" class="codeline ">{
</span><span id="line6375" class="codeline ">    if (statePtr == NULL) return XXH_ERROR;
</span><span id="line6376" class="codeline ">    if (seed==0) return XXH3_64bits_reset(statePtr);
</span><span id="line6377" class="codeline ">    if ((seed != statePtr-&gt;seed) || (statePtr-&gt;extSecret != NULL))
</span><span id="line6378" class="codeline ">        XXH3_initCustomSecret(statePtr-&gt;customSecret, seed);
</span><span id="line6379" class="codeline ">    XXH3_reset_internal(statePtr, seed, NULL, XXH_SECRET_DEFAULT_SIZE);
</span><span id="line6380" class="codeline ">    return XXH_OK;
</span><span id="line6381" class="codeline ">}
</span><span id="line6382" class="codeline ">
</span><span id="line6383" class="codeline ">/*! @ingroup XXH3_family */
</span><span id="line6384" class="codeline ">XXH_PUBLIC_API XXH_errorcode
</span><span id="line6385" class="codeline ">XXH3_64bits_reset_withSecretandSeed(XXH_NOESCAPE XXH3_state_t* statePtr, XXH_NOESCAPE const void* secret, size_t secretSize, XXH64_hash_t seed64)
</span><span id="line6386" class="codeline ">{
</span><span id="line6387" class="codeline ">    if (statePtr == NULL) return XXH_ERROR;
</span><span id="line6388" class="codeline ">    if (secret == NULL) return XXH_ERROR;
</span><span id="line6389" class="codeline ">    if (secretSize &lt; XXH3_SECRET_SIZE_MIN) return XXH_ERROR;
</span><span id="line6390" class="codeline ">    XXH3_reset_internal(statePtr, seed64, secret, secretSize);
</span><span id="line6391" class="codeline ">    statePtr-&gt;useSeed = 1; /* always, even if seed64==0 */
</span><span id="line6392" class="codeline ">    return XXH_OK;
</span><span id="line6393" class="codeline ">}
</span><span id="line6394" class="codeline ">
</span><span id="line6395" class="codeline ">/*!
</span><span id="line6396" class="codeline "> * @internal
</span><span id="line6397" class="codeline "> * @brief Processes a large input for XXH3_update() and XXH3_digest_long().
</span><span id="line6398" class="codeline "> *
</span><span id="line6399" class="codeline "> * Unlike XXH3_hashLong_internal_loop(), this can process data that overlaps a block.
</span><span id="line6400" class="codeline "> *
</span><span id="line6401" class="codeline "> * @param acc                Pointer to the 8 accumulator lanes
</span><span id="line6402" class="codeline "> * @param nbStripesSoFarPtr  In/out pointer to the number of leftover stripes in the block*
</span><span id="line6403" class="codeline "> * @param nbStripesPerBlock  Number of stripes in a block
</span><span id="line6404" class="codeline "> * @param input              Input pointer
</span><span id="line6405" class="codeline "> * @param nbStripes          Number of stripes to process
</span><span id="line6406" class="codeline "> * @param secret             Secret pointer
</span><span id="line6407" class="codeline "> * @param secretLimit        Offset of the last block in @p secret
</span><span id="line6408" class="codeline "> * @param f_acc              Pointer to an XXH3_accumulate implementation
</span><span id="line6409" class="codeline "> * @param f_scramble         Pointer to an XXH3_scrambleAcc implementation
</span><span id="line6410" class="codeline "> * @return                   Pointer past the end of @p input after processing
</span><span id="line6411" class="codeline "> */
</span><span id="line6412" class="codeline ">XXH_FORCE_INLINE const xxh_u8 *
</span><span id="line6413" class="codeline ">XXH3_consumeStripes(xxh_u64* XXH_RESTRICT acc,
</span><span id="line6414" class="codeline ">                    size_t* XXH_RESTRICT nbStripesSoFarPtr, size_t nbStripesPerBlock,
</span><span id="line6415" class="codeline ">                    const xxh_u8* XXH_RESTRICT input, size_t nbStripes,
</span><span id="line6416" class="codeline ">                    const xxh_u8* XXH_RESTRICT secret, size_t secretLimit,
</span><span id="line6417" class="codeline ">                    XXH3_f_accumulate f_acc,
</span><span id="line6418" class="codeline ">                    XXH3_f_scrambleAcc f_scramble)
</span><span id="line6419" class="codeline ">{
</span><span id="line6420" class="codeline ">    const xxh_u8* initialSecret = secret + *nbStripesSoFarPtr * XXH_SECRET_CONSUME_RATE;
</span><span id="line6421" class="codeline ">    /* Process full blocks */
</span><span id="line6422" class="codeline ">    if (nbStripes &gt;= (nbStripesPerBlock - *nbStripesSoFarPtr)) {
</span><span id="line6423" class="codeline ">        /* Process the initial partial block... */
</span><span id="line6424" class="codeline ">        size_t nbStripesThisIter = nbStripesPerBlock - *nbStripesSoFarPtr;
</span><span id="line6425" class="codeline ">
</span><span id="line6426" class="codeline ">        do {
</span><span id="line6427" class="codeline ">            /* Accumulate and scramble */
</span><span id="line6428" class="codeline ">            f_acc(acc, input, initialSecret, nbStripesThisIter);
</span><span id="line6429" class="codeline ">            f_scramble(acc, secret + secretLimit);
</span><span id="line6430" class="codeline ">            input += nbStripesThisIter * XXH_STRIPE_LEN;
</span><span id="line6431" class="codeline ">            nbStripes -= nbStripesThisIter;
</span><span id="line6432" class="codeline ">            /* Then continue the loop with the full block size */
</span><span id="line6433" class="codeline ">            nbStripesThisIter = nbStripesPerBlock;
</span><span id="line6434" class="codeline ">            initialSecret = secret;
</span><span id="line6435" class="codeline ">        } while (nbStripes &gt;= nbStripesPerBlock);
</span><span id="line6436" class="codeline ">        *nbStripesSoFarPtr = 0;
</span><span id="line6437" class="codeline ">    }
</span><span id="line6438" class="codeline ">    /* Process a partial block */
</span><span id="line6439" class="codeline ">    if (nbStripes &gt; 0) {
</span><span id="line6440" class="codeline ">        f_acc(acc, input, initialSecret, nbStripes);
</span><span id="line6441" class="codeline ">        input += nbStripes * XXH_STRIPE_LEN;
</span><span id="line6442" class="codeline ">        *nbStripesSoFarPtr += nbStripes;
</span><span id="line6443" class="codeline ">    }
</span><span id="line6444" class="codeline ">    /* Return end pointer */
</span><span id="line6445" class="codeline ">    return input;
</span><span id="line6446" class="codeline ">}
</span><span id="line6447" class="codeline ">
</span><span id="line6448" class="codeline ">#ifndef XXH3_STREAM_USE_STACK
</span><span id="line6449" class="codeline "># if XXH_SIZE_OPT &lt;= 0 &amp;&amp; !defined(__clang__) /* clang doesn&#39;t need additional stack space */
</span><span id="line6450" class="codeline ">#   define XXH3_STREAM_USE_STACK 1
</span><span id="line6451" class="codeline "># endif
</span><span id="line6452" class="codeline ">#endif
</span><span id="line6453" class="codeline ">/*
</span><span id="line6454" class="codeline "> * Both XXH3_64bits_update and XXH3_128bits_update use this routine.
</span><span id="line6455" class="codeline "> */
</span><span id="line6456" class="codeline ">XXH_FORCE_INLINE XXH_errorcode
</span><span id="line6457" class="codeline ">XXH3_update(XXH3_state_t* XXH_RESTRICT const state,
</span><span id="line6458" class="codeline ">            const xxh_u8* XXH_RESTRICT input, size_t len,
</span><span id="line6459" class="codeline ">            XXH3_f_accumulate f_acc,
</span><span id="line6460" class="codeline ">            XXH3_f_scrambleAcc f_scramble)
</span><span id="line6461" class="codeline ">{
</span><span id="line6462" class="codeline ">    if (input==NULL) {
</span><span id="line6463" class="codeline ">        XXH_ASSERT(len == 0);
</span><span id="line6464" class="codeline ">        return XXH_OK;
</span><span id="line6465" class="codeline ">    }
</span><span id="line6466" class="codeline ">
</span><span id="line6467" class="codeline ">    XXH_ASSERT(state != NULL);
</span><span id="line6468" class="codeline ">    {   const xxh_u8* const bEnd = input + len;
</span><span id="line6469" class="codeline ">        const unsigned char* const secret = (state-&gt;extSecret == NULL) ? state-&gt;customSecret : state-&gt;extSecret;
</span><span id="line6470" class="codeline ">#if defined(XXH3_STREAM_USE_STACK) &amp;&amp; XXH3_STREAM_USE_STACK &gt;= 1
</span><span id="line6471" class="codeline ">        /* For some reason, gcc and MSVC seem to suffer greatly
</span><span id="line6472" class="codeline ">         * when operating accumulators directly into state.
</span><span id="line6473" class="codeline ">         * Operating into stack space seems to enable proper optimization.
</span><span id="line6474" class="codeline ">         * clang, on the other hand, doesn&#39;t seem to need this trick */
</span><span id="line6475" class="codeline ">        XXH_ALIGN(XXH_ACC_ALIGN) xxh_u64 acc[8];
</span><span id="line6476" class="codeline ">        XXH_memcpy(acc, state-&gt;acc, sizeof(acc));
</span><span id="line6477" class="codeline ">#else
</span><span id="line6478" class="codeline ">        xxh_u64* XXH_RESTRICT const acc = state-&gt;acc;
</span><span id="line6479" class="codeline ">#endif
</span><span id="line6480" class="codeline ">        state-&gt;totalLen += len;
</span><span id="line6481" class="codeline ">        XXH_ASSERT(state-&gt;bufferedSize &lt;= XXH3_INTERNALBUFFER_SIZE);
</span><span id="line6482" class="codeline ">
</span><span id="line6483" class="codeline ">        /* small input : just fill in tmp buffer */
</span><span id="line6484" class="codeline ">        if (len &lt;= XXH3_INTERNALBUFFER_SIZE - state-&gt;bufferedSize) {
</span><span id="line6485" class="codeline ">            XXH_memcpy(state-&gt;buffer + state-&gt;bufferedSize, input, len);
</span><span id="line6486" class="codeline ">            state-&gt;bufferedSize += (XXH32_hash_t)len;
</span><span id="line6487" class="codeline ">            return XXH_OK;
</span><span id="line6488" class="codeline ">        }
</span><span id="line6489" class="codeline ">
</span><span id="line6490" class="codeline ">        /* total input is now &gt; XXH3_INTERNALBUFFER_SIZE */
</span><span id="line6491" class="codeline ">        #define XXH3_INTERNALBUFFER_STRIPES (XXH3_INTERNALBUFFER_SIZE / XXH_STRIPE_LEN)
</span><span id="line6492" class="codeline ">        XXH_STATIC_ASSERT(XXH3_INTERNALBUFFER_SIZE % XXH_STRIPE_LEN == 0);   /* clean multiple */
</span><span id="line6493" class="codeline ">
</span><span id="line6494" class="codeline ">        /*
</span><span id="line6495" class="codeline ">         * Internal buffer is partially filled (always, except at beginning)
</span><span id="line6496" class="codeline ">         * Complete it, then consume it.
</span><span id="line6497" class="codeline ">         */
</span><span id="line6498" class="codeline ">        if (state-&gt;bufferedSize) {
</span><span id="line6499" class="codeline ">            size_t const loadSize = XXH3_INTERNALBUFFER_SIZE - state-&gt;bufferedSize;
</span><span id="line6500" class="codeline ">            XXH_memcpy(state-&gt;buffer + state-&gt;bufferedSize, input, loadSize);
</span><span id="line6501" class="codeline ">            input += loadSize;
</span><span id="line6502" class="codeline ">            XXH3_consumeStripes(acc,
</span><span id="line6503" class="codeline ">                               &amp;state-&gt;nbStripesSoFar, state-&gt;nbStripesPerBlock,
</span><span id="line6504" class="codeline ">                                state-&gt;buffer, XXH3_INTERNALBUFFER_STRIPES,
</span><span id="line6505" class="codeline ">                                secret, state-&gt;secretLimit,
</span><span id="line6506" class="codeline ">                                f_acc, f_scramble);
</span><span id="line6507" class="codeline ">            state-&gt;bufferedSize = 0;
</span><span id="line6508" class="codeline ">        }
</span><span id="line6509" class="codeline ">        XXH_ASSERT(input &lt; bEnd);
</span><span id="line6510" class="codeline ">        if (bEnd - input &gt; XXH3_INTERNALBUFFER_SIZE) {
</span><span id="line6511" class="codeline ">            size_t nbStripes = (size_t)(bEnd - 1 - input) / XXH_STRIPE_LEN;
</span><span id="line6512" class="codeline ">            input = XXH3_consumeStripes(acc,
</span><span id="line6513" class="codeline ">                                       &amp;state-&gt;nbStripesSoFar, state-&gt;nbStripesPerBlock,
</span><span id="line6514" class="codeline ">                                       input, nbStripes,
</span><span id="line6515" class="codeline ">                                       secret, state-&gt;secretLimit,
</span><span id="line6516" class="codeline ">                                       f_acc, f_scramble);
</span><span id="line6517" class="codeline ">            XXH_memcpy(state-&gt;buffer + sizeof(state-&gt;buffer) - XXH_STRIPE_LEN, input - XXH_STRIPE_LEN, XXH_STRIPE_LEN);
</span><span id="line6518" class="codeline ">
</span><span id="line6519" class="codeline ">        }
</span><span id="line6520" class="codeline ">        /* Some remaining input (always) : buffer it */
</span><span id="line6521" class="codeline ">        XXH_ASSERT(input &lt; bEnd);
</span><span id="line6522" class="codeline ">        XXH_ASSERT(bEnd - input &lt;= XXH3_INTERNALBUFFER_SIZE);
</span><span id="line6523" class="codeline ">        XXH_ASSERT(state-&gt;bufferedSize == 0);
</span><span id="line6524" class="codeline ">        XXH_memcpy(state-&gt;buffer, input, (size_t)(bEnd-input));
</span><span id="line6525" class="codeline ">        state-&gt;bufferedSize = (XXH32_hash_t)(bEnd-input);
</span><span id="line6526" class="codeline ">#if defined(XXH3_STREAM_USE_STACK) &amp;&amp; XXH3_STREAM_USE_STACK &gt;= 1
</span><span id="line6527" class="codeline ">        /* save stack accumulators into state */
</span><span id="line6528" class="codeline ">        XXH_memcpy(state-&gt;acc, acc, sizeof(acc));
</span><span id="line6529" class="codeline ">#endif
</span><span id="line6530" class="codeline ">    }
</span><span id="line6531" class="codeline ">
</span><span id="line6532" class="codeline ">    return XXH_OK;
</span><span id="line6533" class="codeline ">}
</span><span id="line6534" class="codeline ">
</span><span id="line6535" class="codeline ">/*! @ingroup XXH3_family */
</span><span id="line6536" class="codeline ">XXH_PUBLIC_API XXH_errorcode
</span><span id="line6537" class="codeline ">XXH3_64bits_update(XXH_NOESCAPE XXH3_state_t* state, XXH_NOESCAPE const void* input, size_t len)
</span><span id="line6538" class="codeline ">{
</span><span id="line6539" class="codeline ">    return XXH3_update(state, (const xxh_u8*)input, len,
</span><span id="line6540" class="codeline ">                       XXH3_accumulate, XXH3_scrambleAcc);
</span><span id="line6541" class="codeline ">}
</span><span id="line6542" class="codeline ">
</span><span id="line6543" class="codeline ">
</span><span id="line6544" class="codeline ">XXH_FORCE_INLINE void
</span><span id="line6545" class="codeline ">XXH3_digest_long (XXH64_hash_t* acc,
</span><span id="line6546" class="codeline ">                  const XXH3_state_t* state,
</span><span id="line6547" class="codeline ">                  const unsigned char* secret)
</span><span id="line6548" class="codeline ">{
</span><span id="line6549" class="codeline ">    xxh_u8 lastStripe[XXH_STRIPE_LEN];
</span><span id="line6550" class="codeline ">    const xxh_u8* lastStripePtr;
</span><span id="line6551" class="codeline ">
</span><span id="line6552" class="codeline ">    /*
</span><span id="line6553" class="codeline ">     * Digest on a local copy. This way, the state remains unaltered, and it can
</span><span id="line6554" class="codeline ">     * continue ingesting more input afterwards.
</span><span id="line6555" class="codeline ">     */
</span><span id="line6556" class="codeline ">    XXH_memcpy(acc, state-&gt;acc, sizeof(state-&gt;acc));
</span><span id="line6557" class="codeline ">    if (state-&gt;bufferedSize &gt;= XXH_STRIPE_LEN) {
</span><span id="line6558" class="codeline ">        /* Consume remaining stripes then point to remaining data in buffer */
</span><span id="line6559" class="codeline ">        size_t const nbStripes = (state-&gt;bufferedSize - 1) / XXH_STRIPE_LEN;
</span><span id="line6560" class="codeline ">        size_t nbStripesSoFar = state-&gt;nbStripesSoFar;
</span><span id="line6561" class="codeline ">        XXH3_consumeStripes(acc,
</span><span id="line6562" class="codeline ">                           &amp;nbStripesSoFar, state-&gt;nbStripesPerBlock,
</span><span id="line6563" class="codeline ">                            state-&gt;buffer, nbStripes,
</span><span id="line6564" class="codeline ">                            secret, state-&gt;secretLimit,
</span><span id="line6565" class="codeline ">                            XXH3_accumulate, XXH3_scrambleAcc);
</span><span id="line6566" class="codeline ">        lastStripePtr = state-&gt;buffer + state-&gt;bufferedSize - XXH_STRIPE_LEN;
</span><span id="line6567" class="codeline ">    } else {  /* bufferedSize &lt; XXH_STRIPE_LEN */
</span><span id="line6568" class="codeline ">        /* Copy to temp buffer */
</span><span id="line6569" class="codeline ">        size_t const catchupSize = XXH_STRIPE_LEN - state-&gt;bufferedSize;
</span><span id="line6570" class="codeline ">        XXH_ASSERT(state-&gt;bufferedSize &gt; 0);  /* there is always some input buffered */
</span><span id="line6571" class="codeline ">        XXH_memcpy(lastStripe, state-&gt;buffer + sizeof(state-&gt;buffer) - catchupSize, catchupSize);
</span><span id="line6572" class="codeline ">        XXH_memcpy(lastStripe + catchupSize, state-&gt;buffer, state-&gt;bufferedSize);
</span><span id="line6573" class="codeline ">        lastStripePtr = lastStripe;
</span><span id="line6574" class="codeline ">    }
</span><span id="line6575" class="codeline ">    /* Last stripe */
</span><span id="line6576" class="codeline ">    XXH3_accumulate_512(acc,
</span><span id="line6577" class="codeline ">                        lastStripePtr,
</span><span id="line6578" class="codeline ">                        secret + state-&gt;secretLimit - XXH_SECRET_LASTACC_START);
</span><span id="line6579" class="codeline ">}
</span><span id="line6580" class="codeline ">
</span><span id="line6581" class="codeline ">/*! @ingroup XXH3_family */
</span><span id="line6582" class="codeline ">XXH_PUBLIC_API XXH64_hash_t XXH3_64bits_digest (XXH_NOESCAPE const XXH3_state_t* state)
</span><span id="line6583" class="codeline ">{
</span><span id="line6584" class="codeline ">    const unsigned char* const secret = (state-&gt;extSecret == NULL) ? state-&gt;customSecret : state-&gt;extSecret;
</span><span id="line6585" class="codeline ">    if (state-&gt;totalLen &gt; XXH3_MIDSIZE_MAX) {
</span><span id="line6586" class="codeline ">        XXH_ALIGN(XXH_ACC_ALIGN) XXH64_hash_t acc[XXH_ACC_NB];
</span><span id="line6587" class="codeline ">        XXH3_digest_long(acc, state, secret);
</span><span id="line6588" class="codeline ">        return XXH3_finalizeLong_64b(acc, secret, (xxh_u64)state-&gt;totalLen);
</span><span id="line6589" class="codeline ">    }
</span><span id="line6590" class="codeline ">    /* totalLen &lt;= XXH3_MIDSIZE_MAX: digesting a short input */
</span><span id="line6591" class="codeline ">    if (state-&gt;useSeed)
</span><span id="line6592" class="codeline ">        return XXH3_64bits_withSeed(state-&gt;buffer, (size_t)state-&gt;totalLen, state-&gt;seed);
</span><span id="line6593" class="codeline ">    return XXH3_64bits_withSecret(state-&gt;buffer, (size_t)(state-&gt;totalLen),
</span><span id="line6594" class="codeline ">                                  secret, state-&gt;secretLimit + XXH_STRIPE_LEN);
</span><span id="line6595" class="codeline ">}
</span><span id="line6596" class="codeline ">#endif /* !XXH_NO_STREAM */
</span><span id="line6597" class="codeline ">
</span><span id="line6598" class="codeline ">
</span><span id="line6599" class="codeline ">/* ==========================================
</span><span id="line6600" class="codeline "> * XXH3 128 bits (a.k.a XXH128)
</span><span id="line6601" class="codeline "> * ==========================================
</span><span id="line6602" class="codeline "> * XXH3&#39;s 128-bit variant has better mixing and strength than the 64-bit variant,
</span><span id="line6603" class="codeline "> * even without counting the significantly larger output size.
</span><span id="line6604" class="codeline "> *
</span><span id="line6605" class="codeline "> * For example, extra steps are taken to avoid the seed-dependent collisions
</span><span id="line6606" class="codeline "> * in 17-240 byte inputs (See XXH3_mix16B and XXH128_mix32B).
</span><span id="line6607" class="codeline "> *
</span><span id="line6608" class="codeline "> * This strength naturally comes at the cost of some speed, especially on short
</span><span id="line6609" class="codeline "> * lengths. Note that longer hashes are about as fast as the 64-bit version
</span><span id="line6610" class="codeline "> * due to it using only a slight modification of the 64-bit loop.
</span><span id="line6611" class="codeline "> *
</span><span id="line6612" class="codeline "> * XXH128 is also more oriented towards 64-bit machines. It is still extremely
</span><span id="line6613" class="codeline "> * fast for a _128-bit_ hash on 32-bit (it usually clears XXH64).
</span><span id="line6614" class="codeline "> */
</span><span id="line6615" class="codeline ">
</span><span id="line6616" class="codeline ">XXH_FORCE_INLINE XXH_PUREF XXH128_hash_t
</span><span id="line6617" class="codeline ">XXH3_len_1to3_128b(const xxh_u8* input, size_t len, const xxh_u8* secret, XXH64_hash_t seed)
</span><span id="line6618" class="codeline ">{
</span><span id="line6619" class="codeline ">    /* A doubled version of 1to3_64b with different constants. */
</span><span id="line6620" class="codeline ">    XXH_ASSERT(input != NULL);
</span><span id="line6621" class="codeline ">    XXH_ASSERT(1 &lt;= len &amp;&amp; len &lt;= 3);
</span><span id="line6622" class="codeline ">    XXH_ASSERT(secret != NULL);
</span><span id="line6623" class="codeline ">    /*
</span><span id="line6624" class="codeline ">     * len = 1: combinedl = { input[0], 0x01, input[0], input[0] }
</span><span id="line6625" class="codeline ">     * len = 2: combinedl = { input[1], 0x02, input[0], input[1] }
</span><span id="line6626" class="codeline ">     * len = 3: combinedl = { input[2], 0x03, input[0], input[1] }
</span><span id="line6627" class="codeline ">     */
</span><span id="line6628" class="codeline ">    {   xxh_u8 const c1 = input[0];
</span><span id="line6629" class="codeline ">        xxh_u8 const c2 = input[len &gt;&gt; 1];
</span><span id="line6630" class="codeline ">        xxh_u8 const c3 = input[len - 1];
</span><span id="line6631" class="codeline ">        xxh_u32 const combinedl = ((xxh_u32)c1 &lt;&lt;16) | ((xxh_u32)c2 &lt;&lt; 24)
</span><span id="line6632" class="codeline ">                                | ((xxh_u32)c3 &lt;&lt; 0) | ((xxh_u32)len &lt;&lt; 8);
</span><span id="line6633" class="codeline ">        xxh_u32 const combinedh = XXH_rotl32(XXH_swap32(combinedl), 13);
</span><span id="line6634" class="codeline ">        xxh_u64 const bitflipl = (XXH_readLE32(secret) ^ XXH_readLE32(secret+4)) + seed;
</span><span id="line6635" class="codeline ">        xxh_u64 const bitfliph = (XXH_readLE32(secret+8) ^ XXH_readLE32(secret+12)) - seed;
</span><span id="line6636" class="codeline ">        xxh_u64 const keyed_lo = (xxh_u64)combinedl ^ bitflipl;
</span><span id="line6637" class="codeline ">        xxh_u64 const keyed_hi = (xxh_u64)combinedh ^ bitfliph;
</span><span id="line6638" class="codeline ">        XXH128_hash_t h128;
</span><span id="line6639" class="codeline ">        h128.low64  = XXH64_avalanche(keyed_lo);
</span><span id="line6640" class="codeline ">        h128.high64 = XXH64_avalanche(keyed_hi);
</span><span id="line6641" class="codeline ">        return h128;
</span><span id="line6642" class="codeline ">    }
</span><span id="line6643" class="codeline ">}
</span><span id="line6644" class="codeline ">
</span><span id="line6645" class="codeline ">XXH_FORCE_INLINE XXH_PUREF XXH128_hash_t
</span><span id="line6646" class="codeline ">XXH3_len_4to8_128b(const xxh_u8* input, size_t len, const xxh_u8* secret, XXH64_hash_t seed)
</span><span id="line6647" class="codeline ">{
</span><span id="line6648" class="codeline ">    XXH_ASSERT(input != NULL);
</span><span id="line6649" class="codeline ">    XXH_ASSERT(secret != NULL);
</span><span id="line6650" class="codeline ">    XXH_ASSERT(4 &lt;= len &amp;&amp; len &lt;= 8);
</span><span id="line6651" class="codeline ">    seed ^= (xxh_u64)XXH_swap32((xxh_u32)seed) &lt;&lt; 32;
</span><span id="line6652" class="codeline ">    {   xxh_u32 const input_lo = XXH_readLE32(input);
</span><span id="line6653" class="codeline ">        xxh_u32 const input_hi = XXH_readLE32(input + len - 4);
</span><span id="line6654" class="codeline ">        xxh_u64 const input_64 = input_lo + ((xxh_u64)input_hi &lt;&lt; 32);
</span><span id="line6655" class="codeline ">        xxh_u64 const bitflip = (XXH_readLE64(secret+16) ^ XXH_readLE64(secret+24)) + seed;
</span><span id="line6656" class="codeline ">        xxh_u64 const keyed = input_64 ^ bitflip;
</span><span id="line6657" class="codeline ">
</span><span id="line6658" class="codeline ">        /* Shift len to the left to ensure it is even, this avoids even multiplies. */
</span><span id="line6659" class="codeline ">        XXH128_hash_t m128 = XXH_mult64to128(keyed, XXH_PRIME64_1 + (len &lt;&lt; 2));
</span><span id="line6660" class="codeline ">
</span><span id="line6661" class="codeline ">        m128.high64 += (m128.low64 &lt;&lt; 1);
</span><span id="line6662" class="codeline ">        m128.low64  ^= (m128.high64 &gt;&gt; 3);
</span><span id="line6663" class="codeline ">
</span><span id="line6664" class="codeline ">        m128.low64   = XXH_xorshift64(m128.low64, 35);
</span><span id="line6665" class="codeline ">        m128.low64  *= PRIME_MX2;
</span><span id="line6666" class="codeline ">        m128.low64   = XXH_xorshift64(m128.low64, 28);
</span><span id="line6667" class="codeline ">        m128.high64  = XXH3_avalanche(m128.high64);
</span><span id="line6668" class="codeline ">        return m128;
</span><span id="line6669" class="codeline ">    }
</span><span id="line6670" class="codeline ">}
</span><span id="line6671" class="codeline ">
</span><span id="line6672" class="codeline ">XXH_FORCE_INLINE XXH_PUREF XXH128_hash_t
</span><span id="line6673" class="codeline ">XXH3_len_9to16_128b(const xxh_u8* input, size_t len, const xxh_u8* secret, XXH64_hash_t seed)
</span><span id="line6674" class="codeline ">{
</span><span id="line6675" class="codeline ">    XXH_ASSERT(input != NULL);
</span><span id="line6676" class="codeline ">    XXH_ASSERT(secret != NULL);
</span><span id="line6677" class="codeline ">    XXH_ASSERT(9 &lt;= len &amp;&amp; len &lt;= 16);
</span><span id="line6678" class="codeline ">    {   xxh_u64 const bitflipl = (XXH_readLE64(secret+32) ^ XXH_readLE64(secret+40)) - seed;
</span><span id="line6679" class="codeline ">        xxh_u64 const bitfliph = (XXH_readLE64(secret+48) ^ XXH_readLE64(secret+56)) + seed;
</span><span id="line6680" class="codeline ">        xxh_u64 const input_lo = XXH_readLE64(input);
</span><span id="line6681" class="codeline ">        xxh_u64       input_hi = XXH_readLE64(input + len - 8);
</span><span id="line6682" class="codeline ">        XXH128_hash_t m128 = XXH_mult64to128(input_lo ^ input_hi ^ bitflipl, XXH_PRIME64_1);
</span><span id="line6683" class="codeline ">        /*
</span><span id="line6684" class="codeline ">         * Put len in the middle of m128 to ensure that the length gets mixed to
</span><span id="line6685" class="codeline ">         * both the low and high bits in the 128x64 multiply below.
</span><span id="line6686" class="codeline ">         */
</span><span id="line6687" class="codeline ">        m128.low64 += (xxh_u64)(len - 1) &lt;&lt; 54;
</span><span id="line6688" class="codeline ">        input_hi   ^= bitfliph;
</span><span id="line6689" class="codeline ">        /*
</span><span id="line6690" class="codeline ">         * Add the high 32 bits of input_hi to the high 32 bits of m128, then
</span><span id="line6691" class="codeline ">         * add the long product of the low 32 bits of input_hi and XXH_PRIME32_2 to
</span><span id="line6692" class="codeline ">         * the high 64 bits of m128.
</span><span id="line6693" class="codeline ">         *
</span><span id="line6694" class="codeline ">         * The best approach to this operation is different on 32-bit and 64-bit.
</span><span id="line6695" class="codeline ">         */
</span><span id="line6696" class="codeline ">        if (sizeof(void *) &lt; sizeof(xxh_u64)) { /* 32-bit */
</span><span id="line6697" class="codeline ">            /*
</span><span id="line6698" class="codeline ">             * 32-bit optimized version, which is more readable.
</span><span id="line6699" class="codeline ">             *
</span><span id="line6700" class="codeline ">             * On 32-bit, it removes an ADC and delays a dependency between the two
</span><span id="line6701" class="codeline ">             * halves of m128.high64, but it generates an extra mask on 64-bit.
</span><span id="line6702" class="codeline ">             */
</span><span id="line6703" class="codeline ">            m128.high64 += (input_hi &amp; 0xFFFFFFFF00000000ULL) + XXH_mult32to64((xxh_u32)input_hi, XXH_PRIME32_2);
</span><span id="line6704" class="codeline ">        } else {
</span><span id="line6705" class="codeline ">            /*
</span><span id="line6706" class="codeline ">             * 64-bit optimized (albeit more confusing) version.
</span><span id="line6707" class="codeline ">             *
</span><span id="line6708" class="codeline ">             * Uses some properties of addition and multiplication to remove the mask:
</span><span id="line6709" class="codeline ">             *
</span><span id="line6710" class="codeline ">             * Let:
</span><span id="line6711" class="codeline ">             *    a = input_hi.lo = (input_hi &amp; 0x00000000FFFFFFFF)
</span><span id="line6712" class="codeline ">             *    b = input_hi.hi = (input_hi &amp; 0xFFFFFFFF00000000)
</span><span id="line6713" class="codeline ">             *    c = XXH_PRIME32_2
</span><span id="line6714" class="codeline ">             *
</span><span id="line6715" class="codeline ">             *    a + (b * c)
</span><span id="line6716" class="codeline ">             * Inverse Property: x + y - x == y
</span><span id="line6717" class="codeline ">             *    a + (b * (1 + c - 1))
</span><span id="line6718" class="codeline ">             * Distributive Property: x * (y + z) == (x * y) + (x * z)
</span><span id="line6719" class="codeline ">             *    a + (b * 1) + (b * (c - 1))
</span><span id="line6720" class="codeline ">             * Identity Property: x * 1 == x
</span><span id="line6721" class="codeline ">             *    a + b + (b * (c - 1))
</span><span id="line6722" class="codeline ">             *
</span><span id="line6723" class="codeline ">             * Substitute a, b, and c:
</span><span id="line6724" class="codeline ">             *    input_hi.hi + input_hi.lo + ((xxh_u64)input_hi.lo * (XXH_PRIME32_2 - 1))
</span><span id="line6725" class="codeline ">             *
</span><span id="line6726" class="codeline ">             * Since input_hi.hi + input_hi.lo == input_hi, we get this:
</span><span id="line6727" class="codeline ">             *    input_hi + ((xxh_u64)input_hi.lo * (XXH_PRIME32_2 - 1))
</span><span id="line6728" class="codeline ">             */
</span><span id="line6729" class="codeline ">            m128.high64 += input_hi + XXH_mult32to64((xxh_u32)input_hi, XXH_PRIME32_2 - 1);
</span><span id="line6730" class="codeline ">        }
</span><span id="line6731" class="codeline ">        /* m128 ^= XXH_swap64(m128 &gt;&gt; 64); */
</span><span id="line6732" class="codeline ">        m128.low64  ^= XXH_swap64(m128.high64);
</span><span id="line6733" class="codeline ">
</span><span id="line6734" class="codeline ">        {   /* 128x64 multiply: h128 = m128 * XXH_PRIME64_2; */
</span><span id="line6735" class="codeline ">            XXH128_hash_t h128 = XXH_mult64to128(m128.low64, XXH_PRIME64_2);
</span><span id="line6736" class="codeline ">            h128.high64 += m128.high64 * XXH_PRIME64_2;
</span><span id="line6737" class="codeline ">
</span><span id="line6738" class="codeline ">            h128.low64   = XXH3_avalanche(h128.low64);
</span><span id="line6739" class="codeline ">            h128.high64  = XXH3_avalanche(h128.high64);
</span><span id="line6740" class="codeline ">            return h128;
</span><span id="line6741" class="codeline ">    }   }
</span><span id="line6742" class="codeline ">}
</span><span id="line6743" class="codeline ">
</span><span id="line6744" class="codeline ">/*
</span><span id="line6745" class="codeline "> * Assumption: `secret` size is &gt;= XXH3_SECRET_SIZE_MIN
</span><span id="line6746" class="codeline "> */
</span><span id="line6747" class="codeline ">XXH_FORCE_INLINE XXH_PUREF XXH128_hash_t
</span><span id="line6748" class="codeline ">XXH3_len_0to16_128b(const xxh_u8* input, size_t len, const xxh_u8* secret, XXH64_hash_t seed)
</span><span id="line6749" class="codeline ">{
</span><span id="line6750" class="codeline ">    XXH_ASSERT(len &lt;= 16);
</span><span id="line6751" class="codeline ">    {   if (len &gt; 8) return XXH3_len_9to16_128b(input, len, secret, seed);
</span><span id="line6752" class="codeline ">        if (len &gt;= 4) return XXH3_len_4to8_128b(input, len, secret, seed);
</span><span id="line6753" class="codeline ">        if (len) return XXH3_len_1to3_128b(input, len, secret, seed);
</span><span id="line6754" class="codeline ">        {   XXH128_hash_t h128;
</span><span id="line6755" class="codeline ">            xxh_u64 const bitflipl = XXH_readLE64(secret+64) ^ XXH_readLE64(secret+72);
</span><span id="line6756" class="codeline ">            xxh_u64 const bitfliph = XXH_readLE64(secret+80) ^ XXH_readLE64(secret+88);
</span><span id="line6757" class="codeline ">            h128.low64 = XXH64_avalanche(seed ^ bitflipl);
</span><span id="line6758" class="codeline ">            h128.high64 = XXH64_avalanche( seed ^ bitfliph);
</span><span id="line6759" class="codeline ">            return h128;
</span><span id="line6760" class="codeline ">    }   }
</span><span id="line6761" class="codeline ">}
</span><span id="line6762" class="codeline ">
</span><span id="line6763" class="codeline ">/*
</span><span id="line6764" class="codeline "> * A bit slower than XXH3_mix16B, but handles multiply by zero better.
</span><span id="line6765" class="codeline "> */
</span><span id="line6766" class="codeline ">XXH_FORCE_INLINE XXH128_hash_t
</span><span id="line6767" class="codeline ">XXH128_mix32B(XXH128_hash_t acc, const xxh_u8* input_1, const xxh_u8* input_2,
</span><span id="line6768" class="codeline ">              const xxh_u8* secret, XXH64_hash_t seed)
</span><span id="line6769" class="codeline ">{
</span><span id="line6770" class="codeline ">    acc.low64  += XXH3_mix16B (input_1, secret+0, seed);
</span><span id="line6771" class="codeline ">    acc.low64  ^= XXH_readLE64(input_2) + XXH_readLE64(input_2 + 8);
</span><span id="line6772" class="codeline ">    acc.high64 += XXH3_mix16B (input_2, secret+16, seed);
</span><span id="line6773" class="codeline ">    acc.high64 ^= XXH_readLE64(input_1) + XXH_readLE64(input_1 + 8);
</span><span id="line6774" class="codeline ">    return acc;
</span><span id="line6775" class="codeline ">}
</span><span id="line6776" class="codeline ">
</span><span id="line6777" class="codeline ">
</span><span id="line6778" class="codeline ">XXH_FORCE_INLINE XXH_PUREF XXH128_hash_t
</span><span id="line6779" class="codeline ">XXH3_len_17to128_128b(const xxh_u8* XXH_RESTRICT input, size_t len,
</span><span id="line6780" class="codeline ">                      const xxh_u8* XXH_RESTRICT secret, size_t secretSize,
</span><span id="line6781" class="codeline ">                      XXH64_hash_t seed)
</span><span id="line6782" class="codeline ">{
</span><span id="line6783" class="codeline ">    XXH_ASSERT(secretSize &gt;= XXH3_SECRET_SIZE_MIN); (void)secretSize;
</span><span id="line6784" class="codeline ">    XXH_ASSERT(16 &lt; len &amp;&amp; len &lt;= 128);
</span><span id="line6785" class="codeline ">
</span><span id="line6786" class="codeline ">    {   XXH128_hash_t acc;
</span><span id="line6787" class="codeline ">        acc.low64 = len * XXH_PRIME64_1;
</span><span id="line6788" class="codeline ">        acc.high64 = 0;
</span><span id="line6789" class="codeline ">
</span><span id="line6790" class="codeline ">#if XXH_SIZE_OPT &gt;= 1
</span><span id="line6791" class="codeline ">        {
</span><span id="line6792" class="codeline ">            /* Smaller, but slightly slower. */
</span><span id="line6793" class="codeline ">            unsigned int i = (unsigned int)(len - 1) / 32;
</span><span id="line6794" class="codeline ">            do {
</span><span id="line6795" class="codeline ">                acc = XXH128_mix32B(acc, input+16*i, input+len-16*(i+1), secret+32*i, seed);
</span><span id="line6796" class="codeline ">            } while (i-- != 0);
</span><span id="line6797" class="codeline ">        }
</span><span id="line6798" class="codeline ">#else
</span><span id="line6799" class="codeline ">        if (len &gt; 32) {
</span><span id="line6800" class="codeline ">            if (len &gt; 64) {
</span><span id="line6801" class="codeline ">                if (len &gt; 96) {
</span><span id="line6802" class="codeline ">                    acc = XXH128_mix32B(acc, input+48, input+len-64, secret+96, seed);
</span><span id="line6803" class="codeline ">                }
</span><span id="line6804" class="codeline ">                acc = XXH128_mix32B(acc, input+32, input+len-48, secret+64, seed);
</span><span id="line6805" class="codeline ">            }
</span><span id="line6806" class="codeline ">            acc = XXH128_mix32B(acc, input+16, input+len-32, secret+32, seed);
</span><span id="line6807" class="codeline ">        }
</span><span id="line6808" class="codeline ">        acc = XXH128_mix32B(acc, input, input+len-16, secret, seed);
</span><span id="line6809" class="codeline ">#endif
</span><span id="line6810" class="codeline ">        {   XXH128_hash_t h128;
</span><span id="line6811" class="codeline ">            h128.low64  = acc.low64 + acc.high64;
</span><span id="line6812" class="codeline ">            h128.high64 = (acc.low64    * XXH_PRIME64_1)
</span><span id="line6813" class="codeline ">                        + (acc.high64   * XXH_PRIME64_4)
</span><span id="line6814" class="codeline ">                        + ((len - seed) * XXH_PRIME64_2);
</span><span id="line6815" class="codeline ">            h128.low64  = XXH3_avalanche(h128.low64);
</span><span id="line6816" class="codeline ">            h128.high64 = (XXH64_hash_t)0 - XXH3_avalanche(h128.high64);
</span><span id="line6817" class="codeline ">            return h128;
</span><span id="line6818" class="codeline ">        }
</span><span id="line6819" class="codeline ">    }
</span><span id="line6820" class="codeline ">}
</span><span id="line6821" class="codeline ">
</span><span id="line6822" class="codeline ">XXH_NO_INLINE XXH_PUREF XXH128_hash_t
</span><span id="line6823" class="codeline ">XXH3_len_129to240_128b(const xxh_u8* XXH_RESTRICT input, size_t len,
</span><span id="line6824" class="codeline ">                       const xxh_u8* XXH_RESTRICT secret, size_t secretSize,
</span><span id="line6825" class="codeline ">                       XXH64_hash_t seed)
</span><span id="line6826" class="codeline ">{
</span><span id="line6827" class="codeline ">    XXH_ASSERT(secretSize &gt;= XXH3_SECRET_SIZE_MIN); (void)secretSize;
</span><span id="line6828" class="codeline ">    XXH_ASSERT(128 &lt; len &amp;&amp; len &lt;= XXH3_MIDSIZE_MAX);
</span><span id="line6829" class="codeline ">
</span><span id="line6830" class="codeline ">    {   XXH128_hash_t acc;
</span><span id="line6831" class="codeline ">        unsigned i;
</span><span id="line6832" class="codeline ">        acc.low64 = len * XXH_PRIME64_1;
</span><span id="line6833" class="codeline ">        acc.high64 = 0;
</span><span id="line6834" class="codeline ">        /*
</span><span id="line6835" class="codeline ">         *  We set as `i` as offset + 32. We do this so that unchanged
</span><span id="line6836" class="codeline ">         * `len` can be used as upper bound. This reaches a sweet spot
</span><span id="line6837" class="codeline ">         * where both x86 and aarch64 get simple agen and good codegen
</span><span id="line6838" class="codeline ">         * for the loop.
</span><span id="line6839" class="codeline ">         */
</span><span id="line6840" class="codeline ">        for (i = 32; i &lt; 160; i += 32) {
</span><span id="line6841" class="codeline ">            acc = XXH128_mix32B(acc,
</span><span id="line6842" class="codeline ">                                input  + i - 32,
</span><span id="line6843" class="codeline ">                                input  + i - 16,
</span><span id="line6844" class="codeline ">                                secret + i - 32,
</span><span id="line6845" class="codeline ">                                seed);
</span><span id="line6846" class="codeline ">        }
</span><span id="line6847" class="codeline ">        acc.low64 = XXH3_avalanche(acc.low64);
</span><span id="line6848" class="codeline ">        acc.high64 = XXH3_avalanche(acc.high64);
</span><span id="line6849" class="codeline ">        /*
</span><span id="line6850" class="codeline ">         * NB: `i &lt;= len` will duplicate the last 32-bytes if
</span><span id="line6851" class="codeline ">         * len % 32 was zero. This is an unfortunate necessity to keep
</span><span id="line6852" class="codeline ">         * the hash result stable.
</span><span id="line6853" class="codeline ">         */
</span><span id="line6854" class="codeline ">        for (i=160; i &lt;= len; i += 32) {
</span><span id="line6855" class="codeline ">            acc = XXH128_mix32B(acc,
</span><span id="line6856" class="codeline ">                                input + i - 32,
</span><span id="line6857" class="codeline ">                                input + i - 16,
</span><span id="line6858" class="codeline ">                                secret + XXH3_MIDSIZE_STARTOFFSET + i - 160,
</span><span id="line6859" class="codeline ">                                seed);
</span><span id="line6860" class="codeline ">        }
</span><span id="line6861" class="codeline ">        /* last bytes */
</span><span id="line6862" class="codeline ">        acc = XXH128_mix32B(acc,
</span><span id="line6863" class="codeline ">                            input + len - 16,
</span><span id="line6864" class="codeline ">                            input + len - 32,
</span><span id="line6865" class="codeline ">                            secret + XXH3_SECRET_SIZE_MIN - XXH3_MIDSIZE_LASTOFFSET - 16,
</span><span id="line6866" class="codeline ">                            (XXH64_hash_t)0 - seed);
</span><span id="line6867" class="codeline ">
</span><span id="line6868" class="codeline ">        {   XXH128_hash_t h128;
</span><span id="line6869" class="codeline ">            h128.low64  = acc.low64 + acc.high64;
</span><span id="line6870" class="codeline ">            h128.high64 = (acc.low64    * XXH_PRIME64_1)
</span><span id="line6871" class="codeline ">                        + (acc.high64   * XXH_PRIME64_4)
</span><span id="line6872" class="codeline ">                        + ((len - seed) * XXH_PRIME64_2);
</span><span id="line6873" class="codeline ">            h128.low64  = XXH3_avalanche(h128.low64);
</span><span id="line6874" class="codeline ">            h128.high64 = (XXH64_hash_t)0 - XXH3_avalanche(h128.high64);
</span><span id="line6875" class="codeline ">            return h128;
</span><span id="line6876" class="codeline ">        }
</span><span id="line6877" class="codeline ">    }
</span><span id="line6878" class="codeline ">}
</span><span id="line6879" class="codeline ">
</span><span id="line6880" class="codeline ">static XXH_PUREF XXH128_hash_t
</span><span id="line6881" class="codeline ">XXH3_finalizeLong_128b(const xxh_u64* XXH_RESTRICT acc, const xxh_u8* XXH_RESTRICT secret, size_t secretSize, xxh_u64 len)
</span><span id="line6882" class="codeline ">{
</span><span id="line6883" class="codeline ">    XXH128_hash_t h128;
</span><span id="line6884" class="codeline ">    h128.low64 = XXH3_finalizeLong_64b(acc, secret, len);
</span><span id="line6885" class="codeline ">    h128.high64 = XXH3_mergeAccs(acc, secret + secretSize
</span><span id="line6886" class="codeline ">                                             - XXH_STRIPE_LEN - XXH_SECRET_MERGEACCS_START,
</span><span id="line6887" class="codeline ">                                             ~(len * XXH_PRIME64_2));
</span><span id="line6888" class="codeline ">    return h128;
</span><span id="line6889" class="codeline ">}
</span><span id="line6890" class="codeline ">
</span><span id="line6891" class="codeline ">XXH_FORCE_INLINE XXH128_hash_t
</span><span id="line6892" class="codeline ">XXH3_hashLong_128b_internal(const void* XXH_RESTRICT input, size_t len,
</span><span id="line6893" class="codeline ">                            const xxh_u8* XXH_RESTRICT secret, size_t secretSize,
</span><span id="line6894" class="codeline ">                            XXH3_f_accumulate f_acc,
</span><span id="line6895" class="codeline ">                            XXH3_f_scrambleAcc f_scramble)
</span><span id="line6896" class="codeline ">{
</span><span id="line6897" class="codeline ">    XXH_ALIGN(XXH_ACC_ALIGN) xxh_u64 acc[XXH_ACC_NB] = XXH3_INIT_ACC;
</span><span id="line6898" class="codeline ">
</span><span id="line6899" class="codeline ">    XXH3_hashLong_internal_loop(acc, (const xxh_u8*)input, len, secret, secretSize, f_acc, f_scramble);
</span><span id="line6900" class="codeline ">
</span><span id="line6901" class="codeline ">    /* converge into final hash */
</span><span id="line6902" class="codeline ">    XXH_STATIC_ASSERT(sizeof(acc) == 64);
</span><span id="line6903" class="codeline ">    XXH_ASSERT(secretSize &gt;= sizeof(acc) + XXH_SECRET_MERGEACCS_START);
</span><span id="line6904" class="codeline ">    return XXH3_finalizeLong_128b(acc, secret, secretSize, (xxh_u64)len);
</span><span id="line6905" class="codeline ">}
</span><span id="line6906" class="codeline ">
</span><span id="line6907" class="codeline ">/*
</span><span id="line6908" class="codeline "> * It&#39;s important for performance that XXH3_hashLong() is not inlined.
</span><span id="line6909" class="codeline "> */
</span><span id="line6910" class="codeline ">XXH_NO_INLINE XXH_PUREF XXH128_hash_t
</span><span id="line6911" class="codeline ">XXH3_hashLong_128b_default(const void* XXH_RESTRICT input, size_t len,
</span><span id="line6912" class="codeline ">                           XXH64_hash_t seed64,
</span><span id="line6913" class="codeline ">                           const void* XXH_RESTRICT secret, size_t secretLen)
</span><span id="line6914" class="codeline ">{
</span><span id="line6915" class="codeline ">    (void)seed64; (void)secret; (void)secretLen;
</span><span id="line6916" class="codeline ">    return XXH3_hashLong_128b_internal(input, len, XXH3_kSecret, sizeof(XXH3_kSecret),
</span><span id="line6917" class="codeline ">                                       XXH3_accumulate, XXH3_scrambleAcc);
</span><span id="line6918" class="codeline ">}
</span><span id="line6919" class="codeline ">
</span><span id="line6920" class="codeline ">/*
</span><span id="line6921" class="codeline "> * It&#39;s important for performance to pass @p secretLen (when it&#39;s static)
</span><span id="line6922" class="codeline "> * to the compiler, so that it can properly optimize the vectorized loop.
</span><span id="line6923" class="codeline "> *
</span><span id="line6924" class="codeline "> * When the secret size is unknown, or on GCC 12 where the mix of NO_INLINE and FORCE_INLINE
</span><span id="line6925" class="codeline "> * breaks -Og, this is XXH_NO_INLINE.
</span><span id="line6926" class="codeline "> */
</span><span id="line6927" class="codeline ">XXH3_WITH_SECRET_INLINE XXH128_hash_t
</span><span id="line6928" class="codeline ">XXH3_hashLong_128b_withSecret(const void* XXH_RESTRICT input, size_t len,
</span><span id="line6929" class="codeline ">                              XXH64_hash_t seed64,
</span><span id="line6930" class="codeline ">                              const void* XXH_RESTRICT secret, size_t secretLen)
</span><span id="line6931" class="codeline ">{
</span><span id="line6932" class="codeline ">    (void)seed64;
</span><span id="line6933" class="codeline ">    return XXH3_hashLong_128b_internal(input, len, (const xxh_u8*)secret, secretLen,
</span><span id="line6934" class="codeline ">                                       XXH3_accumulate, XXH3_scrambleAcc);
</span><span id="line6935" class="codeline ">}
</span><span id="line6936" class="codeline ">
</span><span id="line6937" class="codeline ">XXH_FORCE_INLINE XXH128_hash_t
</span><span id="line6938" class="codeline ">XXH3_hashLong_128b_withSeed_internal(const void* XXH_RESTRICT input, size_t len,
</span><span id="line6939" class="codeline ">                                XXH64_hash_t seed64,
</span><span id="line6940" class="codeline ">                                XXH3_f_accumulate f_acc,
</span><span id="line6941" class="codeline ">                                XXH3_f_scrambleAcc f_scramble,
</span><span id="line6942" class="codeline ">                                XXH3_f_initCustomSecret f_initSec)
</span><span id="line6943" class="codeline ">{
</span><span id="line6944" class="codeline ">    if (seed64 == 0)
</span><span id="line6945" class="codeline ">        return XXH3_hashLong_128b_internal(input, len,
</span><span id="line6946" class="codeline ">                                           XXH3_kSecret, sizeof(XXH3_kSecret),
</span><span id="line6947" class="codeline ">                                           f_acc, f_scramble);
</span><span id="line6948" class="codeline ">    {   XXH_ALIGN(XXH_SEC_ALIGN) xxh_u8 secret[XXH_SECRET_DEFAULT_SIZE];
</span><span id="line6949" class="codeline ">        f_initSec(secret, seed64);
</span><span id="line6950" class="codeline ">        return XXH3_hashLong_128b_internal(input, len, (const xxh_u8*)secret, sizeof(secret),
</span><span id="line6951" class="codeline ">                                           f_acc, f_scramble);
</span><span id="line6952" class="codeline ">    }
</span><span id="line6953" class="codeline ">}
</span><span id="line6954" class="codeline ">
</span><span id="line6955" class="codeline ">/*
</span><span id="line6956" class="codeline "> * It&#39;s important for performance that XXH3_hashLong is not inlined.
</span><span id="line6957" class="codeline "> */
</span><span id="line6958" class="codeline ">XXH_NO_INLINE XXH128_hash_t
</span><span id="line6959" class="codeline ">XXH3_hashLong_128b_withSeed(const void* input, size_t len,
</span><span id="line6960" class="codeline ">                            XXH64_hash_t seed64, const void* XXH_RESTRICT secret, size_t secretLen)
</span><span id="line6961" class="codeline ">{
</span><span id="line6962" class="codeline ">    (void)secret; (void)secretLen;
</span><span id="line6963" class="codeline ">    return XXH3_hashLong_128b_withSeed_internal(input, len, seed64,
</span><span id="line6964" class="codeline ">                XXH3_accumulate, XXH3_scrambleAcc, XXH3_initCustomSecret);
</span><span id="line6965" class="codeline ">}
</span><span id="line6966" class="codeline ">
</span><span id="line6967" class="codeline ">typedef XXH128_hash_t (*XXH3_hashLong128_f)(const void* XXH_RESTRICT, size_t,
</span><span id="line6968" class="codeline ">                                            XXH64_hash_t, const void* XXH_RESTRICT, size_t);
</span><span id="line6969" class="codeline ">
</span><span id="line6970" class="codeline ">XXH_FORCE_INLINE XXH128_hash_t
</span><span id="line6971" class="codeline ">XXH3_128bits_internal(const void* input, size_t len,
</span><span id="line6972" class="codeline ">                      XXH64_hash_t seed64, const void* XXH_RESTRICT secret, size_t secretLen,
</span><span id="line6973" class="codeline ">                      XXH3_hashLong128_f f_hl128)
</span><span id="line6974" class="codeline ">{
</span><span id="line6975" class="codeline ">    XXH_ASSERT(secretLen &gt;= XXH3_SECRET_SIZE_MIN);
</span><span id="line6976" class="codeline ">    /*
</span><span id="line6977" class="codeline ">     * If an action is to be taken if `secret` conditions are not respected,
</span><span id="line6978" class="codeline ">     * it should be done here.
</span><span id="line6979" class="codeline ">     * For now, it&#39;s a contract pre-condition.
</span><span id="line6980" class="codeline ">     * Adding a check and a branch here would cost performance at every hash.
</span><span id="line6981" class="codeline ">     */
</span><span id="line6982" class="codeline ">    if (len &lt;= 16)
</span><span id="line6983" class="codeline ">        return XXH3_len_0to16_128b((const xxh_u8*)input, len, (const xxh_u8*)secret, seed64);
</span><span id="line6984" class="codeline ">    if (len &lt;= 128)
</span><span id="line6985" class="codeline ">        return XXH3_len_17to128_128b((const xxh_u8*)input, len, (const xxh_u8*)secret, secretLen, seed64);
</span><span id="line6986" class="codeline ">    if (len &lt;= XXH3_MIDSIZE_MAX)
</span><span id="line6987" class="codeline ">        return XXH3_len_129to240_128b((const xxh_u8*)input, len, (const xxh_u8*)secret, secretLen, seed64);
</span><span id="line6988" class="codeline ">    return f_hl128(input, len, seed64, secret, secretLen);
</span><span id="line6989" class="codeline ">}
</span><span id="line6990" class="codeline ">
</span><span id="line6991" class="codeline ">
</span><span id="line6992" class="codeline ">/* ===   Public XXH128 API   === */
</span><span id="line6993" class="codeline ">
</span><span id="line6994" class="codeline ">/*! @ingroup XXH3_family */
</span><span id="line6995" class="codeline ">XXH_PUBLIC_API XXH128_hash_t XXH3_128bits(XXH_NOESCAPE const void* input, size_t len)
</span><span id="line6996" class="codeline ">{
</span><span id="line6997" class="codeline ">    return XXH3_128bits_internal(input, len, 0,
</span><span id="line6998" class="codeline ">                                 XXH3_kSecret, sizeof(XXH3_kSecret),
</span><span id="line6999" class="codeline ">                                 XXH3_hashLong_128b_default);
</span><span id="line7000" class="codeline ">}
</span><span id="line7001" class="codeline ">
</span><span id="line7002" class="codeline ">/*! @ingroup XXH3_family */
</span><span id="line7003" class="codeline ">XXH_PUBLIC_API XXH128_hash_t
</span><span id="line7004" class="codeline ">XXH3_128bits_withSecret(XXH_NOESCAPE const void* input, size_t len, XXH_NOESCAPE const void* secret, size_t secretSize)
</span><span id="line7005" class="codeline ">{
</span><span id="line7006" class="codeline ">    return XXH3_128bits_internal(input, len, 0,
</span><span id="line7007" class="codeline ">                                 (const xxh_u8*)secret, secretSize,
</span><span id="line7008" class="codeline ">                                 XXH3_hashLong_128b_withSecret);
</span><span id="line7009" class="codeline ">}
</span><span id="line7010" class="codeline ">
</span><span id="line7011" class="codeline ">/*! @ingroup XXH3_family */
</span><span id="line7012" class="codeline ">XXH_PUBLIC_API XXH128_hash_t
</span><span id="line7013" class="codeline ">XXH3_128bits_withSeed(XXH_NOESCAPE const void* input, size_t len, XXH64_hash_t seed)
</span><span id="line7014" class="codeline ">{
</span><span id="line7015" class="codeline ">    return XXH3_128bits_internal(input, len, seed,
</span><span id="line7016" class="codeline ">                                 XXH3_kSecret, sizeof(XXH3_kSecret),
</span><span id="line7017" class="codeline ">                                 XXH3_hashLong_128b_withSeed);
</span><span id="line7018" class="codeline ">}
</span><span id="line7019" class="codeline ">
</span><span id="line7020" class="codeline ">/*! @ingroup XXH3_family */
</span><span id="line7021" class="codeline ">XXH_PUBLIC_API XXH128_hash_t
</span><span id="line7022" class="codeline ">XXH3_128bits_withSecretandSeed(XXH_NOESCAPE const void* input, size_t len, XXH_NOESCAPE const void* secret, size_t secretSize, XXH64_hash_t seed)
</span><span id="line7023" class="codeline ">{
</span><span id="line7024" class="codeline ">    if (len &lt;= XXH3_MIDSIZE_MAX)
</span><span id="line7025" class="codeline ">        return XXH3_128bits_internal(input, len, seed, XXH3_kSecret, sizeof(XXH3_kSecret), NULL);
</span><span id="line7026" class="codeline ">    return XXH3_hashLong_128b_withSecret(input, len, seed, secret, secretSize);
</span><span id="line7027" class="codeline ">}
</span><span id="line7028" class="codeline ">
</span><span id="line7029" class="codeline ">/*! @ingroup XXH3_family */
</span><span id="line7030" class="codeline ">XXH_PUBLIC_API XXH128_hash_t
</span><span id="line7031" class="codeline ">XXH128(XXH_NOESCAPE const void* input, size_t len, XXH64_hash_t seed)
</span><span id="line7032" class="codeline ">{
</span><span id="line7033" class="codeline ">    return XXH3_128bits_withSeed(input, len, seed);
</span><span id="line7034" class="codeline ">}
</span><span id="line7035" class="codeline ">
</span><span id="line7036" class="codeline ">
</span><span id="line7037" class="codeline ">/* ===   XXH3 128-bit streaming   === */
</span><span id="line7038" class="codeline ">#ifndef XXH_NO_STREAM
</span><span id="line7039" class="codeline ">/*
</span><span id="line7040" class="codeline "> * All initialization and update functions are identical to 64-bit streaming variant.
</span><span id="line7041" class="codeline "> * The only difference is the finalization routine.
</span><span id="line7042" class="codeline "> */
</span><span id="line7043" class="codeline ">
</span><span id="line7044" class="codeline ">/*! @ingroup XXH3_family */
</span><span id="line7045" class="codeline ">XXH_PUBLIC_API XXH_errorcode
</span><span id="line7046" class="codeline ">XXH3_128bits_reset(XXH_NOESCAPE XXH3_state_t* statePtr)
</span><span id="line7047" class="codeline ">{
</span><span id="line7048" class="codeline ">    return XXH3_64bits_reset(statePtr);
</span><span id="line7049" class="codeline ">}
</span><span id="line7050" class="codeline ">
</span><span id="line7051" class="codeline ">/*! @ingroup XXH3_family */
</span><span id="line7052" class="codeline ">XXH_PUBLIC_API XXH_errorcode
</span><span id="line7053" class="codeline ">XXH3_128bits_reset_withSecret(XXH_NOESCAPE XXH3_state_t* statePtr, XXH_NOESCAPE const void* secret, size_t secretSize)
</span><span id="line7054" class="codeline ">{
</span><span id="line7055" class="codeline ">    return XXH3_64bits_reset_withSecret(statePtr, secret, secretSize);
</span><span id="line7056" class="codeline ">}
</span><span id="line7057" class="codeline ">
</span><span id="line7058" class="codeline ">/*! @ingroup XXH3_family */
</span><span id="line7059" class="codeline ">XXH_PUBLIC_API XXH_errorcode
</span><span id="line7060" class="codeline ">XXH3_128bits_reset_withSeed(XXH_NOESCAPE XXH3_state_t* statePtr, XXH64_hash_t seed)
</span><span id="line7061" class="codeline ">{
</span><span id="line7062" class="codeline ">    return XXH3_64bits_reset_withSeed(statePtr, seed);
</span><span id="line7063" class="codeline ">}
</span><span id="line7064" class="codeline ">
</span><span id="line7065" class="codeline ">/*! @ingroup XXH3_family */
</span><span id="line7066" class="codeline ">XXH_PUBLIC_API XXH_errorcode
</span><span id="line7067" class="codeline ">XXH3_128bits_reset_withSecretandSeed(XXH_NOESCAPE XXH3_state_t* statePtr, XXH_NOESCAPE const void* secret, size_t secretSize, XXH64_hash_t seed)
</span><span id="line7068" class="codeline ">{
</span><span id="line7069" class="codeline ">    return XXH3_64bits_reset_withSecretandSeed(statePtr, secret, secretSize, seed);
</span><span id="line7070" class="codeline ">}
</span><span id="line7071" class="codeline ">
</span><span id="line7072" class="codeline ">/*! @ingroup XXH3_family */
</span><span id="line7073" class="codeline ">XXH_PUBLIC_API XXH_errorcode
</span><span id="line7074" class="codeline ">XXH3_128bits_update(XXH_NOESCAPE XXH3_state_t* state, XXH_NOESCAPE const void* input, size_t len)
</span><span id="line7075" class="codeline ">{
</span><span id="line7076" class="codeline ">    return XXH3_64bits_update(state, input, len);
</span><span id="line7077" class="codeline ">}
</span><span id="line7078" class="codeline ">
</span><span id="line7079" class="codeline ">/*! @ingroup XXH3_family */
</span><span id="line7080" class="codeline ">XXH_PUBLIC_API XXH128_hash_t XXH3_128bits_digest (XXH_NOESCAPE const XXH3_state_t* state)
</span><span id="line7081" class="codeline ">{
</span><span id="line7082" class="codeline ">    const unsigned char* const secret = (state-&gt;extSecret == NULL) ? state-&gt;customSecret : state-&gt;extSecret;
</span><span id="line7083" class="codeline ">    if (state-&gt;totalLen &gt; XXH3_MIDSIZE_MAX) {
</span><span id="line7084" class="codeline ">        XXH_ALIGN(XXH_ACC_ALIGN) XXH64_hash_t acc[XXH_ACC_NB];
</span><span id="line7085" class="codeline ">        XXH3_digest_long(acc, state, secret);
</span><span id="line7086" class="codeline ">        XXH_ASSERT(state-&gt;secretLimit + XXH_STRIPE_LEN &gt;= sizeof(acc) + XXH_SECRET_MERGEACCS_START);
</span><span id="line7087" class="codeline ">        return XXH3_finalizeLong_128b(acc, secret, state-&gt;secretLimit + XXH_STRIPE_LEN,  (xxh_u64)state-&gt;totalLen);
</span><span id="line7088" class="codeline ">    }
</span><span id="line7089" class="codeline ">    /* len &lt;= XXH3_MIDSIZE_MAX : short code */
</span><span id="line7090" class="codeline ">    if (state-&gt;useSeed)
</span><span id="line7091" class="codeline ">        return XXH3_128bits_withSeed(state-&gt;buffer, (size_t)state-&gt;totalLen, state-&gt;seed);
</span><span id="line7092" class="codeline ">    return XXH3_128bits_withSecret(state-&gt;buffer, (size_t)(state-&gt;totalLen),
</span><span id="line7093" class="codeline ">                                   secret, state-&gt;secretLimit + XXH_STRIPE_LEN);
</span><span id="line7094" class="codeline ">}
</span><span id="line7095" class="codeline ">#endif /* !XXH_NO_STREAM */
</span><span id="line7096" class="codeline ">/* 128-bit utility functions */
</span><span id="line7097" class="codeline ">
</span><span id="line7098" class="codeline ">#include &lt;string.h&gt;   /* memcmp, memcpy */
</span><span id="line7099" class="codeline ">
</span><span id="line7100" class="codeline ">/* return : 1 is equal, 0 if different */
</span><span id="line7101" class="codeline ">/*! @ingroup XXH3_family */
</span><span id="line7102" class="codeline ">XXH_PUBLIC_API int XXH128_isEqual(XXH128_hash_t h1, XXH128_hash_t h2)
</span><span id="line7103" class="codeline ">{
</span><span id="line7104" class="codeline ">    /* note : XXH128_hash_t is compact, it has no padding byte */
</span><span id="line7105" class="codeline ">    return !(memcmp(&amp;h1, &amp;h2, sizeof(h1)));
</span><span id="line7106" class="codeline ">}
</span><span id="line7107" class="codeline ">
</span><span id="line7108" class="codeline ">/* This prototype is compatible with stdlib&#39;s qsort().
</span><span id="line7109" class="codeline "> * @return : &gt;0 if *h128_1  &gt; *h128_2
</span><span id="line7110" class="codeline "> *           &lt;0 if *h128_1  &lt; *h128_2
</span><span id="line7111" class="codeline "> *           =0 if *h128_1 == *h128_2  */
</span><span id="line7112" class="codeline ">/*! @ingroup XXH3_family */
</span><span id="line7113" class="codeline ">XXH_PUBLIC_API int XXH128_cmp(XXH_NOESCAPE const void* h128_1, XXH_NOESCAPE const void* h128_2)
</span><span id="line7114" class="codeline ">{
</span><span id="line7115" class="codeline ">    XXH128_hash_t const h1 = *(const XXH128_hash_t*)h128_1;
</span><span id="line7116" class="codeline ">    XXH128_hash_t const h2 = *(const XXH128_hash_t*)h128_2;
</span><span id="line7117" class="codeline ">    int const hcmp = (h1.high64 &gt; h2.high64) - (h2.high64 &gt; h1.high64);
</span><span id="line7118" class="codeline ">    /* note : bets that, in most cases, hash values are different */
</span><span id="line7119" class="codeline ">    if (hcmp) return hcmp;
</span><span id="line7120" class="codeline ">    return (h1.low64 &gt; h2.low64) - (h2.low64 &gt; h1.low64);
</span><span id="line7121" class="codeline ">}
</span><span id="line7122" class="codeline ">
</span><span id="line7123" class="codeline ">
</span><span id="line7124" class="codeline ">/*======   Canonical representation   ======*/
</span><span id="line7125" class="codeline ">/*! @ingroup XXH3_family */
</span><span id="line7126" class="codeline ">XXH_PUBLIC_API void
</span><span id="line7127" class="codeline ">XXH128_canonicalFromHash(XXH_NOESCAPE XXH128_canonical_t* dst, XXH128_hash_t hash)
</span><span id="line7128" class="codeline ">{
</span><span id="line7129" class="codeline ">    XXH_STATIC_ASSERT(sizeof(XXH128_canonical_t) == sizeof(XXH128_hash_t));
</span><span id="line7130" class="codeline ">    if (XXH_CPU_LITTLE_ENDIAN) {
</span><span id="line7131" class="codeline ">        hash.high64 = XXH_swap64(hash.high64);
</span><span id="line7132" class="codeline ">        hash.low64  = XXH_swap64(hash.low64);
</span><span id="line7133" class="codeline ">    }
</span><span id="line7134" class="codeline ">    XXH_memcpy(dst, &amp;hash.high64, sizeof(hash.high64));
</span><span id="line7135" class="codeline ">    XXH_memcpy((char*)dst + sizeof(hash.high64), &amp;hash.low64, sizeof(hash.low64));
</span><span id="line7136" class="codeline ">}
</span><span id="line7137" class="codeline ">
</span><span id="line7138" class="codeline ">/*! @ingroup XXH3_family */
</span><span id="line7139" class="codeline ">XXH_PUBLIC_API XXH128_hash_t
</span><span id="line7140" class="codeline ">XXH128_hashFromCanonical(XXH_NOESCAPE const XXH128_canonical_t* src)
</span><span id="line7141" class="codeline ">{
</span><span id="line7142" class="codeline ">    XXH128_hash_t h;
</span><span id="line7143" class="codeline ">    h.high64 = XXH_readBE64(src);
</span><span id="line7144" class="codeline ">    h.low64  = XXH_readBE64(src-&gt;digest + 8);
</span><span id="line7145" class="codeline ">    return h;
</span><span id="line7146" class="codeline ">}
</span><span id="line7147" class="codeline ">
</span><span id="line7148" class="codeline ">
</span><span id="line7149" class="codeline ">
</span><span id="line7150" class="codeline ">/* ==========================================
</span><span id="line7151" class="codeline "> * Secret generators
</span><span id="line7152" class="codeline "> * ==========================================
</span><span id="line7153" class="codeline "> */
</span><span id="line7154" class="codeline ">#define XXH_MIN(x, y) (((x) &gt; (y)) ? (y) : (x))
</span><span id="line7155" class="codeline ">
</span><span id="line7156" class="codeline ">XXH_FORCE_INLINE void XXH3_combine16(void* dst, XXH128_hash_t h128)
</span><span id="line7157" class="codeline ">{
</span><span id="line7158" class="codeline ">    XXH_writeLE64( dst, XXH_readLE64(dst) ^ h128.low64 );
</span><span id="line7159" class="codeline ">    XXH_writeLE64( (char*)dst+8, XXH_readLE64((char*)dst+8) ^ h128.high64 );
</span><span id="line7160" class="codeline ">}
</span><span id="line7161" class="codeline ">
</span><span id="line7162" class="codeline ">/*! @ingroup XXH3_family */
</span><span id="line7163" class="codeline ">XXH_PUBLIC_API XXH_errorcode
</span><span id="line7164" class="codeline ">XXH3_generateSecret(XXH_NOESCAPE void* secretBuffer, size_t secretSize, XXH_NOESCAPE const void* customSeed, size_t customSeedSize)
</span><span id="line7165" class="codeline ">{
</span><span id="line7166" class="codeline ">#if (XXH_DEBUGLEVEL &gt;= 1)
</span><span id="line7167" class="codeline ">    XXH_ASSERT(secretBuffer != NULL);
</span><span id="line7168" class="codeline ">    XXH_ASSERT(secretSize &gt;= XXH3_SECRET_SIZE_MIN);
</span><span id="line7169" class="codeline ">#else
</span><span id="line7170" class="codeline ">    /* production mode, assert() are disabled */
</span><span id="line7171" class="codeline ">    if (secretBuffer == NULL) return XXH_ERROR;
</span><span id="line7172" class="codeline ">    if (secretSize &lt; XXH3_SECRET_SIZE_MIN) return XXH_ERROR;
</span><span id="line7173" class="codeline ">#endif
</span><span id="line7174" class="codeline ">
</span><span id="line7175" class="codeline ">    if (customSeedSize == 0) {
</span><span id="line7176" class="codeline ">        customSeed = XXH3_kSecret;
</span><span id="line7177" class="codeline ">        customSeedSize = XXH_SECRET_DEFAULT_SIZE;
</span><span id="line7178" class="codeline ">    }
</span><span id="line7179" class="codeline ">#if (XXH_DEBUGLEVEL &gt;= 1)
</span><span id="line7180" class="codeline ">    XXH_ASSERT(customSeed != NULL);
</span><span id="line7181" class="codeline ">#else
</span><span id="line7182" class="codeline ">    if (customSeed == NULL) return XXH_ERROR;
</span><span id="line7183" class="codeline ">#endif
</span><span id="line7184" class="codeline ">
</span><span id="line7185" class="codeline ">    /* Fill secretBuffer with a copy of customSeed - repeat as needed */
</span><span id="line7186" class="codeline ">    {   size_t pos = 0;
</span><span id="line7187" class="codeline ">        while (pos &lt; secretSize) {
</span><span id="line7188" class="codeline ">            size_t const toCopy = XXH_MIN((secretSize - pos), customSeedSize);
</span><span id="line7189" class="codeline ">            memcpy((char*)secretBuffer + pos, customSeed, toCopy);
</span><span id="line7190" class="codeline ">            pos += toCopy;
</span><span id="line7191" class="codeline ">    }   }
</span><span id="line7192" class="codeline ">
</span><span id="line7193" class="codeline ">    {   size_t const nbSeg16 = secretSize / 16;
</span><span id="line7194" class="codeline ">        size_t n;
</span><span id="line7195" class="codeline ">        XXH128_canonical_t scrambler;
</span><span id="line7196" class="codeline ">        XXH128_canonicalFromHash(&amp;scrambler, XXH128(customSeed, customSeedSize, 0));
</span><span id="line7197" class="codeline ">        for (n=0; n&lt;nbSeg16; n++) {
</span><span id="line7198" class="codeline ">            XXH128_hash_t const h128 = XXH128(&amp;scrambler, sizeof(scrambler), n);
</span><span id="line7199" class="codeline ">            XXH3_combine16((char*)secretBuffer + n*16, h128);
</span><span id="line7200" class="codeline ">        }
</span><span id="line7201" class="codeline ">        /* last segment */
</span><span id="line7202" class="codeline ">        XXH3_combine16((char*)secretBuffer + secretSize - 16, XXH128_hashFromCanonical(&amp;scrambler));
</span><span id="line7203" class="codeline ">    }
</span><span id="line7204" class="codeline ">    return XXH_OK;
</span><span id="line7205" class="codeline ">}
</span><span id="line7206" class="codeline ">
</span><span id="line7207" class="codeline ">/*! @ingroup XXH3_family */
</span><span id="line7208" class="codeline ">XXH_PUBLIC_API void
</span><span id="line7209" class="codeline ">XXH3_generateSecret_fromSeed(XXH_NOESCAPE void* secretBuffer, XXH64_hash_t seed)
</span><span id="line7210" class="codeline ">{
</span><span id="line7211" class="codeline ">    XXH_ALIGN(XXH_SEC_ALIGN) xxh_u8 secret[XXH_SECRET_DEFAULT_SIZE];
</span><span id="line7212" class="codeline ">    XXH3_initCustomSecret(secret, seed);
</span><span id="line7213" class="codeline ">    XXH_ASSERT(secretBuffer != NULL);
</span><span id="line7214" class="codeline ">    memcpy(secretBuffer, secret, XXH_SECRET_DEFAULT_SIZE);
</span><span id="line7215" class="codeline ">}
</span><span id="line7216" class="codeline ">
</span><span id="line7217" class="codeline ">
</span><span id="line7218" class="codeline ">
</span><span id="line7219" class="codeline ">/* Pop our optimization override from above */
</span><span id="line7220" class="codeline ">#if XXH_VECTOR == XXH_AVX2 /* AVX2 */ \
</span><span id="line7221" class="codeline ">  &amp;&amp; defined(__GNUC__) &amp;&amp; !defined(__clang__) /* GCC, not Clang */ \
</span><span id="line7222" class="codeline ">  &amp;&amp; defined(__OPTIMIZE__) &amp;&amp; XXH_SIZE_OPT &lt;= 0 /* respect -O0 and -Os */
</span><span id="line7223" class="codeline ">#  pragma GCC pop_options
</span><span id="line7224" class="codeline ">#endif
</span><span id="line7225" class="codeline ">
</span><span id="line7226" class="codeline ">#endif  /* XXH_NO_LONG_LONG */
</span><span id="line7227" class="codeline ">
</span><span id="line7228" class="codeline ">#endif  /* XXH_NO_XXH3 */
</span><span id="line7229" class="codeline ">
</span><span id="line7230" class="codeline ">/*!
</span><span id="line7231" class="codeline "> * @}
</span><span id="line7232" class="codeline "> */
</span><span id="line7233" class="codeline ">#endif  /* XXH_IMPLEMENTATION */
</span><span id="line7234" class="codeline ">
</span><span id="line7235" class="codeline ">
</span><span id="line7236" class="codeline ">#if defined (__cplusplus)
</span><span id="line7237" class="codeline ">} /* extern &#34;C&#34; */
</span><span id="line7238" class="codeline ">#endif
</span></code></pre>
    </td>
  </tr>
</table>

<script type="text/javascript">
  debsources.source_file();
  hljs.highlightBlock(document.getElementById('sourcecode'))

</script>




      </div>

      <footer id="footer">
        
          

    
  
<p style="margin: 0 0 0 0; line-height: 1em;">
  Browse by prefix: &ensp;
  

    
  
    <a href="/prefix/0/">0</a>
    <a href="/prefix/1/">1</a>
    <a href="/prefix/2/">2</a>
    <a href="/prefix/3/">3</a>
    <a href="/prefix/4/">4</a>
    <a href="/prefix/6/">6</a>
    <a href="/prefix/7/">7</a>
    <a href="/prefix/8/">8</a>
    <a href="/prefix/9/">9</a>
    <a href="/prefix/a/">a</a>
    <a href="/prefix/b/">b</a>
    <a href="/prefix/c/">c</a>
    <a href="/prefix/d/">d</a>
    <a href="/prefix/e/">e</a>
    <a href="/prefix/f/">f</a>
    <a href="/prefix/g/">g</a>
    <a href="/prefix/h/">h</a>
    <a href="/prefix/i/">i</a>
    <a href="/prefix/j/">j</a>
    <a href="/prefix/k/">k</a>
    <a href="/prefix/l/">l</a>
    <a href="/prefix/lib-/">lib-</a>
    <a href="/prefix/lib1/">lib1</a>
    <a href="/prefix/lib2/">lib2</a>
    <a href="/prefix/lib3/">lib3</a>
    <a href="/prefix/lib6/">lib6</a>
    <a href="/prefix/liba/">liba</a>
    <a href="/prefix/libb/">libb</a>
    <a href="/prefix/libc/">libc</a>
    <a href="/prefix/libd/">libd</a>
    <a href="/prefix/libe/">libe</a>
    <a href="/prefix/libf/">libf</a>
    <a href="/prefix/libg/">libg</a>
    <a href="/prefix/libh/">libh</a>
    <a href="/prefix/libi/">libi</a>
    <a href="/prefix/libj/">libj</a>
    <a href="/prefix/libk/">libk</a>
    <a href="/prefix/libl/">libl</a>
    <a href="/prefix/libm/">libm</a>
    <a href="/prefix/libn/">libn</a>
    <a href="/prefix/libo/">libo</a>
    <a href="/prefix/libp/">libp</a>
    <a href="/prefix/libq/">libq</a>
    <a href="/prefix/libr/">libr</a>
    <a href="/prefix/libs/">libs</a>
    <a href="/prefix/libt/">libt</a>
    <a href="/prefix/libu/">libu</a>
    <a href="/prefix/libv/">libv</a>
    <a href="/prefix/libw/">libw</a>
    <a href="/prefix/libx/">libx</a>
    <a href="/prefix/liby/">liby</a>
    <a href="/prefix/libz/">libz</a>
    <a href="/prefix/m/">m</a>
    <a href="/prefix/n/">n</a>
    <a href="/prefix/o/">o</a>
    <a href="/prefix/p/">p</a>
    <a href="/prefix/q/">q</a>
    <a href="/prefix/r/">r</a>
    <a href="/prefix/s/">s</a>
    <a href="/prefix/t/">t</a>
    <a href="/prefix/u/">u</a>
    <a href="/prefix/v/">v</a>
    <a href="/prefix/w/">w</a>
    <a href="/prefix/x/">x</a>
    <a href="/prefix/y/">y</a>
    <a href="/prefix/z/">z</a>

  &ensp; | &ensp;
  Browse <a href="/list/1/">by page</a>
</p>
<hr />
<div style="position: relative">

<p>
  Debsources &mdash; Copyright (C) 2011&ndash;2021,
  <a href="https://salsa.debian.org/qa/debsources/blob/master/AUTHORS">The Debsources developers</a>.
  License:
  <a href="https://www.gnu.org/licenses/agpl.html">GNU AGPLv3+</a>.
  <br />
  Hosted source files are available under their own
  <a href="https://www.debian.org/doc/debian-policy/ch-source.html#s-dpkgcopyright">copyright
  and licenses</a>.
  <br />
  Source code: <a href="https://salsa.debian.org/qa/debsources">Git</a>.
  Contact: <a href="mailto:qa-debsources@lists.alioth.debian.org">qa-debsources@lists.alioth.debian.org</a>.
  Last update: Sun, 16 Nov 2025 14:15:44 -0000.
</p>
</div>

<script type="text/javascript">
// @license magnet:?xt=urn:btih:0b31508aeb0634b347b8270c7bee4d411b5d4109&dn=agpl-3.0.txt AGPL-3.0
var elems = document.querySelectorAll('.js-append-window-location-hash');

for (var i = 0; i < elems.length; ++i) {
  elems[i].setAttribute('href', elems[i].getAttribute('href') + window.location.hash);
}
// @license-end
</script>
        
      </footer>
    
  </body>
</html>