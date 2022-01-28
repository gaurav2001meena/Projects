<script>
let a='',b='',c='',d='',e='';
function refresh() {window.location.reload()}
import { fly } from 'svelte/transition';


    let shown = false;
	
		
	
	  function show() {
        shown = !shown;
        //transition:fly="{{ y: 200, duration: 2000 }}"
				
		}

</script>

<body class="bg-white relative ">
    <h1 class="text-center shadow-md shadow-red-500 m-auto bg-black text-4xl pt-8 pb-8 text-white font-bold">Application Builder</h1>
    <div class=" bg-blue-300 ml-8 mt-5 shadow-md pt-0.5 shadow-black  w-80 rounded-2xl inline-block">
    
<div class="mt-8 pl-5">
 <label class="text-xl text-red-800 font-semibold" for="{a}">Enter your Full name </label>   
<input class="bg-lime-50 text-xl text-red-600 border-2 rounded border-blue-800 font-semibold" type="text"  bind:value={a}>
</div>
<div class="mt-8 pl-5">
    <label class="text-xl text-red-800 font-semibold" for="{b}">Enter your Class </label>   
   <input class="bg-lime-50 text-xl text-red-600 border-2 rounded border-blue-800 font-semibold" type="text"  bind:value={b}>
   </div> 
   <div class="mt-8 pl-5">
    <label class="text-xl text-red-800 font-semibold" for="{c}">Enter your Leave reason </label>  
    <textarea  class= "bg-lime-50 text-xl w-64 text-red-600 border-2 rounded border-blue-800 font-semibold" type="para"  bind:value={c} cols="30" rows="10"></textarea> 
   
   </div> 
   <div class="mt-8 pl-5">
    <label class="text-xl text-red-800 font-semibold" for="{d}">Enter starting date </label>   
   <input class="bg-lime-50 text-xl text-red-600 border-2 rounded border-blue-800 font-semibold" type="date"  bind:value={d}>
   </div> 
   <div class="mt-8 pl-5">
    <label class="text-xl text-red-800 font-semibold" for="{e}">Enter your ending date </label>   
   <input class="bg-lime-50 text-xl text-red-600 border-2 rounded border-blue-800 font-semibold" type="date"  bind:value={e}>
   </div>  
   <div class="mt-8 pl-5 pb-10  text-xl " >
    <button on:click={show} class= " bg-yellow-50 w-24 rounded-full shadow-black shadow-md hover:transition:ease-in-out duration-500 hover:bg-violet-300 " >Submit</button>
    <button on:click="{refresh}" class="w-24 max-h-16 ml-12 rounded-full bg-yellow-50 shadow-black shadow-md transition:ease-in-out duration-500 hover:bg-violet-300">Reset</button>
    


   </div>
   
</div >
<div  class=" inline-block absolute mt-40  " >
    {#if shown}
    <p  id="hd" class="bg-indigo-200 w-5/12 border-black border-0 rounded-2xl  px-4 py-2 my-auto ml-96  text-2xl popout  ">
        Respected Sir, my name is {a} from class {b}.<br> Sir i would like to request for leave because of the following reason: {c} <br> So i humbly Request you to grant me leave from {d} to {e}  
    </p>
   
{/if}
    
</div>
</body>
 <style>
      .popout {
        animation: popout 1s ease;
        -webkit-animation: popout 1s ease;
    }
    @keyframes popout {
        from{transform:scale(0)}
        80%{transform:scale(1.2)}
        to{transform:scale(1)}
    }
    @-webkit-keyframes popout {
        from{-webkit-transform:scale(0)}
        80%{-webkit-transform:scale(1.2)}
        to{-webkit-transform:scale(1)}
    }

 </style>