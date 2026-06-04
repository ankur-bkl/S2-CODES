function setError(id, show) {
    const input = document.getElementById(id);
    const msg   = document.getElementById('err-' + id);
    if (input)  input.classList.toggle('error', show);
    if (msg)    msg.classList.toggle('show', show);
    return !show;   
  }

  function submitForm() {
    let valid = true;

    const name = document.getElementById('fullname').value.trim();
    valid &= setError('fullname', name === '' || name.length > 50);

    const cid  = document.getElementById('collegeid').value.trim();
    valid &= setError('collegeid', !/^\d{11}$/.test(cid));

    const course = document.getElementById('course').value.trim();
    valid &= setError('course', course === '');

    const gender = document.querySelector('input[name="gender"]:checked');
    const genderEl = document.getElementById('gender-group');
    const errGender = document.getElementById('err-gender');
    if (!gender) {
      errGender.classList.add('show');
      valid = false;
    } else {
      errGender.classList.remove('show');
    }

    const dob  = document.getElementById('dob').value;
    const dobOk = dob !== '' && new Date(dob) <= new Date('2008-01-01');
    valid &= setError('dob', !dobOk);

    const email = document.getElementById('email').value.trim();
    valid &= setError('email', !/^[^\s@]+@[^\s@]+\.[^\s@]+$/.test(email));

    const mob  = document.getElementById('mobile').value.trim();
    valid &= setError('mobile', !/^\d{10}$/.test(mob));

    const medical = document.querySelector('input[name="medical"]:checked');
    valid &= setError('medical', !medical);

    if (valid) showSuccess();
  }

  
  function showSuccess() {
    document.getElementById('form-section').style.display = 'none';
    const sp = document.getElementById('success-page');
    sp.style.display = 'flex';
  }


  function goBack() {
    document.getElementById('success-page').style.display = 'none';
    document.getElementById('form-section').style.display = 'flex';


    document.querySelectorAll('input[type="text"], input[type="email"], input[type="tel"], input[type="date"]')
      .forEach(el => el.value = '');
    document.querySelectorAll('input[type="radio"]')
      .forEach(el => el.checked = false);
    document.querySelectorAll('.error').forEach(el => el.classList.remove('error'));
    document.querySelectorAll('.err-msg.show').forEach(el => el.classList.remove('show'));
  }