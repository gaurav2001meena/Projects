<script>
	
	let num1, num2, selected, ans;
	

   
	function onChange(event) {
		selected = event.currentTarget.value;
	}

	const showAns=()=>{
		console.log(selected);

		 if(selected== 10)
		{
			ans= +num1 + +num2;
		}
		else if(selected== 20)
		{
			ans=num1-num2;
		}
		else if(selected==30)
		{
			ans=num1*num2;
		}
		else{
			alert("Please Choose a operator.")
		}
	}


</script>
  

<main>
	<form id="mama">
     <label for="num1">Enter your 1st number</label>
	 <input type="text" id="num1" bind:value={num1} />
	 <label for='num2'>enter your 2nd number</label>
	 <input type="text" id="num2" bind:value={num2} />
	 <label for="mama">choose your operator symbol </label>
	
	 <label>
		<input checked={selected==="+"} on:change={onChange} type="radio" name="amount" value="10" /> +
	</label>
	<label>
		<input checked={selected==="-"} on:change={onChange} type="radio" name="amount" value="20" /> -
	</label>
	<label>
		<input checked={selected==="*"} on:change={onChange} type="radio" name="amount" value="30" /> *
	</label>
	 <label for="answer">The answer is : </label>
	 <input type="text" id="answer" bind:value={ans} />
	 <button on:click|preventDefault={showAns}>Show results</button>
	 </form>
</main>

<style>
	main {
		text-align: center;
		padding: 1em;
		max-width: 240px;
		margin: 0 auto;
	}

	h1 {
		color: #ff3e00;
		text-transform: uppercase;
		font-size: 4em;
		font-weight: 100;
	}

	@media (min-width: 640px) {
		main {
			max-width: none;
		}
	}
	#mama{

		border-style: solid;
		border-radius: 100px;
		border-width: 5px;
		
	}
</style>